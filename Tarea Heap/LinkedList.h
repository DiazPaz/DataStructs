#include "Node.h"

class LinkedList
{
    private: 
        int size = 0; 
        Node *head;
    public: 
        LinkedList(){ size = 0; head = nullptr; }
        bool isEmpty(){ return size == 0; }
        int getSize(){ return size; }
        void addFirst(int);
        void addLast(int);
        void printList();
        int getData(int);
        int findData(int);
        bool deleteData(int);
        bool deleteAt(int);
        void updateData(int, int);
        void updateAt(int, int);
        bool insertAt(int, int);
        void clear();
};

void LinkedList::addFirst(int dato)
{
    Node *aux = new Node(dato);
    aux->next = head; 
    head = aux; 
    size++; 
}

void LinkedList::addLast(int dato)
{
    Node *aux = head; 
    for(int i = 0; i < size-1; i++)
        aux = aux->next;
    aux->next = new Node(dato);
    size++;
}

void LinkedList::printList()
{
    if(size > 0)
    {
        Node *aux = head; 
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

int LinkedList::getData(int index)
{
    if(size > 0 && index <= size)
    {
        Node *aux = head; 
        for(int i = 1; i < index; i++)
            aux = aux->next; 
        return aux->dato;
    }
    else
    {
        return -1;
    }
}

int LinkedList::findData(int data)
{
    Node *aux = head; 
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

bool LinkedList::deleteData(int data)
{
    Node *aux = head; 
    Node *aux2; 
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

bool LinkedList::deleteAt(int index)
{
    Node *aux = head; 
    Node *aux2; 
    int count = 1; 
    while(count < index)
    {
        aux2 = aux;
        aux = aux->next;
        count++;
    }
    if(index <= size)
    {
        if(count == 1)
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

void LinkedList::updateData(int data, int newData)
{
    Node *aux = head; 
    int count = 0; 
    while(aux->dato != data && count < size)
    {
        aux = aux->next; 
        count++;
    }
    if(aux->dato == data)
        aux->dato = newData; 
}

void LinkedList::updateAt(int index, int newData)
{
    if(size > 0 && index <= size)
    {
        Node *aux = head; 
        for(int i = 1; i < index; i++)
            aux = aux->next; 
        aux->dato = newData;
    }
}

bool LinkedList::insertAt(int index, int data)
{
    if(index <= size)
    {
        Node *aux = head; 
        Node *aux2; 
        int count = 1; 
        while(count < index)
        {
            aux2 = aux;
            aux = aux->next;
            count++;
        }
        if(count == 1)
        {
            addFirst(data); 
            return true;
        }
        else
        {
            Node *newNode = new Node(data);
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

void LinkedList::clear()
{
    if(size > 0)
    {
        Node *aux = head; 
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