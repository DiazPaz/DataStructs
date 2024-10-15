class Node
{
    friend class Queue;
    private: 
        int dato; 
        Node *next; 

    public: 
        Node(int data){ dato = data; next = nullptr; }

};