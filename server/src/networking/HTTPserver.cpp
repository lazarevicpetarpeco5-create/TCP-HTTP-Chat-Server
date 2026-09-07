#include "HttpServer.hpp"

#include <iostream>
#include <string>
#include <sstream>

#include <sys/socket.h>
#include <unistd.h>


   




void HttpServer:: HandleRequest(int clientsocket)  {

char buffer[4096];

int bytesrecived = recv(clientsocket, buffer, sizeof(buffer) - 1, 0);

if (bytesrecived == -1)
{
    std::cerr << "recv failed\n";
    return;
} 
if (bytesrecived == 0)
{
    std::cout << "Client disconnected\n";
    return;
}


    buffer[bytesrecived] = '\0';

std::cout << buffer << std::endl;
} 