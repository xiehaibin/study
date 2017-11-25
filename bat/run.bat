echo off


rem p-可取消删除操作时的系统确认
rem f-只读 
rem s-从当前目录及其所有子目录中删除指定文件。显示正在被删除的文件名
rem q-指定静音状态。不提示您确认删除
rem a-根据指定的属性删除文件
rem *.* del c:\test\*.* 要删除驱动器 C:\ 上名为 Test 文件夹中的所有文件
:del /q /f /s test
:del /q /s test\*.*

rem 删除当前目录里的abc子目录，要求为空目录
:rd test
rem 删除 d:temp 文件夹及其子文件夹和文件，/q安静模式
:rd  /s/q test


echo -----------------


rem 如果 d:a 不存在，将会自动创建中级目录
rem 如果命令扩展名被停用，则需要键入 mkdir abc
:md temp
:mkdir temp1


goto flag
echo -----------------1
:flag
echo -----------------2


rem 复制 000.txtt 文件到  temp并重命名为 000.bak
:copy 000.txt temp\000.bak

rem 从屏幕上等待输入，按 Ctrl+Z 结束输入，输入内容存为test.txt文件
rem con代表屏幕，prn代表打印机，nul代表空设备
:copy con 000.txt

rem 合并 000.txt 和 111.txt 的内容，保存为 333.txt 文件
rem 如果不指定 3.txt ，则保存到 1.txt
:copy 000.txt + 111.txt 333.txt

rem 复制文件到自己，实际上是修改了文件日期
:copy 000.txt +

rem 复制 temp 文件夹、所有子文件夹和文件到 temp1覆盖已有文件
rem 加 /i 表示如果没有 temp1 文件夹就自动新建一个，否则会有询问 
:xcopy temp temp1 /i/s/y


rem 执行python脚本
python.py
:E:\work2\run\client\sg.exe


rem 设置cmd窗口的标题
:title xiehaibin



pause
exit