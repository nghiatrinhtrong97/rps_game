#ifndef HUMAN_PLAYER_HPP
#define HUMAN_PLAYER_HPP

/**
 * @file HumanPlayer.hpp
 * @brief Declaration of the HumanPlayer class for human player interaction.
 * 
 * The HumanPlayer class extends the Player class and implements the makeMove() 
 * method to allow the user to input their move (rock, paper, or scissors) via 
 * standard input. It prompts the user for their choice and returns the selected move.
 */

#include "Player.hpp"
#include <iostream>

class HumanPlayer : public Player {
public:
    std::string makeMove() override;
};

#endif // HUMAN_PLAYER_HPP
