#ifndef CLIENT_HPP
#define CLIENT_HPP

/**
 * @file Client.hpp
 * @brief Declaration of the Client class for the "Rock-Paper-Scissors" game.
 * 
 * This header file contains the declaration of the Client class, which is responsible for managing 
 * the connection to a game server in a networked version of the "Rock-Paper-Scissors" game.
 * 
 * The Client class provides methods to:
 * - Connect to the server.
 * - Send a player's move to the server.
 * - Receive the result of the opponent's move from the server.
 * - Close the connection to the server.
 */

#include <string>
#include <sys/socket.h>
#include <netinet/in.h>

class Client {
public:
    Client(const std::string& addr, int port);
    void connectToServer();
    void sendMove(const std::string& move);
    std::string receiveResult();
    void closeConnection();

private:
    std::string serverAddress;
    int port;
    int clientSocket;
};

#endif // CLIENT_HPP
