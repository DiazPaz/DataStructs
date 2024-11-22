#ifndef NodeT_H
#define NodeT_H

template <class T> class LinkedListT; 
template <class T> class LinkedListTGP; 
template <class T> class Queue; 
template <class T> class Stack; 
template <class T>
class NodeT
{
    friend class LinkedListT<T>; 
    friend class LinkedListTGP<T>; 
    friend class Queue<T>; 
    friend class Stack<T>; 
    private: 
        T dato;
        int peso = 0; 
        NodeT<T> *next;
        bool processed = false; 
    public: 
        NodeT<T>(T datoParam){ dato = datoParam; next = nullptr; } 
        NodeT<T>(T datoParam, int ponderacion){ dato = datoParam; peso = ponderacion; next = nullptr; } 
};

#endif