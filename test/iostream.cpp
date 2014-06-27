#include <iostream>
#include <string>
using namespace std;
int ss();
class me
{
  public:
     me();
     void test(string);
  private:
    string host;
};
int main()
{
  ss();
  cout << "hello";
  me ime;
  ime.test("wangtao and wangyanxi this is good!");  

}
int ss()
{
  cout << "hello wangtao";
  return 0;
}

me::me()
{
  cout << "i is me";
}
void me::test(string name)
{
  cout << name;
}
