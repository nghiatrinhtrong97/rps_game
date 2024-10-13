#include "Server.hpp"
#include <iostream>
#include <cstring>
#include <unistd.h>

Server::Server(int port) : port(port) {
    serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocket < 0) {
        std::cerr << "Error creating socket" << std::endl;
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in serverAddress;
    memset(&serverAddress, 0, sizeof(serverAddress));
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_addr.s_addr = INADDR_ANY;
    serverAddress.sin_port = htons(port);

    if (bind(serverSocket, (struct sockaddr*)&serverAddress, sizeof(serverAddress)) < 0) {
        std::cerr << "Error binding socket" << std::endl;
        exit(EXIT_FAILURE);
    }

    listen(serverSocket, 1);
    std::cout << "Server listening on port " << port << std::endl;
}

void Server::acceptClient() {
    clientSocket = accept(serverSocket, nullptr, nullptr);
    if (clientSocket < 0) {
        std::cerr << "Error accepting client" << std::endl;
        return;
    }
    std::cout << "Client connected!" << std::endl;
}

void Server::start() {
    acceptClient();
}

std::string Server::receiveMove() {
    char buffer[1024] = {0};
    recv(clientSocket, buffer, sizeof(buffer), 0);
    return std::string(buffer);
}

void Server::sendResult(const std::string& result) {
    send(clientSocket, result.c_str(), result.size(), 0);
}

void Server::closeConnection() {
    close(clientSocket);
    close(serverSocket);
}
