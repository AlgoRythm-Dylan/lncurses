lncurses = require("liblncurses");

function errorWrap(func)
	if not pcall(func) then
		lncurses.endwin(); -- Clean up
		return false;
	end
	return true;
end
