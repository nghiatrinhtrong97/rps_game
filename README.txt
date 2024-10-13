Rock-Paper-Scissors Game
Overview

This is a Rock-Paper-Scissors game that can be played in two modes:

    Play against the computer.
    Play against another player over a network (via socket client-server model).

Requirements

    C++ Compiler: GCC or any other C++ compiler supporting C++11 or above.
    Networking libraries: No additional libraries are required as the code uses standard POSIX sockets.

Compilation

To compile the program, use the following command:
(only Linux)

cd rps_game && make

This will generate an executable file named rps_game.

How to Run
Running in Play with Computer Mode

    After compiling, run the program:

    bash

    ./rps_game

    Choose 1 when asked for the game mode to play against the computer.
    Follow the prompts to make your moves (rock, paper, or scissors).
    You can choose to play multiple rounds, and the game will continue until you choose to quit.

Running in Play with Another Player Over Network

    Run the server on one machine:

    bash

./rps_game

    Choose 2 for network play.
    Choose s to run the server with localhost as default

Run the client on another machine:

bash

    ./rps_game

        Choose 2 for network play.
        Choose c to run the client with server address (127.0.0.1 for localhost).

    Both players will be prompted to make their moves. The result will be displayed, and you will be asked if you want to play again. Both players must agree to continue for the next round.


Future Improvements

    Better UI: The current interaction is text-based. In the future, a GUI can be added for better user experience.
    Encryption: Add encrypted communication between the client and server for secure network play (SSL/HTTPs)
