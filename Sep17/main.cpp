#include <iostream>
using namespace std;

#include "BST.h"

/*
        10
       /  \
      5    20
    / \   /  \
   4  7  15  22 
     /
    6
*/

int main(void)
{ 
    BST miArbol;
    miArbol.add(10);
    miArbol.find(10);
    miArbol.add(20);
    miArbol.add(5);
    miArbol.add(15);
    miArbol.add(7);
    miArbol.add(6);
    miArbol.add(4);
    miArbol.add(22); 

    miArbol.remove(10);
    miArbol.visita(4);

    miArbol.visita(1); // 10 5 4 7 6 20 15 22
    cout << "\n";
    miArbol.visita(2); // 4 5 6 7 10 15 20 22
    cout << "\n";
    miArbol.visita(3); // 4 6 7 5 15 22 20 10
    cout << "\n";
    miArbol.visita(4); // 10 5 20 4 7 15 22 6
    
    cout << endl << miArbol.getAltura() << endl; 

    miArbol.ancestors(7);
    cout << "\n";

    cout << miArbol.whatLevelAmI(6) << " " << miArbol.whatLevelAmI(22) << endl;

    return 0; 
}