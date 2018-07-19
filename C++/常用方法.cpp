1.二进制转换
void binary_print(const unsigned int &v)
{
    int i;
    int bit;
    int size = sizeof(v)*8;
    //这里的size是输入参数v的位数，直接用32代替也可以，但写成sizeof(v)*8这样更为通用。
    for(i = 0; i < size; i ++)
    {
        bit = v&(1<<(size-i-1));//提取出第i位的值
        if(bit == 0) cout << 0;
        else cout << 1;
        if(i % 4 == 3)cout << ' '; //为了方便阅读输出，在每输出四位后加一个空格
    }
}

2.内存对齐
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