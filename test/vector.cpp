#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
using namespace std;

void outputVector( const vector< int > & ) ; //函数定义
void inputVector( vector< int > & );

int main()
{
  vector< int > integers1( 7 );
  vector< string > istr(5);


  istr[0]="wangtao";
  istr[1]="wangyanxi";
  istr[2]="22304";
  istr[3]="db:127.0.0.1;port:3306";
  for(size_t i=0; i<istr.size(); i++)
{
  cout << istr[i]<< endl;;
}


}




