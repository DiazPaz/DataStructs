#include "Node.h"

class CircleLinkedList
{
    private: 
        int size = 0; 
        Node *head;
    public: 
        CircleLinkedList(){ size = 0; head = nullptr; }
        ~CircleLinkedList(){}
        bool isEmpty(){ return (size == 0) ? true : false; }
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

void CircleLinkedList::addFirst(int dato)
{
    Node *aux = new Node(dato);
    if(size == 0)
    {
        head = aux; 
        aux->next = head; 
    }
    else
    {
        Node *aux2 = head; 
        aux->next = aux2;
        while(aux2->next != head)
            aux2 = aux2->next; 
        head = aux; 
        aux2->next = head; 
    } 
    size++; 
}

void CircleLinkedList::addLast(int dato)
{
    Node *aux = head; 
    while(aux->next != head)
        aux = aux->next;
    aux->next = new Node(dato);
    aux = aux->next;
    aux->next = head; 
    size++;
}

void CircleLinkedList::printList()
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

int CircleLinkedList::getData(int index)
{
    if(size > 0 && index < size)
    {
        Node *aux = head; 
        for(int i = 0; i < index; i++)
            aux = aux->next; 
        return aux->dato;
    }
    else
    {
        return -1;
    }
}

int CircleLinkedList::findData(int data)
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

bool CircleLinkedList::deleteData(int data)
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

bool CircleLinkedList::deleteAt(int index)
{
    Node *aux = head; 
    Node *aux2; 
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

void CircleLinkedList::updateData(int data, int newData)
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

void CircleLinkedList::updateAt(int index, int newData)
{
    if(size > 0 && index < size)
    {
        Node *aux = head; 
        for(int i = 0; i < index; i++)
            aux = aux->next; 
        aux->dato = newData;
    }
}

bool CircleLinkedList::insertAt(int index, int data)
{
    if(index < size)
    {
        Node *aux = head; 
        Node *aux2; 
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
        if(size < index + 1)
        {
            addLast(data);
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
    else
    {
        return false;
    } 
}

void CircleLinkedList::clear()
{
    if(size <= 0)
    {
        cout << "Lista vacIa\n"; 
    }
    else
    {
        Node *aux = head; 
        while(head->next != head && size > 0)
        {
            head = aux->next;
            aux->next = nullptr; 
            delete aux; 
            aux = head;
            size--; 
        }
        head = nullptr; 
        delete head;
        size--; 
        cout << "Lista borrada!\n";
    }
}