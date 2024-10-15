template <class T> class LinkedListT; 
template <class T>
class NodeT
{
    friend class LinkedListT<T>; 
    private: 
        T dato;
        NodeT<T> *next;
    public: 
        NodeT<T>(int datoParam){ dato = datoParam; next = nullptr; } 
};