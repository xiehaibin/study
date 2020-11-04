#include <map>
#include <iostream>

int main( )
{
   using namespace std;
   typedef pair <const int, int> cInt2Int;

   map <int, int> m1;
   map <int, int> :: key_type key1;         // �ؼ��ֵ�����
   map <int, int> :: mapped_type mapped1;   // Ԫ�ص�����
   map <int, int> :: value_type value1;     // map����
   map <int, int> :: iterator pIter;        // ����������
   
   // ���ֲ�ͬ�����Ԫ�ط���
   m1.insert ( map <int, int> :: value_type ( 1, 10 ) );
   m1.insert ( cInt2Int ( 2, 20 ) );
   m1[ 3 ] = 30;  // ����������� �ұ����ǵ�ַ

   key1 = ( m1.begin( ) -> first );
   mapped1 = ( m1.begin( ) -> second );
   cout << " key : "
        << key1 << "." << endl;

   cout << "data : "
        << mapped1 << "." << endl;


   for ( pIter = m1.begin( ) ; pIter != m1.end( ) ; pIter++ )
      cout << " " << pIter -> first;
   cout << "." << endl;

   for ( pIter = m1.begin( ) ; pIter != m1.end( ) ; pIter++ )
      cout << " " << pIter -> second;
   cout << "." << endl;
}