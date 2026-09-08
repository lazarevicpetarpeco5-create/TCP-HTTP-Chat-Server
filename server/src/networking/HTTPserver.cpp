#include "HttpServer.hpp"
#include <iostream>
#include <string>
#include <sstream>
#include <thread>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

int HttpServer::Start() {

    sockaddr_in ServerAdress{};

    ServerAdress.sin_family = (AF_INET);
    ServerAdress.sin_port = htons(8080);
    ServerAdress.sin_addr.s_addr = INADDR_ANY;



  int HttpSerSocket = socket(AF_INET, SOCK_STREAM, 0);
  if (HttpSerSocket < 0)   
  {
   std::cerr << "[HTTP] socket() creation failed\n";
    return -1;
  } 
  
    if (bind(HttpSerSocket,
    reinterpret_cast<sockaddr*>(&ServerAdress),
    sizeof(ServerAdress)
    ) == -1 )
    {
    std::cerr << "bind() failed\n";
    return 1;
    }

   if (listen(HttpSerSocket, 5) == -1)
   {
    std::cerr << "listen() failed\n";
    return 1;
   }
   return HttpSerSocket;
}


void HttpServer::AcceptLoop(int HttpSerSocket){

while(true)
  { 
    ///Blocks connection until a client is connected 
    int HttpClient = accept(HttpSerSocket, )
     
    }

  if (clientsocket < 0) 
    {
    std::cerr << "[HTTP] accept() failed\n";
    continue;
    }
}




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