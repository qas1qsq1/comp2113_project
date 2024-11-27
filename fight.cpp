#include <iostream>
#include <cstdlib>
#include <ctime>


void Fight(Player &player) {


    // Seed for random number generation
    srand(time(0));

    // Generate random BossLife and BossAttack
    int BossLife = rand() % (4 * player.PlayerAttack) + 2 * player.PlayerAttack;
    int BossAttack = rand() % (int)(0.3 * player.PlayerLife) + 0.2 * player.PlayerLife;

    std::cout << "PlayerLife: " << player.PlayerLife << std::endl;
    std::cout << "PlayerAttack: " << player.PlayerAttack << std::endl;
    std::cout << "PlayerScore: " << player.score << std::endl;
    std::cout << "BossLife: " << BossLife << std::endl;
    std::cout << "BossAttack: " << BossAttack << std::endl;

    int n = 1; // Round number

    while (true) {
        std::cout << "Round " << n << std::endl;
        std::cout << "Player life: " << player.PlayerLife << std::endl;
        std::cout << "Boss life: " << BossLife << std::endl;

        // Player attacks first
        BossLife -= PlayerAttack;

        if (BossLife <= 0) {
            player.score += BossLife + BossAttack;
            std::cout << "Player wins!" << std::endl;
            std::cout << "PlayerLife: " << player.PlayerLife << std::endl;
            std::cout << "PlayerAttack: " << player.PlayerAttack << std::endl;
            std::cout << "PlayerScore: " << player.score << std::endl;
            break;
        }

        // Boss attacks
        player.PlayerLife -= BossAttack;

        if (player.PlayerLife <= 0) {
            std::cout << "You are dead. Game over!" << std::endl;
            player.failed = true;
            break;
        }

        n++;
    }
}

//int main() {
//    char choice;
//    std::cout << "Do you want to fight the boss? (Y/N): ";
//    std::cin >> choice;

//    if (choice == 'Y' || choice == 'y') {
//        Fight();
//    } else {
//        std::cout << "You chose not to fight. Exiting..." << std::endl;
//    }

//    return 0;
//}