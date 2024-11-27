#ifndef DEBUFF_H
#define DEBUFF_H

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "player.h"
#include "randomevent.h"

//class RandomEvent {
//public:
//    RandomEvent() {
//        std::srand(std::time(nullptr));
//    }

//   int generateRandom(int min, int max) {
//        return std::rand() % (max - min + 1) + min;
//    }
//};
void applyDebuff(Player &player, int debuffType, RandomEvent &randomEvent);
void debuff(Player &player, RandomEvent &randomEvent);

#endif