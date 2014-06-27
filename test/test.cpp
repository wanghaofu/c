#include <iostream>

using namespace std;

//This test operator rewrite
//这里进行类声明
class itest
{
  friend istream &operator>>( istream &input, itest &test);
  friend ostream &operator<<( ostream &output, itest &test);
  public:
  itest();
  int  operator+(int );
  int operator-(int);
  private:
  int num;
};


//istream &operator>>( istream &input, itest &test);
//ostream &operator<<( ostream &output, itest &test);


int main()
{
  itest test;
  cin >> test;
  cout<< test;
}


itest::itest()
{
  num=20;
}

int itest::operator+(int cnum)
{
  num= num+cnum;
  return num;
}
int itest::operator-(int inum)
{
  int s;
  s = num-inum;
  cout << "hello this is "<<num <<"-" << inum<< "is : " << s << endl;
  return s;
}

istream &operator>>( istream &input, itest &test)
{
  cout << "Please input you number: ";
  input>> test.num;
  return input;
}
ostream &operator<<( ostream &output, itest &test)
{
  output<<"You input the number is " <<  test.num << endl;
  return output;
}
