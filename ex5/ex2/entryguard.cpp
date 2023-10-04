#include <pthread.h>
#include "entryguard.h"
#include <iostream>


pthread_mutex_t entry_mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t entry_signal = PTHREAD_COND_INITIALIZER;
int CAR_WAIT_ENTRY = 0;
bool ALLOW_ENTRY = false;


void *entryGuard(void *arg)
{
    while(true){
        pthread_mutex_lock(&entry_mutex);
        
        std::cout << "\nentry guard waiting for car" << std::endl;

        //while there is no car thread waits for signal from car thread
        while(!CAR_WAIT_ENTRY){

            pthread_cond_wait(&entry_signal, &entry_mutex);
        }

        std::cout << "car entering" << std::endl;


        ALLOW_ENTRY = true;
        pthread_cond_signal(&entry_signal);


        std::cout << "Guard signalling access" << std::endl;

        while (CAR_WAIT_ENTRY)
        {
            pthread_cond_wait(&entry_signal, &entry_mutex);
        }

        ALLOW_ENTRY = false;


        pthread_mutex_unlock(&entry_mutex);

    }
    return nullptr;


}