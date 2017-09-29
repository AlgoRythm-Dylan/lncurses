#include <ncurses.h>
#include <lua5.2/lua.h>
#include <lua5.2/lualib.h>
#include <lua5.2/lauxlib.h>

/*

    I'm sorry in advance about the code quality here -
    this is a learning project for me.

    lncurses: Lua ncurses bindings by AlgoRythm
    (https://github.com/AlgoRythm-Dylan)

    License: MIT

    Tips for building yourself:
        - Obviously this uses Lua 5.2, you should do the same or newer.
        - If using g++, use -llua5.2 option. This fixes link errors.
        - Don't try, this won't work on Windows.
            - curses (& ncurses) is linux/ unix only

*/

#define VERSION "0.1.0"

/*
** Put the terminal in curses mode
*/
static int lncurses_initscr(lua_State* L){
    initscr();
    return 0;
}

/*
** Exit curses mode
*/
static int lncurses_endwin(lua_State* L){
    endwin();
    return 0;
}



// Define the bindings
static const luaL_Reg lncurseslib[] = {
    {"initscr", lncurses_initscr},
    {"endwin", lncurses_endwin},
    {NULL, NULL}
};

// Driver function
LUALIB_API int luaopen_liblncurses(lua_State* L){
    luaL_newlib(L, lncurseslib);
    return 1;
}
