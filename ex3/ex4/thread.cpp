
// Thread function that modifies the shared Vector instance
#include <thread.hpp>

void *thread_vector(void *arg)
{
    ThreadInfo* threadInfo = static_cast<ThreadInfo*>(arg);

    int number = rand() % 100 + 1; // Generate a random number between 1 and 100

    while (true)
    {
        // Attempt to set and test a value in the shared Vector
        if (!threadInfo->vector->setAndTest(number))
        {
            // If the test fails, print an error message
            std::cout << "Thread:" << threadInfo->id << " encountered an error at number = " << number << std::endl;
        };
        usleep(1); // Sleep for 1 millisecond
    }

    return nullptr;
}
