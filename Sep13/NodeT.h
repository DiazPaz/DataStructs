template <class T> class Stack; 
template <class T>
class NodeT
{
    friend class Stack<T>; 
    private: 
        T dato;
        NodeT<T> *next;
    public: 
        NodeT<T>(int datoParam){ dato = datoParam; next = nullptr; } 
};