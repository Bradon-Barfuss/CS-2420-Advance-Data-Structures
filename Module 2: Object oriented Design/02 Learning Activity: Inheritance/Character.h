//
// Created by bradon on 1/21/20.
//

#ifndef INHERITANCEWIZARD_CHARACTER_H
#define INHERITANCEWIZARD_CHARACTER_H

#include <string>
#include <iostream>
#include <random>
#include <ctime>

using namespace std;

class Character {
    private:
protected:
    string name;
    int hp;
    int defence;
    int attack;

public:
        Character(string name, int hp): name(name), hp(hp){}

        virtual void startBattle(){
            attack = (rand() % 10) + 2;
            defence = (rand() % 10) + 2;
        }
        virtual void takeDamage(int damage){
            hp -= damage;
        }
        void battle(Character *enemy){
            if(attack > enemy->defence){
                int damage = attack - defence;
                enemy->takeDamage(damage);
                cout << endl << name << " hits for " << damage;
            }
            else{
                cout <<endl << name << " attempts but is blocked\n";
            }
        }
        int getHp(){
            return hp;
        }
        friend ostream &operator << (ostream &out, const Character &c){
            out << c.name << " HP:" << c.hp << endl;

            return out;
        }
};


#endif //INHERITANCEWIZARD_CHARACTER_H
