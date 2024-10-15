class NodeTr
{
    friend class BST; 
    private: 
        int dato;
        NodeTr *left, *right; 
    public: 
        NodeTr(int data)
        {
            dato = data; 
            left = nullptr;
            right = nullptr;
        }
};