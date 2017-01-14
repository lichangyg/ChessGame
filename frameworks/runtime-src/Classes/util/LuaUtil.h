#ifndef LUA_UTIL_H__
#define LUA_UTIL_H__
#include <iostream>
#include <vector>
#include "CCLuaEngine.h"

#define ERROR_RETURN_INT		 -1


class LuaUtil
{
public:
	LuaUtil();
	virtual ~LuaUtil();

	static std::vector<std::string> getLuaStringVector(const char *luaFile, const char *luaFunc, const char *paramType = NULL,...);

	static std::vector<int> getLuaIntVector(const char *luaFile, const char *luaFunc, const char *paramType= NULL,...);

	static std::vector<double> getLuafloatVector(const char *luaFile, const char *luaFunc, const char *paramType= NULL,...);

	static int getLuaInt(const char *luaFile, const char *luaFunc, const char *paramType = NULL,...);

	static bool getLuaBool(const char *luaFile, const char *luaFunc, const char *paramType= NULL,...);

	static const char * getLuapChar(const char *luaFile, const char *luaFunc, const char *paramType= NULL,...);

	static double getLuaDouble(const char *luaFile, const char *luaFunc, const char *paramType= NULL,...);

private:
	static void handlerParamType(lua_State *L, const char *paramType,va_list params);
};


#endif