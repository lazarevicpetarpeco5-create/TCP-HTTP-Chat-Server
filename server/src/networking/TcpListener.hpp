#pragma once

int CreateTcpSocket ();
int listenSocketJob (int serverSocketfd);
int Startlistening  (int serverSocketfd);
int StartAccepting  (int serverSocketfd);
int ReciveData      (int clientSocketFd);
void Messigechat   (int RecevedData);
void HandleClient(int clientSocketFd);