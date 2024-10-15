#include "NodeT.h"

template <class T>
class Stack
{
    private: 
        int size = 0; 
        NodeT<T> *top;
    public: 
        Stack<T>(){ size = 0; top = nullptr; }
        bool isEmpty(){ return size == 0; }
        int getSize(){ return size; }
        void push(T); //addFirst
        void print();
        int findData(T);
        T peek(); //getData
        bool pop(); //deleteAt(0)
        void clear();
};

template <class T> 
void Stack<T>::push(T dato)
{
    NodeT<T> *aux = new NodeT<T>(dato);
    aux->next = top; 
    top = aux; 
    size++; 
}

template <class T> 
void Stack<T>::print()
{
    if(size > 0)
    {
        NodeT<T> *aux = top; 
        for(int i = 0; i < size; i++)
        {
            cout << aux->dato << endl; 
            aux = aux->next;
        }
    }
    else
    {
        cout << "Pila vacIa\n";
    }
}

template <class T> 
T Stack<T>::peek()
{
    if(size > 0)
    { 
        return top->dato;
    }
    else
    {
        return -1;
    }
}

template <class T> 
int Stack<T>::findData(T data)
{
    NodeT<T> *aux = top; 
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
bool Stack<T>::pop()
{
    if(0 < size)
    {
        NodeT<T> *aux = top; 
        aux = top; 
        top = aux->next; 
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
void Stack<T>::clear()
{
    if(size > 0)
    {
        NodeT<T> *aux = top; 
        while(top->next != nullptr)
        {
            top = aux->next;
            aux->next = nullptr; 
            delete aux; 
            aux = top;
            size--; 
        }
        top = nullptr; 
        delete aux;
        size--; 
        cout << "Lista borrada!\n";
    }
    else
    {
        cout << "Lista vacIa\n"; 
    }
}