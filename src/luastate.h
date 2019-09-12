#ifndef luastate_h
#define luastate_h 

#include "luaobject.h"

#define LUA_EXTRASPACE sizeof(void*) 
#define G(L) ((L)->l_G)

typedef TValue* StkId;

struct CallInfo {
    StkId               func;                   // function index in the stack
    StkId               top;                    // top for this function
    int                 nresult;                // expected number of results from this function
    int                 callstatus;
    struct CallInfo*    next;
    struct CallInfo*    previous;
};

typedef struct lua_State {
    StkId                   stack;              // stack base 
    StkId                   stack_last;         // last free slot in the stack 
    StkId                   top;                // first free slot in the stack 
    int                     stack_size;         // stack size
    struct lua_longjmp*     errorjmp;           // current error recover point
    int                     status;
    struct lua_State*       next;
    struct lua_State*       previous;
    struct CallInfo         base_ci;            // base call info
    struct CallInfo*        ci;                 // call info for current function 
    struct global_State*    l_G;                // global state
    ptrdiff_t               errorfunc;          // current error handling function (stack index)
    int                     ncalls;             // number of nested C calls
} lua_State;

typedef struct global_State {
    struct lua_State*       mainthread;
    lua_Alloc               frealloc;           // function to reallocate memory
    void*                   ud;                 // auxiliary data to 'frealloc'
    lua_CFunction           panic;              // to be called in unprotected errors
} global_State;

struct lua_State* lua_newstate(lua_Alloc alloc, void* ud);
void lua_close(lua_State* L);

void setivalue(StkId target, int integer);
void setfvalue(StkId target, lua_CFunction f);
void setfltvalue(StkId target, float number);
void setbvalue(StkId target, bool b);
void setnilvalue(StkId target);
void setpvalue(StkId target, void* p);

void setobj(StkId target, StkId value);

void increase_top(lua_State* L);
void lua_pushcfunction(lua_State* L, lua_CFunction f);
void lua_pushinteger(lua_State* L, int integer);
void lua_pushnumber(lua_State* L, float number);
void lua_pushboolean(lua_State* L, bool b);
void lua_pushnil(lua_State* L);
void lua_pushlightuserdata(lua_State* L, void* p);

lua_Integer  lua_tointegerx(lua_State* L, int idx, int* isnum);
lua_Number   lua_tonumberx(lua_State* L, int idx, int* isnum);
bool         lua_toboolean(lua_State* L, int idx);
int          lua_isnil(lua_State* L, int idx);

void    lua_settop(lua_State* L, int idx);
int     lua_gettop(lua_State* L);
void    lua_pop(lua_State* L);

#endif 
