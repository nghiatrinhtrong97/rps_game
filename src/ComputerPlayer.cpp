#include "ComputerPlayer.hpp"

ComputerPlayer::ComputerPlayer() {
    std::srand(std::time(nullptr)); // Seed random number generator
}

std::string ComputerPlayer::makeMove() {
    int randomMove = std::rand() % 3;
    if (randomMove == 0) return "rock";
    else if (randomMove == 1) return "paper";
    else return "scissors";
}