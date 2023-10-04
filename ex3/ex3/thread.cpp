#include <thread.hpp>

void *thread_incrementer(void *arg)
{
    ThreadInfo *info = static_cast<ThreadInfo *>(arg);

    for (int i = 0; i < 10; i++)
    {
        info->count++;
        sleep(1);
    }

    return NULL;
}

void *thread_reader(void *arg)
{
    ThreadInfo *info = static_cast<ThreadInfo *>(arg);

    for (int i = 0; i < 10; i++)
    {
        printf("Shared value: %d\n", info->count);
        sleep(1);
    }

    return NULL;
}