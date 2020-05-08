#include <iostream>
#include "Wizard.h"

using namespace std;


int main() {
    srand(time(nullptr));


    cout << "Wizard Battle!" << endl;
    Character *gandolf = new Wizard("gandolf", 100, 9);
    Wizard *saron = new Wizard("Saron", 100, 7);

    do{
        saron->startBattle();
        gandolf->startBattle();
        cout << endl;

        saron->battle(gandolf);
        gandolf->battle(saron);

        cout << *gandolf;
        cout << *saron << endl;

    } while (saron->getHp() > 0 && gandolf->getHp() > 0);


    return 0;
}