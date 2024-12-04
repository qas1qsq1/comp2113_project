/*#include "randomevent.h"
#include <iostream>

int main() {
    RandomEvent randomEvent; // Create an object of the RandomEvent class
    int randomNumber = randomEvent.generateRandom(1, 10); // Call the generateRandom function
    //std::cout << "Random number: " << randomNumber << std::endl;
    return 0;
}*/

#include "randomevent.h"

RandomEvent::RandomEvent() {
    srand(static_cast<unsigned int>(time(0))); // Initialization
}

int RandomEvent::generateRandom(int min, int max) {
    return rand() % (max - min + 1) + min; // Randomly generate the number between the given maximum and minimum number
}
