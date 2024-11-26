// David Díaz Paz y Puente | 650794 | Estructuras de Datos
// Doy mi palabra que he realizado esta actividad con integridad académica.

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
        int distanciaTren; 
        int distanciaCarro; 
        int tiempoTren; 
        int tiempoCarro; 
        NodeT<T> *next;
        bool processed = false; 
    public: 
        NodeT<T>(T datoParam, int pondTiempoTren, int pondDistTren, int pondTiempoCarro, int pondDistCarro)
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