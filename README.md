# lncurses
Lua ncurses bindings.


A couple quick notes about this project: I am trying to keep it as close
to ncurses as possible, so that someone with knowledge of ncurses can
download lncurses and get started. That being said, Lua is not c and I
cannot perfectly emulate ncurses in Lua.


This is a learning project for me. That means not only some questionable
code, but I also am not currently looking for any help. I'm not trying to
finish this project ASAP, I'm trying to learn everything I can about
ncurses and c (and the Lua API) by working on lncurses.


My main competition is lcurses. I very rarely read that code to see what
they did to solve certain issues, but in general, I am not incredibly
impressed, and you will not find any lcurses code in lncurses.


I am not planning on working with Windows compatibility. I am aware of
certain ways of using ncurses with Windows machines but that is not
something I want to worry about.


My end goal is to apply this some way. Of course, lncurses is fantastic by
itself, but I hope you don't expect me to bind all of ncurses to Lua and
not do something with it. My best idea right now is LuE, which will be a
Lua-based development environment very similar to emacs, with the power of
vim.


I am very open to criticism and suggestions, don't hesitate.
