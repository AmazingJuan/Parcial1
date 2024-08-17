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

