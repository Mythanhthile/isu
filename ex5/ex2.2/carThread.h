// #ifndef CAR_THREAD_HPP
// #define CAR_THREAD_HPP
#include "entryguard.h"
#include "exitguard.h"
void *carHandler(void* arg);

struct Car {
    int id;
    int time; 

};

// #endif