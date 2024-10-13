#include <iostream>
#include <string>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h> // For close()
#include "GameManager.hpp"
#include <arpa/inet.h>

// bool isServerRunning(int port) {
//     int sock = socket(AF_INET, SOCK_STREAM, 0);
//     if (sock < 0) {
//         return false; // Socket creation failed
//     }

//     struct sockaddr_in serverAddress;
//     serverAddress.sin_family = AF_INET;
//     serverAddress.sin_addr.s_addr = inet_addr("127.0.0.1"); // Check localhost
//     serverAddress.sin_port = htons(port);

//     // Attempt to connect to the server
//     bool running = (connect(sock, (struct sockaddr*)&serverAddress, sizeof(serverAddress)) == 0);
    
//     close(sock); // Close the socket
//     return running; // Return true if connection succeeded, meaning server is running
// }

int main() {
    std::cout << "Choose game mode:\n";
    std::cout << "1. Play with computer\n";
    std::cout << "2. Play with another player over network\n";
    int choice;
    std::cin >> choice;

    if (choice == 1) {
        playWithComputer();
    } else if (choice == 2) {
        std::cout << "Do you want to be the server or client? (s/c): ";
        char mode;
        std::cin >> mode;
        const int DEFAULT_PORT = 1235; // Default port for the server

        if (mode == 's') {
            // int port;
            // std::cout << "Enter port: ";
            // std::cin >> port;
            playWithHumanOverNetwork(true, "", DEFAULT_PORT);
        } else if (mode == 'c') {
            // std::string address;
            std::string address = "127.0.0.1"; // Default server address
            // int port;
            std::cout << "Defult local host: 127.0.0.1 ";
            // std::cin >> address;
            // std::cout << "Enter port: ";
            // std::cin >> port;
            playWithHumanOverNetwork(false, address, DEFAULT_PORT);
        }
    }

    return 0;
}