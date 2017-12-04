#include <ncurses.h>
#include <lua5.2/lualib.h>
#include "lncurses_definitions.h"

/*
** Bind the keys
*/
void defineKeys(lua_State* L){

    lua_pushinteger(L, KEY_A1);
    lua_setfield(L, -2, "KEY_A1");

    lua_pushinteger(L, KEY_A3);
    lua_setfield(L, -2, "KEY_A3");

    lua_pushinteger(L, KEY_B2);
    lua_setfield(L, -2, "KEY_B2");

    lua_pushinteger(L, KEY_BACKSPACE);
    lua_setfield(L, -2, "KEY_BACKSPACE");

    lua_pushinteger(L, KEY_BEG);
    lua_setfield(L, -2, "KEY_BEG");

    lua_pushinteger(L, KEY_BREAK);
    lua_setfield(L, -2, "KEY_BREAK");

    lua_pushinteger(L, KEY_BTAB);
    lua_setfield(L, -2, "KEY_BTAB");

    lua_pushinteger(L, KEY_C1);
    lua_setfield(L, -2, "KEY_C1");

    lua_pushinteger(L, KEY_C3);
    lua_setfield(L, -2, "KEY_C3");

    lua_pushinteger(L, KEY_CANCEL);
    lua_setfield(L, -2, "KEY_CANCEL");

    lua_pushinteger(L, KEY_CATAB);
    lua_setfield(L, -2, "KEY_CATAB");

    lua_pushinteger(L, KEY_CLEAR);
    lua_setfield(L, -2, "KEY_CLEAR");

    lua_pushinteger(L, KEY_CLOSE);
    lua_setfield(L, -2, "KEY_CLOSE");

    lua_pushinteger(L, KEY_CODE_YES);
    lua_setfield(L, -2, "KEY_CODE_YES");

    lua_pushinteger(L, KEY_COMMAND);
    lua_setfield(L, -2, "KEY_COMMAND");

    lua_pushinteger(L, KEY_COPY);
    lua_setfield(L, -2, "KEY_COPY");

    lua_pushinteger(L, KEY_CREATE);
    lua_setfield(L, -2, "KEY_CREATE");

    lua_pushinteger(L, KEY_CTAB);
    lua_setfield(L, -2, "KEY_CTAB");

    lua_pushinteger(L, KEY_DC);
    lua_setfield(L, -2, "KEY_DC");

    lua_pushinteger(L, KEY_DL);
    lua_setfield(L, -2, "KEY_DL");

    lua_pushinteger(L, KEY_DOWN);
    lua_setfield(L, -2, "KEY_DOWN");

    lua_pushinteger(L, KEY_EIC);
    lua_setfield(L, -2, "KEY_EIC");

    lua_pushinteger(L, KEY_END);
    lua_setfield(L, -2, "KEY_END");

    lua_pushinteger(L, KEY_ENTER);
    lua_setfield(L, -2, "KEY_ENTER");

    lua_pushinteger(L, KEY_EOL);
    lua_setfield(L, -2, "KEY_EOL");

    lua_pushinteger(L, KEY_EOS);
    lua_setfield(L, -2, "KEY_EOS");

    lua_pushinteger(L, KEY_EVENT);
    lua_setfield(L, -2, "KEY_EVENT");

    lua_pushinteger(L, KEY_EXIT);
    lua_setfield(L, -2, "KEY_EXIT");

    lua_pushinteger(L, KEY_F0);
    lua_setfield(L, -2, "KEY_F0");

    lua_pushinteger(L, KEY_FIND);
    lua_setfield(L, -2, "KEY_FIND");

    lua_pushinteger(L, KEY_HELP);
    lua_setfield(L, -2, "KEY_HELP");

    lua_pushinteger(L, KEY_HOME);
    lua_setfield(L, -2, "KEY_HOME");

    lua_pushinteger(L, KEY_IC);
    lua_setfield(L, -2, "KEY_IC");

    lua_pushinteger(L, KEY_IL);
    lua_setfield(L, -2, "KEY_IL");

    lua_pushinteger(L, KEY_LEFT);
    lua_setfield(L, -2, "KEY_LEFT");

    lua_pushinteger(L, KEY_LL);
    lua_setfield(L, -2, "KEY_LL");

    lua_pushinteger(L, KEY_MARK);
    lua_setfield(L, -2, "KEY_MARK");

    lua_pushinteger(L, KEY_MAX);
    lua_setfield(L, -2, "KEY_MAX");

    lua_pushinteger(L, KEY_MESSAGE);
    lua_setfield(L, -2, "KEY_MESSAGE");

    lua_pushinteger(L, KEY_MIN);
    lua_setfield(L, -2, "KEY_MIN");

    lua_pushinteger(L, KEY_MOUSE);
    lua_setfield(L, -2, "KEY_MOUSE");

    lua_pushinteger(L, KEY_MOVE);
    lua_setfield(L, -2, "KEY_MOVE");

    lua_pushinteger(L, KEY_NEXT);
    lua_setfield(L, -2, "KEY_NEXT");

    lua_pushinteger(L, KEY_NPAGE);
    lua_setfield(L, -2, "KEY_NPAGE");

    lua_pushinteger(L, KEY_OPEN);
    lua_setfield(L, -2, "KEY_OPEN");

    lua_pushinteger(L, KEY_OPTIONS);
    lua_setfield(L, -2, "KEY_OPTIONS");

    lua_pushinteger(L, KEY_PPAGE);
    lua_setfield(L, -2, "KEY_PPAGE");

    lua_pushinteger(L, KEY_PREVIOUS);
    lua_setfield(L, -2, "KEY_PREVIOUS");

    lua_pushinteger(L, KEY_PRINT);
    lua_setfield(L, -2, "KEY_PRINT");

    lua_pushinteger(L, KEY_REDO);
    lua_setfield(L, -2, "KEY_REDO");

    lua_pushinteger(L, KEY_REFERENCE);
    lua_setfield(L, -2, "KEY_REFERENCE");

    lua_pushinteger(L, KEY_REFRESH);
    lua_setfield(L, -2, "KEY_REFRESH");

    lua_pushinteger(L, KEY_REPLACE);
    lua_setfield(L, -2, "KEY_REPLACE");

    lua_pushinteger(L, KEY_RESET);
    lua_setfield(L, -2, "KEY_RESET");

    lua_pushinteger(L, KEY_RESIZE);
    lua_setfield(L, -2, "KEY_RESIZE");

    lua_pushinteger(L, KEY_RESTART);
    lua_setfield(L, -2, "KEY_RESTART");

    lua_pushinteger(L, KEY_RESUME);
    lua_setfield(L, -2, "KEY_RESUME");

    lua_pushinteger(L, KEY_RIGHT);
    lua_setfield(L, -2, "KEY_RIGHT");

    lua_pushinteger(L, KEY_SAVE);
    lua_setfield(L, -2, "KEY_SAVE");

    lua_pushinteger(L, KEY_SBEG);
    lua_setfield(L, -2, "KEY_SBEG");

    lua_pushinteger(L, KEY_SCANCEL);
    lua_setfield(L, -2, "KEY_SCANCEL");

    lua_pushinteger(L, KEY_SCOMMAND);
    lua_setfield(L, -2, "KEY_SCOMMAND");

    lua_pushinteger(L, KEY_SCOPY);
    lua_setfield(L, -2, "KEY_SCOPY");

    lua_pushinteger(L, KEY_SCREATE);
    lua_setfield(L, -2, "KEY_SCREATE");

    lua_pushinteger(L, KEY_SDC);
    lua_setfield(L, -2, "KEY_SDC");

    lua_pushinteger(L, KEY_SDL);
    lua_setfield(L, -2, "KEY_SDL");

    lua_pushinteger(L, KEY_SELECT);
    lua_setfield(L, -2, "KEY_SELECT");

    lua_pushinteger(L, KEY_SEND);
    lua_setfield(L, -2, "KEY_SEND");

    lua_pushinteger(L, KEY_SEOL);
    lua_setfield(L, -2, "KEY_SEOL");

    lua_pushinteger(L, KEY_SEXIT);
    lua_setfield(L, -2, "KEY_SEXIT");

    lua_pushinteger(L, KEY_SF);
    lua_setfield(L, -2, "KEY_SF");

    lua_pushinteger(L, KEY_SFIND);
    lua_setfield(L, -2, "KEY_SFIND");

    lua_pushinteger(L, KEY_SHELP);
    lua_setfield(L, -2, "KEY_SHELP");

    lua_pushinteger(L, KEY_SHOME);
    lua_setfield(L, -2, "KEY_SHOME");

    lua_pushinteger(L, KEY_SIC);
    lua_setfield(L, -2, "KEY_SIC");

    lua_pushinteger(L, KEY_SLEFT);
    lua_setfield(L, -2, "KEY_SLEFT");

    lua_pushinteger(L, KEY_SMESSAGE);
    lua_setfield(L, -2, "KEY_MESSAGE");

    lua_pushinteger(L, KEY_SMOVE);
    lua_setfield(L, -2, "KEY_SMOVE");

    lua_pushinteger(L, KEY_SNEXT);
    lua_setfield(L, -2, "KEY_SNEXT");

    lua_pushinteger(L, KEY_SOPTIONS);
    lua_setfield(L, -2, "KEY_SOPTIONS");

    lua_pushinteger(L, KEY_SPREVIOUS);
    lua_setfield(L, -2, "KEY_SPREVIOUS");

    lua_pushinteger(L, KEY_SPRINT);
    lua_setfield(L, -2, "KEY_SPRINT");

    lua_pushinteger(L, KEY_SR);
    lua_setfield(L, -2, "KEY_SR");

    lua_pushinteger(L, KEY_SREDO);
    lua_setfield(L, -2, "KEY_SREDO");

    lua_pushinteger(L, KEY_SREPLACE);
    lua_setfield(L, -2, "KEY_SREPLACE");

    lua_pushinteger(L, KEY_SRESET);
    lua_setfield(L, -2, "KEY_SRESET");

    lua_pushinteger(L, KEY_SRIGHT);
    lua_setfield(L, -2, "KEY_SRIGHT");

    lua_pushinteger(L, KEY_SSAVE);
    lua_setfield(L, -2, "KEY_SSAVE");

    lua_pushinteger(L, KEY_SSUSPEND);
    lua_setfield(L, -2, "KEY_SSUSPEND");

    lua_pushinteger(L, KEY_STAB);
    lua_setfield(L, -2, "KEY_STAB");

    lua_pushinteger(L, KEY_SUNDO);
    lua_setfield(L, -2, "KEY_SUNDO");

    lua_pushinteger(L, KEY_SUSPEND);
    lua_setfield(L, -2, "KEY_SUSPEND");

}

/*
** Bind the attributes
*/
void defineAttributes(lua_State* L)
{

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

/*
** Bind the colors
*/
void defineColors(lua_State* L)
{

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
