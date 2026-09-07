#include "client.hpp"
#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string>

 char message[1024];


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
    
    std::cout << "Connected to server!\n";
    return connectionresult;
}


void Sendingmessige (int clientsocket)
{

 std::string message;
 std::cout << "Write the message: "; 
 while(true)
 {
 std::getline(std::cin, message);




 ssize_t result = send(clientsocket, message.c_str(), message.size(), 0);
 std::cout << "User Sent: " << result << '\n';
 }

}