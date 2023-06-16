//
// Created by Bdude on 5/12/2023.
//

#include <vector>
#include "Turn.h"
#include "cstdlib"
#include "iostream"


Turn::Turn() {
    this->reroll();
}

void Turn::reroll() {
    this->occurrences.clear();
    dice.clear();
    options.clear();
    for (int i=0;i<numDice;i++) {
        occurrences.push_back(0);
    }
    for (int i =0;i<numDice;i++) {
       this->dice.push_back( std::rand() % 6 + 1);
       this->occurrences[this->dice[i]-1] += 1;
    }
}

void Turn::display() {
    std::cout << "Current Turn Score: " << score << "\n";
    std::cout << "Dice:\n";
    draw_dice();
}

void Turn::draw_dice() {
   std::vector<std::vector<std::string>> diceTextures;
   std::vector<std::string> one;
   one.emplace_back("-------");
   one.emplace_back("|     |");
   one.emplace_back("|  o  |");
   one.emplace_back("|     |");
   one.emplace_back("-------");
   diceTextures.push_back(one);

   std::vector<std::string> two;
   two.emplace_back("-------");
   two.emplace_back("|   o |");
   two.emplace_back("|     |");
   two.emplace_back("| o   |");
   two.emplace_back("-------");
   diceTextures.push_back(two);

    std::vector<std::string> three;
    three.emplace_back("-------");
    three.emplace_back("|   o |");
    three.emplace_back("|  o  |");
    three.emplace_back("| o   |");
    three.emplace_back("-------");
    diceTextures.emplace_back(three);

    std::vector<std::string> four;
    four.emplace_back("-------");
    four.emplace_back("| o o |");
    four.emplace_back("|     |");
    four.emplace_back("| o o |");
    four.emplace_back("-------");
    diceTextures.emplace_back(four);

    std::vector<std::string> five;
    five.emplace_back("-------");
    five.emplace_back("| o o |");
    five.emplace_back("|  o  |");
    five.emplace_back("| o o |");
    five.emplace_back("-------");
    diceTextures.emplace_back(five);

    std::vector<std::string> six;
    six.emplace_back("-------");
    six.emplace_back("| o o |");
    six.emplace_back("| o o |");
    six.emplace_back("| o o |");
    six.emplace_back("-------");
    diceTextures.emplace_back(six);

    for (int t=0;t<5;t++) {
        for (int i=0;i<3;i++){
            if (i < dice.size()) {
                std::cout << diceTextures[dice[i]-1][t] << "  ";
            }
        }
        std::cout << "\n";
    }
    for (int t=0;t<5;t++) {
        for (int i=3;i<6;i++){
            if (i < dice.size()) {
                std::cout << diceTextures[dice[i]-1][t] << "  ";
            }
        }
        std::cout << "\n";
    }
}

void Turn::generateOptions() {
    std::vector<int> singles;
    std::vector<int> doubles;
    std::vector<int> triples;
    options.clear();
    for (int i=0;i<occurrences.size();i++) {
       if (occurrences[i] == 1) {
           singles.push_back(i);
       }
       if (occurrences[i] == 2) {
           doubles.push_back(i);
       }
       if (occurrences[i] == 3) {
           triples.push_back(i);
           int diceUsed[6] {0,0,0,0,0,0};
           diceUsed[i] = 3;
           options.push_back(Option("Take triple "+std::to_string(i+1) + "s",(i+1)*100,3,diceUsed));
       }
        else if (occurrences[i] == 4) {
            int diceUsed[6] {0,0,0,0,0,0};
            diceUsed[i] = 4;
            options.push_back(Option("Take a set of four "+std::to_string(i+1) + "s",1000,4,diceUsed));
        }
       else if (occurrences[i] == 5) {
           int diceUsed[6] {0,0,0,0,0,0};
           diceUsed[i] = 5;
           options.push_back(Option("Take a set of five "+std::to_string(i+1) + "s",2000,5,diceUsed));
       }
       else if (occurrences[i] == 6) {
           int diceUsed[6] {0,0,0,0,0,0};
           diceUsed[i] = 6;
           options.push_back(Option("Take a set of six "+std::to_string(i+1) + "s",3000,6,diceUsed));
       }
    }
    if (singles.size() == 6) {
        int diceUsed[]  {1,1,1,1,1,1};
        options.push_back(Option("Take a straight 1-6!",1500,6,diceUsed));
    }
    if (doubles.size() == 3) {

        int diceUsed[6] {0,0,0,0,0,0};
        for (int i=0;i<3;i++){
            diceUsed[doubles[i]] = 2;
        }
        options.push_back(Option("Take three pairs!",1500,6,diceUsed));
    }
    if (triples.size() == 2) {
        int diceUsed[6] {0,0,0,0,0,0};
        for (int i=0;i<2;i++){
            diceUsed[triples[i]] = 3;
        }
        options.push_back(Option("Take two triplets!",2500,6,diceUsed));

    }
    if (occurrences[4] > 0) {
        int diceUsed[6] {0,0,0,0,0,0};
        diceUsed[4] = 1;
        options.push_back(Option("Take a 5",50,1,diceUsed));
    }
    if (occurrences[0] > 0) {
        int diceUsed[6] {0,0,0,0,0,0};
        diceUsed[0] = 1;
        options.push_back(Option("Take a 1",100,numDice,diceUsed));
    }


}

void Turn::displayOptions() {
    int number = 1;
    std::cout << "\n";
    for (auto option: options) {
        option.display(number++);
        std::cout << "\n";
    }
    if (options.size() == 0 && numDice == dice.size()) {
        std::cout << 1 << ": You Farkled! End turn and lose all points from this turn.\n";
    }
    else if (score > 0) {
        std::cout << number << ": Roll again\n";
        std::cout << number + 1 << ": Take it to the bank. (Ends Turn)\n";
    }

}

bool Turn::chooseOption(int choice) {
    //Display the diceUsed
//    for (int i=1;i<7;i++)
//        std::cout << i << ": " << options[choice-1].getAmountUsed(i) << "\n";
    if (options.size() == 0 && dice.size() == numDice) {
        score = 0;
        return false;
    }
    if (choice <= options.size()) {
        score += options[choice-1].getScore();
        std::vector<int> newDice;
        std::vector<int> newOccurrences(6,0);

        for (int die :dice) {
            if (newOccurrences[die-1] < (occurrences[die-1] - options[choice-1].getAmountUsed(die))) {
                newOccurrences[die-1]++;
                newDice.push_back(die);
            }
        }
        this->dice.clear();
        dice = newDice;
        this->occurrences.clear();
        occurrences = newOccurrences;
        options.clear();

        return true;
    }
    else if (choice == options.size()+1) {
        if (dice.size() == 0) {
            this->numDice = 6;
        }
        else {
            this->numDice = dice.size();
        }
        this->options.clear();
        this->reroll();
        return true;
    }
    else if (choice == options.size()+2) {
        return false;
    }
    else {
        std::cout << "Error";
        return true;
    }

}
void Turn::takeTurn(Player& player) {
    reroll();
    player.display();
    while (true) {
        display();
        generateOptions();
        displayOptions();
        int choice = player.getChoice(options,score);
        if (!chooseOption(choice)) {
            player+=this->score;
            break;
        }
    }
}
int Turn::getScore() {
    return score;
}

std::vector<Option>& Turn::getOptions() {
    return options;
}


