//
// Created by Bdude on 5/12/2023.
//

#ifndef FARKLE_TURN_H
#define FARKLE_TURN_H

#include "Option.h"
#include "Player.h"

class Turn {
private:
    std::vector<int> dice;
    std::vector<int> occurrences;
    std::vector<Option> options;
    int score = 0;
    int numDice = 6;
public:
    Turn();
    void reroll();
    void display();
    void generateOptions();
    void displayOptions();
    bool chooseOption(int);
    void takeTurn(Player &player);
    void draw_dice();
    std::vector<Option>& getOptions();
    int getScore();
};



#endif //FARKLE_TURN_H
