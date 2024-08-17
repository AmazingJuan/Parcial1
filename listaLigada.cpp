#include "listaLigada.h"

ListaLigada::ListaLigada(){
    cabeza = nullptr;
    size = 0;
}
ListaLigada::~ListaLigada(){
    
}

void ListaLigada::add(const Producto &dato){
    if(cabeza == nullptr) cabeza = new Nodo(dato);
    else{
        Nodo *aux = cabeza;
        while(aux->getsiguiente() != nullptr) aux = aux->getsiguiente();
        aux->setsiguiente(new Nodo(dato));
    }
    size += 1;
}

