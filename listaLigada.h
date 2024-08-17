#ifndef LISTALIGADA_H
#define LISTALIGADA_H
#include "nodo.h"

class ListaLigada{
    private:
        Nodo *cabeza;
        Nodo *cola;

    public:
        unsigned int size;
        ListaLigada();
        ~ListaLigada();
        void add(const Producto &dato);
};
#endif //LISTALIGADA_H