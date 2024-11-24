#ifndef NodeT_H
#define NodeT_H

template <class T> class LinkedListTGP; 
template <class T> class QueueT; 
template <class T>
class NodeT
{
    friend class LinkedListTGP<T>; 
    friend class QueueT<T>; 
    private: 
        T dato;
        string distanciaTren; 
        string distanciaCarro; 
        string tiempoTren; 
        string tiempoCarro; 
        NodeT<T> *next;
        bool processed = false; 
    public: 
        NodeT<T>(T datoParam, string pondTiempoTren, string pondDistTren, string pondTiempoCarro, string pondDistCarro)
        { 
            dato = datoParam; 
            tiempoTren = pondTiempoTren;
            tiempoCarro = pondTiempoCarro;
            distanciaTren = pondDistTren; 
            distanciaCarro = pondDistCarro; 
            next = nullptr; 
        } 
        NodeT<T>(T datoParam)
        {
            dato = datoParam;
        }
};

#endif