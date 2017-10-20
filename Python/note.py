# -*- coding:utf-8 -*-

#1. python 解释执行语言

#2. 单行注释 #
#3. 多行注释 ''' ''' / """ """
#4. 代码分行 \

#5. 代码缩进
'''
a = 3
b = 2
if a < b:
    print("a > b")
else:
    print("a <= b")

print("---1"); print("---2")

if a < b: print("a > b")
else: print("a <= b")

print("hello \
python")

print("hello ",\
      100,\
      200)
'''

#6. 接收键盘\输入
'''
对于 input() ，它希望能够读取一个合法的 python 表达式，即你输入字符串的时候必须使用引号将它括起来，否则它会引发一个 SyntaxError 。
关于python中的raw_input()和input()，两者都是python 的内建函数，通过读取控制台的输入与用户实现交互，主要区别有如下两点：

1、这两个函数均能接收 字符串 ，但 raw_input() 直接读取控制台的输入（任何类型的输入它都可以接收）。而对于 input() ，
它希望能够读取一个合法的 python 表达式，即你输入字符串的时候必须使用引号将它括起来，否则它会引发一个 SyntaxError 。

2、raw_input() 将所有输入作为字符串看待，返回字符串类型。而 input() 在对待纯数字输入时具有自己的特性，
它返回所输入的数字的类型（ int, float ）；同时在例子 1 知道，input() 可接受合法的 python 表达式，举例：input( 1 + 3 ) 会返回 int 型的

从help(input)的帮助结果可知，input()本质上还是通过raw_input()实现的，只是调用完 raw_input() 之后再调用 eval() 函数，
所以，你甚至可以将表达式作为 input() 的参数，并且它会计算表达式的值并返回它。
'''
'''
name = ''
name = input('Please input your name:')
print(name)
name = raw_input('Please input your name:')
print(name)
'''

#7. 输出
'''
print(value, ..., sep = '', end = '\n')
value: 用户要输出的信息，省略号表示可以有多个
sep: 多个输出信息之间的分隔符，默认值是一个空格
end: 所有输出信息之后添加的符号，默认值为换行符
'''
'''
print('a', '100')
print('a', 100, sep = '-')
print('a', 'b', end = ';')
'''

#8. maht 标准库
'''
import math
print(math.pi)
'''


#9. 数据类型

#string
"""
print('ab\'c')
print("ab'c")
print('''ab
c''')
print("aaa" + "bbb") #字符串连接
print("python "*3) #字符串多次连接
str = "xiehaibin"
print(str.count("x"))
print(len(str))

print(r"abc\\efg") #原始字符串不得以'\'结尾

1.%c单个字符 2.%d十进制 3.%o八进制 4.%s字符串 5.%x十六进制字母小写 6.%X十六进制字母大写
print("%X" % 91857)
print("%x" % 91857)
print("%d + %d = %d" %(1, 2, 1+2))
"""
'''
# -*- coding:utf-8 -*-
首先要搞清楚，字符串在Python内部的表示是unicode编码，因此，在做编码转换时，通常需要以unicode作为中间编码，
即先将其他编码的字符串解码（decode）成unicode，再从unicode编码（encode）成另一种编码。

decode的作用是将其他编码的字符串转换成unicode编码，如str1.decode('gb2312')，
表示将gb2312编码的字符串转换成unicode编码。

encode的作用是将unicode编码转换成其他编码的字符串，如str2.encode('gb2312')，
表示将unicode编码的字符串转换成gb2312编码。

在某些IDE中，字符串的输出总是出现乱码，甚至错误，其实是由于IDE的结果输出控制台自身不能显示字符串的编码，
而不是程序本身的问题。

s = "我爱python"
print type(s)
#if isinstance(s, unicode):
#    print("unicode")
import sys
print sys.getdefaultencoding()
u = s.decode('gbk')
sg = u.encode("gbk")
print(type(u))
print(u)
print(type(sg))
print sg
b = u.encode("utf-8")
print "b = "+b
c = b.decode("utf-8")
print "c = "+c
'''

#int float
"""
o = 0o25  #八进制
x = 0x2f  #十六进制
b = 0b101 #二进制
print(o)
print(x)
print(b)
#** 乘方, *, /, //整除, %, +, -, |, ^, &, <<, >>
print(2**4) #16
print(5//2) #2
"""

#类型转换
"""
print(str(45.6))
print(int("45", base = 10))
print(float(45))
print type(s) #对象类型

x = 2
y = 2.0
print(x is y) false
"""

#list 列表
"""
list1 = [1, "a", 3.14]
list2 = [100, 200]
print(list1[0])

list3 = list1 + list2
print(list3) # 1, "a", 3.14, 100, 200

list4 = list2 * 2
print(list4) #[100, 200, 100, 200]

#操作 ...
list2.append(119)
print(list2)

list5 = [0, 1, list1]
print(list5)
print(list5[2][2])
"""

#tuple 元组
"""
'''
元组是一种特殊的列表，元组一旦建立就不能改变，即不能改变其中的数据项，
也不能添加删除数据项
'''
#空元组
tuple1 = ()
tuple2 = tuple()
print(tuple1, tuple2)

tuple3 = (1, 2, "a")
x, y, z = tuple3
print(x, y, z)    # 1, 2, a
print(tuple3[2])  # a
"""

