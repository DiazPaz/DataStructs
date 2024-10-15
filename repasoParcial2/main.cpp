#include <iostream>
using namespace std; 

#include "Queue.h" 

int main(void)
{
    Queue queue; 
    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);
    queue.enqueue(40);
    queue.printQueue();

    return 0; 
}