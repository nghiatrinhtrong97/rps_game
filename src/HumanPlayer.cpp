#include "HumanPlayer.hpp"
#include <iostream>

std::string HumanPlayer::makeMove() {
    std::string move;
    std::cout << "Enter move (rock, paper, scissors): ";
    std::cin >> move;
    return move;
}
