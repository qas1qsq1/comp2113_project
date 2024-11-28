#include <iostream>
#include <cstdlib>
#include <ctime>
#include "player1.h"
#include "randomevent.h"

using namespace std;

//class RandomEvent {
//public:
//    RandomEvent() {
//        srand(time(nullptr));
//    }

//    int generateRandom(int min, int max) {
//        return rand() % (max - min + 1) + min;
//    }
//};

//struct Player {
//    int PlayerAttack;   
//    int PlayerLife;    
//    int PlayerMaxLife;  
//    int score;
//};

void applyBuff(Player &player, int buffType, RandomEvent &randomEvent) {
    int amount;
    switch(buffType) {
        case 1:
            amount = randomEvent.generateRandom(5, 15);
            player.PlayerAttack += player.PlayerAttack * (amount / 100.0);
            cout << "Your attack power increased by " << amount << "%." << endl;
            break;
        case 2:
            amount = randomEvent.generateRandom(10, 20);
            if (player.PlayerLife < player.PlayerMaxLife) {
                player.PlayerLife += amount;
                if (player.PlayerLife > player.PlayerMaxLife) {
                    player.PlayerLife = player.PlayerMaxLife;
                }
                cout << "Your life increased by " << amount << " points." << endl;
            } else {
                cout << "Your life is already at maximum. No increase applied." << endl;
            }
            break;
        case 3:
            amount = randomEvent.generateRandom(10, 20);
            player.PlayerMaxLife += amount;
            player.PlayerLife += amount; // Increase current life as well
            cout << "Your max life increased by " << amount << " points, and current life adjusted." << endl;
            break;
    }
}

void buff(Player &player, RandomEvent &randomEvent) {
    int buffType = randomEvent.generateRandom(1, 3);
    
    cout << "A buff effect is applied:" << endl;

    switch(buffType) {
        case 1: cout << "1. Increase attack power by a random percentage." << endl; break;
        case 2: cout << "2. Increase life by a random number of points." << endl; break;
        case 3: cout << "3. Increase max life by a random number of points." << endl; break;
    }

    applyBuff(player, buffType, randomEvent);

    cout << "Your life is: " << player.PlayerLife << endl;
    cout << "Your max life is: " << player.PlayerMaxLife << endl;
    cout << "Your attack is: " << player.PlayerAttack << endl;
}

//int main() {
//    RandomEvent randomEvent; 


//    int previousAttack;
//    int previousLife;
//    int previousMaxLife; 

//    Player player = {previousAttack, previousLife, previousMaxLife, 0}; 

//    buff(player, randomEvent); 

//    return 0;
//}
