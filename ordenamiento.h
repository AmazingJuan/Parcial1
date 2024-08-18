#include "listaLigada.h"
void intercambiar(Nodo *nodo1, Nodo *nodo2);
void bubbleSort(unsigned short criterio, ListaLigada &lista);
void mergeSort(unsigned short criterio, ListaLigada &lista);
Nodo* recursiveMerge(unsigned short criterio, Nodo *head);
Nodo* combinar(unsigned short criterio, Nodo *izquierda, Nodo *derecha);