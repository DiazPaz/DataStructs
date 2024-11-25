#include "NodeVT.h"
#include "QueueT.h"
#include <limits>

template <class T>
class LinkedListTGP
{
    private: 
        int size = 0; 
        NodeVT<T> *head;
        Queue<T> fila;
        Queue<T> procesados;
        int table[20][4];
        void printTable(T from);
        void initTable(T from);
        int DijkstraRun(T from);
    public: 
        LinkedListTGP<T>(){ size = 0; head = nullptr; }
        ~LinkedListTGP(){};
        bool isEmpty(){ return size == 0; }
        int getSize(){ return size; }
        void addFirst(T);
        void addLast(T);
        void printList();
        void printGraph();
        T getData(int);
        int findData(T);
        bool deleteData(T);
        bool deleteAt(int);
        void updateData(T, T);
        void updateAt(int, T);
        bool insertAt(int, T);
        void insertAdj(T fromV, T toV, int ponderacion);
        void BFS(T data);
        void DFS(T data);
        void Dijkstra(T from); 
        void clear();
};

template <class T>
void LinkedListTGP<T>::printTable(T from)
{
    int ruta; 
    for(int i = 0; i < size; i++)
    {
        cout << table[i][0] << " ";
        cout << table[i][1] << " ";
        cout << table[i][2] << " ";
        cout << table[i][3] << " ";
        if(table[i][3] == -1)
        {
            cout << table[i][0] << endl; 
        }
        else
        {
            ruta = i;
            while(table[ruta][3] != -1)
            {
                cout << table[ruta][0] << " ";
                ruta = table[ruta][3];
            }
            cout << table[ruta][0] << endl; 
        }
    }
}

template <class T>
void LinkedListTGP<T>::Dijkstra(T from)
{
    initTable(from);
    int res = DijkstraRun(from);
    printTable(from);
}

template <class T>
int LinkedListTGP<T>::DijkstraRun(T from)
{
    int pos0 = findData(from);
    NodeVT<T> *aux = head; 
    int pos = 0, posT, costo = table[pos0][2];
    while(aux->dato != from && pos < size) // ciclo para ponerme en el nodo donde este from
    {
        aux = aux->next; 
        pos++; 
    }
    if(aux->dato == from)
    {
        if(aux->adj != nullptr) // si tiene adyacencias, las recorrera todas
        {
            NodeT<T> *aux2 = aux->adj;
            do{
                posT = findData(aux2->dato);
                if(table[posT][1] == 0)
                {
                    if(table[posT][2] > (costo + aux2->peso))
                    {
                        table[posT][2] = costo + aux2->peso; 
                        table[posT][3] = pos0; 
                    }
                }
                aux2 = aux2->next;
            }while(aux != nullptr);
        }
    }
    int menor = numeric_limits<T>::max();
    int posM; 
    for(int i = 0; i < size; i++)
    {
        if(table[i][1] == 0)
        {
            if(table[i][2] < menor)
            {
                menor = table[i][2];
                posM = i; 
            }
        }
    }
    if(menor != numeric_limits<T>::max())
    {
        from = getData(posM);
        pos0 = findData(from);
        table[pos0][1] = 1; 
        DijkstraRun(from);
    }
    else
    {
        return 0; 
    }
    return 0;
}

template <class T>
void LinkedListTGP<T>::initTable(T from)
{
    int pos = findData(from);
    for(int i = 0; i < size; i++)
    {
        table[i][0] = i; // columna de datos
        table[i][1] = 0; // columna de si ya fueron visitados (se inicializa en 0 == false)
        table[i][2] = std::numeric_limits<T>::max(); // columna de limites iniciales (se inicializa en el infinito)
        table[i][3] = -1; // columna de costo para visitar al vertice
    }
    table[pos][1] = 1; 
    table[pos][2] = 0; 
}

template <class T>
void LinkedListTGP<T>::insertAdj(T fromV, T toV, int ponderacion)
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
        NodeT<T> *newAdj = new NodeT(toV, ponderacion);
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
void LinkedListTGP<T>::addFirst(T dato)
{
    NodeVT<T> *aux = new NodeVT<T>(dato);
    aux->next = head; 
    head = aux; 
    size++; 
}

template <class T> 
void LinkedListTGP<T>::addLast(T dato)
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
void LinkedListTGP<T>::printList()
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
void LinkedListTGP<T>::printGraph()
{
    if(size > 0)
    {
        NodeVT<T> *aux = head; 
        NodeT<T> *auxAdj;
        while(aux->next != nullptr)
        {
            cout << aux->dato << " "; 
            if(aux->adj != nullptr)
            {
                auxAdj = aux->adj;
                cout << auxAdj->peso << " "; 
                cout << auxAdj->dato << " "; 
                while(auxAdj->next != nullptr)
                {
                    auxAdj = auxAdj->next; 
                    cout << auxAdj->peso << " "; 
                    cout << auxAdj->dato << " "; 
                }
            }
            aux = aux->next;
            cout << endl; 
        }
        cout << aux->dato << " "; 
        if(aux->adj != nullptr)
        {
            auxAdj = aux->adj; 
            cout << auxAdj->peso << " "; 
            cout << auxAdj->dato << " "; 
            while(auxAdj->next != nullptr)
            {
                auxAdj = auxAdj->next;
                cout << auxAdj->peso << " "; 
                cout << auxAdj->dato << " "; 
            }
        }
        cout << endl;
    }
    else
    {
        cout << "Lista vacIa\n";
    }
}

template <class T> 
T LinkedListTGP<T>::getData(int index)
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
int LinkedListTGP<T>::findData(T data)
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
bool LinkedListTGP<T>::deleteData(T data)
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
bool LinkedListTGP<T>::deleteAt(int index)
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
void LinkedListTGP<T>::updateData(T data, T newData)
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
void LinkedListTGP<T>::updateAt(int index, T newData)
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
bool LinkedListTGP<T>::insertAt(int index, T data)
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
void LinkedListTGP<T>::clear()
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
void LinkedListTGP<T>::BFS(T data)
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
void LinkedListTGP<T>::DFS(T data)
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

// template <class T>
// int LinkedListTGP<T>::isProcessed(T data)
// {
//     // int pos = procesados.
// }