#include "base/ccConfig.h"
#ifndef __DispatchHandler_h__
#define __DispatchHandler_h__

#ifdef __cplusplus
extern "C" {
#endif
#include "tolua++.h"
#ifdef __cplusplus
}
#endif

int register_all_DispatchHandler(lua_State* tolua_S);

#endif // __DispatchHandler_h__
