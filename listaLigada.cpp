#include "listaLigada.h"

ListaLigada::ListaLigada() : cabeza(nullptr), cola(nullptr), size(0){} //Se inicializa la lista con parametros vacios.

ListaLigada::~ListaLigada(){ //Permite liberar memoria que se aloja al a hora de crear los nodos de la lista.
    Nodo *aux = cabeza; //Se inicializa una variable auxiliar con el valor del puntero del a cabeza
    Nodo *temp; //Variable temporal que servirá para almacenar el valor siguiente de la variable auxiliar.
    while(aux != nullptr){
        temp = aux ->getSiguiente(); //Se asigna el nodo siguiente de la variable auxiliar.
        delete aux; //Se borra el nodo actual.
        aux = temp; //El nodo actual pasa a ser el nodo siguiente.
    }
    //Se dejan vacíos los parametros de la lista.
    cola = nullptr;
    cabeza = nullptr;
    size = 0;
}

void ListaLigada::add(const Producto &dato){ //Sirve para añadir un nuevo nodo a la lista, en este caso en la cola.
    if(cabeza == nullptr) { //Si la cabeza es vacía, entonces se inicializa la cabeza y la cola a la vez
        cabeza = new Nodo(dato);
        cola = cabeza;
    }
    else{ //Si la cabeza no es vacia se inserta el nuevo nodo después de la cola, y este nuevo nodo será la nueva cola.
        cola->setSiguiente(new Nodo(dato));
        cola = cola->getSiguiente();
    }
    size += 1; //Se incrementa el tamaño de la lista en uno.
}

unsigned int ListaLigada::getSize() const
{
    return size; 
}

Nodo *ListaLigada::getCabeza() const
{
    return cabeza;
}

Nodo *ListaLigada::getCola() const
{
    return cola;
}

void ListaLigada::setCabeza(Nodo *cabeza)
{
    this->cabeza = cabeza;
}

void ListaLigada::setCola(Nodo *cola)
{
    this -> cola = cola;
}


//Funcion que permite imprimir los elementos deseados de una lista.
void ListaLigada::imprimir(unsigned int elementosImprimir) const
{
    unsigned int modulo;  //Se define el modulo, que será cada cuantos nodos se va a imprimir uno de ellos.
    if(elementosImprimir > size) modulo = 1;
    else modulo = size / elementosImprimir;
    unsigned int cont = 0; //Contador auxiliar para contar los elementos de la lista.
    unsigned int imprimidos = 0; //Cuenta cuantos elementos de la lista se han impreso.
    Nodo *aux = cabeza; //Nodo auxiliar que comienza en la cabeza de la lista.

    while(aux != nullptr){
        if(cont % modulo == 0 && imprimidos < elementosImprimir){ //Si el contador es multiplo del modulo se imprime la descripcion del producto.
            Producto producAux = aux -> getDato();
            std::cout << producAux;
            imprimidos++;
        }
        cont++; //Aumenta el contador de datos.
        aux = aux -> getSiguiente(); //Se pasa al siguiente nodo.
    }
}
