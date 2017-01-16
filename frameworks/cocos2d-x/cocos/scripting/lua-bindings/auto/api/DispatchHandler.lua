
--------------------------------
-- @module DispatchHandler
-- @parent_module lcy

--------------------------------
-- 
-- @function [parent=#DispatchHandler] update 
-- @param self
-- @param #float dt
        
--------------------------------
-- @overload self, int, int         
-- @overload self, int         
-- @function [parent=#DispatchHandler] removeDispatchHandler
-- @param self
-- @param #int cmd
-- @param #int order

--------------------------------
-- 
-- @function [parent=#DispatchHandler] addDispatchHandlerByData 
-- @param self
-- @param #int cmd
-- @param #DispatchData dispatch
-- @return int#int ret (return value: int)
        
--------------------------------
-- 
-- @function [parent=#DispatchHandler] addDispatchHandler 
-- @param self
-- @param #int cmd
-- @param #function dispatch
-- @return int#int ret (return value: int)
        
--------------------------------
-- 
-- @function [parent=#DispatchHandler] postDispatchHandler 
-- @param self
-- @param #int cmd
-- @param #void data
-- @param #unsigned int lenght
-- @param #function endCallBack
        
--------------------------------
-- 
-- @function [parent=#DispatchHandler] getInstance 
-- @param self
-- @return DispatchHandler#DispatchHandler ret (return value: DispatchHandler)
        
--------------------------------
-- 
-- @function [parent=#DispatchHandler] DispatchHandler 
-- @param self
        
return nil
