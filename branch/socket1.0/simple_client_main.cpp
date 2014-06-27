#include "ClientSocket.h"
#include "SocketException.h"
#include <iostream>
#include <string>
#include <cstring>
using namespace std;
int main ( int argc, int argv[] )
{
  try
  {

    ClientSocket client_socket ( "localhost", 3000 );

    string reply;
    string message;
    while(2)
    {
      cout  <<"Send :" ;

      getline(cin,message);

      if(message.empty())
      {
        continue;
      }
      try
      {
        client_socket << message;
        client_socket >> reply;
      }
      catch ( SocketException& ) {}

      std::cout << "Server Message:" << reply << "\n";;
      if( message == "quit")
      {
        cout << "I will quit Bye!" << endl;
        return 0;
      }
    }
  }
  catch ( SocketException& e )
  {
    std::cout << "Exception was caught:" << e.description() << "\n";
  }

  return 0;
}


