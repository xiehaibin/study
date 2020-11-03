#include <map>
#include <iostream>

int main( )
{
   using namespace std;
   typedef pair <const int, int> cInt2Int;

   map <int, int> m1;
   map <int, int> :: key_type key1;         // 关键字的类型
   map <int, int> :: mapped_type mapped1;   // 元素的类型
   map <int, int> :: value_type value1;     // map类型
   map <int, int> :: iterator pIter;        // 迭代器类型
   
   // 三种不同的添加元素方法
   m1.insert ( map <int, int> :: value_type ( 1, 10 ) );
   m1.insert ( cInt2Int ( 2, 20 ) );
   m1[ 3 ] = 30;  // 如果是类类型 且必须是地址

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