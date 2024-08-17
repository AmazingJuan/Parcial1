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


bool mayorStock(const Producto &producto1, const Producto &producto2)
{
    return producto1.stock > producto2.stock;
}

bool menorStock(const Producto &producto1, const Producto &producto2)
{
    return producto1.stock < producto2.stock;
}

bool igualStock(const Producto &producto1, const Producto &producto2)
{
    return producto1.stock == producto2.stock;
}

