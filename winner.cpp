#include <iostream>
#include "winner.h"
using namespace std;

void findTopPlayer(Player* all_players, int player_num) {
    bool allFailed = true;
    int topScore = -1;   // 初始值为 -1 表示尚未找到最高分玩家
    int topPlayerIndex = -1;
    int topScoreCount = 0; // 计数最高分玩家的数量

    // 遍历所有玩家，检查是否全部失败，并找出得分最高的玩家
    for (int i = 0; i < player_num; i++) {
        if (!all_players[i].failed) {
            allFailed = false;  // 发现至少有一个玩家未失败
            all_players[i].score = all_players[i].PlayerAttack + all_players[i].PlayerLife + all_players[i].PlayerMaxLife; // 计算该玩家的得分
            
            if (all_players[i].score > topScore) {
                topScore = all_players[i].score;
                topPlayerIndex = i;  // 记录最高分玩家的索引
                topScoreCount = 1;   // 重置计数
            } else if (all_players[i].score == topScore) {
                topScoreCount++;    // 如果得分相同，计数加 1
            }
        }
    }

    // 判断结果
    if (allFailed) {
        cout << "All losers." << endl;
    } else if (topScoreCount > 1) {
        cout << "Draw." << endl; // 如果最高分玩家数量超过 1，输出 Draw
    } else {
        cout << "Congratulations! Highest scoring player is: " << topPlayerIndex << endl;
        cout << "Score: " << topScore << endl;
    }
}

