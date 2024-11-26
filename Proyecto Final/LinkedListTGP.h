// David Díaz Paz y Puente | 650794 | Estructuras de Datos
// Doy mi palabra que he realizado esta actividad con integridad académica.

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

        int tableCar[82][7] = {0};
        int tableTrain[82][7] = {0};
        
        T route[82];
        void printTable(T org, int table[82][7]);
        void initTableCarro(T dest);
        void initTableTren(T dest);
        int DijkstraRunCarro(T destTime, T destDist);
        int DijkstraRunTren(T destTime, T destDist);

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
        void insertAdj(T destV, T toV, int pondTiempoTren, int pondDistTren, int pondTiempoCarro, int pondDistCarro);
        void BFS(T data, int cont);
        void DFS(T data, int cont);
        void resetProcessed();
        void Dijkstra(T org, T dest); 
        void clear();
};

template <class T>
void LinkedListTGP<T>::printTable(T org, int table[82][7])
{
    int ruta;

    cout << "La ruta de menos tiempo: "; 
    for(int i = 0; i < size; i++)
    {
        if(getData(table[i][0]-1) == org)
        {
            cout << table[i][3]/60 << ":";
            if(table[i][3]%60 < 10)
                cout << "0" << table[i][3]%60 << " hrs" << endl; 
            else
                cout << table[i][3]%60 << " hrs" << endl; 
            if(table[i][5] == -1)
            {
                cout << getData(table[i][0]-1) << endl; 
            }
            else
            {
                ruta = i;
                while(table[ruta][5] != -1)
                {
                    cout << getData(table[ruta][0]-1) << " -> ";
                    ruta = table[ruta][5];
                }
                cout << getData(table[ruta][0]-1) << endl; 
            }
        }
    }

    cout << "\nLa ruta mAs corta en distancia: "; 
    for(int i = 0; i < size; i++)
    {
        if(getData(table[i][0]-1) == org)
        {
            cout << table[i][4] << "km \n";
            if(table[i][6] == -1)
            {
                cout << getData(table[i][0]-1) << endl; 
            }
            else
            {
                ruta = i;
                while(table[ruta][6] != -1)
                {
                    cout << getData(table[ruta][0]-1) << " -> ";
                    ruta = table[ruta][6];
                }
                cout << getData(table[ruta][0]-1) << endl; 
            }
        }
    }

    cout << "----------------\n";
}


// Función para llamar al método que se encarga de correr el algoritmo Dijkstra
template <class T>
void LinkedListTGP<T>::Dijkstra(T org, T dest)
{
    initTableCarro(dest);
    initTableTren(dest);
    int res1 = DijkstraRunCarro(dest, dest);
    int res2 = DijkstraRunTren(dest, dest);
    cout << "EN CARRO: \n\n";
    printTable(org, tableCar);
    cout << "EN TREN: \n\n";
    printTable(org, tableTrain);
}

