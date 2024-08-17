#ifndef PRODUCTO_H
#define PRODUCTO_H
#include <string>
#include <chrono>
using namespace std;

class Producto{
    private:
        string nombre;
        string nombreComparable;
        unsigned int codigo, stock, precio;
        //Metodos de comparación según el criterio

        //STOCK
        friend bool mayorStock(const Producto &producto1, const Producto &producto2);
        friend bool menorStock(const Producto &producto1, const Producto &producto2);
        friend bool igualStock(const Producto &producto1, const Producto &producto2);

        //NOMBRE
        friend bool mayorNombre(const Producto &producto1, const Producto &producto2);
        friend bool menorNombre(const Producto &producto1, const Producto &producto2);
        friend bool igualNombre(const Producto &producto1, const Producto &producto2);


    public:
        Producto(const string &nombre, unsigned int codigo, unsigned int stock, unsigned int precio);
        bool esMayor(unsigned short criterio, const Producto &producto1, const Producto &producto2);
        bool esIgual(unsigned short criterio, const Producto &producto1, const Producto &producto2);
        bool esMenor(unsigned short criterio, const Producto &producto1, const Producto &producto2);

        
    //CODIGO DE PRODUCTO, NOMBRE, STOCK, PRECIO, ULTIMA FECHA DE REPOSICION  
};
#endif //PRODUCTO_H