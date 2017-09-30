#include <ncurses.h>
#include <stdio.h>
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

/*
** Binding for the printw function
*/
static int lncurses_printw(lua_State* L){
    printw(luaL_checkstring(L, -1));

    // lua_gettop gets the size of the stack. If its 0,
    // the stack is empty, the loop exits

    // printw clears the screen so using addstr adds the
    // rest of the arguments
    while(lua_gettop(L) != 0){
        addstr(luaL_checkstring(L, -1));
        // Remove the top item from the stack
        lua_pop(L, -1);
    }
    return 0;
}

/*
** Binding for the addstr function
*/
static int lncurses_addstr(lua_State* L){
    // lua_gettop gets the size of the stack. If its 0,
    // the stack is empty, the loop exits
    while(lua_gettop(L) != 0){
        addstr(luaL_checkstring(L, -1));
        // Remove the top item from the stack
        lua_pop(L, -1);
    }
    return 0;
}

/*
** Refresh stdscr
*/
static int lncurses_refresh(lua_State* L){
    // Just calls the refresh function
    refresh();
    return 0;
}

/*
** Refresh stdscr
*/
static int lncurses_getch(lua_State* L){
    // Just calls the refresh function
    getch();
    return 0;
}

// Define the bindings
static const luaL_Reg lncurseslib[] = {
    {"initscr", lncurses_initscr},
    {"endwin", lncurses_endwin},
    {"printw", lncurses_printw},
    {"addstr", lncurses_addstr},
    {"refresh", lncurses_refresh},
    {"getch", lncurses_getch},
    {NULL, NULL}
};

// Driver function
LUALIB_API int luaopen_liblncurses(lua_State* L){
    luaL_newlib(L, lncurseslib);
    lua_pushstring(L, VERSION);
    lua_setglobal(L, "_LNCURSES_VERSION");
    return 1;
}
