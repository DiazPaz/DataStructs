#include "LinkedList.h"

class PriorityQueue
{
    private:
        LinkedList lista; 

    public:
        PriorityQueue(){ LinkedList lista; };
        PriorityQueue(LinkedList listaEntrada){ lista = listaEntrada; }
        
        /** 
         * @brief Inserta un dato en la fila priorizada. 
         * @param int el dato a insertar.
         * @note Complejidad O(n).
         */
        void insert(int dato);

        /**
         * @brief Elimina el valor con mayor prioridad en la fila priorizada. 
         * @return El nodo (de mayor prioridad) eliminado.
         * @note Complejidad O(1).
         */
        int remove();

        /**
         * @brief Ordena la información de la fila priorizada. 
         * @return La lista ordenada (heap).
         * @note Complejidad O(n^2).
         */
        LinkedList heapSort();

        void print();
};

void PriorityQueue::insert(int dato)
{
    if(lista.isEmpty())
        lista.addFirst(dato); 
    else
        lista.addLast(dato);
}
int PriorityQueue::remove()
{
    int aux = lista.getData(1);
    lista.deleteAt(1);
    return aux; 
}
LinkedList PriorityQueue::heapSort()
{
    int pos = 1; 
    while(pos < lista.getSize())
    {

        if(lista.getData(pos) < lista.getData(pos*2) || lista.getData(pos) < lista.getData(pos*2+1))
        {
            if(lista.getData(pos*2) > lista.getData(pos*2+1))
            {
                int aux = lista.getData(pos);
                lista.updateAt(pos, lista.getData(pos*2));
                lista.updateAt(pos*2, aux);
                pos = 1; 
            }
            else
            {
                int aux = lista.getData(pos);
                lista.updateAt(pos, lista.getData(pos*2+1));
                lista.updateAt(pos*2+1, aux);
                pos = 1;
            }
        }
        else 
        {
            pos++;
        }
    }
    return lista;    
}
void PriorityQueue::print()
{
    for(int i = 0; i < lista.getSize(); i++)
    {
        cout << lista.getData(i+1) << " ";
    }
    cout << endl; 
}