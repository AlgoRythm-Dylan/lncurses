lncurses = require("liblncurses");
require("errorWrap");
bit = require("bit");

function run()
	lncurses.initscr()
	lncurses.keypad(lncurses.stdscr, true);
	lncurses.start_color();
	lncurses.init_pair(1, lncurses.COLOR_BLACK, lncurses.COLOR_GREEN);
	lncurses.attron(lncurses.COLOR_PAIR(1));
	lncurses.addstr("COOL STUFF");
	lncurses.attroff(lncurses.COLOR_PAIR(1));
	key = lncurses.getch();
	lncurses.endwin();
	print(key);
end

success, msg = pcall(run);
if not success then
	print("== FAILURE ==");
	print(msg);
end

print("If there aren't any errors at this point, maybe it worked");