template <class T>
int LinkedListTGP<T>::DijkstraRunCarro(T destTime, T destDist)
{
    int pos0Time = findData(destTime); // asignamos posición para el dato donde se empieza la busqueda
    int pos0Dist = findData(destDist); // asignamos posición para el dato donde se empieza la busqueda
    NodeVT<T> *auxT = head, *auxD = head; 
    int pos1 = 0, pos2 = 0, posT, posD, tiempo = tableCar[pos0Time][3], distancia = tableCar[pos0Dist][4];

    while(auxT->dato != destTime && pos1 < size) // ciclo para ponerme en el nodo donde este dest
    {
        auxT = auxT->next; 
        pos1++; 
    }
    
    while(auxD->dato != destDist && pos2 < size) // ciclo para ponerme en el nodo donde este dest
    {
        auxD = auxD->next; 
        pos2++; 
    }

    if(auxT->dato == destTime && auxD->dato == destDist)
    {
        if(auxT->adj != nullptr && auxD->adj != nullptr) // si tiene adyacencias, las recorrera todas
        {
            NodeT<T> *aux2 = auxT->adj;
            NodeT<T> *aux3 = auxD->adj;

            // Deberían de haber 2 ciclos: uno para tiempo y otro para distancia

            // Tiempo
            do{ // ciclo para recorrer todas las adyacencias
                posT = findData(aux2->dato);
                if(tableCar[posT][1] == 0) // recordamos que la posición 1 de la tabla es para valores booleanos: 1=visitado y 0=noVisitado
                {
                    if(tableCar[posT][3] > (tiempo + aux2->tiempoCarro)) // comparamos el peso actual puesto en la tabla con el peso de las adyacencias del objeto 'dest'
                    {
                        tableCar[posT][3] = tiempo + aux2->tiempoCarro; // si el peso para a la adyacencia de 'dest' es menor que el ya propuesto en la tabla, se suma (para armar la ruta)
                        tableCar[posT][5] = pos0Time; // asignamos el valor de la columna 3 de la tabla para ese dato como el nombre del nodo del que venimos
                    }
                }
                aux2 = aux2->next; // vamos a la siguiente adyacencia
            }while(aux2 != nullptr);
            
            // Distancia
            do{ // ciclo para recorrer todas las adyacencias
                posD = findData(aux3->dato);
                if(tableCar[posD][2] == 0) // recordamos que la posición 2 de la tabla es para valores booleanos: 1=visitado y 0=noVisitado
                {
                    if(tableCar[posD][4] > (distancia + aux3->distanciaCarro)) // comparamos el peso actual puesto en la tabla con el peso de las adyacencias del objeto 'dest'
                    {
                        tableCar[posD][4] = distancia + aux3->distanciaCarro; // si el peso para a la adyacencia de 'dest' es menor que el ya propuesto en la tabla, se suma (para armar la ruta)
                        tableCar[posD][6] = pos0Dist; // asignamos el valor de la columna 3 de la tabla para ese dato como el nombre del nodo del que venimos
                    }
                }
                aux3 = aux3->next; // vamos a la siguiente adyacencia
            }while(aux3 != nullptr);
        }
    }

    int menorTiempo = numeric_limits<int>::max();
    int menorDistancia = numeric_limits<int>::max();
    int posMT, posMD; 

    for(int i = 0; i < size; i++) // ciclo para encontrar la via más rápida entre dos puntos ( menor tiempo )
    {
        if(tableCar[i][1] == 0) // si el dato 'i' no ha sido visitado
        {
            if(tableCar[i][3] < menorTiempo) // si el peso para llegar al dato 'i' es menor al peso ya menor para llegar al dato 'i'
            {
                menorTiempo = tableCar[i][3]; // asignamos nuevo valor menor para llegar al dato 'i'
                posMT = i; // posición del dato 'i'
            }
        }
    }
    
    for(int i = 0; i < size; i++) // ciclo para encontrar la via más rápida entre dos puntos ( menor distancia )
    {
        if(tableCar[i][2] == 0) // si el dato 'i' no ha sido visitado
        {
            if(tableCar[i][4] < menorDistancia) // si el peso para llegar al dato 'i' es menor al peso ya menor para llegar al dato 'i'
            {
                menorDistancia = tableCar[i][4]; // asignamos nuevo valor menor para llegar al dato 'i'
                posMD = i; // posición del dato 'i'
            }
        }
    }

    if(menorTiempo != numeric_limits<int>::max() && menorDistancia != numeric_limits<int>::max()) // si todos los caminos a cada vertice ya tienen un peso
    {

        // aquí mi lógica me dice que hay un problema: No necesariamente el camino que tome menos tiempo será el camino más corto en distancia
        destTime = getData(posMT); // (recordamos que posMT es la posición del elemento vecino al que más rápido se llega) asignamos a 'destTime' como el elemento más rápido al que podemos llegar
        destDist = getData(posMD); // (recordamos que posMD es la posición del elemento vecino al que más rápido se llega) asignamos a 'destDist' como el elemento más rápido al que podemos llegar
        pos0Time = findData(destTime); // buscamos la posición del dato de 'destTime' (el de más rápido acceso) en nuestra Linked List
        pos0Dist = findData(destDist); // buscamos la posición del dato de 'destDist' (el de más rápido acceso) en nuestra Linked List
        tableCar[pos0Time][1] = 1; // visitamos la posición en la tabla para nuestro dato 'destTime' y la colocamos como visitada (= 1)
        tableCar[pos0Dist][2] = 1; // visitamos la posición en la tabla para nuestro dato 'destDist' y la colocamos como visitada (= 1)
        DijkstraRunCarro(destTime, destDist); // ahora ya tenemos la ruta más rápida para para el nodo vecino más proximo en tiempo y en distancia
    }
    else
    {
        return 0; // si el vertice es infinito es por que la tabla sigue vacía
    }
    return 0;
}

