#include "exitguard.h"
#include <pthread.h>
#include <iostream>

pthread_mutex_t exit_mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t exit_signal = PTHREAD_COND_INITIALIZER;
int CAR_WAIT_EXIT = 0;
bool ALLOW_EXIT = false;


void *exitGuard(void* arg)
{
    while(true){
        pthread_mutex_lock(&exit_mutex);
            std::cout << "\nexit guard waiting for car" << std::endl;

        while(!CAR_WAIT_EXIT){
            pthread_cond_wait(&exit_signal, &exit_mutex);
        }
        std::cout << "car exiting" << std::endl;

        ALLOW_EXIT = true;
        pthread_cond_signal(&exit_signal);

        std::cout << "Guard signalling exit" << std::endl;
        while (CAR_WAIT_EXIT)
        {
            pthread_cond_wait(&exit_signal, &exit_mutex);
        }

        ALLOW_EXIT = false;

        pthread_mutex_unlock(&exit_mutex);
        
        }
    return nullptr;
}