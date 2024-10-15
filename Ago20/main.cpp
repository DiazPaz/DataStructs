#include <iostream>
using namespace std; 

#include "LinkedList.h"

int main(void)
{
    LinkedList miLista;

    miLista.addFirst(20);
    miLista.addFirst(30);
    miLista.addLast(10);
    miLista.addFirst(40);
    miLista.addLast(50);
    miLista.printList();
    
    cout << endl << miLista.getData(5) << endl; 
    
    cout << endl << miLista.findData(20) << endl << endl; 

    miLista.deleteData(50);    
    miLista.deleteAt(0);    
    miLista.printList();

    cout << endl; 
    
    miLista.updateData(30,100);
    miLista.updateAt(1,200);
    miLista.printList();

    cout << endl; 

    miLista.insertAt(2, 300);
    miLista.printList();

    return 0;
}