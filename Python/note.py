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
"""
x = 2
y = 2
print(x is y)