#dict 字典
"""
#空字典
dict1 = {}
dict2 = dict()
print(dict1, dict2) #({}, {})

dict3 = {"a":1, "b":"python", "c":3.14}
print(dict3) #{"a":1, "b":"python", "c":3.14}
print(dict3["b"])
#print(dict3[2]) 错误

#操作 ...
dict3.clear()
print(dict3)
"""

#内置常量
'''
None: 无 表示没有值的对象
True
False (false none 0 空字符串 空元组() 空列表[] 空字典{})
'''
"""
a = {}  #false
b = ""  #false
if b: print("true")
else: print("false")
"""


#逻辑运算符
#and or not
'''
print(0 or 1) #1
print(0 and "true" or "false") #false
'''

'''
is  is not是二操作符，用于判断左端与右端对象引用是否指向同一个对象
'''
'''
a = 1
b = 1
print(a is b) #true
a = [1]
b = [1]
print(a is b) #false
a = "1"
b = "1"
print(a is b) #true
'''

'''
in  not in称为成员操作符，用于检查某个数据是否存于包含多个成员的数据类型
（字符串，列表，元组，字典）
成员操作符对于字典来说检查的是键成员面不是值成员
'''
'''
list1 = [1, 2]
list2 = ["a", "b"]
list3 = [1, list1]
print(1 in list1) #true
print(1 in list2) #false
print(list1 in list3) #true
'''


#比较运算符
'''
== > < >= <= !=
字符（串）也是可以进行大小比较的, 其比较依据的是ascii码
'''

#赋值运算符 + - * / // ** % & | ^ >> <<


#序列
"""
alst1 = [-1, 1, [-100, -200], 3.5, 4]
print(alst1[0])
print(alst1[-1])
print(alst1[:])
print(alst1[2:5])
print(alst1[::-1])
#序列内置操作
print(len(alst1)) #长度
print(min(alst1)) #'最小值'
print(max(alst1)) #'最大值'
#print(sum(alst1)) #'各项的和'
print(all(alst1)) #'所有项为真 返回真'
print(any(alst1)) #一项为真 返回真'
"""


#语句
#if：
"""
value = 5
if value == 5:
    print("value = 5")
elif value == 10:
    print("value = 10")
else:
    print("value error")

if False:
    print("true")
print("----------")  #不在if条件范围
"""

#------------------for------------------------
"""
python中for语句是通过循环遍历某个对象（元组，列表，字典）来构建循环
"""
"""
list = [1,2,3,4,5]
for i in list:
    if i == 3:
        print('i ===== 3')
        continue
    if i == 5:
        break
    print('i = ', i)
else:
    print('for 结束') #break跳出不会执行

adce = {'key1':1, 'key2':'python', 'key3':3.14}
for key, value in adce.items(): #同时遍历键和值
    print(key, ' : ', value)
for key in adce.keys():
    print(key)
for value in adce.values():
    print(value)

#range(start, stop, step start:起始数，stop:终止数， step:步长 产生的整数序列长度最大值为step-1
for i in range(5):
    print(i, ' = ', i) #0,1,2,3,4
for i in range(0, 5, 2):
    print(i, ' = ', i) #0,2,4

for i in 'python':
    print(i)

x = ( int(input('输入开始数：')), int(input('输入结束数：')) )
x1 = min(x)
x2 = max(x)
for a in range(x1, x2+1):
    for b in range(x1+1, x2-1):
        if a%b == 0:
            break
    else:
        print(a, '是素数')

#内置迭代函数
#编号迭代
for i, item in enumerate('abcd'):
    print("第%d个字符是：%s" % (i, item))
    
#排序
for i in sorted([2,3,1,4]):
    print(i)
    
#翻转
for i in reversed([2,3,1,4]):
    print(i)
    
#并行
list1 = [1,2]
list2 = [3,4,5]
list3 = [6,7]
for i in zip(list1, list2, list3):
    print(i)

#while
alst = [1,2,3,4]
count = len(alst)
i = 0
while i < count:
    i = i + 1
else:
    print("while end")

#推导或内涵
list1 = [i*i for i in range(1,5)]
print(list1)

keys = ['name', 'age', 'weight']
values = ['bob', 23, '68']
adct = {k:v for k,v in zip(keys, values)}
print(adct)
# 有条件的推导
list2 = [i*i for i in range(1,5) if i*i%2 == 1]
print(list2)
"""
#--------------------------------------------------------


#-------------------------函数-----------------------------
def function1(name="name", age="0"):
    print(name, ' : ', age)
function1('xiehaibin')
function1('xiehaibin', "18")
function1()
function1(name="pythom", age="30")
function1(age="30", name="pythom")

def function2(a,b,c):
    print(a*b*c)
function2(2, b = 2, c =2)
#function2(b = 2, c =2, 2) error

#可变数量参数
def function3(a, *value):
    print(type(value), " - ", value, " - ", a)
function3(100, 1, 2, 3) # 元组

def function4(a, **values):
    print(type(values), values)
    print('a ', a)
function4(1, k1=10, k2 = 20) #字典
#拆解序列
def mysum(a, b):
    print(a, " - ", b)
mysum(*(1, 2))
mysum(**{'a':100,'b':200})
#---------------------------------------------------------
