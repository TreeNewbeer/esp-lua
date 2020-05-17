#include <stdio.h>
#include <string.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"


static const char *prg =
    "print(\"Hello,I am lua!\\n--this is newline printf\")\n"
    "function foo()\n"
    "  local i = 0\n"
    "  local sum = 1\n"
    "  while i <= 10 do\n"
    "    sum = sum * 2\n"
    "    i = i + 1\n"
    "  end\n"
    "return sum\n"
    "end\n"
    "print(\"sum =\", foo())\n"
    "print(\"and sum = 2^11 =\", 2 ^ 11)\n"
    "print(\"exp(200) =\", math.exp(200))\n";


static int report(lua_State *L, int status)
{
    if (status != LUA_OK)
    {
        const char *msg = lua_tostring(L, -1);
        lua_writestring(msg, strlen(msg));
        lua_writeline();
        lua_pop(L, 1); /* remove message */
    }
    return status;
}

void test(void *arg)
{
    lua_State *L = luaL_newstate();
    if (!L)
    {
        printf("Could not create state....\n");
        while (1) { vTaskDelay(1000); }
    }
    luaL_openlibs(L);
    int r = luaL_loadstring(L, prg);
    if (r)
    {
        report(L, r);
        while (1) { vTaskDelay(1000); }
    }
    r = lua_pcall(L, 0, 0, 0);
    if (r)
        report(L, r);
    lua_close(L);
    while (1)
    {
        printf(".");
        vTaskDelay(100);
    }
}




void app_main()
{
    xTaskCreate(test, "test", 10 * 1024, NULL, 5, NULL);
    // while (1)
    // {
    //     vTaskDelay(500 / portTICK_RATE_MS);
    // }
}
