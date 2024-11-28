#ifndef MAIN_H
#define MAIN_H

#include "randomevent.h"
#include "fight.h"
#include "buff.h"
#include "debuff1.h"
#include "player1.h"

void findTopPlayer(Player* all_players, int player_num)

// buff functions
void applyBuff(Player &player, int buffType, RandomEvent &randomEvent)
void buff(Player &player, RandomEvent &randomEvent)

// debuff functions
void applyDebuff(Player &player, int debuffType, RandomEvent &randomEvent)
void debuff(Player &player, RandomEvent &randomEvent)

// fight
void Fight(Player &player)

// randomevent

#endif
