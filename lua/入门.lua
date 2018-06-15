1.变量
	1.局部变量：local a
	2.全局变量：a
	3.单行注释：--
	4.多行注释：--[[ ]]
	nil:lua中特殊的类型，一个全局变量没有被赋值以前是默认值为nil;
	给全局变量赋nil可以删除除该变量

	5. lua类型
	boolean: true false
	number:  1, 1.1
	string:  "", ''
	function function()
	
	类型判断 type(...)
	print(a..b) 字符串连接

2.函数
	--无参无返回值函数
	function funa()
		print("无参无返回值函数")
	end

	--有参无返回值函数
	function funb(a, b)
		print(a+b)
	end

	--有参有返回值函数
	function func(a, b)
		return a*b
	end

	--参数的默认值
	function fund(a, b, c)
		a = a or 1
		b = b or 2
		c = c or 3

		print(a)
		print(b)
		print(c)
	end

	--不定参数
	function fune(...)
		--获得...的值
		--local a,b,c = ...

		--获得...的值
		for k, v in ipairs({...})do
			print(k, v)
		end

		return select("#", ...)
	end

	--传递函数
	function funf(fun)
		fun()
	end

3. 运算符
	1.算数运算符：+ - * / % ^
	2.关系运算符：==, ~=(不同类型可以), >, <, >=, <= （不同类型不可以）
	3.逻辑运算符：and(&&), or(||)， not(!)/not(.)
	4.三目运算符：(a < b) and a or b
	5.连接运算符：..
	6.长度运算符：#s s为(字符串, 数组)
	非法 -- ++ -a a+=1;  a = -a(负) a = a+1可以的

4.赋值
	1.a,b = function(){return a, b}
	2.代码块 do  local a = 1  end

5.分支语句
	1. if a>b and c>d then
   			print("a>b")
	   elseif a<b then
	   		print("a<b")
	   else 
	   		print("a==b")
	   end
	2.没有switch
    3.
    --while
    while cout<num do
   		print(cout)
   		cout = cout + 1
    end

    --do...while
	repeat
	   print(cout)
	   cout = cout + 1
	until cout > num --此处条件需要注意

    --for
	for i=1, 10, 2 do
		print(i)
	end

6.数组
    1.--数组方式
    a = {1, 2, 3, nil, 4, 5, nil}
    --len = #a --不安全
    a[10] = 0
    len = table.maxn(a);
    --下标从0开始
    for i=1, len do
    	print(a[i])
    end

    2.--键方式
    a = {x = 1, y = 2, z = "point"}
    a.m = "m"
    a["n"] = "n"
    print(table.maxn(a)) -- = 0
    print("a.x = "..a.x) -- 1
    print("a[y] = "..a["y"]) --2
    print("a.m = "..a.m) --m
    print("a[n] = "..a["n"]) --n

    3.--混合方式
    a = {1,2,3; x = 0, y = 1}
    len = table.maxn(a) --=3
    for i = 1, len do
    	print(a[i]) --1 2 3
    end
    print(a["x"]) --0
    print(a.y) --1

    4.
    a = {["add"] = "add", ["fun"] = 1}
    print(table.maxn(a))
    print(a["add"]) --add
    print(a.fun) --1

    5.--二维数组
    a = {{1,2,3}, {"aa","bb","cc"}}
    a[3] = {'a','b','c', 'd', 'e'}
    len1 = table.maxn(a)
    for i = 1, len1 do
    	len2 = table.maxn(a[i])
    	for j = 1, len2 do
    		print(a[i][j])
    	end
    end
	
	6.--表的遍历
	a = {1,2,3, nil, a = "a", b = "b"}
	-- k=健， v=值
	for k, v in next, a do
		print(k.." = "..v)
	end
	print("----------------")

	--ipairs是关键字，只输出1 2 3等数组元素
	for k, v in ipairs(a) do
		print(k.." = "..v)
	end
	print("----------------")

	-- pairs是关键字，可以输出全部键值
	for k, v in pairs(a) do
		print(k.." = "..v)
	end
	print("----------------")

	b = {1,2,3,4}
	table.insert(b, 2, "aaa") --插入 针对数组下标的
	table.insert(b,"bbb") --插入到数组最后
	table.remove(b, 1) --删除 针对数组下标的
	m = table.remove(b) --删除最后一个
	for k, v in pairs(b) do
		print(k.." = "..v)
	end
	print("m = "..m)

	7.排序
	function sort1()
		len = table.maxn(array)
		for i=1, len do
			for j = i+1, len do
				if array[i] > array[j] then
					local temp = array[i]
					array[i] = array[j]
					array[j] = temp
				end
			end
		end

		sortPrint()
	end

	function sort2()
		table.sort(array, function(a, b) return a>b end)
		sortPrint()
	end

