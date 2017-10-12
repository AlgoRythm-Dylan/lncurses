i = 0;
for _,__ in pairs(require("liblncurses")) do print(_..": "..type(__));i = i + 1; end
print("Total: "..tostring(i));
