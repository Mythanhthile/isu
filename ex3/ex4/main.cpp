#include "thread.hpp"

// Function to read an unsigned integer from the console
unsigned int ConsoleInputAmount()
{
    unsigned int number;
    std::cin >> number;
    return number;
}

// Function to validate the input number (between 1 and 100)
unsigned int ValidateNum(unsigned int number)
{
    if (number >= 1 && number <= 100)
    {
        return number;
    }

    return 10; // Default value if the input is out of range
}

int main(int argc, char *argv[])
{
    std::cout << "Number of threads you wanna create? From 1-100" << std::endl;

    // Read and validate the number of threads from the user
    unsigned int numberThreads = ValidateNum(ConsoleInputAmount());


    std::cout << "Number of microsecons you want to sleep?" << std::endl;

    unsigned int numberSleep = ConsoleInputAmount();

    Vector vector; // Create an instance of the Vector class
    ThreadInfo* threadInfoArray = new ThreadInfo[numberThreads]; // Create an array to hold thread-specific information
    pthread_t threads[numberThreads]; // Create an array to hold thread IDs

    std::cout << "Main: Creating threads" << std::endl;

    // Create multiple threads, each operating on the same Vector instance
    for (unsigned int i = 0; i < numberThreads; i++)
    {
        threadInfoArray[i].id = i; // Assign a unique ID to each thread
        threadInfoArray[i].vector = &vector; // Point each thread to the same Vector instance
        threadInfoArray[i].sleepTime = numberSleep;
        pthread_create(&threads[i], nullptr, thread_vector, (void *)&threadInfoArray[i]);
    }

    std::cout << "Joining threads..." << std::endl;

    // Wait for all threads to finish
    for (unsigned int i = 0; i < numberThreads; i++)
    {
        pthread_join(threads[i], nullptr);
    }

    delete[] threadInfoArray; // Clean up memory allocated for thread information

    std::cout << "Terminating threads..." << std::endl;

    return 0;
}