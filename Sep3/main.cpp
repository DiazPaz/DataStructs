#include <iostream>
#include <string>
using namespace std; 

#include "LinkedListT.h"

int main(void)
{
    LinkedListT<int> listaEnt;
    LinkedListT<string> listaStr; 

    for(int i = 0; i < 5; i++)
        listaEnt.addLast(i);
    listaEnt.printList();

    return 0; 
}