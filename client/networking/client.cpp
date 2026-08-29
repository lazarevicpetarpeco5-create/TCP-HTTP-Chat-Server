#include "TcpListener.hpp"
#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>



int ClientTcpSocket () 
{

    int clientsocket = socket(AF_INET, SOCK_STREAM, 0);
    std::cout <<  "client.cpp output: " << clientsocket << '\n'; 

    return clientsocket;
}


int ConnectToServer (int clientsocket)
{

    sockaddr_in ServerAdress{};

    ServerAdress.sin_family = (AF_INET);
    ServerAdress.sin_port = htons(5001);
    inet_pton(AF_INET, "127.0.0.1", &ServerAdress.sin_addr);

   int connectionresult = connect
    (clientsocket,
        reinterpret_cast<sockaddr*>
        (&ServerAdress),
        sizeof(ServerAdress)
    );

    if (connectionresult == -1)
    {
        std::cerr << "connect() failed\n";
        return -1;
    }
   
    return connectionresult;
}