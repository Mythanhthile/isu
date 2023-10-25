#include "msgqueue.hpp"


MsgQueue::MsgQueue(unsigned long maxSize=10)
{
    maxSize_ = maxSize;
    pthread_mutex_init(&mutex, NULL);
    pthread_cond_init(&receiverSignal, NULL);
    pthread_cond_init(&senderSignal, NULL);

}

void MsgQueue::Send(unsigned long id, Message* msg){
    pthread_mutex_lock(&mutex);
    
    while(maxSize_==container_.size()){
        pthread_cond_wait(&senderSignal, &mutex);
    }

    item tempMsg = {msg,id};
    container_.push(tempMsg);
    pthread_cond_signal(&receiverSignal);
    pthread_mutex_unlock(&mutex);
    
}


Message* MsgQueue::Receive(unsigned long& id)
{
    pthread_mutex_lock(&mutex);

    while(container_.empty()){
        pthread_cond_wait(&receiverSignal, &mutex);
    }

    item tempMsg = container_.front();

    //reference
    id = tempMsg.id_;

    Message* Msg = tempMsg.msg_;
    container_.pop();
    pthread_cond_signal(&senderSignal);

    pthread_mutex_unlock(&mutex);
    return Msg;

}

MsgQueue::~MsgQueue(){
    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&receiverSignal);
    pthread_cond_destroy(&senderSignal);

}