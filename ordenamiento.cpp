#include "ordenamiento.h"
#include "listaLigada.h"

void intercambiar(Nodo *nodo1, Nodo *nodo2)
{
    Producto copia = nodo1->getDato();
    nodo1->setDato(nodo2->getDato());
    nodo2->setDato(copia);
}

void bubbleSort(unsigned short criterio, ListaLigada &lista){
    bool intercambio;
    Nodo *actual;
    if(lista.getSize() == 0) {
        return;
    }
    else{
        intercambio = true;

        while(intercambio){
            intercambio = false;
            actual = lista.getCabeza();

            while(actual->getSiguiente() !=  nullptr){
                if(esMayor(criterio, actual -> getDato(), actual->getSiguiente() -> getDato())){
                    intercambio = true;
                    intercambiar(actual, actual ->getSiguiente());
                }
                actual = actual->getSiguiente();
            }
        }
    }
}

void mergeSort(unsigned short criterio, ListaLigada &lista){
    cout << "EMPEZANDO";
    Nodo *aux = recursiveMerge(criterio, lista.getCabeza());
    lista.setCabeza(aux);
}

Nodo* recursiveMerge(unsigned short criterio, Nodo *head)
{
    if(head == nullptr || head->getSiguiente() == nullptr){
        return head;
    }

    Nodo *mitad = head;
    Nodo *final = head;

    cout << "IM HIR";
    while(final -> getSiguiente() != nullptr || final -> getSiguiente() -> getSiguiente() != nullptr){
        final -> getSiguiente() -> getSiguiente() != nullptr;
        cout << "IM HIRI";
        mitad = mitad -> getSiguiente();
    }
    Nodo *segundaMitad = mitad -> getSiguiente();
    mitad -> setSiguiente(nullptr);

    Nodo *izquierda = recursiveMerge(criterio, head);
    Nodo *derecha = recursiveMerge(criterio, segundaMitad);

    return combinar(criterio, izquierda, derecha);
}

Nodo *combinar(unsigned short criterio, Nodo *izquierda, Nodo *derecha)
{
    if (izquierda == nullptr) return derecha;
    if (derecha == nullptr) return izquierda;

    if (esMenor(criterio, izquierda->getDato(),derecha->getDato())) {
        izquierda->setSiguiente(combinar(criterio, izquierda->getSiguiente(), derecha));
        izquierda->getSiguiente()->setSiguiente(nullptr);
        return izquierda;
    } else {
        derecha->setSiguiente(combinar(criterio, izquierda, derecha->getSiguiente()));
        derecha->getSiguiente()->setSiguiente(nullptr);
        return derecha;
    }
}
