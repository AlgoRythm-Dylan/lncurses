#include <lua5.2/lualib.h>

#ifndef LNCURSES_DEFINITIONS
#define LNCURSES_DEFINITIONS

void defineKeys(lua_State*);
void defineAttributes(lua_State*);
void defineColors(lua_State*);

#endif // LNCURSES_DEFINITIONS
