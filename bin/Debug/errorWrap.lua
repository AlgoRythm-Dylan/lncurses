lncurses = require("liblncurses");

function errorWrap(func)
	success, msg = pcall(func);
	if not success then
		lncurses.endwin(); -- Cleanup
		return success, msg;
	end
	return success;
end
