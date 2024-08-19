#include "utilidades.h"

void limpiarPantalla(){
    for(int cont = 0; cont < 50; cont++) cout << "\n";
}

string addResultado(string resulActual, unsigned short criterio, string nombreMetodo, double tiempo)
{
    string criterioString;
    switch(criterio){
        case 1:
            criterioString = "nombre";
            break;
        case 2:
            criterioString = "stock";
            break;
        case 3:
            criterioString = "codigo";
            break;
        case 4:
            criterioString = "precio";
            break;
        default:
            criterioString = "";
            break;
    }


    resulActual.append("Ordenamiento usando criterio de " + criterioString + "\nTiempo de realizacion: " + to_string(tiempo) + "\nMetodo de ordenamiento: " + nombreMetodo + ".\n\n");
    return resulActual;
}

string mensajes(int parametro)
{
    switch(parametro){
        case 1: //MENSAJE CRITERIO
            return "Bienvenido al almacen KOSTKO, elija el criterio con el cual va a ordenar los productos (250000)\n\n1. Orden alfabetico (ocurrencia en el diccionario)\n2. Cantidad de stock\n3. Codigo\n4. Precio \n5. Salir del programa\n\n";
        case 2:
            return "Ahora usted debe seleccionar el algoritmo de ordenamiento con el cual ordenara la lista de productos\n\n1. Bubblesort (muy ineficiente en listas largas)\n2. Mergesort (complejidad nlogn)\n3. Quicksort (complejidad nlogn)\n4. Mostrar resultados de ordenamiento\n5. Borrar resultados de ordenamiento\n6. Cambiar criterio de comparacion\n7. Salir del programa\n\n";
        case 3:
            return "He aquí los resultados de los ordenamientos que ha realizado\n\n";
        default: return "";
    }
}
