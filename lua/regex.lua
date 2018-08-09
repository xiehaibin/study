
--[[
local str = "Ted:13600-919-08176"
local a, b = 1, 0

while true do
	a, b = string.find(str, '[0-9]+', b+1)
	if not a then
		print("break...")
		break;
	else
		print("------- "..a.." - "..b)
	end
end

local str1 = "ftottfttfo"
a, b = string.find(str1, 'fo*')
print("========= "..a.." - "..b)

a, b, c = string.find(str1, 'fo+')
print("========= "..a.." - "..b)

a, b = string.find("1number123xyz", '%d*')
print("========= "..a.." - "..b)

print("\n\n")
]]

print("\n\n")

local s = "1number123xyz"
for x in string.gmatch(s,"%d+") do --匹配数字，一次或多次
	print("- "..x)
end
--[LUA-print] 1
--[LUA-print] 123
--[LUA-print]
--> x = 1, x = 123
print("\n")


local s2 = "0123|0123"--number123xyz"
for x in string.gmatch(s2,"(.*)") do --匹配数字，0次或多次，最短匹配,即0次
	print("- "..x)
end
--[LUA-print] 0
--[LUA-print] 1
--[LUA-print] 2
--[LUA-print] 3
--[LUA-print]
-->完成匹配，返回空白
print("\n")


for x in string.gmatch(s,"%d*") do --匹配数字，0次或多次，最长匹配
	print("- "..x)
end
--[[
[LUA-print] 1
[LUA-print]
[LUA-print]
[LUA-print]
[LUA-print]
[LUA-print]
[LUA-print]
[LUA-print] 123
[LUA-print]
[LUA-print]
[LUA-print]
[LUA-print]
[LUA-print]
]]
-->1          123 --中间为空白
print("\n")


for x in string.gmatch(s,"%d?") do --匹配数字，0次或1次
	print("- "..x)
end
--[[
[LUA-print] 1
[LUA-print]
[LUA-print]
[LUA-print]
[LUA-print]
[LUA-print]
[LUA-print]
[LUA-print] 1
[LUA-print] 2
[LUA-print] 3
[LUA-print]
[LUA-print]
[LUA-print]
[LUA-print]
]]
-->1          123 --中间为空白