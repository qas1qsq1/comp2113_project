#include <iostream>
#include "winner.h"
using namespace std;

void findTopPlayer(Player* all_players, int player_num) {
    bool allFailed = true;
    int topScore = -1;   // An initial value of -1 indicates that the player with the highest score has not been found
    int topPlayerIndex = -1;
    int topScoreCount = 0; // Count the number of players with the highest score

    // Go through all the players, check if they all fail, and find the player with the highest score
    for (int i = 1; i < 1+player_num; i++) {
        if (!all_players[i].failed) {
            allFailed = false;  // At least one player was found not to have failed
            all_players[i].score = all_players[i].PlayerAttack + all_players[i].PlayerLife + all_players[i].PlayerMaxLife; // calculate the score of the player
            
            if (all_players[i].score > topScore) {
                topScore = all_players[i].score;
                topPlayerIndex = i;  // Record the index of the player with the highest score
                topScoreCount = 1;   // Reset count
            } else if (all_players[i].score == topScore) {
                topScoreCount++;    // If the score is the same, add 1 to the count
            }
        }
    }

    // Result
    if (allFailed) {
        cout << "All losers." << endl;
    } else if (topScoreCount > 1) {
        cout << "Draw." << endl; // If the number of players with the highest score exceeds 1, output Draw
    } else {
        cout << "Congratulations! Highest scoring player is: " << topPlayerIndex << endl;
        cout << "Score: " << topScore << endl;
    }
}

