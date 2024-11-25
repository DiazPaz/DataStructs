#include <string>
#include "NodeT.h"

template <class T>
class QueueT
{
    private: 
        int size = 0; 
        NodeT<T> *head;
        NodeT<T> *tail; 

    public: 
        QueueT<T>(){ size = 0; head = nullptr; tail = nullptr; }
        bool isEmpty(){ return size == 0; }
        int getSize(){ return size; }
        void enqueue(T toV, string pondTiempoTren, string pondDistTren, string pondTiempoTrenCarro, string pondDistCarro);
        void enqueueVT(T toV);
        bool dequeue();
        T getData(int);
        void print();
        void clear();
};

template <class T> 
void QueueT<T>::enqueue(T toV, string pondTiempoTren, string pondDistTren, string pondTiempoTrenCarro, string pondDistCarro)
{
    NodeT<T> *aux = new NodeT(toV, pondTiempoTren, pondDistTren, pondTiempoTrenCarro, pondDistCarro);
    if(size > 0)
    {
        tail->next = aux; 
        tail = aux; 
    }
    else 
    {
        head = aux;
        tail = aux; 
    }
    size++;
}

template <class T> 
void QueueT<T>::enqueueVT(T toV)
{
    NodeT<T> *aux = new NodeT(toV);
    if(size > 0)
    {
        tail->next = aux; 
        tail = aux; 
    }
    else 
    {
        head = aux;
        tail = aux; 
    }
    size++;
}

template <class T> 
void QueueT<T>::print()
{
    if(size > 0)
    {
        NodeT<T> *aux = head; 
        for(int i = 0; i < size; i++)
        {
            cout << aux->dato << endl; 
            aux = aux->next;
        }
    }
    else
    {
        cout << "Lista vacIa\n";
    }
}

template <class T> 
bool QueueT<T>::dequeue()
{
    if(size > 0)
    {
        NodeT<T> *aux = head; 
        head = aux->next;         
        aux->next = nullptr; 
        delete aux; 
        size--;
        return true;
    }
    else
    {
        return false;
    } 
}

template <class T> 
T QueueT<T>::getData(int index)
{
    if(size > 0 && index < size)
    {
        NodeT<T> *aux = head; 
        for(int i = 0; i < index; i++)
            aux = aux->next; 
        return aux->dato;
    }
    else
    {
        return 0;
    }
}


template <class T> 
void QueueT<T>::clear()
{
    if(size > 0)
    {
        NodeT<T> *aux = head; 
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
        cout << "Fila borrada!\n";
    }
    else
    {
        cout << "Fila vacIa\n"; 
    }
}