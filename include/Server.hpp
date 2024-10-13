#ifndef SERVER_HPP
#define SERVER_HPP


/**
 * @file Server.hpp
 * @brief Declaration of the Server class for managing network connections.
 * 
 * This header file contains the declaration of the Server class, which facilitates 
 * communication between a server and clients in the "Rock-Paper-Scissors" game.
 * 
 * The Server class is responsible for creating a socket, listening for incoming client 
 * connections, and handling the exchange of game moves and results over the network. 
 * It provides methods to start the server, receive a move from a connected client, 
 * send the result of a game round, and close the connection when done.
 */

#include <string>
#include <sys/socket.h>
#include <netinet/in.h>

class Server {
public:
    Server(int port);
    void start();
    std::string receiveMove();
    void sendResult(const std::string& result);
    void closeConnection();

private:
    int serverSocket;
    int clientSocket;
    int port;
    void acceptClient();
};

#endif // SERVER_HPP
