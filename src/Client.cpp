#include "Client.hpp"
#include <iostream>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <cstring> // for C++

Client::Client(const std::string& addr, int port) 
    : serverAddress(addr), port(port), clientSocket(-1) {}

void Client::connectToServer() {
    clientSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (clientSocket < 0) {
        std::cerr << "Error creating socket" << std::endl;
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in serverAddress;
    memset(&serverAddress, 0, sizeof(serverAddress));
    serverAddress.sin_family = AF_INET;
    inet_pton(AF_INET, this->serverAddress.c_str(), &serverAddress.sin_addr);
    serverAddress.sin_port = htons(port);

    if (connect(clientSocket, (struct sockaddr*)&serverAddress, sizeof(serverAddress)) < 0) {
        std::cerr << "Error connecting to server" << std::endl;
        exit(EXIT_FAILURE);
    }
}

void Client::sendMove(const std::string& move) {
    send(clientSocket, move.c_str(), move.size(), 0);
}

std::string Client::receiveResult() {
    char buffer[1024] = {0};
    recv(clientSocket, buffer, sizeof(buffer), 0);
    return std::string(buffer);
}

void Client::closeConnection() {
    close(clientSocket);
}