7.加载和编译
	1.dofile("绝对路径"):装载并执行
	2.require("相对"):和dofile有点像，不过又很不一样，
	 require在第一次加载文件的时候，会执行里面的代码
	 会搜索目录加载文件
	 会判断是否文件已经加载避免重复加载同一文件。
	 由于上述特征，require在LUA中是加载库的更好的函数
	3.loadfile("绝对路径"):装载并编译为中间码，不执行
	  assert(loadfile("绝对路径")) 返回更清楚的错误信息，
	  如果装载失败抛出例外
	4.loadstring("字符串")：字符串当匿名函数用，通常用运行程序外部
	  的代码，比如运行用户自定义的代码

8.字符串
--查找
    str = "iffffiifffiifffiiiff"
    _start, _end = string.find(str, "hai")
    printf(_start.." : ".._end) --3 4

    _start, _end = string.find(str, "i", 3); --从第三个开始找
    printf(_start.." : ".._end) -- 6 6

    index = 0
    repeat
      _start1, _end1 = string.find(str, "ii", index)
      if _start1 ~= nil then
        print(_start1)
        index = _end1
      else
        print("==========")
        break
      end
    until false

--替换
    s = string.gsub(str, "ii", "00")
    print(s)

--多行文本
    page = [[898908
             iooioio]]
    print(page)

--字符串拼接
    str2 = "123"..456
    print(str2)

--类型替换
    n = 15
    print(type(n))
    print(type(tostring(n)))

--字符串倒序
    m = "xiehaibin"
    m = string.reverse(m)
    print(m)

9.随机数
function getRand(a, b)
	time = os.time()
	timeStr = string.reverse(tostring(time))
	math.randomseed(tonumber(timeStr))
	for i, 10 do
		num = math.random(a, b)
		print(num)
	end
end

10. 文件
function openFile()
	local file, msg = io.open("E:\\quick\\text.txt", "r");
	if file then
		-- 全部读取
		s = file:read("*all");
		print(s);

		-- 逐行读取
		--[[
		repeat
			s = file:read();
			if s~=nil then
				print(s);
			else
				break;
			end
		until false
			]]
	else
		print(msg);
	end
end

function writeFile()
	local file, msg = io.open("E:\\quick\\text.txt", "w");
	file:write("1.xie hai bin");
	file:write("2.xie hai bin");
	file:write("3.xie hai bin");
	file:flush();
	file:close();
end

11. 列外
function errorFun(str)
	if str ~= "12" then
		error("不是数字");
	end

	return "是数字";
end
b, msg = pcall(errorFun, "12");
    print(b);
    print(msg);

 12. 协程
 function corutineFun()
	local co = coroutine.create(function(a)
		for i = 1, 10 do
			print("i = ", i+a);
			coroutine.yield();
		end
	end)

	return co;
end

local co = corutineFun();
for i = 1, 11 do
   	coroutine.resume(co, i);     -- 调用协调线程
   	print(coroutine.status(co)); -- 输出协同状态 
end

13. 闭包
1-闭包是函数中的函数，可以包含父函数的局部变量
的代码块；可以让这些局部变量的值始终保持在内存中
2-他的最大用处有两个，一个是可以读取函数内部的变量，
另外就是让这些变量的值始终保持在内存中
function func(a)
	local aa = a;
	function func1()
		aa = aa + 1;
		print("aa = ", aa);
	end
	return func1;
end

local fun1 = func(10);
local fun2 = func(100);
	for i = 0, 5 do
   		fun1();
   		fun2();
	end

14. 类
local UserClass = class("UserClass")
UserClass.id = 1
UserClass.name = "xiehaibin"
UserClass.age = 29

function UserClass:ctor()
	--print(self.__cname)
	print("UserClass被构造")
end

--[[
function UserClass:ctor(name)
	print(self.__cname)
	print("UserClass被构造 ", name)
end
]]

function UserClass:getId()
	print("UserClass:getId()");
	--return UserClass.id --静态方问
	return self.id --
end

return UserClass

---------------------------------

local UserClass = require("app.scenes.UserClass")
local PlayerClass = class("PlayerClass", UserClass)
PlayerClass.num = 100

function PlayerClass:ctor()
	self.super:ctor()
	print("PlayerClass被构造")
end

function PlayerClass:getId()
	self.super:getId();
	print("PlayerClass:getId() = ", self.num + self.age);
	return self.id --
end

function PlayerClass:setName(name)
	self.name = name
end

return PlayerClass

--------------------------------------

local playerClass = require("app.scenes.PlayerClass")

local player1 = playerClass.new()
player1:setName("www")
print(player1.name)
--print(player1:getId())
--print(user.getId())

local player2 = playerClass.new()
print(player2.name)


local laycolor = cc.LayerColor:create(cc.c4b(0, 0, 0, 120))
	laycolor:setContentSize(cc.size(600, 400))
	laycolor:setAnchorPoint(cc.p(0, 0))
	laycolor:setPosition(cc.p(80, 45))

    local clipNode = cc.ClippingNode:create()
    clipNode:setInverted(false)
    clipNode:setAlphaThreshold(120)
   	self:addChild(clipNode)

    clipNode:addChild(laycolor)
   	local buyBtn = createTouchButton(nil, "res_new/component/button/btn7.png", "res_new/component/button/btn7.png", cc.p(200, 200), nil)
    clipNode:setStencil(buyBtn)


