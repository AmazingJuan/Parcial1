#include "ordenamiento.h"
#include "listaLigada.h"

Nodo* obtenerUltimo(Nodo* cabeza) {
    while (cabeza != nullptr && cabeza->getSiguiente() != nullptr) {
        cabeza = cabeza->getSiguiente();
    }
    return cabeza; // Retornar el último nodo de la lista.
}



//FUNCIONES UTILES PARA EL BUBBLESORT


void intercambiar(Nodo *nodo1, Nodo *nodo2)
{
    Producto copia = nodo1->getDato(); //Realiza una copia del dato del nodo1 y lo intercambia con el nodo 2
    nodo1->setDato(nodo2->getDato());
    nodo2->setDato(copia);
}

//FUNCIONES UTILES PARA EL MERGESORT

Nodo* dividirMitad(Nodo* cabeza) { //DIVIDE LA LISTA EN DOS MITADES. 
    if (cabeza == nullptr || cabeza->getSiguiente() == nullptr) {
        return nullptr; //Si la lista esta vacia o solo tiene un nodo se devuelve un puntero nulo.
        //El return de esta funcion representa la referencia a la segunda mitad de la lista.
    }

    Nodo* lento = cabeza; //Se define el nodo lento, es decir el que avanzará uno por uno.
    Nodo* rapido = cabeza->getSiguiente(); //Se define el nodo rapido, el que se desplazará de dos en dos.

    while (rapido != nullptr && rapido->getSiguiente() != nullptr) {//El while evalua si el puntero rapido llegó al final, o esta proximo a llegar al final.
        
        lento = lento->getSiguiente(); //El puntero lento avanza uno por uno
        rapido = rapido->getSiguiente()->getSiguiente(); //El puntero rapido avanza cada dos.
    }

    Nodo* segundaMitad = lento->getSiguiente(); //Al finalizar el ciclo while la segunda mitad empezará un nodo después del puntero lento.
    lento->setSiguiente(nullptr); //Se desvinculan las listas, permitiendo así que el puntero lento sea el ultimo elemento de la primera mitdad.
    return segundaMitad; //Se devuelve el puntero a la segunda mitad.
}

Nodo* fusionarListas(unsigned short criterio, Nodo* lista1, Nodo* lista2) {
    Nodo* cabezaFusionada = nullptr; //Puntero que indica cual es el inicio de la lista fusionada
    Nodo* ultimoFusionado = nullptr; //Puntero que indica cual es la cola de la lista fusionada

    while (lista1 != nullptr && lista2 != nullptr) { //Mientras las listas no esten vacias.
        Nodo* menor;
        //En el siguiente bloque se asigna al puntero menor el nodo de las listas que sea menor.
        //Si la lista1 contiene el nodo menor, entonces el menor será el puntero actual de la lista 1, y se avanzará al siguiente para seguirlo
        // comparando con los elemtnos de la lista 2, y viceversa.
        if (esMenor(criterio, lista1->getDato(), lista2->getDato())) {
            menor = lista1;
            lista1 = lista1->getSiguiente();
        } else {
            menor = lista2;
            lista2 = lista2->getSiguiente();
        }

        //El bloque siguiente se encarga de los casos donde la cabeza de la lista fusionada es nula.
        if (cabezaFusionada == nullptr) {
            cabezaFusionada = menor; //Si es nula, la cabeza va a ser el primer dato menor que encuentre.
            ultimoFusionado = cabezaFusionada; //Así la cola de la lista también sera el menor dato.
        } else {
            ultimoFusionado-> setSiguiente(menor); //Sino, entonces se añade el menor a la cola
            ultimoFusionado = menor; //Ahora el menor es la cola de la lista.
        }
    }


    //Bloques condicionales que se activan si alguna de las dos listas, despues de realizar las comparaciones queda con elementos.
    if (lista1 != nullptr) {
        if (ultimoFusionado != nullptr) { //Si la lista no es vacia, es decir tiene un nodo en su cola, entonces se le añade los elementos restantes en la lista1.
            ultimoFusionado->setSiguiente(lista1);
        } 
        //Si la lista combinada no tiene elementos, esto es, la cola es vacia, entonces la cabeza serán los elementos restantes de la lista1
        else {
            cabezaFusionada = lista1;
        }
        //Se aplica la misma logica para la lista2
    } else if (lista2 != nullptr) {
        if (ultimoFusionado != nullptr) {
            ultimoFusionado->setSiguiente(lista2);
        } else {
            cabezaFusionada = lista2;
        }
    }

    return cabezaFusionada; //Finalmente se retorna la referencia a la cabeza de la lista fusionada.
}


Nodo* mergeSortRec(unsigned short criterio, Nodo* cabeza) { //Parte recursiva del mergesort.
    //Se solicita el criterio de comparacion y la cabeza de la lista


    //Si se da el caso que la lista que se esté comparando sea vacia o tenga un solo elemento se retorna la cabeza de tal lista.
    if (cabeza == nullptr || cabeza->getSiguiente() == nullptr) {
        return cabeza;
    }

    //Se aplica acá la logica del mergesort
    //Se divide la lista en 2, se ordenan las dos mitades por separado
    //Y finalmente se unen las listas.
    Nodo* segundaMitad = dividirMitad(cabeza); 
    Nodo* izquierda = mergeSortRec(criterio, cabeza);
    Nodo* derecha = mergeSortRec(criterio, segundaMitad);

    return fusionarListas(criterio, izquierda, derecha); //Direccion de memoria de la cabeza de la lista ordenada.
}

