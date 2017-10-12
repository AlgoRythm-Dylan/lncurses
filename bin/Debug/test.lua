lncurses = require("liblncurses");
require("errorWrap");

function run()
	lncurses.initscr()
	lncurses.keypad(lncurses.stdscr, true);
	lncurses.move(10, 3);
	rows, colunmns = lncurses.getmaxyx(lncurses.stdscr);
	--lncurses.addstr(tostring(rows));
	msg = "Message: "..lncurses.getstr();
	lncurses.endwin();
	print(msg);
	--print(char);
end

--print("Fail: "..tostring(errorWrap(run)));
run();

print("If there aren't any errors at this point, maybe it worked");
