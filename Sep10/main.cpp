#include <iostream>
#include <string>
using namespace std; 

#include "Queue.h"

int main(void)
{

    Queue<string> filaNum; 
    
    filaNum.enqueue("Renata");
    filaNum.enqueue("David");
    filaNum.enqueue("Luis");
    filaNum.enqueue("Julia");
    filaNum.dequeue();

    filaNum.print();

    return 0;
}