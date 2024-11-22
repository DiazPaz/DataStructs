#include <iostream>
using namespace std; 

// #include "LinkedListT.h"
#include "LinkedListTGP.h"

int main(void)
{

    system("cls");
    LinkedListTGP<int> miListaV;
    miListaV.addFirst(0);
    miListaV.addFirst(1);
    miListaV.addFirst(2);
    miListaV.addFirst(3);
    miListaV.addFirst(4);
    miListaV.addFirst(5);
    miListaV.addFirst(6);
    miListaV.addFirst(7);
    miListaV.addFirst(6);

    miListaV.insertAdj(0,3,1); 
    miListaV.insertAdj(1,3,4); 
    miListaV.insertAdj(1,6,9); 
    miListaV.insertAdj(2,4,2); 
    miListaV.insertAdj(3,0,1); 
    miListaV.insertAdj(3,1,4); 
    miListaV.insertAdj(3,5,3); 
    miListaV.insertAdj(3,7,9); 
    miListaV.insertAdj(4,2,2); 
    miListaV.insertAdj(4,7,4); 
    miListaV.insertAdj(5,3,3); 
    miListaV.insertAdj(5,6,8); 
    miListaV.insertAdj(6,1,9); 
    miListaV.insertAdj(6,5,8); 
    miListaV.insertAdj(7,3,9); 
    miListaV.insertAdj(7,4,4); 

    miListaV.printGraph();
    
    return 0;   
}