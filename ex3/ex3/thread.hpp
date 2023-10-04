
#include <stdio.h>
#include <iostream>
#include <pthread.h>
#include <unistd.h>

struct ThreadInfo
{
    int id;
    int count;
};


void *thread_reader(void *arg);
void *thread_incrementer(void *arg);

