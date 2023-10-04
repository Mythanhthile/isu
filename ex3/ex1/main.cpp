#include <iostream>
// Include necessary libraries

using namespace std;

// Define a function that the thread will execute
//returns a void pointer
void *helloThreadFun(void *vargp)
{
    cout << "hello world" << endl; // Print "hello world"
    return NULL; // Return NULL (void*) as the thread function's result
}

int main()
{
    pthread_t thread_id; // Declare a pthread (thread) ID variable
    printf("Before Thread\n"); // Print a message before creating the thread

    // Create a new thread and execute helloThreadFun with no arguments
    pthread_create(&thread_id, NULL, helloThreadFun, NULL);

    // Wait for the newly created thread to finish executing
    pthread_join(thread_id, NULL);

    printf("After Thread\n"); // Print a message after the thread has finished

    exit(0); // Exit the program
    return 0; // Return 0 to indicate successful execution (this line is unreachable due to 'exit(0)')
}
