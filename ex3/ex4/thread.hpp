#include <Vector.hpp>
#include <stdio.h>
#include <iostream>
#include <pthread.h>
#include <unistd.h>

struct ThreadInfo
{
    unsigned int id;
    Vector *vector;
    unsigned int sleepTime;

};

void *thread_vector(void *arg);