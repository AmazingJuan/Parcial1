#ifndef LISTALIGADA_H
#define LISTALIGADA_H
#include "nodo.h"

class ListaLigada{
    private:
        Nodo *cabeza;
        unsigned int size;
    public:
        ListaLigada();
        ~ListaLigada();
        void add(const Producto &dato);
};
#endif //LISTALIGADA_H