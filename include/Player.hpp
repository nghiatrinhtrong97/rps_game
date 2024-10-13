#ifndef PLAYER_HPP
#define PLAYER_HPP

/**
 * @file Player.hpp
 * @brief Declaration of the Player class for the "Rock-Paper-Scissors" game.
 * 
 * This header file contains the declaration of the abstract Player class, which serves as a 
 * base class for all player types in the "Rock-Paper-Scissors" game. 
 * 
 * The Player class provides a pure virtual function, `makeMove`, which must be implemented 
 * by derived classes to specify how each player makes a move (i.e., "rock", "paper", or "scissors").
 */

#include <string>

class Player {
public:
    virtual ~Player() = default;
    virtual std::string makeMove() = 0; // Move: "rock", "paper", or "scissors"
};

#endif // PLAYER_HPP