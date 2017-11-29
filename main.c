#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
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
                - I dont want to try to hack this into a windows machine...
        - Don't forget -lncurses linker option for ncurses
        - Don't forget --enable-ext-colors linker option if you want 256 colors
            - Should be enabled by default but just to be sure
        - Also you will want the linker option --enable-widec
        - You may also want -Wno-unused-but-set-variable

*/

/**************************************************************

                        CONSTANTS

**************************************************************/

#define VERSION "0.1.0"
#define START_BUFFER_SIZE 128

/**************************************************************

                       DECLARATIONS

**************************************************************/

static int lncurses_initscr(lua_State*);
static int lncurses_endwin(lua_State*);
static int lncurses_printw(lua_State*);
static int lncurses_addstr(lua_State*);
static int lncurses_refresh(lua_State*);
static int lncurses_getch(lua_State*);
static int lncurses_raw(lua_State*);
static int lncurses_cbreak(lua_State*);
static int lncurses_echo(lua_State*);
static int lncurses_noecho(lua_State*);
static int lncurses_keypad(lua_State*);
static int lncurses_halfdelay(lua_State*);
static int lncurses_move(lua_State*);
static int lncurses_getmaxyx(lua_State*);
static int lncurses_getstr(lua_State*);
static int lncurses_attron(lua_State*);
static int lncurses_attroff(lua_State*);
static int lncurses_attrset(lua_State*);
static int lncurses_standend(lua_State*);
static int lncurses_newwin(lua_State*);
static int lncurses_delwin(lua_State*);
static int lncurses_box(lua_State*);
static int lncurses_wrefresh(lua_State*);
static int lncurses_has_colors(lua_State*);
static int lncurses_start_color(lua_State*);
static int lncurses_wgetch(lua_State*);
static int lncurses_mvgetch(lua_State*);
static int lncurses_mvwgetch(lua_State*);
static int lncurses_addch(lua_State*);
static int lncurses_waddch(lua_State*);
static int lncurses_mvaddch(lua_State*);
static int lncurses_mvwaddch(lua_State*);
static int lncurses_color_content(lua_State*);
static int lncurses_pair_content(lua_State*);
static int lncurses_COLOR_PAIR(lua_State*);
static int lncurses_can_change_color(lua_State*);
static int lncurses_init_pair(lua_State*);
static int lncurses_init_color(lua_State*);
// TODO

// Eh... later
    /*
    static int lncurses_init_extended_pair(lua_State*);
    static int lncurses_init_extended_color(lua_State*);
    static int lncurses_extended_color_content(lua_State*);
    static int lncurses_extended_pair_content(lua_State*);
    */
// HELPER FUNCTIONS
static WINDOW* toWindow(lua_State*, int);
static char* lncurses_helper_getstr(WINDOW*);

/**************************************************************

                          DATA

**************************************************************/

static int echoing = 1;
static int swapxy = 0;

/**************************************************************

                    IMPLEMENTATIONS

**************************************************************/

