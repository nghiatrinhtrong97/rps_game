#include <iostream>
#include <memory>
#include "Game.hpp"
#include "HumanPlayer.hpp"
#include "ComputerPlayer.hpp"
#include "Server.hpp"
#include "Client.hpp"
#include "GameManager.hpp"

void playWithComputer() {
    std::shared_ptr<Player> humanPlayer = std::make_shared<HumanPlayer>();
    std::shared_ptr<Player> computerPlayer = std::make_shared<ComputerPlayer>();

    Game game(humanPlayer, computerPlayer);
    
    char continuePlaying;
    do {
        game.start();
        std::cout << "Do you want to play again with the computer? (y/n): ";
        std::cin >> continuePlaying;
    } while (continuePlaying == 'y' || continuePlaying == 'Y');
}

void playWithHumanOverNetwork(bool isServer, const std::string& address, int port) {
    std::shared_ptr<Player> humanPlayer = std::make_shared<HumanPlayer>();
    std::string move;
    int humanWins = 0, opponentWins = 0, ties = 0;

    if (isServer) {
        Server server(port);
        server.start();

        char continuePlayingServer, continuePlayingClient;
        do {
            move = humanPlayer->makeMove();
            server.sendResult(move);
            std::string opponentMove = server.receiveMove();
            std::cout << "Opponent plays: " << opponentMove << std::endl;

            // Determine the result of the game
            if (move == opponentMove) {
                std::cout << "It's a tie!" << std::endl;
                ties++;
            } else if ((move == "rock" && opponentMove == "scissors") ||
                       (move == "scissors" && opponentMove == "paper") ||
                       (move == "paper" && opponentMove == "rock")) {
                std::cout << "You win!" << std::endl;
                humanWins++;
            } else {
                std::cout << "Opponent wins!" << std::endl;
                opponentWins++;
            }

            std::cout << "Scores - You: " << humanWins << ", Opponent: " << opponentWins << ", Ties: " << ties << std::endl;

            // Ask both players if they want to continue
            std::cout << "Do you want to play again? (y/n): ";
            std::cin >> continuePlayingServer;
            server.sendResult(continuePlayingServer == 'y' || continuePlayingServer == 'Y' ? "yes" : "no");

            // Wait for the opponent's response
            continuePlayingClient = server.receiveMove()[0]; // Assuming the opponent's response is a single character

        } while ((continuePlayingServer == 'y' || continuePlayingServer == 'Y') && (continuePlayingClient == 'y' || continuePlayingClient == 'Y'));
        
        // Print summary
        std::cout << "Final Scores - You: " << humanWins << ", Opponent: " << opponentWins << ", Ties: " << ties << std::endl;
        server.closeConnection();
    } else {
        Client client(address, port);
        client.connectToServer();

        char continuePlayingServer, continuePlayingClient;
        do {
            move = humanPlayer->makeMove();
            client.sendMove(move);
            std::string opponentMove = client.receiveResult();
            std::cout << "Opponent plays: " << opponentMove << std::endl;

            // Determine the result of the game
            if (move == opponentMove) {
                std::cout << "It's a tie!" << std::endl;
                ties++;
            } else if ((move == "rock" && opponentMove == "scissors") ||
                       (move == "scissors" && opponentMove == "paper") ||
                       (move == "paper" && opponentMove == "rock")) {
                std::cout << "You win!" << std::endl;
                humanWins++;
            } else {
                std::cout << "Opponent wins!" << std::endl;
                opponentWins++;
            }

            std::cout << "Scores - You: " << humanWins << ", Opponent: " << opponentWins << ", Ties: " << ties << std::endl;

            // Ask both players if they want to continue
            std::cout << "Do you want to play again? (y/n): ";
            std::cin >> continuePlayingClient;
            client.sendMove(continuePlayingClient == 'y' || continuePlayingClient == 'Y' ? "yes" : "no");

            // Wait for the server's response
            continuePlayingServer = client.receiveResult()[0]; // Assuming the server's response is a single character

        } while ((continuePlayingClient == 'y' || continuePlayingClient == 'Y') && (continuePlayingServer == 'y' || continuePlayingServer == 'Y'));
        
        // Print summary
        std::cout << "Final Scores - You: " << humanWins << ", Opponent: " << opponentWins << ", Ties: " << ties << std::endl;
        
        client.closeConnection();
    }
}
