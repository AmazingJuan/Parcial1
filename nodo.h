#ifndef NODO_H
#define NODO_H
#include "producto.h"
class Nodo {
    private://<>
        Nodo *siguiente;
        Producto dato;
    public: 
        Nodo(const Producto &producto);
        const Producto &getdato() const;
        void setdato(const Producto &dato);
        Nodo* getsiguiente() const;
        void setsiguiente(Nodo* siguiente);
};
#endif