template <class T>
int LinkedListTGP<T>::DijkstraRunTren(T destTime, T destDist)
{
    int pos0Time = findData(destTime); // asignamos posición para el dato donde se empieza la busqueda
    int pos0Dist = findData(destDist); // asignamos posición para el dato donde se empieza la busqueda
    NodeVT<T> *auxT = head, *auxD = head; 
    int pos1 = 0, pos2 = 0, posT, posD, tiempo = tableTrain[pos0Time][3], distancia = tableTrain[pos0Dist][4];

    while(auxT->dato != destTime && pos1 < size) // ciclo para ponerme en el nodo donde este dest
    {
        auxT = auxT->next; 
        pos1++; 
    }
    
    while(auxD->dato != destDist && pos2 < size) // ciclo para ponerme en el nodo donde este dest
    {
        auxD = auxD->next; 
        pos2++; 
    }

    if(auxT->dato == destTime && auxD->dato == destDist)
    {
        if(auxT->adj != nullptr && auxD->adj != nullptr) // si tiene adyacencias, las recorrera todas
        {
            NodeT<T> *aux2 = auxT->adj;
            NodeT<T> *aux3 = auxD->adj;

            // Deberían de haber 2 ciclos: uno para tiempo y otro para distancia

            // Tiempo
            do{ // ciclo para recorrer todas las adyacencias
                posT = findData(aux2->dato);
                if(tableTrain[posT][1] == 0) // recordamos que la posición 1 de la tabla es para valores booleanos: 1=visitado y 0=noVisitado
                {
                    if(tableTrain[posT][3] > (tiempo + aux2->tiempoTren)) // comparamos el peso actual puesto en la tabla con el peso de las adyacencias del objeto 'dest'
                    {
                        tableTrain[posT][3] = tiempo + aux2->tiempoTren; // si el peso para a la adyacencia de 'dest' es menor que el ya propuesto en la tabla, se suma (para armar la ruta)
                        tableTrain[posT][5] = pos0Time; // asignamos el valor de la columna 3 de la tabla para ese dato como el nombre del nodo del que venimos
                    }
                }
                aux2 = aux2->next; // vamos a la siguiente adyacencia
            }while(aux2 != nullptr);
            
            // Distancia
            do{ // ciclo para recorrer todas las adyacencias
                posD = findData(aux3->dato);
                if(tableTrain[posD][2] == 0) // recordamos que la posición 2 de la tabla es para valores booleanos: 1=visitado y 0=noVisitado
                {
                    if(tableTrain[posD][4] > (distancia + aux3->distanciaTren)) // comparamos el peso actual puesto en la tabla con el peso de las adyacencias del objeto 'dest'
                    {
                        tableTrain[posD][4] = distancia + aux3->distanciaTren; // si el peso para a la adyacencia de 'dest' es menor que el ya propuesto en la tabla, se suma (para armar la ruta)
                        tableTrain[posD][6] = pos0Dist; // asignamos el valor de la columna 3 de la tabla para ese dato como el nombre del nodo del que venimos
                    }
                }
                aux3 = aux3->next; // vamos a la siguiente adyacencia
            }while(aux3 != nullptr);
        }
    }

    int menorTiempo = numeric_limits<int>::max();
    int menorDistancia = numeric_limits<int>::max();
    int posMT, posMD; 

    for(int i = 0; i < size; i++) // ciclo para encontrar la via más rápida entre dos puntos ( menor tiempo )
    {
        if(tableTrain[i][1] == 0) // si el dato 'i' no ha sido visitado
        {
            if(tableTrain[i][3] < menorTiempo) // si el peso para llegar al dato 'i' es menor al peso ya menor para llegar al dato 'i'
            {
                menorTiempo = tableTrain[i][3]; // asignamos nuevo valor menor para llegar al dato 'i'
                posMT = i; // posición del dato 'i'
            }
        }
    }
    
    for(int i = 0; i < size; i++) // ciclo para encontrar la via más rápida entre dos puntos ( menor distancia )
    {
        if(tableTrain[i][2] == 0) // si el dato 'i' no ha sido visitado
        {
            if(tableTrain[i][4] < menorDistancia) // si el peso para llegar al dato 'i' es menor al peso ya menor para llegar al dato 'i'
            {
                menorDistancia = tableTrain[i][4]; // asignamos nuevo valor menor para llegar al dato 'i'
                posMD = i; // posición del dato 'i'
            }
        }
    }

    if(menorTiempo != numeric_limits<int>::max() && menorDistancia != numeric_limits<int>::max()) // si todos los caminos a cada vertice ya tienen un peso
    {

        // aquí mi lógica me dice que hay un problema: No necesariamente el camino que tome menos tiempo será el camino más corto en distancia
        destTime = getData(posMT); // (recordamos que posMT es la posición del elemento vecino al que más rápido se llega) asignamos a 'destTime' como el elemento más rápido al que podemos llegar
        destDist = getData(posMD); // (recordamos que posMD es la posición del elemento vecino al que más rápido se llega) asignamos a 'destDist' como el elemento más rápido al que podemos llegar
        pos0Time = findData(destTime); // buscamos la posición del dato de 'destTime' (el de más rápido acceso) en nuestra Linked List
        pos0Dist = findData(destDist); // buscamos la posición del dato de 'destDist' (el de más rápido acceso) en nuestra Linked List
        tableTrain[pos0Time][1] = 1; // visitamos la posición en la tabla para nuestro dato 'destTime' y la colocamos como visitada (= 1)
        tableTrain[pos0Dist][2] = 1; // visitamos la posición en la tabla para nuestro dato 'destDist' y la colocamos como visitada (= 1)
        DijkstraRunTren(destTime, destDist); // ahora ya tenemos la ruta más rápida para para el nodo vecino más proximo en tiempo y en distancia
    }
    else
    {
        return 0; // si el vertice es infinito es por que la tabla sigue vacía
    }
    return 0;
}

