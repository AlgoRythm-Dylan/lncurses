lncurses = require("liblncurses");
require("errorWrap");
bit = require("bit");

function run()
	lncurses.initscr()
	lncurses.keypad(lncurses.stdscr, true);
	lncurses.attron(bit.bor(lncurses.A_BOLD, lncurses.A_REVERSE));
	lncurses.move(5, 5);
	--rows, colunmns = lncurses.getmaxyx(lncurses.stdscr);
	--lncurses.addstr(tostring(rows));
	msg = "Message: "..lncurses.getstr();
	lncurses.endwin();
	print(msg);
	--print(char);
end

success, msg = pcall(run);
if not success then
	print("== FAILURE ==");
	print(msg);
end

print("If there aren't any errors at this point, maybe it worked");
