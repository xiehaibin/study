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

2.�ڴ����
const int Len = 3;
#pragma pack(8) /* n = 1, 2, 4, 8, 16 */
struct test_t
{
	int a;         //4
	char b;        //2 0
	short c;       //2
	char d[Len];   //3 0
	short e;       //4 00
 };

void print_hex_data(char *info, char *data, int len)
{
	int i;
	printf("%s:\n\r", info);
	for(i = 0; i < len; i++)
	{
		printf("%02x ", (unsigned char)data[i]);
		if (0 == ((i+1) % 32))
			printf("\n");
	}
	printf("\n\r");
}

int main (int argc, char *argv[])
{
	test_t ttt;

	cout<<sizeof(test_t)<<endl;

	ttt.a = 0x1a2a3a4a;
	ttt.b = 0x1b;
	ttt.c = 0x1c2c;
	ttt.e = 0x1a2a3a4a;
	char* s = "123456";
	//memcpy(ttt.d, s, Len);
	print_hex_data("struct_data", (char *)&ttt, sizeof(struct test_t));

	_sleep(1000000);
}     