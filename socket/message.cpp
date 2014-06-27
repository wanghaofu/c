#include <iostream>


class protocol{
  public:
    void protocol(); 
    void ~protocol();
    message makeProtocol(struct message imsg);
  private:
    struct message imessage;
};


protocol::protocol()
{
}

protocol::~protocol()
{
}

protocol:: makeProtocol(Message imsg)
{
}

