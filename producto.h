#ifndef PRODUCTO_H
#define PRODUCTO_H
#include "importaciones.h"

class Producto{
    private:
        string nombre;
        string fechaAbastecimiento;
        string nombreComparable;
        unsigned int codigo, stock, precio;

    public:
        Producto(const string &nombre, unsigned int codigo, unsigned int stock, unsigned int precio, const string &fecha);

        string getNombre() const;
        unsigned int getCodigo() const;
        unsigned int getStock() const;
        unsigned int getPrecio() const;

        friend bool esMayor(unsigned short criterio, const Producto &producto1, const Producto &producto2);
        friend bool esIgual(unsigned short criterio, const Producto &producto1, const Producto &producto2);
        friend bool esMenor(unsigned short criterio, const Producto &producto1, const Producto &producto2);

        friend std::ostream& operator<<(std::ostream& os, const Producto& producto);
    //CODIGO DE PRODUCTO, NOMBRE, STOCK, PRECIO, ULTIMA FECHA DE REPOSICION  
};
#endif //PRODUCTO_H
