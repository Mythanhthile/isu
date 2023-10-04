#include "thread.hpp"
#include <pthread.h>

const int NUM_THREAD = 2;

int main(int argc, char *argv[])
{

    pthread_t threads[NUM_THREAD];
    struct ThreadInfo thread_infos = {1, 0};

    std::cout << "Main: Creating threads" << std::endl;
    pthread_create(&threads[0], nullptr, thread_incrementer, (void *)&thread_infos);
    pthread_create(&threads[1], nullptr, thread_reader, (void *)&thread_infos);

    std::cout << "Joining threads..." << std::endl;
    for (int i = 0; i < NUM_THREAD; i++)
    {
        thread_infos.id = i;
        pthread_join(threads[i], nullptr);
    }

    std::cout << "Terminating threads..." << std::endl;

    return 0;
}