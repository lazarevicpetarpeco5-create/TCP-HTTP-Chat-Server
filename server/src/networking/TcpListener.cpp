#include "TcpListener.hpp"
#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>




///// Old School Chat Memory

char textmsgsize[1024];




int CreateTcpSocket () 
{

    int serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    std::cout <<  "TcpListener.cpp output: " << serverSocket << '\n'; 

    return serverSocket;
}



int listenSocketJob (int serverSocketfd)
{
    sockaddr_in ServerAdress{};

    ServerAdress.sin_family = (AF_INET);
    ServerAdress.sin_port = htons(5000);
    ServerAdress.sin_addr.s_addr = INADDR_ANY;
    
    if ( bind(
        serverSocketfd,
        reinterpret_cast<sockaddr*>(&ServerAdress),
        sizeof(ServerAdress)
        ) == -1 )
        {
            std::cerr << "bind() failed\n";
            return 1;
        }
    return 0;    
}

int Startlistening (int serverSocketfd)
{
   /// check if listening is started 
   if (listen(serverSocketfd, 5) == -1)
   {

    std::cerr << "listen() failed\n";
    
    return 1;
   }
   return 0;
}

int StartAccepting (int serverSocketfd)
{  
    sockaddr_in ClientAdress{};
    socklen_t ClientAdressLength = sizeof(ClientAdress);
  
   int clientaccepted = accept
    (serverSocketfd,
        reinterpret_cast<sockaddr*>
        (&ClientAdress),
        &ClientAdressLength);
    
 if (clientaccepted == -1)       
 {
    std::cerr << "Accepting() failed\n";
    return -1;
 }
return clientaccepted;
}


int ReciveData (int clientSocketFd)
{
  size_t msgsize = sizeof(textmsgsize);

  int RecevedData = 
        recv(clientSocketFd,
        textmsgsize,
        sizeof(textmsgsize),
        0);

  if (RecevedData == -1 )
  {
    std::cerr << "Recv() failed\n";
    return -1;
  }       

  return ;
}
