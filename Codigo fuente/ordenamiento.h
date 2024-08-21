#include "listaLigada.h"
#include "producto.h"

Nodo* obtenerUltimo(Nodo* cabeza);

//ELEMENTOS IMPORTANTES PARA BUBBLESORT
void intercambiar(Nodo *nodo1, Nodo *nodo2);

//ELEMENTOS IMPORTANTES PARA MERGESORT
Nodo* mergeSortRec(unsigned short criterio, Nodo* cabeza);
Nodo* fusionarListas(unsigned short criterio, Nodo* lista1, Nodo* lista2);
Nodo* dividirMitad(Nodo* cabeza);

//ELEMENTOS IMPORTANTES PARA QUICKSORT
Nodo* dividirPivote(unsigned short criterio, Nodo* bajo, Nodo* alto, Nodo** nuevoBajo, Nodo** nuevoAlto);
Nodo* recursivoQuick(unsigned short criterio, Nodo* bajo, Nodo* alto);

//METODOS DE ORDENAMIENTO.
void bubbleSort(unsigned short criterio, ListaLigada &lista);
void mergeSort(unsigned short criterio, ListaLigada &lista);
void quickSort(unsigned short criterio, ListaLigada &lista);



