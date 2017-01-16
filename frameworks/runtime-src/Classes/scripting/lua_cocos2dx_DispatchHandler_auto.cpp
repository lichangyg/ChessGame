#include "lua_cocos2dx_DispatchHandler_auto.hpp"
#include "util/DispatchHandler.h"
#include "tolua_fix.h"
#include "LuaBasicConversions.h"



int lua_DispatchHandler_DispatchHandler_update(lua_State* tolua_S)
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
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_DispatchHandler_DispatchHandler_update'", nullptr);
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
            tolua_error(tolua_S,"invalid arguments in function 'lua_DispatchHandler_DispatchHandler_update'", nullptr);
            return 0;
        }
        cobj->update(arg0);
        return 0;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "DispatchHandler:update",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_DispatchHandler_DispatchHandler_update'.",&tolua_err);
#endif

    return 0;
}
int lua_DispatchHandler_DispatchHandler_removeDispatchHandler(lua_State* tolua_S)
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
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_DispatchHandler_DispatchHandler_removeDispatchHandler'", nullptr);
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
    tolua_error(tolua_S,"#ferror in function 'lua_DispatchHandler_DispatchHandler_removeDispatchHandler'.",&tolua_err);
#endif

    return 0;
}
int lua_DispatchHandler_DispatchHandler_addDispatchHandlerByData(lua_State* tolua_S)
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
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_DispatchHandler_DispatchHandler_addDispatchHandlerByData'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        int arg0;
        const DispatchData* arg1;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "DispatchHandler:addDispatchHandlerByData");

        #pragma warning NO CONVERSION TO NATIVE FOR DispatchData*
		ok = false;
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_DispatchHandler_DispatchHandler_addDispatchHandlerByData'", nullptr);
            return 0;
        }
        int ret = cobj->addDispatchHandlerByData(arg0, arg1);
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "DispatchHandler:addDispatchHandlerByData",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_DispatchHandler_DispatchHandler_addDispatchHandlerByData'.",&tolua_err);
#endif

    return 0;
}
int lua_DispatchHandler_DispatchHandler_addDispatchHandler(lua_State* tolua_S)
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
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_DispatchHandler_DispatchHandler_addDispatchHandler'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        int arg0;
        std::function<void (int, void *, unsigned int)> arg1;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "DispatchHandler:addDispatchHandler");

        do {
			// Lambda binding for lua is not supported.
			assert(false);
		} while(0)
		;
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_DispatchHandler_DispatchHandler_addDispatchHandler'", nullptr);
            return 0;
        }
        int ret = cobj->addDispatchHandler(arg0, arg1);
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "DispatchHandler:addDispatchHandler",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_DispatchHandler_DispatchHandler_addDispatchHandler'.",&tolua_err);
#endif

    return 0;
}
int lua_DispatchHandler_DispatchHandler_postDispatchHandler(lua_State* tolua_S)
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
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_DispatchHandler_DispatchHandler_postDispatchHandler'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 3) 
    {
        int arg0;
        void* arg1;
        unsigned int arg2;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "DispatchHandler:postDispatchHandler");

        #pragma warning NO CONVERSION TO NATIVE FOR void*
		ok = false;

        ok &= luaval_to_uint32(tolua_S, 4,&arg2, "DispatchHandler:postDispatchHandler");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_DispatchHandler_DispatchHandler_postDispatchHandler'", nullptr);
            return 0;
        }
        cobj->postDispatchHandler(arg0, arg1, arg2);
        return 0;
    }
    if (argc == 4) 
    {
        int arg0;
        void* arg1;
        unsigned int arg2;
        std::function<void ()> arg3;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "DispatchHandler:postDispatchHandler");

        #pragma warning NO CONVERSION TO NATIVE FOR void*
		ok = false;

        ok &= luaval_to_uint32(tolua_S, 4,&arg2, "DispatchHandler:postDispatchHandler");

        do {
			// Lambda binding for lua is not supported.
			assert(false);
		} while(0)
		;
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_DispatchHandler_DispatchHandler_postDispatchHandler'", nullptr);
            return 0;
        }
        cobj->postDispatchHandler(arg0, arg1, arg2, arg3);
        return 0;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "DispatchHandler:postDispatchHandler",argc, 3);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_DispatchHandler_DispatchHandler_postDispatchHandler'.",&tolua_err);
#endif

    return 0;
}
int lua_DispatchHandler_DispatchHandler_getInstance(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"DispatchHandler",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_DispatchHandler_DispatchHandler_getInstance'", nullptr);
            return 0;
        }
        DispatchHandler* ret = DispatchHandler::getInstance();
        object_to_luaval<DispatchHandler>(tolua_S, "DispatchHandler",(DispatchHandler*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "DispatchHandler:getInstance",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_DispatchHandler_DispatchHandler_getInstance'.",&tolua_err);
#endif
    return 0;
}
int lua_DispatchHandler_DispatchHandler_constructor(lua_State* tolua_S)
{
    int argc = 0;
    DispatchHandler* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_DispatchHandler_DispatchHandler_constructor'", nullptr);
            return 0;
        }
        cobj = new DispatchHandler();
        tolua_pushusertype(tolua_S,(void*)cobj,"DispatchHandler");
        tolua_register_gc(tolua_S,lua_gettop(tolua_S));
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "DispatchHandler:DispatchHandler",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_DispatchHandler_DispatchHandler_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_DispatchHandler_DispatchHandler_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (DispatchHandler)");
    return 0;
}

int lua_register_DispatchHandler_DispatchHandler(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"DispatchHandler");
    tolua_cclass(tolua_S,"DispatchHandler","DispatchHandler","",nullptr);

    tolua_beginmodule(tolua_S,"DispatchHandler");
        tolua_function(tolua_S,"new",lua_DispatchHandler_DispatchHandler_constructor);
        tolua_function(tolua_S,"update",lua_DispatchHandler_DispatchHandler_update);
        tolua_function(tolua_S,"removeDispatchHandler",lua_DispatchHandler_DispatchHandler_removeDispatchHandler);
        tolua_function(tolua_S,"addDispatchHandlerByData",lua_DispatchHandler_DispatchHandler_addDispatchHandlerByData);
        tolua_function(tolua_S,"addDispatchHandler",lua_DispatchHandler_DispatchHandler_addDispatchHandler);
        tolua_function(tolua_S,"postDispatchHandler",lua_DispatchHandler_DispatchHandler_postDispatchHandler);
        tolua_function(tolua_S,"getInstance", lua_DispatchHandler_DispatchHandler_getInstance);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(DispatchHandler).name();
    g_luaType[typeName] = "DispatchHandler";
    g_typeCast["DispatchHandler"] = "DispatchHandler";
    return 1;
}
TOLUA_API int register_all_DispatchHandler(lua_State* tolua_S)
{
	tolua_open(tolua_S);
	
	tolua_module(tolua_S,"lcy",0);
	tolua_beginmodule(tolua_S,"lcy");

	lua_register_DispatchHandler_DispatchHandler(tolua_S);

	tolua_endmodule(tolua_S);
	return 1;
}

