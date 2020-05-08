//
// Created by bradon on 1/21/20.
//

#ifndef INHERITANCEWIZARD_WIZARD_H
#define INHERITANCEWIZARD_WIZARD_H

using namespace std;
#include "Character.h"

class Wizard : public Character {
private:
    int magic;
public:
    Wizard(string name, int hp, int magic) : Character(name, hp), magic(magic) {}

    void startBattle(){
        int attack = (rand() % 10) + 2 + magic;
        int defence = (rand() % 10) + 2;
    }

};


#endif //INHERITANCEWIZARD_WIZARD_H
