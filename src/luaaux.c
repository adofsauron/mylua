#include "luaaux.h"
#include "luado.h"

static void* l_alloc(void* ud, void* ptr, size_t osize, size_t nsize) {
    (void)ud;
    (void)osize;

    if (nsize == 0) {
        free(ptr);
        return NULL;
    }

    return realloc(ptr, nsize);
}

lua_State* luaL_newstate() {
    lua_State* L = lua_newstate(&l_alloc, NULL);
    return L;
}

void luaL_close(lua_State* L) {
    lua_close(L);
}

void luaL_pushinteger(lua_State* L, lua_Integer integer) {
    lua_pushinteger(L, integer);
}

void luaL_pushnumber(lua_State* L, lua_Number number) {
    lua_pushnumber(L, number);
}

void luaL_pushlightuserdata(lua_State* L, void* userdata) {
    lua_pushlightuserdata(L, userdata);
}

void luaL_pushnil(lua_State* L) {
    lua_pushnil(L);
}

void luaL_pushcfunction(lua_State* L, lua_CFunction f) {
    lua_pushcfunction(L, f);
}

void luaL_pushboolean(lua_State* L, bool boolean) {
    lua_pushboolean(L, boolean);
}

// function call
typedef struct CallS {
    StkId func;
    int nresult;
} CallS;

static int f_call(lua_State* L, void* ud) {
    CallS* c = cast(CallS*, ud);
    return luaD_call(L, c->func, c->nresult);
}

int luaL_pcall(lua_State* L, int narg, int nresult) {
    CallS c;
    c.func = L->top - (narg + 1);
    c.nresult = nresult; 

    return luaD_pcall(L, &f_call, &c, savestack(L, L->top), 0);
}

bool luaL_checkinteger(lua_State* L, int idx) {
    int isnum = 0;
    lua_tointegerx(L, idx, &isnum);
    return isnum ? true : false;
}

lua_Integer luaL_tointeger(lua_State* L, int idx) {
    int isnum = 0;
    return lua_tointegerx(L, idx, &isnum);
}

lua_Number luaL_tonumber(lua_State* L, int idx) {
    int isnum = 0;
    return lua_tonumberx(L, idx, &isnum);
}

void* luaL_touserdata(lua_State* L, int idx) {
    // TODO
    return NULL;
}

bool luaL_toboolean(lua_State* L, int idx) {
    return lua_toboolean(L, idx);
}

int luaL_isnil(lua_State* L, int idx) {
    return lua_isnil(L, idx);
}

void luaL_pop(lua_State* L) {
    lua_pop(L); 
}

int luaL_stacksize(lua_State* L) {
    return lua_gettop(L);
}
