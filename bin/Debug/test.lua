lncurses = require("liblncurses");
require("errorWrap");

function run()
	lncurses.initscr(); -- Init the screen
	lncurses.addstr("Hello"); -- Say something
	lncurses.addstr("world");
	lncurses.refresh(); -- Display the message
	char = lncurses.getch();
	lncurses.endwin();  -- Exit curses mode
	print(char);
	print("Version: ".._LNCURSES_VERSION); -- Print the version
end

errorWrap(run);

print("If there aren't any errors at this point, maybe it worked");
