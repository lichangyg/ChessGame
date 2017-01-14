#include "LuaUtil.h"


USING_NS_CC;
LuaUtil::LuaUtil()
{

}

LuaUtil::~LuaUtil()
{
	
}

void LuaUtil::handlerParamType(lua_State *L, const char *paramType,va_list params)
{
	if (!paramType)
	{
		return ;
	}
	auto count = strlen(paramType);
	for (int i = 0; i < count; i++)
	{
		switch (paramType[i])
		{
		case 'i':
			{
				auto now = va_arg(params, int);
				lua_pushinteger(L, now);
			}
			break;
		case 's':
			{
				auto temp = va_arg(params, const char*);
				lua_pushstring(L, temp);
			}
			break;
		default:
			break;
		}
	}
}


std::vector<std::string> LuaUtil::getLuaStringVector(const char *luaFile, const char *luaFunc, const char *paramType,...)
{
	auto engine = LuaEngine::getInstance();
    lua_State* L = engine->getLuaStack()->getLuaState();
	if (!L)
	{
		return std::vector<std::string>();
	}

	// 调取函数入栈
	lua_getglobal(L,luaFunc);
	int count = 0;
	// 参数个数
	if (paramType)
	{
		va_list params;
		// 参数入栈
		va_start(params, paramType);
		handlerParamType(L,paramType,params);
		va_end(params);
		count = strlen(paramType);
	}
	int iRet = lua_pcall(L,count,2,0);
	if (iRet)
	{
		const char *pErrorMsg = lua_tostring(L,-1);
		std::cout << pErrorMsg << std::endl;
		lua_close(L);
		return std::vector<std::string>();
	}
	// 调用函数成功取值
	std::vector<std::string> ret;
	std::vector<double> re2t;
	
	if (lua_istable(L,-1))
	{
		auto tableCount = lua_tonumber(L,-2);
		for (int i = 1; i <= tableCount; i++)
		{
			lua_pushnumber(L,i);
			lua_gettable(L,-2);
			if (lua_isnumber(L,-1))
			{
				auto dd = lua_tonumber(L,-1);
				char buf[512]={0};
				sprintf_s(buf,"%f",dd);
				ret.push_back(buf);
			}
			else if(lua_isstring(L,-1))
			{
				auto tempValue = lua_tostring(L,-1);
				ret.push_back(tempValue);
			}

			lua_pop(L,1);
		}
		return ret;
	}
	return std::vector<std::string>();
}

std::vector<int> LuaUtil::getLuaIntVector(const char *luaFile, const char *luaFunc, const char *paramType,...)
{
		auto engine = LuaEngine::getInstance();
    lua_State* L = engine->getLuaStack()->getLuaState();
	if (!L)
	{
		return std::vector<int>();
	}

	// 调取函数入栈
	lua_getglobal(L,luaFunc);
	int count = 0;
	// 参数个数
	if (paramType)
	{
		va_list params;
		// 参数入栈
		va_start(params, paramType);
		handlerParamType(L,paramType,params);
		va_end(params);
		count = strlen(paramType);
	}
	int iRet = lua_pcall(L,count,2,0);
	if (iRet)
	{
		const char *pErrorMsg = lua_tostring(L,-1);
		std::cout << pErrorMsg << std::endl;
		lua_close(L);
		return std::vector<int>();
	}
	// 调用函数成功取值
	std::vector<int> ret;
	
	if (lua_istable(L,-1))
	{
		auto tableCount = lua_tonumber(L,-2);
		for (int i = 1; i <= tableCount; i++)
		{
			lua_pushnumber(L,i);
			lua_gettable(L,-2);
			if (lua_isnumber(L,-1))
			{
				auto dd = lua_tonumber(L,-1);
				ret.push_back((int)dd);
			}

			lua_pop(L,1);
		}
		return ret;
	}
	return std::vector<int>();
}

