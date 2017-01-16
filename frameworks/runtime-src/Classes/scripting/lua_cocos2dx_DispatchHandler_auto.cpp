#include "lua_cocos2dx_DispatchHandler_auto.hpp"
#include "util/DispatchHandler.h"
#include "tolua_fix.h"
#include "LuaBasicConversions.h"


TOLUA_API int register_all_DispatchHandler(lua_State* tolua_S)
{
	tolua_open(tolua_S);
	
	tolua_module(tolua_S,nullptr,0);
	tolua_beginmodule(tolua_S,nullptr);


	tolua_endmodule(tolua_S);
	return 1;
}

