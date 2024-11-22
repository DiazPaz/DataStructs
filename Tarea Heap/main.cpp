#include <iostream>
using namespace std;

#include "PriorityQueue.h"

int main(void)
{
    PriorityQueue heap; 

    heap.insert(49);
    heap.insert(36);
    heap.insert(23);
    heap.insert(13);
    heap.insert(1);
    heap.insert(98);
    heap.insert(74);
    heap.insert(54);
    heap.insert(20);
    heap.insert(9);
    heap.insert(6);
    
    cout << "Lista: ";
    heap.print();
    cout << endl; 
    
    cout << "heapSort: ";
    heap.heapSort();
    heap.print();
    cout << endl; 

    cout << "remove: ";
    heap.remove();
    heap.print();
    cout << endl; 

    cout << "heapSort: ";
    heap.heapSort();
    heap.print();
    cout << endl; 
    
    cout << "remove: ";
    heap.remove();
    heap.print();
    cout << endl; 

    cout << "heapSort: ";
    heap.heapSort();
    heap.print();
    cout << endl; 


    return 0; 
}