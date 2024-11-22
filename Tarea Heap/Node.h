class Node
{
    friend class LinkedList; 
    private: 
        int dato;
        Node *next;
    public: 
        Node(int datoParam){ dato = datoParam; next = nullptr; } 
};