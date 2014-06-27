#include "ServerSocket.h"
#include "SocketException.h"
#include <string>
#include <iostream>
#include <cstdlib>
using namespace std;

struct message{
  string name;
  string sex;
  int length; 
};
typedef struct message Message;
int main ( int argc, int argv[] )
{
  Message imessage={"wangtao","body",23};
  std::cout << "running....\n";


  try
  {
    // Create the socket
    ServerSocket server ( 3000 );
    while ( true )
    {
      ServerSocket new_sock;
      server.accept ( new_sock );

      try
      {
        while ( true )
        {
          std::string data;
          new_sock >> data;
          cout << "client message is :" << data << endl;
          new_sock <<  data ;
        }
      }
      catch ( SocketException& ) {}
    }
  }
  catch ( SocketException& e )
  {
    std::cout << "Exception was caught:" << e.description() << "\nExiting.\n";
  }

  return 0;
}


