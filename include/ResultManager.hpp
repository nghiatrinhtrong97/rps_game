#ifndef RESULT_MANAGER_HPP
#define RESULT_MANAGER_HPP

/**
 * @file ResultManager.hpp
 * @brief Declaration of the ResultManager class for managing game results.
 * 
 * This header file contains the declaration of the ResultManager class, which is responsible 
 * for tracking and displaying the results of the "Rock-Paper-Scissors" game. 
 * 
 * The ResultManager keeps count of wins, losses, and draws, and provides methods to update 
 * these counts based on the outcomes of the game rounds, as well as to display the final results 
 * after the game concludes.
 */

#include <iostream>

class ResultManager {
public:
    ResultManager();
    void updateResult(const std::string& result);
    void displayFinalResult();

private:
    int wins;
    int losses;
    int draws;
};

#endif // RESULT_MANAGER_HPP
