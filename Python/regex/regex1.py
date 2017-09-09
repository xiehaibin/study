"# coding=utf-8"
import re

def fun0():
    str = 'read'
    print(re.match('r.d', 'red'))
    
def fun1():
    #str = "13091908176"
    str = "aa13091908176bb"
    if re.search('13[3-9][0-9]{8}', str):
        print("移动号码")
    elif re.search('13[0-2][0-9]{8}', str):
        print("联通号码")

def fun2():
    str = 'http//www.hao123.com'
    if re.match('(http//www|www)\.[a-z0-9-]*\.[a-z]{2,3}', str):
        print("正确网址")
        
def fun3():
    str = 'xie hai bin615'
    print(re.findall('[a-z]{1,3}', str))

def sub():
    str = 'xie hai bin xiexie'
    print(re.sub('xie', '000', str))
    print(re.sub('xie|in', '000', str))
    print(re.subn('xie|in', '000', str))

def split():
    str = 'xie hai bin'
    print(re.split(' ', str))
    print(re.split(' ', str, 1))
    print(re.split('i', str))

def _compile():
    str = 'List can be good'
    r = re.compile('go*d')
    print(r.match('List can be good', 12))
    print(r.search('List can be good', 12))
    
    r = re.compile('b.\sg')
    print(r.search('List can be good'))

    r = re.compile('\\b\w..?\s')
    print(r.findall('List can be good'))

#-----------------------------------------
def fun4():
    str = 'iphone No: 0739-7090239'
    r = re.compile('(\d+)-(\d+)')
    m = r.search(str)
    print(m.group(1))
    print(m.group(1))
    print(m.groups())

    r = re.compile('(?P<Area>\d+)-(?P<No>\d+)')
    m = r.search(str)
    print(m.group('Area'))
    print(m.group('No'))
    print(m.groupdict())

if __name__ == "__main__":
    fun4()
    
