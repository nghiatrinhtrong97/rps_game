#ifndef COMPUTER_PLAYER_HPP
#define COMPUTER_PLAYER_HPP

/**
 * @file ComputerPlayer.hpp
 * @brief Definition of the ComputerPlayer class for the "Rock-Paper-Scissors" game.
 * 
 * The ComputerPlayer class inherits from the Player class and implements the logic
 * for making random moves in the game.
 */

#include "Player.hpp"
#include <cstdlib>
#include <ctime>

class ComputerPlayer : public Player {
public:
    ComputerPlayer();

    std::string makeMove() override;
};

#endif // COMPUTER_PLAYER_HPP
