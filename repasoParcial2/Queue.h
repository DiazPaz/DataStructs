#include "Node.h"

class Queue
{
    private: 
        int size; 
        Node *head; 
        Node *tail; 

    public: 
        void enqueue(int dato)
        {
            Node *aux = new Node(dato);
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

        void dequeue()
        {
            if(size > 0)
            {
                Node *aux = head;
                head = aux->next;
                aux->next = nullptr;
                delete aux;
                size--; 
            }
            else
            {
                cout << "Lista vacIa, no hay elementos para borrar. \n";
            }
        }

        void printQueue()
        {
            if(size > 0)
            {
                Node *aux = head; 
                for(int i = 0; i < size-2; i++)
                {
                    cout << aux->dato << " ";
                    aux = aux->next;
                }
            }
            else
            {
                cout << "Lista vacIa.\n";
            }
        }

};