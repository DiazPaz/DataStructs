#include <iostream>
using namespace std; 

#include "GraphM.h"

int main(void)
{
    GraphM miGrafo; 
    char misVertices[10] = {'a','b','c','d','e','f','g','h','i','j'};
    miGrafo.insertVertex(misVertices, 10);
    miGrafo.insertEdges('a','f'); 
    miGrafo.insertEdges('d','i'); 
    miGrafo.print();

    return 0; 
}