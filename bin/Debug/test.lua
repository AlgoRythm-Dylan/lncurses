lncurses = require("liblncurses");
require("errorWrap");

function run()
	lncurses.initscr()
	lncurses.keypad(lncurses.stdscr, true);
	lncurses.move(10, 3);
	rows, colunmns = lncurses.getmaxyx(lncurses.stdscr);
	lncurses.addstr(tostring(rows));
	char = lncurses.getch();
	lncurses.endwin();
	print(char);
end

--print("Fail: "..tostring(errorWrap(run)));
run();

print("If there aren't any errors at this point, maybe it worked");
