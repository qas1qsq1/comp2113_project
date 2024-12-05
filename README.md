## 1.  Identification of the Team Members (Sort by initials)
- **Qiu Hanchen (Leader)**: Wrote the winner function，main function；determined program overall structuer & data strucutre; introduced the game and the input in the video.
- **CAI Yiling (Member)**: Wrote the randomevent function; wrote bonus part in the fight function; debugged and compiled all codes; wrote the README.md file; recorded video clips of the final video.
- **Fang Kaiwen (Member)**: Wrote the buff function; edited and created the final video.
- **Yan Jiaying (Member)**: Wrote the debuff function; introduced the buff and debuff function in the video.
- **Yang Ruofan (Member)**: Wrote the fight function; introduced the fight function in the video.
## 2.  Description of Application
Our game provides an interesting adventure for several players. Each player will experience a 30-day trip, where each day they will encounter a random event, including buffs, debuffs, and fighting monsters. Players’ information is stored using a struct called `Player`, with five properties: attack, life, max life, score, and whether the player is still alive. In the end, the player with the highest score becomes the winner. A “Draw” will be shown if several living players share the same final score. If all players die, the program will end in advance.

Players’ information is stored in a dynamic array. For each player, a for loop is used to go through the journey. Every day, a random number is generated to decide whether a buff, debuff, or fighting will happen. These three blocks are developed as separate functions. For buff and debuff, they also carry a second round random number generator to determine the exact event.
## 3.  Implemented Features
- **Player Structure**: Implemented a `Player` struct that encapsulates essential attributes such as attack, life, max life, score, and status (alive/dead). This structure allows for easy management of player data throughout the game.
  
- **Random Event Generation**: Utilized a `RandomEvent` class to generate random numbers, determining whether players encounter buffs, debuffs, or monsters. This feature enhances gameplay variability and unpredictability, making each playthrough unique. It also determines which buff or debuff players will encounter and to what extent.

- **Main Function**: Stored players’ information in a dynamic array and utilized a for loop to navigate through the journey. It also used `<fstream>` for reading player configurations from the `property.txt` file, allowing for customizable player attributes at the start of the game.

- **Buff and Debuff**: Developed functions for applying buffs and debuffs that affect player attributes. Buffs can increase attack, life points, or max life points, while debuffs decrease them. Notably, there is a special debuff where max life is reduced, but a 10% increase in life is given. These functions include checks to ensure that life does not exceed maximum limits.

- **Fight System**: Implemented a combat system where players can choose to fight monsters. The fight mechanics calculate damage based on player and monster stats, and reward players with scores based on their performance, adding excitement and risk to the game.

- **Winner Calculation**: After all players complete their journeys, the program calculates the final scores and identifies the winner. If multiple players share the highest score, a "Draw" is declared. However, if all players die, the program will end in advance. This feature provides closure and a competitive element to the game.
## 4.  Library Used
#### Standard
- **`<iostream>`**: Used for input and output operations, allowing interaction with the user through the console.

#### Non-standard
  
- **`<cstdlib>`**: Provides functions for random number generation.
  
- **`<ctime>`**: Used to seed the random number generator with the current time, ensuring randomness in gameplay.
  
- **`<thread>`**: Enables multi-threading support, allowing the game to pause and create delays to improve user experience during events.
  
- **`<chrono>`**: Provides functionality for creating sleep durations for pauses in gameplay.
  
- **`<fstream>`**: Used for reading player configurations from the `property.txt` file.
## 5.  Compilation and Execution Instructions
   **Clone the Repository**:
   
   git clone https://github.com/qas1qsq1/comp2113_project.git
   
   cd <repository-directory>
   
   **Compile the Program**:
   
   make
   
   **Run the Game**:
   
   ./output
   
   **Input**:
   
   Follow the prompts to enter the number of players and their initial stats as defined in property.txt.
   
   **Gameplay**: 
   
   Players will experience 30 days of random events, including buffs, debuffs, and monster fights. Make choices as prompted to navigate the adventure.

