-- 登录服务器IP
local LOGIN_SERVER_IP = "127.0.0.1"
-- 游戏服务器IP
local LOGIN_GAME_SERVER_IP	= "127.0.0.1"
-- home键退到后台 
local KEY_HOME_PAUSE  = 	100

-- home键回到游戏中
local KEY_HOME_RESUME = 	101

-- 端口号
local GAME_PORT		= 6600

function getLoginSerVerIp()
    return LOGIN_SERVER_IP
end

function getGameServerIP()
    return LOGIN_GAME_SERVER_IP
end

function getPort()
	return GAME_PORT
end

function gettable()
	local dd = {1,3,5,8,7}
	return #dd, dd
end