lncurses = require("liblncurses");

function errorWrap(func)
	if not pcall(func) then
		lncurses.endwin(); -- Clean up
	end
end
