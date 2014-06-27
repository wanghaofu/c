#include <iostream>

using namespace std;

template<typename Tem>
void ttest( Tem ss)
{
  cout << ss;
}

int main()
{
  ttest(20);
  ttest("haha");
  ttest("22.3");
}