std::vector<double> LuaUtil::getLuafloatVector(const char *luaFile, const char *luaFunc, const char *paramType,...)
{
			auto engine = LuaEngine::getInstance();
    lua_State* L = engine->getLuaStack()->getLuaState();
	if (!L)
	{
		return std::vector<double>();
	}

	// 调取函数入栈
	lua_getglobal(L,luaFunc);
	int count = 0;
	// 参数个数
	if (paramType)
	{
		va_list params;
		// 参数入栈
		va_start(params, paramType);
		handlerParamType(L,paramType,params);
		va_end(params);
		count = strlen(paramType);
	}
	int iRet = lua_pcall(L,count,2,0);
	if (iRet)
	{
		const char *pErrorMsg = lua_tostring(L,-1);
		std::cout << pErrorMsg << std::endl;
		lua_close(L);
		return std::vector<double>();
	}
	// 调用函数成功取值
	std::vector<double> ret;
	
	if (lua_istable(L,-1))
	{
		auto tableCount = lua_tonumber(L,-2);
		for (int i = 1; i <= tableCount; i++)
		{
			lua_pushnumber(L,i);
			lua_gettable(L,-2);
			if (lua_isnumber(L,-1))
			{
				auto dd = lua_tonumber(L,-1);
				ret.push_back(dd);
			}

			lua_pop(L,1);
		}
		return ret;
	}
	return std::vector<double>();
}

int LuaUtil::getLuaInt(const char *luaFile, const char *luaFunc, const char *paramType,...)
{
	auto engine = LuaEngine::getInstance();
    lua_State* L = engine->getLuaStack()->getLuaState();
	if (!L)
	{
		return ERROR_RETURN_INT;
	}

	// 调取函数入栈
	lua_getglobal(L,luaFunc);

	int count = 0;
	// 参数个数
	if (paramType)
	{
		va_list params;
		// 参数入栈
		va_start(params, paramType);
		handlerParamType(L,paramType,params);
		va_end(params);
		count = strlen(paramType);
	}
	int iRet = lua_pcall(L,count,1,0);
	if (iRet)
	{
		const char *pErrorMsg = lua_tostring(L,-1);
		std::cout << pErrorMsg << std::endl;
		lua_close(L);
		return ERROR_RETURN_INT;
	}

	return lua_tonumber(L,-1);
}

bool LuaUtil::getLuaBool(const char *luaFile, const char *luaFunc, const char *paramType,...)
{
	auto engine = LuaEngine::getInstance();
    lua_State* L = engine->getLuaStack()->getLuaState();
	if (!L)
	{
		return false;
	}

	// 调取函数入栈
	lua_getglobal(L,luaFunc);

	int count = 0;
	// 参数个数
	if (paramType)
	{
		va_list params;
		// 参数入栈
		va_start(params, paramType);
		handlerParamType(L,paramType,params);
		va_end(params);
		count = strlen(paramType);
	}
	int iRet = lua_pcall(L,count,1,0);
	if (iRet)
	{
		const char *pErrorMsg = lua_tostring(L,-1);
		std::cout << pErrorMsg << std::endl;
		lua_close(L);
		return false;
	}

	return lua_toboolean(L,-1);
}

const char * LuaUtil::getLuapChar(const char *luaFile, const char *luaFunc, const char *paramType,...)
{
	auto engine = LuaEngine::getInstance();
    lua_State* L = engine->getLuaStack()->getLuaState();
	if (!L)
	{
		return NULL;
	}

	// 调取函数入栈
	lua_getglobal(L,luaFunc);
	int count = 0;
	// 参数个数
	if (paramType)
	{
		va_list params;
		// 参数入栈
		va_start(params, paramType);
		handlerParamType(L,paramType,params);
		va_end(params);
		count = strlen(paramType);
	}
	
	int iRet = lua_pcall(L,count,1,0);
	if (iRet)
	{
		const char *pErrorMsg = lua_tostring(L,-1);
		std::cout << pErrorMsg << std::endl;
		lua_close(L);
		return NULL;
	}

	return lua_tostring(L,-1);
}

double LuaUtil::getLuaDouble(const char *luaFile, const char *luaFunc, const char *paramType,...)
{
	auto engine = LuaEngine::getInstance();
    lua_State* L = engine->getLuaStack()->getLuaState();
	if (!L)
	{
		return 0.0f;
	}

	// 调取函数入栈
	lua_getglobal(L,luaFunc);

	int count = 0;
	// 参数个数
	if (paramType)
	{
		va_list params;
		// 参数入栈
		va_start(params, paramType);
		handlerParamType(L,paramType,params);
		va_end(params);
		count = strlen(paramType);
	}

	int iRet = lua_pcall(L,count,1,0);
	if (iRet)
	{
		const char *pErrorMsg = lua_tostring(L,-1);
		std::cout << pErrorMsg << std::endl;
		lua_close(L);
		return 0.0f;
	}

	auto luaData = lua_tostring(L,-1);
	return atof(luaData);
}