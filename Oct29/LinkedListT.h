#include "NodeVT.h"
#include "QueueT.h"

template <class T>
class LinkedListT
{
    private: 
        int size = 0; 
        NodeVT<T> *head;
        Queue<T> fila;
        Queue<T> procesados;
    public: 
        LinkedListT<T>(){ size = 0; head = nullptr; }
        ~LinkedListT(){};
        bool isEmpty(){ return size == 0; }
        int getSize(){ return size; }
        void addFirst(T);
        void addLast(T);
        void printList();
        void printGraph();
        void printBFS();
        T getData(int);
        int findData(T);
        bool deleteData(T);
        bool deleteAt(int);
        void updateData(T, T);
        void updateAt(int, T);
        bool insertAt(int, T);

        void insertAdj(T fromV, T toV);

        void BFS(T data);
        void DFS(T data);
        void clear();
};

template <class T>
void LinkedListT<T>::insertAdj(T fromV, T toV)
{
    NodeVT<T> *aux = head; 
    int count = 0; 
    while(aux->dato != fromV && count < size)
    {
        aux = aux->next; 
        count++;
    }
    if(aux->dato == fromV) // aquí voy a ligar la lista de adyacencias
    {
        NodeT<T> *newAdj = new NodeT(toV);
        NodeT<T> *aux2; 
        if(aux->adj == nullptr)
        {
            aux->adj = newAdj; 
        }
        else
        {
            aux2 = aux->adj;
            while(aux2->next != nullptr)
                aux2 = aux2->next; 
            aux2->next = newAdj; 
        }
    }
}

template <class T> 
void LinkedListT<T>::addFirst(T dato)
{
    NodeVT<T> *aux = new NodeVT<T>(dato);
    aux->next = head; 
    head = aux; 
    size++; 
}

template <class T> 
void LinkedListT<T>::addLast(T dato)
{
    if(size > 0)
    {
        NodeVT<T> *aux = head; 
        for(int i = 0; i < size-1; i++)
            aux = aux->next;
        aux->next = new NodeVT<T>(dato);
    }
    else
    {
        head = new NodeVT<T>(dato);
    }
    size++;
}

template <class T> 
void LinkedListT<T>::printList()
{
    if(size > 0)
    {
        NodeVT<T> *aux = head; 
        for(int i = 0; i < size; i++)
        {
            cout << aux->dato << endl; 
            aux = aux->next;
            cout << endl; 
        }
    }
    else
    {
        cout << "Lista vacIa\n";
    }
}

template <class T> 
void LinkedListT<T>::printGraph()
{
    if(size > 0)
    {
        NodeVT<T> *aux = head; 
        NodeT<T> *auxAdj = aux->adj;
        for(int i = 0; i < size; i++)
        {
            cout << aux->dato << " "; 
            auxAdj = aux->adj;
            while(auxAdj != nullptr)
            {
                cout << auxAdj->dato << " ";
                auxAdj = auxAdj->next; 
            }
            aux = aux->next;
            cout << endl; 
        }
    }
    else
    {
        cout << "Lista vacIa\n";
    }
}

template <class T> 
T LinkedListT<T>::getData(int index)
{
    if(size > 0 && index < size)
    {
        NodeVT<T> *aux = head; 
        for(int i = 0; i < index; i++)
            aux = aux->next; 
        return aux->dato;
    }
    else
    {
        return -1;
    }
}

template <class T> 
int LinkedListT<T>::findData(T data)
{
    NodeVT<T> *aux = head; 
    int count = 0; 
    while(aux->dato != data && count < size)
    {
        aux = aux->next; 
        count++;
    }
    if(aux->dato == data)
        return count;
    else   
        return -1;
}

template <class T> 
bool LinkedListT<T>::deleteData(T data)
{
    NodeVT<T> *aux = head; 
    NodeVT<T> *aux2; 
    int count = 0; 
    while(aux->dato != data && count < size)
    {
        aux2 = aux;
        aux = aux->next;
        count++;
    }
    if(aux->dato == data)
    {
        if(count == 0)
        {
            head = aux->next;
            aux->next = nullptr;
            delete aux; 
        }
        else
        {
            aux2->next = aux->next; 
            aux->next = nullptr; 
            delete aux; 
        }
        size--;
        return true;
    }
    else
    {
        return false;
    }   
}

