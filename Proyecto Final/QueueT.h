#include <string>
#include "NodeT.h"

template <class T>
class Queue
{
    private: 
        int size = 0; 
        NodeT<T> *head;
        NodeT<T> *tail; 

    public: 
        Queue<T>(){ size = 0; head = nullptr; tail = nullptr; }
        bool isEmpty(){ return size == 0; }
        int getSize(){ return size; }
        void enqueue(T);
        bool dequeue();
        T getData(int);
        void print();
        void clear();
};

template <class T> 
void Queue<T>::enqueue(T dato)
{
    NodeT<T> *aux = new NodeT<T>(dato);
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
void Queue<T>::print()
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
bool Queue<T>::dequeue()
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
T Queue<T>::getData(int index)
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
        return -1;
    }
}


template <class T> 
void Queue<T>::clear()
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