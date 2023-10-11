#include "carThread.h"
#include <pthread.h>
#include <iostream>
#include <unistd.h>

void* carHandler(void *arg){
    Car *car = static_cast<Car *>(arg);
    // request access
    while(true){

        pthread_mutex_lock(&entry_mutex);
        // Signal waiting car
        ++CAR_WAIT_ENTRY;

        pthread_cond_signal(&entry_signal);


        printf("\nCar %d in entry queue", car->id);
        // std::cout << "\nCar " << car->id << " in entry queue" << std::endl; 

        // Wait for access
        while(!ALLOW_ENTRY){    
    
            pthread_cond_wait(&entry_signal, &entry_mutex);// wait for access

        }

        printf("\nCar %d entered", car->id);

        //std::cout << "Car "<< car->id<< " entered" << std::endl;

        //Signal no car is wait ing for entry
        --CAR_WAIT_ENTRY;
        pthread_cond_signal(&entry_signal);

        pthread_mutex_unlock(&entry_mutex);


        printf("\nCar %d sleeping for: %d seconds", car->id, car->time);

        //std::cout << "\nCar " << car->id << " sleeping for: " << car->time <<" seconds" << std::endl;


        sleep(car->time);

        pthread_mutex_lock(&exit_mutex);
        // Signal exit
        ++CAR_WAIT_EXIT;
        //Signal car waiting for access
        pthread_cond_signal(&exit_signal);

        printf("\nCar %d exit queue", car->id);

        //std::cout << "\nCar " << car->id << " in exit queue" << std::endl;
    

        while (!ALLOW_EXIT)
        {
            pthread_cond_wait(&exit_signal, &exit_mutex);
        }

        
        printf("\nCar %d exited", car->id);

        //std::cout << "Car " << car->id << " exited" << std::endl;

        --CAR_WAIT_EXIT;
        //Signal no car is waiting for exit
        pthread_cond_signal(&exit_signal);


        pthread_mutex_unlock(&exit_mutex);
        
        sleep(car->time);

        printf("\nCar %d sleeping for: %d seconds", car->id, car->time);

        //std::cout << "\nCar " << car->id << " sleeping for: " << car->time <<" seconds" << std::endl;

    }

    return nullptr;

}
