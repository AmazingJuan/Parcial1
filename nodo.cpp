#include "nodo.h"
// Constructor de la clase nodo 
Nodo::Nodo(const Producto& data) : dato(data){
    this-> siguiente = nullptr;
}
// Setters & Getters 

const Producto &Nodo::getdato() const {
    return dato;
}
void Nodo::setdato(const Producto &dato) {
    Nodo::dato = dato;
}
Nodo* Nodo::getsiguiente() const {
    return siguiente;
}
void Nodo::setsiguiente(Nodo *siguiente) {
    Nodo::siguiente = siguiente;
}
