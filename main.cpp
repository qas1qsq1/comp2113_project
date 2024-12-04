#include "fight.h"
#include "randomevent.h"
#include "buff.h"
#include "debuff1.h"

#include "player1.h"
#include "winner.h"
#include <thread>
#include <chrono>
#include<iostream>
#include <iostream>
#include <fstream>
using namespace std;


int main(){
    int player_num;
    // Determine the number of players
    cout << "How many players?" << endl;
    cin >> player_num;
    Player *all_players = new Player [player_num];

    // Determine the starting stats of each player
    // Select input from an external file here

    cout << "Reading default parameters from file 'config.txt'..." << endl;

    int attack_default, life_default, max_life_default;
    ifstream config_file("property.txt");
    if (config_file.is_open()) {
        config_file >> attack_default >> life_default >> max_life_default;

        if (attack_default < 100 || life_default < 100 || max_life_default < 100) {
            cerr << "Error: Default values should be at least 100. Please check 'property.txt'." << endl;
            delete[] all_players;
            return 1;
        }

        cout << "Default Attack: " << attack_default << endl;
        cout << "Starting Life: " << life_default << endl;
        cout << "Starting Maximum Life: " << max_life_default << endl;

        for (int i = 1; i < 1 + player_num; i++) {
            all_players[i].PlayerAttack = attack_default;
            all_players[i].PlayerLife = life_default;
            all_players[i].PlayerMaxLife = max_life_default;
            all_players[i].score = 0;
            all_players[i].failed = false;
        }

        config_file.close();
    } else {
        cerr << "Error: Unable to open 'property.txt'. Make sure the file exists." << endl;
        delete[] all_players;
        return 1;
    }


    RandomEvent randomEvent;

    // Then each player starts to finish the level

    for (int i =1 ; i<1 +player_num; i++){
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
                
                // After one day of processing, pause for 2 seconds before moving on to the next day
                
                this_thread::sleep_for(std::chrono::seconds(2));

            } else {
                break;
            }
            
        }
    }

    // After all players have completed the level, all the survivors are found and the winner with the highest score is judged

    findTopPlayer(all_players, player_num);

    // Free dynamically allocated memory
    delete[] all_players;

    return 0;
} 
