class Node
{
    friend class LinkedList; 
    friend class CircleLinkedList; 
    private: 
        int dato;
        Node *next;
    public: 
        Node(int datoParam){ dato = datoParam; next = nullptr; } 
};