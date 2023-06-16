#include <iostream>
#include <vector>
#include <ctime>
#include "Turn.h"

int main() {
    srand(time(nullptr));
    std::cout << "Welcome to Farkle!" << std::endl;
    Player p1("Player 1",false);
    Player p2("AI 1",true);

    std::cout << "How many points would you like to play to? (Standard is 10000)\n";
    std::string line;
    std::getline(std::cin,line);
    int winCondition = std::stoi(line);
    while (!p1.hasWon(winCondition) && !p2.hasWon(winCondition)) {
        Turn currTurn;
        currTurn.takeTurn(p1);
        Turn nextTurn;
        nextTurn.takeTurn(p2);
    }
    if (p1.hasWon(winCondition)) {
       std::cout << p1.getName() << " won!";
    }
    else {
        std::cout << p2.getName() << " won!";
    }

    return 0;
}
