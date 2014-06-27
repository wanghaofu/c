#include <iostream>
#include <map>

using namespace std;
int main()
{
  map <string,string> imap;

  imap["name"]="hello";
  imap["sex"]="boy";
  cout << imap["name"];
}
