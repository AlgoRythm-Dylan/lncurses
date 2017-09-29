lncurses = require("liblncurses")

lncurses.initscr(); -- Init the screen
lncurses.endwin();  -- Exit curses mode

print("If there aren't any errors at this point, maybe it worked");
