#include "AppDelegate.h"
#include "CCLuaEngine.h"
#include "SimpleAudioEngine.h"
#include "cocos2d.h"
#include "lua_module_register.h"
#include "util\LuaUtil.h"
#include "util\DispatchHandler.h"
#include "net\NetWork.h"

using namespace CocosDenshion;

USING_NS_CC;
using namespace std;

void dispatch(int cmd, void *data, size_t lenght)
{
	int a = 10;
}

AppDelegate::AppDelegate()
{

}

AppDelegate::~AppDelegate()
{
    SimpleAudioEngine::end();
}

//if you want a different context,just modify the value of glContextAttrs
//it will takes effect on all platforms
void AppDelegate::initGLContextAttrs()
{
    //set OpenGL context attributions,now can only set six attributions:
    //red,green,blue,alpha,depth,stencil
    GLContextAttrs glContextAttrs = {8, 8, 8, 8, 24, 8};

    GLView::setGLContextAttrs(glContextAttrs);
}

bool AppDelegate::applicationDidFinishLaunching()
{
    auto engine = LuaEngine::getInstance();
    ScriptEngineManager::getInstance()->setScriptEngine(engine);
    lua_State* L = engine->getLuaStack()->getLuaState();
    lua_module_register(L);

    // If you want to use Quick-Cocos2d-X, please uncomment below code
     //register_all_quick_manual(L);
	engine->addSearchPath("src");
	engine->getLuaStack()->reload("config");
	engine->getLuaStack()->reload("net/socketHandler");
	engine->getLuaStack()->reload(DISPATCHHANDLER_LUA_FILE_NAME);
	// 读取登录服务器IP
	auto ip = LuaUtil::getLuapChar("config","getLoginSerVerIp");
	
	// 读取登录服务器端口
	auto port = LuaUtil::getLuaInt("config","getPort");

	auto homeKeyCode = LuaUtil::getLuaInt(DISPATCHHANDLER_LUA_FILE_NAME,"getHomeKeyValueResume");
	gDispatchhandler->addDispatchHandler(homeKeyCode,dispatch);

	gNetWork->connection(ip,port);
    if (engine->executeScriptFile("src/main.lua")) {
        return false;
    }
	
    return true;
}

// This function will be called when the app is inactive. When comes a phone call,it's be invoked too
void AppDelegate::applicationDidEnterBackground()
{
    Director::getInstance()->stopAnimation();
	// 加入消息通知退到后台100
	auto homeKeyCode = LuaUtil::getLuaInt(DISPATCHHANDLER_LUA_FILE_NAME,"getHomeKeyValue");
	gDispatchhandler->postDispatchHandler(homeKeyCode,NULL,0);
    SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
}

// this function will be called when the app is active again
void AppDelegate::applicationWillEnterForeground()
{
    Director::getInstance()->startAnimation();
    SimpleAudioEngine::getInstance()->resumeBackgroundMusic();
	// 加入消息通知返回游戏101
	auto homeKeyCodeResume = LuaUtil::getLuaInt(DISPATCHHANDLER_LUA_FILE_NAME,"getHomeKeyValueResume");
	gDispatchhandler->postDispatchHandler(homeKeyCodeResume,NULL,0);
}
