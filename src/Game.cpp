#include "Game.hpp"
#include <iostream>

Game::Game(std::shared_ptr<Player> p1, std::shared_ptr<Player> p2)
    : player1(p1), player2(p2), continueGame(true) {}

void Game::start() {
    while (continueGame) {
        playRound();
        char choice;
        std::cout << "Do you want to continue playing? (y/n): ";
        std::cin >> choice;
        continueGame = (choice == 'y' || choice == 'Y');
    }
    resultManager.displayFinalResult();
}

void Game::playRound() {
    std::string move1 = player1->makeMove();
    std::string move2 = player2->makeMove();

    std::cout << "Player 1 plays: " << move1 << std::endl;
    std::cout << "Player 2 plays: " << move2 << std::endl;

    std::string result = determineWinner(move1, move2);
    std::cout << result << std::endl;

    resultManager.updateResult(result);
}

std::string Game::determineWinner(const std::string& move1, const std::string& move2) {
    if (move1 == move2) return "draw";
    if ((move1 == "rock" && move2 == "scissors") ||
        (move1 == "scissors" && move2 == "paper") ||
        (move1 == "paper" && move2 == "rock")) {
        return "Player 1 wins";
    }
    return "Player 2 wins";
}
