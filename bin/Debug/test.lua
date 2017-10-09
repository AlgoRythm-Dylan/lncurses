lncurses = require("liblncurses");
require("errorWrap");

function run()
	lncurses.initscr()
	--lncurses.keypad(lncurses.stdscr, true);
	char = lncurses.getch();
	lncurses.endwin();
	print(char);
end

errorWrap(run);

print("If there aren't any errors at this point, maybe it worked");
