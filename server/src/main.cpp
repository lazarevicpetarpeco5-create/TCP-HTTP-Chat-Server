#include <iostream>
///#include <sys/socket.h>
#include <unistd.h>
#include <fstream>
#include "networking/TcpListener.hpp"

// Output stream object for our log file for succesful creation of socket
  std::ofstream logWfile("server.log", std::ios::app);


int main ()
{

  int serverSocketfd = CreateTcpSocket ();



  if (serverSocketfd >= 0)
  {
  std::cout <<  "Main.cpp output socket fd import succsesfull: " << serverSocketfd << '\n';
  logWfile << "socket fd import succsesfull";
  }



  if (serverSocketfd == -1)
  {
    std::cout << "Main.cpp output: The Socket: " << serverSocketfd << "Failed To Create";
    logWfile << "Main.cpp output: The Socket: " << serverSocketfd << "Failed To Create";
    return 1;
  }



  listenSocketJob(serverSocketfd);  //// The Fd value gets passed to the function that binds the Socket (fd) and listening socket properties(job)
  if (serverSocketfd >= 0)
  {
   // prints to the terminal that the Socket got made correctly 
  std::cout << "Socket creation Succesful. FD: "
            << serverSocketfd << '\n';
  logWfile << "Main.cpp output: The Socket: " << serverSocketfd << "GOT TO  To Create";
  }



  close(serverSocketfd);
  return 0;
}