//FUNCIONES UTILES PARA EL QUICKSORT

Nodo* dividirPivote(unsigned short criterio, Nodo* bajo, Nodo* alto, Nodo** nuevoBajo, Nodo** nuevoAlto) {
    //Si se da alguna de las condiciones se concluye que la lista es trivial, esto es, esta vacia o tiene un solo elemento.
    if (bajo == nullptr || bajo == alto || alto == nullptr) {
        *nuevoBajo = bajo;
        *nuevoAlto = alto;
        return nullptr; //Se devuelve un puntero nulo ya que el pivote en los casos mencionados siempre es nullptr
    }

    Nodo* pivote = alto;
    Nodo* previo = nullptr;
    Nodo* actual = bajo;
    Nodo* cola = pivote;

    while (actual != pivote) { //Se recorre la lista hasta llegar al pivote, esto es hasta llegar al final
        if (esMenor(criterio, actual->getDato(), pivote->getDato())) { //Se realizan comparaciones
            if (*nuevoBajo == nullptr) {
                *nuevoBajo = actual; //se da que el producto actual es menor al pivote, entonces será la cabeza de la nueva partición.
            }
            previo = actual; //La referencia al dato inmediatamente menor se actualiza, siendo el nodo actual tal dato.
            actual = actual->getSiguiente(); //Posteriormente el dato actual cambia al nodo siguiente al previo.
        } else {
            if (previo != nullptr) { 
//Si hasta ahora hubo datos menores al pivote entonces se cambia el enlace al nodo siguiente del nodo previo, esto es, se desvincula el nodo actual de la lista ligada.
                previo->setSiguiente(actual->getSiguiente());
            }
            Nodo* temp = actual->getSiguiente(); //Se obtiene el nodo siguiente al actual.
            //Los pasos siguientes sirven para llevar el nodo actual, que es mayor que el pivote, hacia la cola de la lista. 
            actual->setSiguiente(nullptr);
            cola->setSiguiente(actual);
            cola = actual;
            actual = temp;
        }
    }

    if (*nuevoBajo == nullptr) { //Si no hubieron datos menores que el pivote, entonces el nuevo bajo es el pivote.
        *nuevoBajo = pivote;
    }
    *nuevoAlto = cola; //El nuevo alto será la cola de la lista actual.
    return pivote; //Se retorna el nodo donde se encuentra el pivote de la lista reordenada.
}

Nodo* recursivoQuick(unsigned short criterio, Nodo* bajo, Nodo* alto) {
    //Si se da alguna de las condiciones se concluye que la lista es trivial, esto es, esta vacia o tiene un solo elemento.
    if (bajo == nullptr || bajo == alto) {
        return bajo;
    }

    Nodo* nuevoBajo = nullptr;
    Nodo* nuevoAlto = nullptr;

    Nodo* pivote = dividirPivote(criterio, bajo, alto, &nuevoBajo, &nuevoAlto);

    if (nuevoBajo != pivote) { //Si hubieron elementos menores que el pivote se ejecuta el siguiente bloque.
        //Se encuentra el nodo anterior al pivote.
        Nodo* temp = nuevoBajo;
        while (temp->getSiguiente() != pivote) {
            temp = temp->getSiguiente();
        }
        //Se divide la lista en dos, como el pivote ya quedo en su posicion fija, entonces se ordenan
        // las listas que resultan de dividir antes del pivote y despues del pivote.
        temp->setSiguiente(nullptr);

        //Se ordena la lista anterior al pivote.
        nuevoBajo= recursivoQuick(criterio, nuevoBajo, temp);
        //Se enlaza la lista ordenada antes del pivote con el pivote.
        temp = obtenerUltimo(nuevoBajo);
        temp->setSiguiente(pivote);
    }
    //Se hace el mismo proceso para la lista después del pivote, en este caso se enlaza
    // la lista ordenada de la izquierda, con el pivote y posteriormente la lista ordenada de la derecha.
    pivote->setSiguiente(recursivoQuick(criterio, pivote->getSiguiente(), nuevoAlto));

    return nuevoBajo; //Se devuelve la cabeza de la nueva lista ordenada.
}

//METODOS DE ORDENAMIENTO APLICABLES A UNA LISTA COMPLETA.

void bubbleSort(unsigned short criterio, ListaLigada &lista){
    bool intercambio;
    Nodo *actual;
    if(lista.getSize() == 0) { //Si la lista es vacia no se hace nada.
        return;
    }
    else{
        intercambio = true;

        while(intercambio){//Se hacen pasadas constantes por la lista en busca de elementos los cual intercambiar
            intercambio = false; //Se establece la variable intercambio como false ya que no se ha hecho ningun intercambio hasta ahora
            actual = lista.getCabeza(); //Se obtieene la cabeza

            while(actual->getSiguiente() !=  nullptr){
                //Sse dan pasadas sobre la lista buscando intercambios.
                if(esMayor(criterio, actual -> getDato(), actual->getSiguiente() -> getDato())){
                    intercambio = true; //Se actualiza la variable dado que hubo un intercambio.
                    intercambiar(actual, actual ->getSiguiente());
                }
                actual = actual->getSiguiente(); //Se continua recorriendo la lista.
            }
        }
    }
}

void mergeSort(unsigned short criterio, ListaLigada &lista)
{
    lista.setCabeza(mergeSortRec(criterio, lista.getCabeza()));
}


void quickSort(unsigned short criterio, ListaLigada &lista)
{
    lista.setCabeza(recursivoQuick(criterio, lista.getCabeza(), lista.getCola()));
}
