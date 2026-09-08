#include <iostream>
#include <sys/socket.h>
#include <unistd.h>
#include <fstream>
#include "networking/TcpListener.hpp"
#include <thread>

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


 
  listenSocketJob(serverSocketfd);  //// The Fd value gets passed to the function that binds the Socket (fd) and socket adress type
 
  Startlistening(serverSocketfd);   //// AFter the bind of the sokcet and address type the function get called to pass on the fd to apply listening API to the scoket
  
 while(true)
 {
  int clientSocketFd = StartAccepting(serverSocketfd); //// make var for the returned fd number,call function, make 2 vars to store adress and length(length us e data type and size of(adress)), tahn make a variable for the accapting socket use accept api
  //  inside the var on the socketfd and use cast for older adress because of code and mark start of memory of client adress and clientadress length 
  std::thread ClientThread (HandleClient, clientSocketFd);
  ClientThread.detach();/// detaches the thread to work standalone while the loop continues to loop allowing the 1st client to stay connected while a thread can accept another one
 
  if (serverSocketfd >= 0)
  {
   // prints to the terminal that the Socket got made correctly 
  std::cout << "Socket creation Succesful. FD: "
            << serverSocketfd << '\n';
  logWfile << "Main.cpp output: The Socket: " << serverSocketfd << "GOT TO  To Create";
  }
 }


  close(serverSocketfd);
 
  return 0;
 }


