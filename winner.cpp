#include <iostream>
#include "winner.h"
using namespace std;

void findTopPlayer(Player* all_players, int player_num) {
    bool allFailed = true;
    int topScore = -1;   // 初始值为 -1 表示尚未找到最高分玩家
    int topPlayerIndex = -1;

    // 遍历所有玩家，检查是否全部失败，并找出得分最高的玩家
    for (int i = 0; i < player_num; i++) {
        if (!all_players[i].failed) {
            allFailed = false;  // 发现至少有一个玩家未失败
            if (all_players[i].score > topScore) {
                topScore = all_players[i].score;
                topPlayerIndex = i;  // 记录最高分玩家的索引
            }
        }
    }

    // 判断结果
    if (allFailed) {
        cout << "All losers." << endl;
    } else {
        cout << "Highest scoring player index: " << topPlayerIndex << endl;
        cout << "Score: " << topScore << endl;
    }
}
