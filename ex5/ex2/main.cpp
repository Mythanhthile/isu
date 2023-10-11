#include "carThread.h"

#include <pthread.h>

int main(){

    // Initialize global variables
    

    pthread_t carThread;
    pthread_t entryGuardThread;
    pthread_t exitGuardThread;


    pthread_create(&entryGuardThread, nullptr, entryGuard, nullptr);
    pthread_create(&exitGuardThread, nullptr, exitGuard, nullptr);

    pthread_create(&carThread, nullptr, carHandler, nullptr);


    pthread_join(entryGuardThread, nullptr);
    pthread_join(exitGuardThread, nullptr);
    pthread_join(carThread, nullptr);

   

    return 0;
}