#include "listaLigada.h"

ListaLigada::ListaLigada(){
    cabeza = nullptr;
    cola = nullptr;
    size = 0;
}
ListaLigada::~ListaLigada(){
    
}

void ListaLigada::add(const Producto &dato){
    if(cabeza == nullptr) {
        cabeza = new Nodo(dato);
        cola = cabeza;
    }
    else{
        cola->setSiguiente(new Nodo(dato));
        cola = cola->getSiguiente();
        /*while(aux->getsiguiente() != nullptr) aux = aux->getsiguiente();
        aux->setsiguiente(new Nodo(dato));
        */
    }
    size += 1;
}

unsigned int ListaLigada::getSize() const
{
    return size;
}

Nodo *ListaLigada::getCabeza() const
{
    return cabeza;
}

void ListaLigada::setCabeza(Nodo *cabeza)
{
    this->cabeza = cabeza;
}

void ListaLigada::imprimir() const
{
    Nodo *aux = cabeza;
    while(aux -> getSiguiente() != nullptr){
        Producto producAux = aux -> getDato();
        std::cout << producAux;
        aux = aux -> getSiguiente();
    }
}