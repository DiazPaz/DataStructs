// David Díaz Paz y Puente | 650794 | Estructuras de Datos
// Doy mi palabra que he realizado esta actividad con integridad académica.

#include "NodeT.h"
template <class T> class LinkedListT; 
template <class T> class LinkedListTGP; 
template <class T>
class NodeVT
{
    friend class LinkedListT<T>; 
    friend class LinkedListTGP<T>; 
    private: 
        T dato;
        bool processed = false; 
        NodeVT<T> *next;
        NodeT<T> *adj; 
    public: 
        NodeVT<T>(T datoParam)
        { 
            dato = datoParam; 
            next = nullptr; 
            adj = nullptr;
        } 
};