#include "thread.hpp"
#include <pthread.h>
#include <iostream>
#define NUM_THREAD 2

int main(int argc, char *argv[])
{

    pthread_t threads[NUM_THREAD];  // Array to hold thread IDs
    struct ThreadInfo thread_infos[NUM_THREAD]; // Array to hold thread-specific information

    std::cout << "Main: Creating threads" << std::endl;
    for (int i = 0; i < NUM_THREAD; i++)
    {
        thread_infos[i].id = i;        
        thread_infos[i].count = 0;
        // i is a unique id for the threadinfo struct
        pthread_create(&threads[i], nullptr, thread_func, (void *)&thread_infos[i]);
    }

    std::cout << "Joining threads..." << std::endl;
    for (int i = 0; i < NUM_THREAD; i++)
    {
        thread_infos[i].id = i;
        pthread_join(threads[i], nullptr);
    }

    std::cout << "Terminating threads..." << std::endl;

    return 0;
}