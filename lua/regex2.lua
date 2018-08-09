--[[
function trim(s)
  return (string.gsub(s, "^%s*(.-)%s*$", "%1"))
end

local s = " space "
local txt = trim(s)

print(txt.."-")
print(string.len(s), string.len(txt))
]]

--print(string.match("12abc45", "%d+"))


--[[
+       匹配前一字符1次或多次
*       匹配前一字符0次或多次 最长匹配
-       匹配前一字符0次或多次 最短匹配
?       匹配前一字符0次或1次
]]

--[[
`+′ 匹配一个或多个字符，她总是进行最长的匹配. 比如，模式串 '%a+'匹配一个或多个字母或者一个单词 : 
print(string.gsub("one, and two; and three", "%a+", "word"))
--> word, word word; word word
	
'%d+'匹配一个或多个数字 (整数): 
i, j = string.find("the number 1298 is even", "%d+")
    print(i,j) --> 12   15
]]
for v in string.gmatch("12abc45", "%d+") do
	print(v)
end
--12 
--45


print("\n")


--[[
`*′ 与 `+′类似, 但是他匹配一个字符0次或多次出现.一个典型的应用是匹配空白。比如，
为了匹配一对圆括号()或者( )之间的空白，可以使用'%(%s*%)'. ( '%s*'用来匹配0个或多个空白. 
由于圆括号在模式中有特殊的含义，所以我们必须使用`%′转义他.) 再看一个例子，
'[_%a][_%w]*'匹配Lua程序中的标示符：字母或者下划线开头的字母下划线数字序列。 
]]
for v in string.gmatch("()and(123)", "%(.*%)") do
	print(v)
end
--()and(123)

for v in string.gmatch("()00(123)", "%(%d*%)") do
	print(v)
end
--() 
--(123)


print("\n")


--[[				
`-′与`*′一样，都匹配一个字符的0次或多次出现，但是他进行的是最短匹配。某些时候这两个用起来没有区别，
但有些时候结果将截然不同。比如，如果你使用模式'[_%a][_%w]-'来查找标示符，你将只能找到第一个字母，因为'[_%w]-'永远匹配空。
另一方面，假定你想查找C程序中的注释，很多人可能使用 '/%*.*%*/' (也就是说 "/*" 后面跟着任意多个字符，然后跟着 "*/").
然而，由于 '.*'进行的是最长匹配，这个模式将匹配程序中第一个"/*" 和最后一个"*/"之间所有部分: 
test = "int x; /* x */   int y; /* y */"
print(string.gsub(test, "/%*.*%*/", "<COMMENT>"))
    --> int x; <COMMENT>

然而模式 '.-'进行的是最短匹配，她会匹配"/*"开始到第一个"*/"之前的部分: 

test = "int x; /* x */   int y; /* y */"
print(string.gsub(test, "/%*.-%*/", "<COMMENT>"))
   --> int x; <COMMENT>   int y; <COMMENT>
]]
for v in string.gmatch("int x; /* x */   int y; /* y */", "/%*.*%*/") do
	print(v)
end
--[[ /* x */   int y; /* y */ ]]

for v in string.gmatch("int x; /*xdx*/   int y; /*ydy*/", "/%*%a-%*/") do
	print(v)
end
--[[
/*xdx*/
/*ydy*/
]]
for v in string.gmatch("|123|456|", "|(.*)|") do
	print(v)
end
--123|456
for v in string.gmatch("|123|456|", "|(.-)|") do
	print(v)
end
--123
for v in string.gmatch("|123|456|", "|.-|") do
	print(v)
end
--|123|

print("\n")


--[[
`?′匹配一个字符0次或1次.举个例子，假定我们想在一段文本内查找一个整数，整数可能带有正负号。 
模式 '[+-]?%d+'符合我们的要求，她可以匹配 像 "-12", "23" 和 "+1009"等数字. '[+-]' 是一个匹配`+′或者 `-′的字符类；
接下来的 `?′意思是匹配前面的字符类0次或者1次. 
]]
for v in string.gmatch("123, -456", "[+-]?%d+") do
	print(v)
end
--[[
123
-456
]]

print("\n-----------")


--[[
与其他系统的模式不同的是，Lua中的修饰符不能用字符类；不能将模式分组然后使用修饰符作用这个分组。
比如，没有一个模式可以匹配一个可选的单词(除非这个单词只有一个字母)。下面我将看到，通常你可以使用一些高级技术绕开这个限制。 

以`^′开头的模式只匹配目标串的开始部分，相似的，以`$′结尾的模式只匹配目标串的结尾部分。
这不仅可以用来限制你要查找的模式，还可以定位(anchor)模式。比如： 
if string.find(s, "^%d") then ...
检查字符串s是否以数字开头，而 
if string.find(s, "^[+-]?%d+$") then ...
检查字符串s是否是一个整数。 
]]
if string.find("-1ghyjh", "^[+-]?%d") then
	print("in number start")
