#ifndef RANDOMEVENT_H
#define RANDOMEVENT_H

#include <cstdlib>
#include <ctime>

class RandomEvent {
public:
    RandomEvent(); 
    int generateRandom(int min, int max);
};

#endif