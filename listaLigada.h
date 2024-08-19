#ifndef LISTALIGADA_H
#define LISTALIGADA_H
#include "nodo.h"
#include <iostream>


class ListaLigada{
    private:
        Nodo *cabeza;
        Nodo *cola;
        unsigned int size;
    public:
        ListaLigada();
        ~ListaLigada();
        void add(const Producto &dato);
        unsigned int getSize() const;
        Nodo* getCabeza() const;
        Nodo* getCola() const;
        void setCabeza(Nodo *cabeza);
        void setCola(Nodo *cola);
        void imprimir() const;
};
#endif //LISTALIGADA_H