end
if string.find("-100", "^[+-]?%d+$") then
	print("it's is integer")
end
if string.find("-100ghyjh", "^[+-]?%d+%a+$") then
	print("ok")
end

print("\n")


--[[
'%b'用来匹配对称的字符.常写为 '%bxy',x和y是任意两个不同的字符；x作为匹配的开始,y作为匹配的结束。比如， '%b()'匹配以`(′开始， 以 `)′结束的字符串: 
print(string.gsub("a (enclosed (in) parentheses) line",
                  "%b()", ""))
    --> a   line
常用的这种模式有： '%b()', '%b[]', '%b%{%}',和 '%b<>'。你也可以使用任何字符作为分隔符。
]]
for v in string.gmatch("xiehaibin^<rad>000^vvv^<wherr>abc^mmmmm", "%b^^") do
	--print(v)
end



local textTab = {}
--[^x]匹配除x以外的其他字符中
local cfg = "^c(c18)0000000^^c(c6)11111^222222222^c(c18)0000000^^c(c6)11111^222222222^c(c18)0000000^^c(c6)11111^222222222^c(c18)0000000^^c(c6)11111^222222222^c(c18)0000000^^c(c6)11111^222222222"
local MAX = 10000000

--[[
正则表达式性能不好，性能和下相差太远
]]
local startTime = os.time()
print(startTime)
for i = 0, MAX do
	for v in string.gmatch(cfg, "[^%^]+") do
		if string.find(v, "(", 1, true) == 2 then
			--local subTab = {}
			--table.insert(textTab, subTab)
			for v in string.gmatch(v, "[^(^)]+") do
				--table.insert(subTab, v)
				--print(""..v)
			end
		else
			--table.insert(textTab, v)
			--print(""..v)
		end
	end
end
local time = os.time() - startTime
print("--------------- "..time)


print("\n\n")


function addText(str, defaultFontColor)
	local startTime = os.time()

	if str == nil then
		return
	end

	--^wrap 表示换行
	str = string.gsub(str, "%^wrap", "\n")
	
	local flag = "%^"
	local flagText = "^c"
	local flagImage = "^i"
	local flagNode = "^d"
	local flagLinkName  = "^n"
	local flagParamBegin = "%("
	local flagParamEnd = "%)"
	local strFound
	local strLeft = str
	local strAdd
	local param
	local strBegin,strEnd
	local tag = 1
	local strflag
	local fontColor
	

	local addTextItem = function(str, fontColor)
		print("addTextItem: "..str)
		--self:addTextItem(str, fontColor, isOutLine, isUnbreak, isHyperlink, callback)
	end

	local addImageItem = function(id)
		print("addImageItem: "..id)
		--self:addImageItem(id)
	end
for i = 0, MAX do
	while true do
		strBegin = string.find(strLeft, flag)
		if strBegin == nil then
			--addTextItem(strLeft, defaultFontColor)
			--print(strLeft)
			break
		else
			if strBegin > 1 then
				strAdd = string.sub(strLeft, 1, strBegin-1)
				--addTextItem(strAdd, defaultFontColor)
				--print(strAdd)
			end

			strEnd = string.find(strLeft, flag, strBegin+1)
			if strEnd then
				strFound = string.sub(strLeft, strBegin, strEnd)
				strFlag = string.sub(strFound, 1, 2)
				if strFlag then
					local paramBegin
					local paramEnd
					if strFlag == flagText or strFlag == flagImage or strFlag == flagNode or strFlag == flagLinkName then
						paramBegin = string.find(strFound, flagParamBegin)
						paramEnd = string.find(strFound, flagParamEnd)

						if paramBegin and paramEnd then
							param = string.sub(strFound, paramBegin+1, paramEnd-1)
							strAdd = string.sub(strFound, paramEnd+1, -2)
							--print(param.." - "..strAdd)
						end

					else
						break
					end
				else
					break
				end
				strLeft = string.sub(strLeft, strEnd+1, -1)
			else
				break
			end
		end
	end
end
	local time = os.time() - startTime
	print("--------------- "..time)
end

addText(cfg)

--local text = "<font color = 0xff0000, size = 20>0000000<font color = 0xff00ff>1111111111</font>0000000</color>"