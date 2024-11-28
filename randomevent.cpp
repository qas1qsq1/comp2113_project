/*#include "randomevent.h"
#include <iostream>

int main() {
    RandomEvent randomEvent; // 创建 RandomEvent 类的对象
    int randomNumber = randomEvent.generateRandom(1, 10); // 调用 generateRandom 函数
    //std::cout << "Random number: " << randomNumber << std::endl;
    return 0;
}*/

#include "randomevent.h"

RandomEvent::RandomEvent() {
    srand(static_cast<unsigned int>(time(0))); // 初始化
}

int RandomEvent::generateRandom(int min, int max) {
    return rand() % (max - min + 1) + min; 
}
