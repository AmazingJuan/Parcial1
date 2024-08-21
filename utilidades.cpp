#include "utilidades.h"

void limpiarPantalla(){
    for(int cont = 0; cont < 50; cont++) cout << "\n"; //Simplemente imprime 50 saltos de linea
}

string addResultado(string resulActual, unsigned short criterio, string nombreMetodo, double tiempo)
{
    string criterioString; //Se realiza un switch para definir la variable criterioString, dependiendo del numero de criterio ingresado.
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

    //Al resultado actual se le concatena un string indicando los detalles del ordenamiento.
    resulActual.append("Ordenamiento usando criterio de " + criterioString + "\nTiempo de realizacion: " + to_string(tiempo) + "\nMetodo de ordenamiento: " + nombreMetodo + ".\n\n");
    return resulActual;
}

string mensajes(int parametro)
{
    //Para cada tipo de parametro se devuelve un mensaje distinto, el significado de los mensajes se muestra al lado del caso.
    switch(parametro){
        case 1: //MENSAJE CRITERIO
            return "Bienvenido al almacen KOSTKO, elija el criterio con el cual va a ordenar los productos (250000)\n\n1. Orden alfabetico (ocurrencia en el diccionario)\n2. Cantidad de stock\n3. Codigo\n4. Precio \n5. Salir del programa\n\n";
        case 2: //MENSAJE ORDENAMIENTO
            return "Ahora usted debe seleccionar el algoritmo de ordenamiento con el cual ordenara la lista de productos\n\n1. Bubblesort (muy ineficiente en listas largas)\n2. Mergesort (complejidad nlogn)\n3. Quicksort (complejidad nlogn)\n4. Mostrar resultados de ordenamiento\n5. Borrar resultados de ordenamiento\n6. Cambiar criterio de comparacion\n7. Mostrar estado actual de la lista (imprime 10 o en su defecto toda la lista)\n8. Salir del programa.\n\n";
        case 3: //MENSAJE DE RESULTADOS DE ORDENAMIENTO
            return "He aquí los resultados de los ordenamientos que ha realizado\n\n";
        default: return "";
    }
}
