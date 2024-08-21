#ifndef NODO_H
#define NODO_H
#include "producto.h"
class Nodo {
    private://<>
        Nodo *siguiente;
        Producto dato;
    public: 
        Nodo(const Producto &producto);
        const Producto &getDato() const;
        void setDato(const Producto &dato);
        Nodo* getSiguiente() const;
        void setSiguiente(Nodo* siguiente);
};
#endif