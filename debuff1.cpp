#include <iostream>
#include "randomevent.h"
#include "player1.h"
#include "debuff1.h"

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

/*
 * Function: applyDebuff
 * Applies a specified debuff to a Player, modifying attributes based on the buff type.
 *
 * Inputs:
 * - Player &player: The player to be buffed.
 * - int debuffType: Type of debuff (1 for current life reduce, 2 for max life reduce, 3 for attack reduce, 4 for max life reduce and current life increase).
 * - switch: Used to generate random values for the debuffs.
 *
 * Outputs:
 * - Modifies the Player's attack power, current life, or maximum life directly.
 * - Print messages to indicate the changes.
 */

void applyDebuff(Player &player, int debuffType, RandomEvent &randomEvent) {
    int amount;
    switch(debuffType) {
        case 1:
            amount = randomEvent.generateRandom(1, 10);
            player.PlayerLife -= player.PlayerLife * (amount / 100.0);
            std::cout << "You feel weakened. Current life reduced by " << amount << "%." << std::endl;
            if (player.PlayerLife <=0){
                player.failed = true;
                std::cout <<"You are dead. Game over!" << std::endl;
            }
            break;
        case 2:
            amount = randomEvent.generateRandom(1, 10);
            player.PlayerMaxLife -= player.PlayerMaxLife * (amount / 100.0);
            std::cout << "You are injured. Max life reduced by " << amount << "%." << std::endl;
            break;
        case 3:
            amount = randomEvent.generateRandom(1, 10);
            player.PlayerAttack -= player.PlayerAttack * (amount / 100.0);
            std::cout << "Your attack power is reduced by " << amount << "%." << std::endl;
            break;
        case 4:
            amount = randomEvent.generateRandom(1, 10);
            player.PlayerMaxLife -= player.PlayerMaxLife * (amount / 100.0);
            player.PlayerLife = std::max(static_cast<int>(player.PlayerLife + player.PlayerMaxLife * 0.1), player.PlayerMaxLife);
            std::cout << "Your max life is reduced by " << amount << "%, and life increased by 10%." << std::endl;
            break;
    }
    if(player.PlayerLife > player.PlayerMaxLife) {
        player.PlayerLife = player.PlayerMaxLife;
    }
}

void debuff(Player &player, RandomEvent &randomEvent) {
    int debuff1 = randomEvent.generateRandom(1, 4);
    int debuff2;
    do {
        debuff2 = randomEvent.generateRandom(1, 4);
    } while(debuff2 == debuff1);

    std::cout << "Choose a debuff effect to apply:" << std::endl;

    for (int i = 1; i <= 4; ++i) {
        if (i == debuff1 || i == debuff2) {
            std::cout << i << ". ";
            switch(i) {
                case 1: std::cout << "Reduce current health by a random percentage." << std::endl; break;
                case 2: std::cout << "Reduce max health by a random percentage." << std::endl; break;
                case 3: std::cout << "Reduce attack power by a random percentage." << std::endl; break;
                case 4: std::cout << "Reduce max health by a random percentage and increase health by 10%." << std::endl; break;
            }
        }
    }

    int choice;
    std::cin >> choice;

    applyDebuff(player, choice, randomEvent);

    std::cout << "Your health is: " << player.PlayerLife << std::endl;
    std::cout << "Your max health is: " << player.PlayerMaxLife << std::endl;
    std::cout << "Your attack is: " << player.PlayerAttack << std::endl;
}

//int main() {
//    RandomEvent randomEvent;
//    Player player = {randomEvent.generateRandom(80, 120),
//                     randomEvent.generateRandom(80, 100),
//                     randomEvent.generateRandom(80, 100),
//                     0};

//    debuff(player, randomEvent);

//    return 0;
//}

//    debuff(player, randomEvent);

//    return 0;
//}
