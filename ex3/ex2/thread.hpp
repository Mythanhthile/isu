
#include <stdio.h>
#include <iostream>
#include <pthread.h>
#include <unistd.h>

struct ThreadInfo
{
    int id;
    int count;
};


void *thread_func(void *arg);

