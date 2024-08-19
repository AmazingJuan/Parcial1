#include "listaLigada.h"
#include "producto.h"

void intercambiar(Nodo *nodo1, Nodo *nodo2);

Nodo* mergeSortRec(Nodo* cabeza);
Nodo* fusionarListas(Nodo* lista1, Nodo* lista2);
Nodo* dividirLista(Nodo* cabeza);


Nodo* obtenerUltimo(Nodo* cabeza);
Nodo* dividir(unsigned short criterio, Nodo* bajo, Nodo* alto, Nodo** nuevoBajo, Nodo** nuevoAlto);
Nodo* recursivoQuick(unsigned short criterio, Nodo* bajo, Nodo* alto);


void bubbleSort(unsigned short criterio, ListaLigada &lista);
void mergeSort(unsigned short criterio, ListaLigada &lista);
void quickSort(unsigned short criterio, ListaLigada &lista);



