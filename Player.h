//
// Created by Bdude on 5/23/2023.
//

#ifndef FARKLE_PLAYER_H
#define FARKLE_PLAYER_H


#include <string>
#include <vector>

#include "cstdlib"
#include "Option.h"

class Player {
private:
    std::string name;
    int score;
    bool ai;
public:
    Player(std::string name,bool ai);
    int getChoice(std::vector<Option>,int turnScore);
    bool hasWon(int winCondition);
    void display();
    Player& operator+=(const int turnScore) {
        this->score+=turnScore;
        return *this;
    }
    std::string getName();
};


#endif //FARKLE_PLAYER_H
