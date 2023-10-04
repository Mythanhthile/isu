#include "carThread.h"
#include <pthread.h>
#include <iostream>
#include <unistd.h>

void* carHandler(void *arg){
    // request access
    while(true){

        pthread_mutex_lock(&entry_mutex);
        // Signal waiting car
        ++CAR_WAIT_ENTRY;

        pthread_cond_signal(&entry_signal);


        std::cout << "\nCar in entry queue(only 1 car)" << std::endl;

        // Wait for access
        while(!ALLOW_ENTRY){    
    
            pthread_cond_wait(&entry_signal, &entry_mutex);// wait for access

        }

        std::cout << "Car entered" << std::endl;

        //Signal no car is waiting for entry
        --CAR_WAIT_ENTRY;
        pthread_cond_signal(&entry_signal);

        pthread_mutex_unlock(&entry_mutex);

        sleep(1);

        pthread_mutex_lock(&exit_mutex);
        // Signal exit
        ++CAR_WAIT_EXIT;
        //Signal car waiting for access
        pthread_cond_signal(&exit_signal);

        std::cout << "\nCar in exit queue(only 1 car)" << std::endl;
    

        while (!ALLOW_EXIT)
        {
            pthread_cond_wait(&exit_signal, &exit_mutex);
        }

        std::cout << "Car exited" << std::endl;

        --CAR_WAIT_EXIT;
        //Signal no car is waiting for exit
        pthread_cond_signal(&exit_signal);


        pthread_mutex_unlock(&exit_mutex);
        
        sleep(1);
    }

    return nullptr;

}
