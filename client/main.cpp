#include <iostream>
#include <sys/socket.h>
#include <unistd.h>
#include <fstream>
#include "networking/client.hpp"


int clientsocket = ClientTcpSocket();

ConnectToServer (clientsocket);


