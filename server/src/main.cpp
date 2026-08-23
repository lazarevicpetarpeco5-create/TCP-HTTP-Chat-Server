#include <iostream>
#include <sys/socket.h>
#include <unistd.h>
#include <fstream>


int main ()
{
  int serverSocket = socket(AF_INET, SOCK_STREAM, 0);
  

// Output stream object for our log file for succesful creation of socket

  std::ofstream logWfile("server.log", std::ios::app);

 if (serverSocket == -1)
  {
    
    std::cerr << "Socket creation failed\n";


    
    logWfile << "Socket creation failed\n";

    return 1;
  }




 // prints to the terminal that the Socket got made correctly 
  std::cout << "Socket creation Succesful. FD: "
            << serverSocket << '\n';

 // send a string messige to logs that the socket was created succesfully 

  logWfile << "Socket creation Succesful. FD: " << serverSocket << '\n';

  close(serverSocket);
  return 0;
}

