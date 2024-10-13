#ifndef GAME_HPP
#define GAME_HPP

/**
 * @file Game.hpp
 * @brief Definition of the Game class for the "Rock-Paper-Scissors" game.
 * 
 * The Game class manages the overall gameplay, including starting the game,
 * 
 * Main members:
 * - player1: The first player.
 * - player2: The second player.
 * - resultManager: Manages the results of the game.
 * - continueGame: A variable to determine whether the game continues or not.
 * 
 * Main methods:
 * - start: Initiates the game.
 * - playRound: Executes a single round of play.
 * - determineWinner: Determines the winner based on moves.
 */

#include "Player.hpp"
#include "ResultManager.hpp"
#include <memory>

class Game {
public:
    Game(std::shared_ptr<Player> p1, std::shared_ptr<Player> p2);
    void start();

private:
    std::shared_ptr<Player> player1;
    std::shared_ptr<Player> player2;
    ResultManager resultManager;
    bool continueGame;

    void playRound();
    std::string determineWinner(const std::string& move1, const std::string& move2);
};

#endif // GAME_HPP
