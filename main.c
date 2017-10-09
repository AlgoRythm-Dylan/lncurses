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
** Get a character
*/
static int lncurses_getch(lua_State* L){
    // Get a char and return it
    int ch = (int) getch();
    lua_pushinteger(L, ch);
    return 1; // Will return one value
}

/*
** Binding for raw()
*/
static int lncurses_raw(lua_State* L){
    raw();
    return 0;
}

/*
** Binding for cbreak
*/
static int lncurses_cbreak(lua_State* L){
    cbreak();
    return 0;
}

/*
** Binding for echo
*/
static int lncurses_echo(lua_State* L){
    echo();
    return 0;
}

/*
** Binding for noecho
*/
static int lncurses_noecho(lua_State* L){
    noecho();
    return 0;
}

// Turn userData into a WINDOW object
static WINDOW* toWindow(lua_State* L, int index){
    WINDOW* window = (WINDOW*) lua_touserdata(L, index);
    if(window == NULL){
        // The window given was not a correct value
    }
    return window;
}

/*
** Binding for keypad
*/
static int lncurses_keypad(lua_State* L){
    printf("Is light user data: %d\n", (int) lua_islightuserdata(L, 1));
    WINDOW* window = toWindow(L, 1);
    keypad(window, lua_toboolean(L, 2));
    return 0;
}

/*
** Binding for halfdelay
*/
static int lncurses_halfdelay(lua_State* L){
    int ch = (int) halfdelay(luaL_checkint(L, -1));
    lua_pushinteger(L, ch);
    return 1;
}

/*
** Moves to (y, x) - That isn't a typo. Old code, whatever.
*/
static int lncurses_move(lua_State* L){
    move(luaL_checkint(L, 1), luaL_checkint(L, 2));
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
    {"raw", lncurses_raw},
    {"cbreak", lncurses_cbreak},
    {"echo", lncurses_echo},
    {"noecho", lncurses_noecho},
    {"keypad", lncurses_keypad},
    {"halfdelay", lncurses_halfdelay},
    {"move", lncurses_move},
    {NULL, NULL}
};

// Driver function
LUALIB_API int luaopen_liblncurses(lua_State* L){
    luaL_newlib(L, lncurseslib);

    // This will start off as NULL
    lua_pushlightuserdata(L, stdscr);
    lua_setfield(L, -2, "stdscr");

    lua_pushstring(L, VERSION);
    lua_setglobal(L, "_LNCURSES_VERSION");
    return 1;
}
