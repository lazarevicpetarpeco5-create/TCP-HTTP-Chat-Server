int ClientTcpSocket () 
{

    int clientSocket = socket(AF_INET, SOCK_STREAM, 0);
    std::cout <<  "TcpListener.cpp output: " << clientSocket << '\n'; 

    return clientSocket;
}


int ConnectToServer ()
{



    
}