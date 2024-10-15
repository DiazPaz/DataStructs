#include "NodeT.h"

template <class T>
class LinkedListT
{
    private: 
        int size = 0; 
        NodeT<T> *head;
    public: 
        LinkedListT<T>(){ size = 0; head = nullptr; }
        bool isEmpty(){ return size == 0; }
        int getSize(){ return size; }
        void addFirst(T);
        void addLast(T);
        void printList();
        T getData(int);
        int findData(T);
        bool deleteData(T);
        bool deleteAt(int);
        void updateData(T, T);
        void updateAt(int, T);
        bool insertAt(int, T);
        void clear();
};

template <class T> 
void LinkedListT<T>::addFirst(T dato)
{
    NodeT<T> *aux = new NodeT<T>(dato);
    aux->next = head; 
    head = aux; 
    size++; 
}

template <class T> 
void LinkedListT<T>::addLast(T dato)
{
    if(size > 0)
    {
        NodeT<T> *aux = head; 
        for(int i = 0; i < size-1; i++)
            aux = aux->next;
        aux->next = new NodeT<T>(dato);
    }
    else
    {
        head = new NodeT<T>(dato);
    }
    size++;
}

template <class T> 
void LinkedListT<T>::printList()
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
T LinkedListT<T>::getData(int index)
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
int LinkedListT<T>::findData(T data)
{
    NodeT<T> *aux = head; 
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
    NodeT<T> *aux = head; 
    NodeT<T> *aux2; 
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
    NodeT<T> *aux = head; 
    NodeT<T> *aux2; 
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
    NodeT<T> *aux = head; 
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
        NodeT<T> *aux = head; 
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
        NodeT<T> *aux = head; 
        NodeT<T> *aux2; 
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
            NodeT<T> *newNode = new NodeT<T>(data);
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
        cout << "Lista borrada!\n";
    }
    else
    {
        cout << "Lista vacIa\n"; 
    }
}