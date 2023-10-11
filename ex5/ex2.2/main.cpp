#include "carThread.h"

#include <pthread.h>
#include <cstdlib> // Include this header for rand()


int main(){

    int NUM_THREAD = 5; 
    // Initialize global variables
    struct Car cars[NUM_THREAD]; // Array to hold thread-specific information
    
    pthread_t carThreads[NUM_THREAD];
    pthread_t entryGuardThread;
    pthread_t exitGuardThread;


    pthread_create(&entryGuardThread, nullptr, entryGuard, nullptr);
    pthread_create(&exitGuardThread, nullptr, exitGuard, nullptr);

    for (int i = 0; i < NUM_THREAD; i++)
    {
        int sleepamount = rand()%10;
        cars[i].id = i;
        cars[i].time = sleepamount;
        pthread_create(&carThreads[i], nullptr, carHandler, (void *)&cars[i]);

    }   

    pthread_join(entryGuardThread, nullptr);
    pthread_join(exitGuardThread, nullptr);
    for (int i = 0; i < NUM_THREAD; i++)
    {
        cars[i].id = i;

        pthread_join(carThreads[i], nullptr);

    }

    return 0;
}