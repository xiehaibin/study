echo off


rem p-��ȡ��ɾ������ʱ��ϵͳȷ��
rem f-ֻ�� 
rem s-�ӵ�ǰĿ¼����������Ŀ¼��ɾ��ָ���ļ�����ʾ���ڱ�ɾ�����ļ���
rem q-ָ������״̬������ʾ��ȷ��ɾ��
rem a-����ָ��������ɾ���ļ�
rem *.* del c:\test\*.* Ҫɾ�������� C:\ ����Ϊ Test �ļ����е������ļ�
:del /q /f /s test
:del /q /s test\*.*

rem ɾ����ǰĿ¼���abc��Ŀ¼��Ҫ��Ϊ��Ŀ¼
:rd test
rem ɾ�� d:temp �ļ��м������ļ��к��ļ���/q����ģʽ
:rd  /s/q test


echo -----------------


rem ��� d:a �����ڣ������Զ������м�Ŀ¼
rem ���������չ����ͣ�ã�����Ҫ���� mkdir abc
:md temp
:mkdir temp1


goto flag
echo -----------------1
:flag
echo -----------------2


rem ���� 000.txtt �ļ���  temp��������Ϊ 000.bak
:copy 000.txt temp\000.bak

rem ����Ļ�ϵȴ����룬�� Ctrl+Z �������룬�������ݴ�Ϊtest.txt�ļ�
rem con������Ļ��prn�����ӡ����nul������豸
:copy con 000.txt

rem �ϲ� 000.txt �� 111.txt �����ݣ�����Ϊ 333.txt �ļ�
rem �����ָ�� 3.txt ���򱣴浽 1.txt
:copy 000.txt + 111.txt 333.txt

rem �����ļ����Լ���ʵ�������޸����ļ�����
:copy 000.txt +

rem ���� temp �ļ��С��������ļ��к��ļ��� temp1���������ļ�
rem �� /i ��ʾ���û�� temp1 �ļ��о��Զ��½�һ�����������ѯ�� 
:xcopy temp temp1 /i/s/y


rem ִ��python�ű�
python.py
:E:\work2\run\client\sg.exe


rem ����cmd���ڵı���
:title xiehaibin



pause
exit