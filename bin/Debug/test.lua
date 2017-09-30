lncurses = require("liblncurses");

lncurses.initscr(); -- Init the screen
lncurses.addstr("Hello"); -- Say something
lncurses.addstr("world");
lncurses.refresh(); -- Display the message
lncurses.getch();
lncurses.endwin();  -- Exit curses mode
print("Version: ".._LNCURSES_VERSION); -- Print the version

print("If there aren't any errors at this point, maybe it worked");
