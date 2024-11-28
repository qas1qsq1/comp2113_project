#include <iostream>
#include "randomevent.h"
#include "player1.h"
#include "debuff1.h"

void applyDebuff(Player &player, int debuffType, RandomEvent &randomEvent) {
    int amount;
    switch(debuffType) {
        case 1:
            amount = randomEvent.generateRandom(5, 15);
            player.PlayerLife -= player.PlayerLife * (amount / 100.0);
            std::cout << "You feel weakened. Current health reduced by " << amount << "%." << std::endl;
            if (player.PlayerLife <=0){
                player.failed = true;
                std::cout <<"You are dead. Game over!" << endl;
            }
            break;
        case 2:
            amount = randomEvent.generateRandom(5, 15);
            player.PlayerMaxLife -= player.PlayerMaxLife * (amount / 100.0);
            std::cout << "You are injured. Max health reduced by " << amount << "%." << std::endl;
            break;
        case 3:
            amount = randomEvent.generateRandom(5, 12);
            player.attack -= player.attack * (amount / 100.0);
            std::cout << "Your attack power is reduced by " << amount << "%." << std::endl;
            break;
        case 4:
            amount = randomEvent.generateRandom(15, 25);
            player.PlayerMaxLife -= player.PlayerMaxLife * (amount / 100.0);
            player.PlayerLife = std::max(static_cast<int>(player.PlayerLife + player.PlayerMaxLife * 0.1), player.PlayerMaxLife);
            std::cout << "Your max health is reduced by " << amount << "%, and health increased by 10%." << std::endl;
            break;
    }
    if(player.health > player.PlayerMaxLife) {
        player.health = player.PlayerMaxLife;
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
