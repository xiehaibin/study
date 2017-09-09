import os

def readFile(fileName):
    file = open(fileName, "a")
    file.writelines(["\n444","\n555","\n666"])

def osTest():
    path = os.getcwd()
    #print("path: %s" %path)

    if not os.path.isdir("test2"):
        os.mkdir("test2")
    if os.path.isfile("111"):
        print("是文件")
    else:
        print("不是文件")
        
    #list = os.listdir(path)
    #for dir in list:
        #print(dir)

    dirList = os.walk(".\\")
    for v in dirList:
        print(v)
        print(v[0])

    os.system("cmd")

    print("----------------------")
    import ctypes
    from distutils.core import setup
    import py2exe
    setup(console=["main.py"])
    python setup.py py2exe

if __name__ == "__main__":
    osTest()
    
