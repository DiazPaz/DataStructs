#include <string>
template <class T> class Queue; 
template <class T>
class NodeT
{
    friend class Queue<T>; 
    private: 
        T dato;
        NodeT<T> *next;
    public: 
        NodeT<T>(string datoParam){ dato = datoParam; next = nullptr; } 
};