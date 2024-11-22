#ifndef NodeT_H
#define NodeT_H

template <class T> class LinkedListTGP; 
template <class T> class Queue; 
template <class T>
class NodeT
{
    friend class LinkedListTGP<T>; 
    friend class Queue<T>; 
    private: 
        T dato;
        int distancia = 0; 
        int tiempo = 0; 
        NodeT<T> *next;
        bool processed = false; 
    public: 
        NodeT<T>(T datoParam, int pondTiempo, int pondDist)
        { 
            dato = datoParam; 
            tiempo = pondTiempo;
            distancia = pondDist; 
            next = nullptr; 
        } 
};

#endif