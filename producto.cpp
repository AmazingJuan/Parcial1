#include "producto.h"
#include <iostream>

Producto::Producto(const string &nombre, unsigned int codigo, unsigned int stock, unsigned int precio, const string &fecha)
{
    this-> nombre = nombre;
    this -> codigo = codigo;
    this -> stock = stock;
    this -> precio = precio;
    fechaAbastecimiento = fecha;

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
        case 4: //precio
            return producto1.precio > producto2.precio;
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
        case 4: //precio
            return producto1.precio < producto2.precio;
        default:
            return false;
    }
}

bool esIgual(unsigned short criterio, const Producto &producto1, const Producto &producto2)
{
    return !esMayor(criterio, producto1, producto2) && !esMenor(criterio, producto1, producto2);
}

std::ostream &operator<<(std::ostream &os, const Producto &producto)
{
    os << "Nombre: " << producto.nombre << '\n' << "Codigo: " << producto.codigo \
       << '\n' << "Precio: " << producto.precio << '\n' <<  "Stock: " << producto.stock \
       << '\n' << "Fecha de ultimo abastecimiento: " << producto.fechaAbastecimiento << "\n\n" ;
    return os;
}
