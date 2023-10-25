#pragma once
#include "pthread.h"
#include "message.hpp"
#include <iostream>
#include <queue>

class MsgQueue{
public:
    MsgQueue(unsigned long maxSize);
    void Send(unsigned long id, Message* msg = NULL); 
    Message* Receive(unsigned long& id);
    ~MsgQueue();

private:
    struct item{
        Message* msg_;
        unsigned long id_;
    };
    
    std::queue<item> container_; //Containter with item of messages
    pthread_mutex_t mutex;
    pthread_cond_t receiverSignal;
    pthread_cond_t senderSignal;
    unsigned long  maxSize_;

// Container with messages
// Plus other relevant variables
};