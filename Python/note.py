# -*- coding:utf-8 -*-

#1. python ����ִ������

#2. ����ע�� #
#3. ����ע�� ''' ''' / """ """
#4. ������� \

#5. ��������
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

#6. ���ռ���\����
'''
���� input() ����ϣ���ܹ���ȡһ���Ϸ��� python ���ʽ�����������ַ�����ʱ�����ʹ�����Ž�����������������������һ�� SyntaxError ��
����python�е�raw_input()��input()�����߶���python ���ڽ�������ͨ����ȡ����̨���������û�ʵ�ֽ�������Ҫ�������������㣺

1���������������ܽ��� �ַ��� ���� raw_input() ֱ�Ӷ�ȡ����̨�����루�κ����͵������������Խ��գ��������� input() ��
��ϣ���ܹ���ȡһ���Ϸ��� python ���ʽ�����������ַ�����ʱ�����ʹ�����Ž�����������������������һ�� SyntaxError ��

2��raw_input() ������������Ϊ�ַ��������������ַ������͡��� input() �ڶԴ�����������ʱ�����Լ������ԣ�
����������������ֵ����ͣ� int, float ����ͬʱ������ 1 ֪����input() �ɽ��ܺϷ��� python ���ʽ��������input( 1 + 3 ) �᷵�� int �͵�

��help(input)�İ��������֪��input()�����ϻ���ͨ��raw_input()ʵ�ֵģ�ֻ�ǵ����� raw_input() ֮���ٵ��� eval() ������
���ԣ����������Խ����ʽ��Ϊ input() �Ĳ������������������ʽ��ֵ����������
'''
'''
name = ''
name = input('Please input your name:')
print(name)
name = raw_input('Please input your name:')
print(name)
'''

#7. ���
'''
print(value, ..., sep = '', end = '\n')
value: �û�Ҫ�������Ϣ��ʡ�Ժű�ʾ�����ж��
sep: ��������Ϣ֮��ķָ�����Ĭ��ֵ��һ���ո�
end: ���������Ϣ֮����ӵķ��ţ�Ĭ��ֵΪ���з�
'''
'''
print('a', '100')
print('a', 100, sep = '-')
print('a', 'b', end = ';')
'''

#8. maht ��׼��
'''
import math
print(math.pi)
'''


#9. ��������

#string
"""
print('ab\'c')
print("ab'c")
print('''ab
c''')
print("aaa" + "bbb") #�ַ�������
print("python "*3) #�ַ����������
str = "xiehaibin"
print(str.count("x"))
print(len(str))

print(r"abc\\efg") #ԭʼ�ַ���������'\'��β

1.%c�����ַ� 2.%dʮ���� 3.%o�˽��� 4.%s�ַ��� 5.%xʮ��������ĸСд 6.%Xʮ��������ĸ��д
print("%X" % 91857)
print("%x" % 91857)
print("%d + %d = %d" %(1, 2, 1+2))
"""
'''
# -*- coding:utf-8 -*-
����Ҫ��������ַ�����Python�ڲ��ı�ʾ��unicode���룬��ˣ���������ת��ʱ��ͨ����Ҫ��unicode��Ϊ�м���룬
���Ƚ�����������ַ������루decode����unicode���ٴ�unicode���루encode������һ�ֱ��롣

decode�������ǽ�����������ַ���ת����unicode���룬��str1.decode('gb2312')��
��ʾ��gb2312������ַ���ת����unicode���롣

encode�������ǽ�unicode����ת��������������ַ�������str2.encode('gb2312')��
��ʾ��unicode������ַ���ת����gb2312���롣

��ĳЩIDE�У��ַ�����������ǳ������룬����������ʵ������IDE�Ľ���������̨��������ʾ�ַ����ı��룬
�����ǳ���������⡣

s = "�Ұ�python"
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
o = 0o25  #�˽���
x = 0x2f  #ʮ������
b = 0b101 #������
print(o)
print(x)
print(b)
#** �˷�, *, /, //����, %, +, -, |, ^, &, <<, >>
print(2**4) #16
print(5//2) #2
"""

#����ת��
"""
print(str(45.6))
print(int("45", base = 10))
print(float(45))
print type(s) #��������
"""
x = 2
y = 2
print(x is y)








