#ifndef GAMEMANAGER_HPP
#define GAMEMANAGER_HPP

/**
 * @file GameManager.hpp
 * @brief Declaration of functions for managing the game modes in the "Rock-Paper-Scissors" game.
 * 
 * This header file contains declarations for functions that handle different game modes,
 * including playing against the computer and playing against another human over the network.
 * 
 * Functions:
 * - playWithComputer(): Initiates a game session where the player competes against a computer.
 * - playWithHumanOverNetwork(): Initiates a game session where the player competes against another human
 *   over a network, specifying whether the current player is a server or client.
 */

#include <memory>
#include <string>
#include "Player.hpp"

void playWithComputer();
void playWithHumanOverNetwork(bool isServer, const std::string& address, int port);

#endif // GAMEMANAGER_HPP
