//
// Created by Bdude on 5/12/2023.
//

#include "Option.h"
#include "iostream"

Option::Option(std::string text,int score,int numDiceUsed,int diceUsed[]) {
   this->text = text;
   this->score = score;
   this->numDiceUsed = numDiceUsed;
   for (int i=0;i<6;i++) {
       this->diceUsed[i] = diceUsed[i];

   }
}

void Option::display(int number) {
    std::cout << number << ": " << text << ". Worth " << score << " points.";
}

int Option::getScore() {
    return this->score;
}
int Option::getAmountUsed(int die) {
    return this->diceUsed[die-1];
}