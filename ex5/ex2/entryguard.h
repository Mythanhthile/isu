// #ifndef ENTRY_GUARD_HPP
// #define ENTRY_GUARD_HPP
#include <pthread.h>

void *entryGuard(void *arg);

extern pthread_mutex_t entry_mutex;
extern pthread_cond_t entry_signal;

extern int CAR_WAIT_ENTRY;

extern bool ALLOW_ENTRY;



// #enf


