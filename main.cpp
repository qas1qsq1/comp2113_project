#include "fight.h"
#include "randomevent.h"
#include "buff.h"
#include "debuff1.h"

#include "player1.h"
#include "winner.h"
#include <thread>
#include <chrono>
#include<iostream>
using namespace std;


int main(){
    int player_num;
    // 决定玩家数量
    cout << "How many players?" << endl;
    cin >> player_num;
    Player *all_players = new Player [player_num];

    // 决定每一个玩家开始时的属性
    cout << "Then please set default parameter for each player." << endl;
    int attack_default, life_default, max_life_default;
    cout << "Default Attack is ?" << endl;
    cin >> attack_default;
    cout << "Starting life point is ?" << endl;
    cin >> life_default;
    cout << "Starting maximum life point is ?" << endl;
    cin >> max_life_default;

    // 设置每个玩家的属性
    for (int i=0; i< player_num; i++){
        all_players[i].score = 0;
        all_players[i].PlayerAttack = attack_default;
        all_players[i].PlayerLife = life_default;
        all_players[i].PlayerMaxLife = max_life_default;
        all_players[i].failed = false;
    }

    RandomEvent randomEvent;

    // 然后每一个玩家开始闯关；

    for (int i =0; i<player_num; i++){
        for (int day =1; day < 31; day ++){
            if (day ==1){
                cout << "Now it's the turn of player " << i << "! Get ready for your journey!" << endl;
            }
            if (not all_players[i].failed){
                cout << "Now it is day " << day << " !";
                this_thread::sleep_for(std::chrono::seconds(2));

                int path = randomEvent.generateRandom(1, 100);
                if (path <= 15){
                    
                    debuff(all_players[i], randomEvent);
                    cout << "Oops! Something bad happened!";
                    this_thread::sleep_for(std::chrono::seconds(1));

                } else if (path <= 75 and path > 15){
                    cout << "Congrats! Something good happened!";
                    this_thread::sleep_for(std::chrono::seconds(1));
                    buff(all_players[i], randomEvent); 


                } else {
                    cout << "You feel that a monster is wondering around." << endl;
                    char choice;
                    cout << "Do you want to fight the boss? (Y/N): ";
                    cin >> choice;

                    if (choice == 'Y' || choice == 'y') {
                        Fight(all_players[i]);
                    } else {
                        cout << "You chose not to fight. Exiting..." << std::endl;
                    }
                }
                cout << "After day " << day <<", your life point is: " << all_players[i].PlayerLife << endl;
                cout << "After day " << day <<", your max life point is: " << all_players[i].PlayerMaxLife << endl;
                cout << "After day " << day <<", your attack is: " << all_players[i].PlayerAttack << endl;
                
                // 处理完一天之后, 暂停2秒再继续下一天
                this_thread::sleep_for(std::chrono::seconds(2));

            } else {
                break;
            }
            
        }
    }

    // 所有玩家闯关结束 接下来找出所有存活者，并判断分数最高的赢家

    findTopPlayer(all_players, player_num);

    // 释放动态分配的内存
    delete[] all_players;

    return 0;
} 
