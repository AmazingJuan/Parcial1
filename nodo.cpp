#include "nodo.h"
// Constructor de la clase nodo 
Nodo::Nodo(const Producto& data) : dato(data){
    this-> siguiente = nullptr;
}
// Setters & Getters 

const Producto &Nodo::getDato() const {
    return dato;
}
void Nodo::setDato(const Producto &dato) {
    Nodo::dato = dato;
}
Nodo* Nodo::getSiguiente() const {
    return siguiente;
}
void Nodo::setSiguiente(Nodo *siguiente) {
    Nodo::siguiente = siguiente;
}