template <class T> 
bool LinkedListT<T>::deleteAt(int index)
{
    NodeVT<T> *aux = head; 
    NodeVT<T> *aux2; 
    int count = 0; 
    while(count < index)
    {
        aux2 = aux;
        aux = aux->next;
        count++;
    }
    if(index < size)
    {
        if(count == 0)
        {
            head = aux->next;
            aux->next = nullptr;
            delete aux; 
        }
        else
        {
            aux2->next = aux->next; 
            aux->next = nullptr; 
            delete aux; 
        }
        size--;
        return true;
    }
    else
    {
        return false;
    } 
}

template <class T> 
void LinkedListT<T>::updateData(T data, T newData)
{
    NodeVT<T> *aux = head; 
    int count = 0; 
    while(aux->dato != data && count < size)
    {
        aux = aux->next; 
        count++;
    }
    if(aux->dato == data)
        aux->dato = newData; 
}

template <class T> 
void LinkedListT<T>::updateAt(int index, T newData)
{
    if(size > 0 && index < size)
    {
        NodeVT<T> *aux = head; 
        for(int i = 0; i < index; i++)
            aux = aux->next; 
        aux->dato = newData;
    }
}

template <class T> 
bool LinkedListT<T>::insertAt(int index, T data)
{
    if(index < size)
    {
        NodeVT<T> *aux = head; 
        NodeVT<T> *aux2; 
        int count = 0; 
        while(count < index)
        {
            aux2 = aux;
            aux = aux->next;
            count++;
        }
        if(count == 0)
        {
            addFirst(data); 
            return true;
        }
        else
        {
            NodeVT<T> *newNode = new NodeVT<T>(data);
            newNode->next = aux2->next; 
            aux2->next = newNode; 
            size++;
            return true;
        }
    }
    else if(index >= size)
    {
        addLast(data); 
        return true; 
    }
    else
    {
        return false;
    } 
}

template <class T> 
void LinkedListT<T>::clear()
{
    if(size > 0)
    {
        NodeVT<T> *aux = head; 
        while(head->next != nullptr)
        {
            head = aux->next;
            aux->next = nullptr; 
            delete aux; 
            aux = head;
            size--; 
        }
        head = nullptr; 
        delete aux;
        size--; 
        cout << "Lista borrada!\n";
    }
    else
    {
        cout << "Lista vacIa\n"; 
    }
}

template <class T>
void LinkedListT<T>::BFS(T data)
{
    NodeVT<T> *aux = head;
    int pos = 0; 
    while(aux->dato != data && pos < size)
    {
        aux = aux->next; 
        pos++;
    }
    if(aux->dato == data && aux->processed == false) // "aux->dato == data &&" es opcional
    {
        aux->processed = true; 
        cout << aux->dato << " ";
        if(aux->adj != nullptr)
        {
            NodeT<T> *aux2 = aux->adj; 
            aux2->processed = true; // opcional
            fila.enqueue(aux2->dato);
            while(aux2->next != nullptr)
            {
                aux2 = aux2->next; 
                aux2->processed = true; // opcional
                fila.enqueue(aux2->dato);
            }
        } 
    }
    T sigNodo = fila.getData(0);
    if(fila.dequeue())
        BFS(sigNodo);
}

template <class T>
void LinkedListT<T>::DFS(T data)
{
    NodeVT<T> *aux = head; 
    // busqueda del nodo origen para empezar el recorrido
    int pos = 0;
    while(aux->dato != data && pos < size)
    {
        aux = aux->next; 
        pos++;
    }

    // verificamos si el nodo ya fue procesado o no 
    if(aux->dato == data && aux->processed == false)
    {
        aux->processed = true; 
        procesados.enqueue(aux->dato);
        cout << aux->dato << " ";
        NodeT<T> *aux2 = aux->adj; 
        
        // ciclo donde verificamos si los nodos adyacentes ya fueron procesados o no
        while(aux2 != nullptr)
        {
            // en caso de que no hayan sido procesados los procesamos para que no se repitan 
            if (aux2->processed == false)
            {
                aux2->processed = true; 
                DFS(aux2->dato); 
            }
            aux2 = aux2->next;
        }
    }
}
