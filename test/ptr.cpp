#include <iostream>
#include <cstdlib>
#include <string>
#include <string.h>


using namespace std;

int p1(int &);
char p2(char *);


int main()
{
int a=3;
cout << p1(a);

char x='g';
cout << p2(&x);
}


int p1(int &num)
{
  int inum;
  inum=num*2;
  return inum;
}

char p2(char *name)
{
  char iname;
  iname=*name;
  return iname;
}
