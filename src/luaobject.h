#ifndef luaobject_h
#define luaobject_h 

#include "lua.h"

typedef struct lua_State lua_State;

typedef LUA_INTEGER     lua_Integer;
typedef LUA_NUMBER      lua_Number;
typedef unsigned char   lu_byte;

typedef int (*lua_CFunction) (lua_State* L);
typedef void* (*lua_Alloc) (void* ud, void* ptr, size_t osize, size_t nsize);

// lua number type 
#define LUA_NUMINT (LUA_TNUMBER | (0 << 4)) // int
#define LUA_NUMFLT (LUA_TNUMBER | (1 << 4)) // float

// lua function type 
#define LUA_TLCL (LUA_TFUNCTION | (0 << 4)) // lua func
#define LUA_TLCF (LUA_TFUNCTION | (1 << 4)) // lua_cfunc
#define LUA_TCCL (LUA_TFUNCTION | (2 << 4)) // 

// string type 
#define LUA_LNGSTR (LUA_TSTRING | (0 << 4))
#define LUA_SHRSTR (LUA_TSTRING | (1 << 4))


typedef union lua_Value {
    void* p;
    int b;
    lua_Integer i;
    lua_Number n;
    lua_CFunction f;
} Value;

typedef struct lua_TValue {
    Value value_;
    int tt_;
} TValue;

#endif 
