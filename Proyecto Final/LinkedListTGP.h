#include "NodeVT.h"
#include "QueueT.h"
#include <limits>
#include <unordered_map>

template <class T>
class LinkedListTGP
{
    private: 
        int size = 0; 
        NodeVT<T> *head;
        QueueT<T> fila;
        QueueT<T> procesados;
        ofstream fout2;
        ofstream fout3;
        int table[82][4];

        string tableCar[82][6];
        string tableTrain[82][6];

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
        void printBFS();
        T getData(int);
        int findData(T);
        bool deleteData(T);
        bool deleteAt(int);
        void updateData(T, T);
        void updateAt(int, T);
        bool insertAt(int, T);
        void insertAdj(T fromV, T toV, int pondTiempoTren, int pondDistTren, int pondTiempoCarro, int pondDistCarro);
        void BFS(T data, int cont);
        void DFS(T data, int cont);
        void resetProcessed();
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
            do{ // ciclo para recorrer todas las adyacencias
                posT = findData(aux2->dato);
                if(table[posT][1] == 0) // recordamos que la posición 1 de la tabla es para valores booleanos: 1=visitado y 0=noVisitado
                {
                    if(table[posT][2] > (costo + aux2->peso)) // comparamos el peso actual puesto en la tabla con el peso de las adyacencias del objeto 'from'
                    {
                        table[posT][2] = costo + aux2->peso; // si el peso para a la adyacencia de 'from' es menor que el ya propuesto en la tabla, se suma (para armar la ruta)
                        table[posT][3] = pos0; // asignamos el valor de la columna 3 de la tabla para ese dato como el nombre del nodo del que venimos
                    }
                }
                aux2 = aux2->next; // vamos a la siguiente adyacencia
            }while(aux2 != nullptr);
        }
    }

    int menor = numeric_limits<T>::max();
    int posM; 

    for(int i = 0; i < size; i++) // ciclo para encontrar la via más rápida entre dos puntos
    {
        if(table[i][1] == 0) // si el dato 'i' no ha sido visitado
        {
            if(table[i][2] < menor) // si el peso para llegar al dato 'i' es menor al peso ya menor para llegar al dato 'i'
            {
                menor = table[i][2]; // asignamos nuevo valor menor para llegar al dato 'i'
                posM = i; // posición del dato 'i'
            }
        }
    }

    if(menor != numeric_limits<T>::max()) // si todos los caminos a cada vertice ya tienen un peso
    {
        from = getData(posM); // (recordamos que posM es la posición del elemento vecino al que más rápido se llega) asignamos a 'from' como el elemento más rápido al que podemos llegar
        pos0 = findData(from); // buscamos la posición del dato de 'from' (el de más rápido acceso) en nuestra Linked List
        table[pos0][1] = 1; // visitamos la posición en la tabla para nuestro dato 'from' y la colocamos como visitada
        DijkstraRun(from); // ahora ya tenemos la ruta más rápida para desde el 'from' del parámetro inicial al 'from' que irá como parámetro en esta siguiente función DijkstraRun
    }
    else
    {
        return 0; // si el vertice es infinito es por que la tabla sigue vacía
    }
    return 0;
}

// template <class T>
// void LinkedListTGP<T>::initTable(T from)
// {
//     int pos = findData(from);
//     for(int i = 0; i < size; i++)
//     {
//         tableCar[i][0] = getData(i+1);
//         tableCar[i][1] = 0;
//         tableCar[i][2] = std::numeric_limits<T>::max();
//     }
// }

template <class T>
void LinkedListTGP<T>::initTable(T from)
{
    int pos = findData(from);
    for(int i = 0; i < size; i++)
    {
        table[i][0] = i; // columna de datos
        table[i][1] = 0; // columna de si ya fueron visitados (se inicializa en 0 == false)
        table[i][2] = std::numeric_limits<int>::max(); // columna de limites iniciales (se inicializa en el infinito)
        table[i][3] = -1; // representa al nodo anterior en la ruta más corta
    }
    table[pos][1] = 1; 
    table[pos][2] = 0; 
}

template <class T>
void LinkedListTGP<T>::insertAdj(T fromV, T toV, int pondTiempoTren, int pondDistTren, int pondTiempoTrenCarro, int pondDistCarro)
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
        NodeT<T> *newAdj = new NodeT(toV, pondTiempoTren, pondDistTren, pondTiempoTrenCarro, pondDistCarro);
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

