#ifndef luado_h
#define luado_h 

#include "luastate.h"

typedef int (*Pfunc)(lua_State* L, void* ud);

void    seterrobj(lua_State* L, int error);
void    luaD_checkstack(lua_State* L, int need);
void    luaD_growstack(lua_State* L, int size);
void    luaD_throw(lua_State* L, int error);

int     luaD_rawrunprotected(lua_State* L, Pfunc f, void* ud);
int     luaD_precall(lua_State* L, StkId func, int nresult);
int     luaD_poscall(lua_State* L, StkId first_result, int nresult);
int     luaD_call(lua_State* L, StkId func, int nresult);
int     luaD_pcall(lua_State* L, Pfunc f, void* ud, ptrdiff_t oldtop, ptrdiff_t ef);

#endif 
