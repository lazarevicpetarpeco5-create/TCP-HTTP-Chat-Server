#include <iostream>
#include <sys/socket.h>
#include <unistd.h>
#include <fstream>
#include "networking/client.hpp"


int main ()  
{



int clientsocket = ClientTcpSocket();

int connectionresult = ConnectToServer(clientsocket);




Sendingmessige(clientsocket);
    

return 0;
}