// cambiar funcion enqueue para que acepte los parametros necesarios para NodeT


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
    ofstream fout("output-1.out");
    fout << "LISTA DE ADYACENCIAS: \n";
    if(size > 0)
    {
        NodeVT<T> *aux = head; 
        NodeT<T> *auxAdj;
        while(aux->next != nullptr)
        {
            fout << aux->dato << " -> "; 
            if(aux->adj != nullptr)
            {
                auxAdj = aux->adj;
                fout << auxAdj->dato << ", "; 
                while(auxAdj->next != nullptr)
                {
                    auxAdj = auxAdj->next; 
                    fout << auxAdj->dato << ", "; 
                }
            }
            aux = aux->next;
            fout << endl; 
        }
        fout << aux->dato << " -> "; 
        if(aux->adj != nullptr)
        {
            auxAdj = aux->adj; 
            fout << auxAdj->dato << ", "; 
            while(auxAdj->next != nullptr)
            {
                auxAdj = auxAdj->next;
                fout << auxAdj->dato << ", "; 
            }
        }
        fout << endl;
    }
    else
    {
        fout << "Lista vacIa\n";
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
    while(aux != nullptr)
    {
        if(aux->dato != data && count < size)
        {
            aux = aux->next; 
            count++;
        }
        else 
        {
            return count; 
        }
    }
    
    if(aux == nullptr)
        return -1; // -1 es la bandera para cuando no se repite el elemento 
    else   
        return count;
    
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
void LinkedListTGP<T>::BFS(T data, int cont)
{
    NodeVT<T> *aux = head;
    int pos = 0; 

    if(cont == 1)
    {
        fout2.open("output-2.out");
        resetProcessed();
        fout2 << "RECORRIDO BFS: \n";
    }

    while(aux->dato != data && pos < size && aux->next != nullptr)
    {
        aux = aux->next; 
        pos++;
    }

    if(aux == nullptr)
    {
        return; 
    }

    if(aux->dato == data && aux->processed == false) 
    {
        aux->processed = true; 
        fout2 << aux->dato << "\n";
        if(aux->adj != nullptr)
        {
            NodeT<T> *aux2 = aux->adj; 
            aux2->processed = true; 
            fila.enqueue(aux2->dato, aux2->tiempoTren, aux2->distanciaTren, aux2->tiempoCarro, aux2->distanciaCarro);
            while(aux2->next != nullptr)
            {
                aux2 = aux2->next; 
                aux2->processed = true;
                fila.enqueue(aux2->dato, aux2->tiempoTren, aux2->distanciaTren, aux2->tiempoCarro, aux2->distanciaCarro);
            }
        } 
    }
    if(fila.getSize()>0)
    {
        T sigNodo = fila.getData(0);
        if(fila.dequeue())
            BFS(sigNodo, cont+1);
    }
}

template <class T>
void LinkedListTGP<T>::DFS(T data, int cont)
{
    if(cont == 0)
    {
        fout3.open("output-3.out");
        resetProcessed();
        fout3 << "RECORRIDO DFS: \n";
    }
    NodeVT<T> *aux = head; 
    // busqueda del nodo origen para empezar el recorrido
    int pos = 0;
    while(aux->dato != data && pos < size)
    {
        aux = aux->next; 
        pos++;
    }

    if(aux == nullptr)
    {
        return; 
    }

    // verificamos si el nodo ya fue procesado o no 
    if(aux->dato == data && aux->processed == false)
    {
        aux->processed = true; 
        procesados.enqueueVT(aux->dato);
        fout3 << aux->dato << "\n";
        NodeT<T> *aux2 = aux->adj; 
        
        // ciclo donde verificamos si los nodos adyacentes ya fueron procesados o no
        while(aux2 != nullptr)
        {
            // en caso de que no hayan sido procesados los procesamos para que no se repitan 
            if (aux2->processed == false)
            {
                aux2->processed = true; 
                DFS(aux2->dato, cont+1); 
            }
            aux2 = aux2->next;
        }
    }
}

template <class T>
void LinkedListTGP<T>::resetProcessed()
{
    NodeVT<T> *aux = head;
    while (aux != nullptr)
    {
        aux->processed = false;
        NodeT<T> *adj = aux->adj;
        while (adj != nullptr)
        {
            adj->processed = false;
            adj = adj->next;
        }
        aux = aux->next;
    }
}
