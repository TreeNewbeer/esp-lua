# The following lines of boilerplate have to be in your project's CMakeLists
# in this exact order for cmake to work correctly
cmake_minimum_required(VERSION 3.5)
set(COMPONENT_SRCS src/linit.c
                   src/lapi.c
                   src/lbaselib.c
                   src/lcode.c
                   src/lctype.c
                   src/ldebug.c
                   src/ldump.c
                   src/lgc.c
                   src/liolib.c
                   src/lmathlib.c
                   src/loadlib.c
                   src/lopcodes.c
                   src/lparser.c
                   src/lstring.c
                   src/ltable.c
                   src/ltm.c
                   src/lutf8lib.c
                   src/lzio.c
                   src/lauxlib.c
                   src/lbitlib.c
                   src/lcorolib.c
                   src/ldblib.c
                   src/ldo.c
                   src/lfunc.c
                   src/llex.c
                   src/lmem.c
                   src/lobject.c
                   src/loslib.c
                   src/lstate.c
                   src/lstrlib.c
                   src/ltablib.c
                   src/lundump.c
                   src/lvm.c
                   src/lua.c)

set(COMPONENT_ADD_INCLUDEDIRS src)
register_component()

#component_compile_options(PUBLIC -Dlualib_h)
#component_compile_options(PRIVATE -Dmain=lua_main)