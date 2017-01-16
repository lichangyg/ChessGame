#include "lua_cocos2dx_DispatchHandler_auto.hpp"
#include "DispatchHandler.h"
#include "tolua_fix.h"
#include "LuaBasicConversions.h"



int lua__DispatchHandler_removeDispatchHandler(lua_State* tolua_S)
{
    int argc = 0;
    DispatchHandler* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"DispatchHandler",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (DispatchHandler*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua__DispatchHandler_removeDispatchHandler'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 2) {
            int arg0;
            ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "DispatchHandler:removeDispatchHandler");

            if (!ok) { break; }
            int arg1;
            ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1, "DispatchHandler:removeDispatchHandler");

            if (!ok) { break; }
            cobj->removeDispatchHandler(arg0, arg1);
            return 0;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 1) {
            int arg0;
            ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "DispatchHandler:removeDispatchHandler");

            if (!ok) { break; }
            cobj->removeDispatchHandler(arg0);
            return 0;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "DispatchHandler:removeDispatchHandler",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua__DispatchHandler_removeDispatchHandler'.",&tolua_err);
#endif

    return 0;
}
int lua__DispatchHandler_update(lua_State* tolua_S)
{
    int argc = 0;
    DispatchHandler* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"DispatchHandler",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (DispatchHandler*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua__DispatchHandler_update'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        double arg0;

        ok &= luaval_to_number(tolua_S, 2,&arg0, "DispatchHandler:update");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua__DispatchHandler_update'", nullptr);
            return 0;
        }
        cobj->update(arg0);
        return 0;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "DispatchHandler:update",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua__DispatchHandler_update'.",&tolua_err);
#endif

    return 0;
}
