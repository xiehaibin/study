1.������ת��
void binary_print(const unsigned int &v)
{
    int i;
    int bit;
    int size = sizeof(v)*8;
    //�����size���������v��λ����ֱ����32����Ҳ���ԣ���д��sizeof(v)*8������Ϊͨ�á�
    for(i = 0; i < size; i ++)
    {
        bit = v&(1<<(size-i-1));//��ȡ����iλ��ֵ
        if(bit == 0) cout << 0;
        else cout << 1;
        if(i % 4 == 3)cout << ' '; //Ϊ�˷����Ķ��������ÿ�����λ���һ���ո�
    }
}