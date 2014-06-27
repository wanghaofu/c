#include <iostream>
#include <map>
#include <string>
using namespace std;
int main()
{
typedef map< string , string> Config;

Config db;
db["host"]="localhost";
db["port"] = "3306";
db["screen"] = "3306*1980";
cout << db["host"] << endl;

for( Config::const_iterator iter = db.begin(); iter != db.end(); ++iter )
  cout << iter->first << "\t" << iter->second<< "\n";

  //cout << dbConfig['host'] ;
}


