#include "producto.h"
#include <iostream>

Producto::Producto(const string &nombre, unsigned int codigo, unsigned int stock, unsigned int precio)
{
    this-> nombre = nombre;
    this -> codigo = codigo;
    this -> stock = stock;
    this -> precio = precio;

    nombreComparable = "";
    for(auto it = nombre.begin(); it != nombre.end(); ++it){
        if(*it != ' '){
            char aux = tolower(*it);
            nombreComparable += aux;
        }
    }
}

string Producto::getNombre() const
{
    return nombre;
}

unsigned int Producto::getCodigo() const
{
    return codigo;
}

unsigned int Producto::getStock() const
{
    return stock;
}

unsigned int Producto::getPrecio() const
{
    return precio;
}

bool esMayor(unsigned short criterio, const Producto &producto1, const Producto &producto2)
{
    switch(criterio){
        case 1: //nombre
            return producto1.nombreComparable > producto2.nombreComparable;
        case 2: // stock
            return producto1.stock > producto2.stock;
        case 3: // Codigo
            return producto1.codigo > producto2.codigo;
        case 4:
            return false;
        default:
            return false;
    }
}

bool esMenor(unsigned short criterio, const Producto &producto1, const Producto &producto2)
{
    switch(criterio){
        case 1: //nombre
            return producto1.nombreComparable < producto2.nombreComparable;
        case 2: // stock
            return producto1.stock < producto2.stock;
        case 3: // Codigo
            return producto1.codigo < producto2.codigo;
        case 4:
            return false;
        default:
            return false;
    }
}

bool esIgual(unsigned short criterio, const Producto &producto1, const Producto &producto2)
{
    switch(criterio){
        case 1: //nombre
            return producto1.nombreComparable == producto2.nombreComparable;
        case 2:
            return producto1.stock == producto2.stock;
        case 3:
            return false;
        default:
            return false;
    }
}

std::ostream &operator<<(std::ostream &os, const Producto &producto)
{
    os << "Nombre: " << producto.getNombre() << '\n' << "Codigo: " << producto.getCodigo() \
    << '\n' << "Stock: " << producto.getStock() << '\n';
    return os;
}
