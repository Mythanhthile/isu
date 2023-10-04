#include <thread.hpp>
#include <unistd.h>
#include <stdio.h>

void *thread_func(void *arg)
{
    /*line ThreadInfo *info = static_cast<ThreadInfo *>(arg); 
    is used to re-establish the correct data type of the pointer 
    arg so that you can access and manipulate the data stored in 
    the ThreadInfo structure pointed to by arg.*/

    ThreadInfo *info = static_cast<ThreadInfo *>(arg);

    for (int i = 0; i <= 10; i++)
    {
        printf("Hello #%d from thread %d\n", info->count, info->id);
        info->count++;
        // In some cases, you might use sleep to control the timing of operations between threads. 
        //For example, if you want to simulate a situation where threads interact or share resources with specific timing, you can use sleep to create those delays.
        sleep(1);
    }

    return nullptr;
}