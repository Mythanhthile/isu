// #ifndef EXIT_GUARD_HPP
// #define EXIT_GUARD_HPP

#include "pthread.h"

void *exitGuard(void* arg);

extern pthread_mutex_t exit_mutex;
extern pthread_cond_t exit_signal;
extern int CAR_WAIT_EXIT;
extern bool ALLOW_EXIT;

// #endif static 