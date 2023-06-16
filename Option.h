//
// Created by Bdude on 5/12/2023.
//

#ifndef FARKLE_OPTION_H
#define FARKLE_OPTION_H

#include <vector>
#include "string"


class Option {
private:
    int score;
    int numDiceUsed;
    std::string text;
    int diceUsed[6];
public:
    Option(std::string text,int score,int numDiceUsed, int diceUsed[]);
    void display(int number);
    Option operator+(const Option otherOption) {
       return Option(text + " and " + otherOption.text,score + otherOption.score,numDiceUsed + otherOption.numDiceUsed,diceUsed);
    }
    bool operator!=(const Option otherOption) {
        return text != otherOption.text;
    }
    int getScore();
    int getAmountUsed(int);
};


#endif //FARKLE_OPTION_H
