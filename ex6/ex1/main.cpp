#include "message.hpp"
#include "msgqueue.hpp"
#include "unistd.h"
#include <iostream>
struct Point3D : public Message{
    int x;
    int y;
    int z; 
};

enum {
    POINT_ID
};

MsgQueue pointMq(10);

/*Create two threads Sender and Receiver, 
where the Sender creates an object Point3D every second 
or so and sends it to the Receiver. 
The Receiver should continuously wait for new messages and,
 on reception, print the x, y, and z 
 coordinates of the received Point3D object to the console.
*/





void pointHandler(unsigned int id, Message* msg){
    switch (id)
    {
    case POINT_ID:
        {//it's casting a pointer to a base class (Message) to a pointer to a derived class (Point3D). 
        //This is known as a downcast
        //Point3D *msgPtr = (Point3D *)msg;
        Point3D *msgPtr = dynamic_cast<Point3D*>(msg);
        std::cout << "(" << msgPtr->x << ", " << msgPtr->y << ", " << msgPtr->z << ")" << std::endl;
        }
        break;
    
    default:
        {
            std::cout << "Unknown msg" << std::endl;
        }
        break;
    }

}

void *receiverFunc(void* arg){
    while(1){
        unsigned long id;
        Message* msg = pointMq.Receive(id);
        pointHandler(id,msg);
        //delete msg;
        msg->~Message();
    }
}

void *senderFunc(void* arg){
    while(1){
        Point3D *point = new Point3D;
        point->x = rand()%100;
        point->y = rand()%100;
        point->z = rand()%100;

        pointMq.Send(POINT_ID, point);
        sleep(1);
    }
   
}


int main(){

    pthread_t senderThread;
    pthread_t receiverThread;

    pthread_create(&receiverThread, nullptr, receiverFunc, nullptr);
    pthread_create(&senderThread, nullptr, senderFunc, nullptr);

    pthread_join(senderThread, nullptr);
    pthread_join(receiverThread, nullptr);
    return 0; 
}