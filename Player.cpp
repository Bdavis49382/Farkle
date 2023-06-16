//
// Created by Bdude on 5/23/2023.
//

#include <iostream>
#include <thread>
#include <chrono>
#include "Player.h"

Player::Player(std::string name, bool ai) {
   this->name = name;
   this->score = 0;
   this->ai = ai;

}

int Player::getChoice(std::vector<Option> options,int turnScore) {
    if (ai) {
        std::cout << "AI Player Responding...";
        std::this_thread::sleep_for(std::chrono::seconds(2));
        if (turnScore > 500){
            std::cout << options.size() + 2 << "\n";
            return options.size()+2;
        }
        std::cout << 1 << "\n";
        return 1;

    }
    else {
        std::string line;
        std::getline(std::cin, line);
        return std::stoi(line);
    }
}

bool Player::hasWon(int winCondition) {
    return this->score >= winCondition;
}

void Player::display() {
    std::cout << name << " Score: " << this->score << "\n";
}

std::string Player::getName() {
    return this->name;
}