#pragma once


class HttpServer
{
  public:
  // Creates, binds, and listens on port 8080 (returns the server socket FD)
     int Start();
  // Infinite loop that accepts client sockets and spawns threads
     void  AcceptLoop(int HttpSerSocket);
  // Handles the individual client socket  
     void HandleRequest(int clientsocket);
};
