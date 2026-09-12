# TCP / HTTP Chat Server

A C++ networking project focused on understanding TCP sockets, client-server communication, and the fundamentals of HTTP request handling.

The project is built from the ground up to explore how network connections work, how servers accept clients, and how data is exchanged between applications over TCP.

## 🚀 Project Overview

This project contains a TCP-based server and client written in C++.

The main goal is to understand the underlying mechanics of network communication rather than relying on high-level networking frameworks.

### Main concepts

* TCP socket programming
* Client-server architecture
* IP addresses and ports
* Socket creation and binding
* Listening for incoming connections
* Accepting client connections
* Sending and receiving data
* Handling client disconnections
* Basic HTTP request handling

## 🏗️ Architecture

The project follows a client-server model:

```text
                 TCP CONNECTION
┌──────────────┐                 ┌──────────────┐
│              │                 │              │
│    Client    │ ◄─────────────► │    Server    │
│              │                 │              │
└──────────────┘                 └──────────────┘
                                      │
                                      ▼
                              Accept connections
                                      │
                                      ▼
                              Receive client data
                                      │
                                      ▼
                              Process requests
                                      │
                                      ▼
                              Send responses
```

## 🛠️ Technologies

* **C++** — Core programming language
* **TCP/IP** — Network communication protocol
* **POSIX Sockets** — Low-level network programming on Linux
* **HTTP** — Exploration of request and response handling
* **Linux** — Development and testing environment

## 📂 Project Structure

```text
ChatServer/
├── Client/
│   └── Client source files
├── Server/
│   └── Server source files
├── TcpListener.cpp
├── TcpListener.h
├── HttpServer.cpp
├── HttpServer.h
└── README.md
```

> The structure above is a general overview. The exact file organization may vary depending on the current version of the project.

## ⚙️ How It Works

### 1. Creating a socket

The server creates a TCP socket that allows it to communicate over the network.

### 2. Binding to a port

The socket is bound to a local IP address and port so that clients can connect to the server.

### 3. Listening for connections

The server starts listening for incoming client connections.

### 4. Accepting clients

When a client connects, the server accepts the connection and obtains a socket dedicated to that client.

### 5. Receiving and sending data

The server uses socket operations such as `recv()` and `send()` to exchange data with the client.

### 6. Handling requests

The project also explores receiving HTTP requests and processing the data sent by an HTTP client.

## 🌐 HTTP Experiments

The project includes experimentation with HTTP communication over TCP.

For example, an HTTP client such as `curl` can connect to a TCP server and send an HTTP request:

```bash
curl -v http://127.0.0.1:5001/
```

This experiment helps demonstrate the relationship between HTTP and TCP:

* TCP provides the connection and reliable byte stream.
* HTTP defines the structure of requests and responses.
* The server must read and interpret the incoming HTTP data correctly.

## 🧪 Running the Project

### Clone the repository

```bash
git clone <YOUR_REPOSITORY_URL>
cd ChatServer
```

### Compile

Use the compilation command appropriate for the current source structure.

For example:

```bash
g++ -std=c++17 -Wall -Wextra -o server *.cpp
```

### Run the server

```bash
./server
```

### Run the client

Open another terminal and start the client using its executable or compilation command.

> Update the commands above to match the exact source files and build system used in the repository.

## 📚 What I Learned

Through this project, I explored:

* How TCP connections are established.
* How a server binds to a port and listens for clients.
* The difference between a listening socket and a connected client socket.
* How `send()` and `recv()` work.
* Why a return value of `0` from `recv()` indicates that the remote peer has closed its connection.
* How HTTP operates on top of TCP.
* The challenges of handling different types of network clients.

## 🔭 Future Improvements

Possible future improvements include:

* Support for multiple simultaneous clients.
* A more complete chat messaging system.
* Improved client disconnection handling.
* Better HTTP request parsing.
* A dedicated HTTP server port.
* Structured HTTP responses.
* A build system using CMake.
* Improved error handling and logging.
* A more modular networking architecture.

## 👤 Author

**Petar Lazarević**

This project is part of my journey into C++, networking, systems programming, and backend development.
