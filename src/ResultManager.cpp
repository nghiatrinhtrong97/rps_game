#include "ResultManager.hpp"
#include <iostream>

ResultManager::ResultManager() : wins(0), losses(0), draws(0) {}

void ResultManager::updateResult(const std::string& result) {
    if (result == "draw") {
        draws++;
    } else if (result == "Player 1 wins" || result == "Server wins!") {
        wins++;
    } else {
        losses++;
    }
}

void ResultManager::displayFinalResult() {
    std::cout << "Final results:" << std::endl;
    std::cout << "Wins: " << wins << std::endl;
    std::cout << "Losses: " << losses << std::endl;
    std::cout << "Draws: " << draws << std::endl;
}