/*
** Put the terminal in curses mode
*/
static int lncurses_initscr(lua_State* L){
    initscr();

    // Update stdscr on the Lua side, as it is NULL before stdscr is called
    lua_getfield(L, LUA_REGISTRYINDEX, "lncurses");
    lua_pushlightuserdata(L, stdscr);
    lua_setfield(L, -2, "stdscr");

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
    lua_pop(L, -1);

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
** getch for a specific window
*/
static int lncurses_wgetch(lua_State* L){
    int ch = wgetch(toWindow(L, 1));
    lua_pushinteger(L, ch);
    return 1;
}

/*
** Binding for mvgetch
*/
static int lncurses_mvgetch(lua_State* L){
    int ch = mvgetch(luaL_checkinteger(L, 1), luaL_checkinteger(L, 2));
    lua_pushinteger(L, ch);
    return 1;
}

/*
** Binding for wmvgetch
*/
static int lncurses_mvwgetch(lua_State* L){
    int ch = mvwgetch(toWindow(L, 1), luaL_checkinteger(L, 2), luaL_checkinteger(L, 3));
    lua_pushinteger(L, ch);
    return 1;
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
    echoing = 1;
    return 0;
}

/*
** Binding for noecho
*/
static int lncurses_noecho(lua_State* L){
    noecho();
    echoing = 0;
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

/*
** This function is more Lua than ncurses: It doesn't modify
** the arguments passed into it, but does return two values
** (y, x)
**
** Binding for getmaxyx
*/
static int lncurses_getmaxyx(lua_State* L){
    int y, x;
    getmaxyx(toWindow(L, 1), x, y);

    // Return the values
    lua_pushinteger(L, y);
    lua_pushinteger(L, x);

    return 2;
}

/*
** Binding for getstr
*/
static int lncurses_getstr(lua_State* L){

    // Grab a char buffers
    char* buffer = lncurses_helper_getstr(stdscr);

    // Give the string to lua and then destroy it
    lua_pushstring(L, buffer);
    free(buffer);

    // Restore echoing if it was on previously
    if(echoing){
        echo();
    }

    return 1; // Will always return one string, but, of varying length
}

/*
**
** From the ncurses man mage: "The function getstr is equivalent
** to a series of calls to getch" - and that is what I will do.
** I want it to be almost infinitely large as in Lua
**
** Helper function to getstr from a given window, of unlimited size
*/
static char* lncurses_helper_getstr(WINDOW* window){
    // Character buffer
    char *buffer;
    // The size of the butter, is dynamic
    int bufferSize = START_BUFFER_SIZE;
    // Current character being read. Integer to catch specia items like backspace
    int ch;
    // The length of the current string, among other uses...
    int index = 0;
    // Where the cursor was initially positioned at the call of the function
    int starty, startx;
    getyx(window, starty, startx);

    // Initial allocation of the char buffer
    buffer = malloc(bufferSize);

    noecho();

    // While the character is not the enter key...
    while((ch = getch()) != '\n'){

        // If the user presses backspace...
        if(ch == KEY_BACKSPACE){
            // Get cursor info
            int y, x, rows, columns;
            getmaxyx(window, rows, columns);

            getyx(window, y, x);
            x--;

            // Move back up a column
            if(x == 0){
                x = columns;
                y--;
            }
            // Delete a character
            mvwdelch(window, y, x);

            // Delete from the buffer
            if(index != 0){
                index--;
            }
            buffer[index] = '\0';
        }
        else{
            // Echo out the character
            waddch(window, ch);
            // Is it too big to fit in the buffer?
            if(index >= bufferSize){

                // A whole new buffer, double the size of the original
                char *newBuffer;

                // Double the size of the buffer.
                // This will avoid reallocating memory frequently.
                bufferSize *= 2;
                newBuffer = realloc(buffer, bufferSize);
                if(newBuffer == NULL){
                    free(buffer);
                    // Memory allocation failed
                }
                buffer = newBuffer;
            }
            // Add the character to the buffer
            buffer[index] = ch;
            // Increase the index counter
            index++;
        }
    }
    return buffer;
}

/*
** Binding for attron
*/
static int lncurses_attron(lua_State* L){
    attron(luaL_checkint(L, 1));
    return 0;
}

/*
** Binding for attroff
*/
static int lncurses_attroff(lua_State* L){
    attroff(luaL_checkint(L, 1));
    return 0;
}

/*
** Binding for attrset
*/
static int lncurses_attrset(lua_State* L){
    attrset(luaL_checkint(L, 1));
    return 0;
}

/*
** Binding for standend
*/
static int lncurses_standend(lua_State* L){
    standend();
    return 0;
}

/*
** Binding for newwin
*/
static int lncurses_newwin(lua_State* L){
    WINDOW* window = newwin(luaL_checkint(L, 1), luaL_checkint(L, 2),
                            luaL_checkint(L, 3), luaL_checkint(L, 4));
    lua_pushlightuserdata(L, window);
    return 1;
}

/*
** Binding for delwin
*/
static int lncurses_delwin(lua_State* L){
    delwin(toWindow(L, 1));
    return 1;
}

/*
** Binding for box
*/
static int lncurses_box(lua_State* L){
    box(toWindow(L, 1), luaL_checkint(L, 2), luaL_checkint(L, 3));
    return 0;
}

/*
** Binding for wrefresh
*/
static int lncurses_wrefresh(lua_State* L){
    wrefresh(toWindow(L, 1));
    return 0;
}

/*
** Binding for has_color
*/
static int lncurses_has_colors(lua_State* L){
    lua_pushboolean(L, has_colors());
    return 1;
}

/*
** Binding for start_color
*/
static int lncurses_start_color(lua_State* L){
    start_color();
    return 0;
}

/*
** Binding for init_pair
*/
static int lncurses_init_pair(lua_State* L){
    init_pair((short) luaL_checkint(L, 1), (short) luaL_checkint(L, 2), (short) luaL_checkint(L, 3));
    return 0;
}

/*
** Binding for COLOR_PAIR
*/
static int lncurses_COLOR_PAIR(lua_State* L){
    lua_pushinteger(L, COLOR_PAIR(luaL_checkint(L, 1)));
    return 1;
}

/*
** Binding for color_content
*/
static int lncurses_color_content(lua_State* L){
    short r, g, b;
    color_content((short) luaL_checkint(L, 1), &r, &g, &b);
    lua_pushinteger(L, r);
    lua_pushinteger(L, g);
    lua_pushinteger(L, b);
    return 3;
}

/*
** Binding for pair_content
*/
static int lncurses_pair_content(lua_State* L){
    short color1, color2;
    pair_content((short) luaL_checkint(L, 1), &color1, &color2);
    lua_pushinteger(L, color1);
    lua_pushinteger(L, color2);
    return 2;
}

/*
** Binding for can_change_color
*/
static int lncurses_can_change_color(lua_State* L){
    lua_pushboolean(L, can_change_color());
    return 1;
}

/*
** Binding for init_color
*/
static int lncurses_init_color(lua_State* L){
    int color = init_color((short) luaL_checkint(L, 1),
                           (short) luaL_checkint(L, 2),
                           (short) luaL_checkint(L, 3),
                           (short) luaL_checkint(L, 4));
    lua_pushinteger(L, color);
    return 1;
}

/*
** Binding for addch
*/
static int lncurses_addch(lua_State* L){
    const char* arg = luaL_checkstring(L, 1);
    addch(arg[0]);
    return 0;
}

/*
** Binding for waddch
*/
static int lncurses_waddch(lua_State* L){
    const char* arg = luaL_checkstring(L, 2);
    waddch(toWindow(L, 1), arg[0]);
    return 0;
}

/*
** Binding for waddch
*/
static int lncurses_mvaddch(lua_State* L){
    const char* arg = luaL_checkstring(L, 3);
    mvaddch(luaL_checkint(L, 1), luaL_checkint(L, 2), arg[0]);
    return 0;
}

/*
** Binding for mvwaddch
*/
static int lncurses_mvwaddch(lua_State* L){
    const char* arg = luaL_checkstring(L, 4);
    mvwaddch(toWindow(L, 1), luaL_checkint(L, 2), luaL_checkint(L, 3), arg[0]);
    return 0;
}


// Define the bindings
static const luaL_Reg lncurseslib[] = {
    {"initscr", lncurses_initscr},
    {"endwin", lncurses_endwin},
    // Output
    {"printw", lncurses_printw},
    {"addstr", lncurses_addstr},
    {"refresh", lncurses_refresh},
    {"raw", lncurses_raw},
    {"cbreak", lncurses_cbreak},
    // Echoing
    {"echo", lncurses_echo},
    {"noecho", lncurses_noecho},
    {"keypad", lncurses_keypad},
    {"halfdelay", lncurses_halfdelay},
    // Moving
    {"move", lncurses_move},
    // Size
    {"getmaxyx", lncurses_getmaxyx},
    // Input
    {"getstr", lncurses_getstr},
    {"getch", lncurses_getch},
    {"wgetch", lncurses_wgetch},
    {"mvgetch", lncurses_mvgetch},
    {"mvwgetch", lncurses_mvwgetch},
    // Attributes
    {"attron", lncurses_attron},
    {"attroff", lncurses_attroff},
    {"attrset", lncurses_attrset},
    {"standend", lncurses_standend},
    // Windows
    {"newwin", lncurses_newwin},
    {"delwin", lncurses_delwin},
    {"box", lncurses_box},
    {"wrefresh", lncurses_wrefresh},
    // Color
    {"has_colors", lncurses_has_colors},
    {"start_color", lncurses_start_color},
    {"init_pair", lncurses_init_pair},
    {"COLOR_PAIR", lncurses_COLOR_PAIR},
    {"color_content", lncurses_color_content},
    {"pair_content", lncurses_pair_content},
    {"init_color", lncurses_init_color},
    {"can_change_color", lncurses_can_change_color},
    // Addch
    {"addch", lncurses_addch},
    {"waddch", lncurses_waddch},
    {"mvaddch", lncurses_mvaddch},
    {"mvwaddch", lncurses_mvwaddch},
    {NULL, NULL}
};

static void defineAttributes(lua_State* L){
    lua_pushinteger(L, A_NORMAL);
    lua_setfield(L, -2, "A_NORMAL");

    lua_pushinteger(L, A_STANDOUT);
    lua_setfield(L, -2, "A_STANDOUT");

    lua_pushinteger(L, A_UNDERLINE);
    lua_setfield(L, -2, "A_UNDERLINE");

    lua_pushinteger(L, A_REVERSE);
    lua_setfield(L, -2, "A_REVERSE");

    lua_pushinteger(L, A_BLINK);
    lua_setfield(L, -2, "A_BLINK");

    lua_pushinteger(L, A_DIM);
    lua_setfield(L, -2, "A_DIM");

    lua_pushinteger(L, A_BOLD);
    lua_setfield(L, -2, "A_BOLD");

    lua_pushinteger(L, A_PROTECT);
    lua_setfield(L, -2, "A_PROTECT");

    lua_pushinteger(L, A_INVIS);
    lua_setfield(L, -2, "A_INVIS");

    lua_pushinteger(L, A_ALTCHARSET);
    lua_setfield(L, -2, "A_ALTCHARSET");

    lua_pushinteger(L, A_CHARTEXT);
    lua_setfield(L, -2, "A_CHARTEXT");
}

static void defineColors(lua_State* L){
    lua_pushinteger(L, COLOR_BLACK);
    lua_setfield(L, -2, "COLOR_BLACK");

    lua_pushinteger(L, COLOR_WHITE);
    lua_setfield(L, -2, "COLOR_WHITE");

    lua_pushinteger(L, COLOR_BLUE);
    lua_setfield(L, -2, "COLOR_BLUE");

    lua_pushinteger(L, COLOR_CYAN);
    lua_setfield(L, -2, "COLOR_CYAN");

    lua_pushinteger(L, COLOR_GREEN);
    lua_setfield(L, -2, "COLOR_GREEN");

}

// Driver function
LUALIB_API int luaopen_liblncurses(lua_State* L){
    luaL_newlib(L, lncurseslib);

    // This will start off as NULL
    lua_pushlightuserdata(L, stdscr);
    lua_setfield(L, -2, "stdscr");

    defineAttributes(L);
    defineColors(L);

    lua_pushstring(L, VERSION);
    lua_setglobal(L, "_LNCURSES_VERSION");

    // This makes a way to reference the library again in the Lua registry
    lua_pushvalue(L, -1);
    lua_setfield(L, LUA_REGISTRYINDEX, "lncurses");

    // ensure defaults
    echo();

    return 1;
}
