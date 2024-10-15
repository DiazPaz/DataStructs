#include <iostream>
using namespace std; 

#include "CircleLinkedList.h"

int main(void)
{
    CircleLinkedList miLista;

    miLista.addFirst(10);
    miLista.addFirst(20);
    miLista.deleteData(10);    
    miLista.addFirst(30);
    miLista.addFirst(40);
    miLista.addLast(5);
    miLista.addLast(50);
    miLista.printList();
    
    cout << endl << miLista.getData(3) << endl; 
    
    cout << endl << miLista.findData(20) << endl << endl; 

    miLista.deleteAt(0);    
    miLista.printList();

    cout << endl; 
    
    miLista.updateData(30,100);
    miLista.updateAt(1,200);
    miLista.printList();

    cout << endl; 

    miLista.insertAt(2, 300);
    miLista.printList();

    miLista.clear();
    miLista.printList();

    return 0;
}