template <class T>
void LinkedListTGP<T>::initTableCarro(T dest)
{
    int pos = findData(dest);
    for(int i = 0; i < size; i++)
    {
        tableCar[i][0] = i+1;
        tableCar[i][1] = 0; // 1=visitado | 0=noVisitado ( TIEMPO )
        tableCar[i][2] = 0; // 1=visitado | 0=noVisitado ( DISTANCIA )
        tableCar[i][3] = std::numeric_limits<int>::max(); // tiempo en carro
        tableCar[i][4] = std::numeric_limits<int>::max(); // distancia Carro
        tableCar[i][5] = -1; // representa al nodo anterior en la ruta más corta (tiempo) 
        tableCar[i][6] = -1; // representa al nodo anterior en la ruta más corta (distancia)
    }
    tableCar[pos][1] = 1; 
    tableCar[pos][2] = 1; 
    tableCar[pos][3] = 0; 
    tableCar[pos][4] = 0; 
}

template <class T>
void LinkedListTGP<T>::initTableTren(T dest)
{
    int pos = findData(dest);
    for(int i = 0; i < size; i++)
    {
        tableTrain[i][0] = i+1;
        tableTrain[i][1] = 0; // 1=visitado | 0=noVisitado ( TIEMPO )
        tableTrain[i][2] = 0; // 1=visitado | 0=noVisitado ( DISTANCIA )
        tableTrain[i][3] = std::numeric_limits<int>::max(); // tiempo en carro
        tableTrain[i][4] = std::numeric_limits<int>::max(); // distancia Carro
        tableTrain[i][5] = -1; // representa al nodo anterior en la ruta más corta (tiempo) 
        tableTrain[i][6] = -1; // representa al nodo anterior en la ruta más corta (distancia)
    }
    tableTrain[pos][1] = 1; 
    tableTrain[pos][2] = 1; 
    tableTrain[pos][3] = 0; 
    tableTrain[pos][4] = 0; 
}

template <class T>
void LinkedListTGP<T>::insertAdj(T destV, T toV, int pondTiempoTren, int pondDistTren, int pondTiempoTrenCarro, int pondDistCarro)
{
    NodeVT<T> *aux = head; 
    int count = 0; 
    while(aux->dato != destV && count < size)
    {
        aux = aux->next; 
        count++;
    }
    if(aux->dato == destV) // aquí voy a ligar la lista de adyacencias
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
        return "";
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

    // Se abre el archivo de salida para BFS
    if(cont == 1)
    {
        fout2.open("output-2.out");
        resetProcessed();
        fout2 << "RECORRIDO BFS: \n";
    }

    // se busca el apuntador al dato
    while(aux->dato != data && pos < size && aux->next != nullptr)
    {
        aux = aux->next; 
        pos++;
    }

    // si no se encuentra el dato, se termina la función
    if(aux == nullptr)
    {
        return; 
    }

    // Si se encontró el dato y aún no ha sido procesado, se comienzan a escribir los datos en el archivo de salida y se almacenan en una queue
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

    // si el tamaño del queue es mayor a cero, se llama a la misma función para conseguir repetir el sistema con el siguiente nodo
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
    // Se abre el archivo de salida para el DFS
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

// Método implementado para poder reiniciar los valores de "procesado" de los nodos, para poder volver a usarlos en cada llamada del BFS y DFS simultanea. 
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
