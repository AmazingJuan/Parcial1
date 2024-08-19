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

// Función para dividir la lista en dos mitades
Nodo* dividirLista(Nodo* cabeza) {
    if (!cabeza || !cabeza->getSiguiente()) {
        return nullptr;
    }

    Nodo* lento = cabeza;
    Nodo* rapido = cabeza->getSiguiente();

    while (rapido && rapido->getSiguiente()) {
        lento = lento->getSiguiente();
        rapido = rapido->getSiguiente()->getSiguiente();
    }

    Nodo* segundaMitad = lento->getSiguiente();
    lento->setSiguiente(nullptr);
    return segundaMitad;
}

// Función para fusionar dos listas ordenadas
Nodo* fusionarListas(Nodo* lista1, Nodo* lista2) {
    Nodo* cabezaFusionada = nullptr;
    Nodo* ultimoFusionado = nullptr;

    while (lista1 && lista2) {
        Nodo* menor;
        if (esMenor(1, lista1->getDato(), lista2->getDato())) {
            menor = lista1;
            lista1 = lista1->getSiguiente();
        } else {
            menor = lista2;
            lista2 = lista2->getSiguiente();
        }

        if (!cabezaFusionada) {
            cabezaFusionada = menor;
            ultimoFusionado = cabezaFusionada;
        } else {
            ultimoFusionado->setSiguiente(menor);
            ultimoFusionado = ultimoFusionado->getSiguiente();
        }
    }

    if (lista1) {
        if (ultimoFusionado) {
            ultimoFusionado->setSiguiente(lista1);
        } else {
            cabezaFusionada = lista1;
        }
    } else if (lista2) {
        if (ultimoFusionado) {
            ultimoFusionado->setSiguiente(lista2);
        } else {
            cabezaFusionada = lista2;
        }
    }

    return cabezaFusionada;
}

// Función de mergeSort
Nodo* mergeSortRec(Nodo* cabeza) {
    if (!cabeza || !cabeza->getSiguiente()) {
        return cabeza;
    }

    Nodo* segundaMitad = dividirLista(cabeza);
    Nodo* lista1 = mergeSortRec(cabeza);
    Nodo* lista2 = mergeSortRec(segundaMitad);

    return fusionarListas(lista1, lista2);
}

Nodo* obtenerUltimo(Nodo* cabeza) {
    while (cabeza != nullptr && cabeza->getSiguiente() != nullptr) {
        cabeza = cabeza->getSiguiente();
    }
    return cabeza; // Retornar el último nodo
}


// Método auxiliar para dividir la lista en dos partes según el pivote
Nodo* dividir(unsigned short criterio, Nodo* bajo, Nodo* alto, Nodo** nuevoBajo, Nodo** nuevoAlto) {
    if (bajo == nullptr || bajo == alto || alto == nullptr) {
        *nuevoBajo = bajo;
        *nuevoAlto = alto;
        return nullptr;
    }

    Nodo* pivote = alto;
    Nodo* previo = nullptr;
    Nodo* actual = bajo;
    Nodo* cola = pivote;

    while (actual != pivote) {
        if (esMenor(criterio, actual->getDato(), pivote->getDato())) {
            if (!*nuevoBajo) {
                *nuevoBajo = actual;
            }
            previo = actual;
            actual = actual->getSiguiente();
        } else {
            if (previo != nullptr) {
                previo->setSiguiente(actual->getSiguiente());
            }
            Nodo* temp = actual->getSiguiente();
            actual->setSiguiente(nullptr);
            cola->setSiguiente(actual);
            cola = actual;
            actual = temp;
        }
    }

    if (*nuevoBajo == nullptr) {
        *nuevoBajo = pivote;
    }
    *nuevoAlto = cola;
    return pivote;
}

Nodo* recursivoQuick(unsigned short criterio, Nodo* bajo, Nodo* alto) {
    if (!bajo || bajo == alto) {
        return bajo;
    }

    Nodo* nuevoBajo = nullptr;
    Nodo* nuevoAlto = nullptr;

    Nodo* pivote = dividir(criterio, bajo, alto, &nuevoBajo, &nuevoAlto);

    if (nuevoBajo != pivote) {
        Nodo* temp = nuevoBajo;
        while (temp->getSiguiente() != pivote) {
            temp = temp->getSiguiente();
        }
        temp->setSiguiente(nullptr);

        nuevoBajo= recursivoQuick(criterio, nuevoBajo, temp);

        temp = obtenerUltimo(nuevoBajo);
        temp->setSiguiente(pivote);
    }
    pivote->setSiguiente(recursivoQuick(criterio, pivote->getSiguiente(), nuevoAlto));

    return nuevoBajo;
}


void quickSort(unsigned short criterio, ListaLigada &lista)
{
    lista.setCabeza(recursivoQuick(criterio, lista.getCabeza(), lista.getCola()));
}

void mergeSort(unsigned short criterio, ListaLigada &lista)
{
    lista.setCabeza(mergeSortRec(lista.getCabeza()));
}
