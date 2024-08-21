#include "validacion.h"
//Funciones utiles para validar si una opcion que haya ingresado el usuario es válida o no.
bool validarOpcion(string entrada, string (&opciones)[8], int lenOpciones){
    if(entrada.size() == 0) return false;
    return stringInArray(entrada, opciones, lenOpciones); //Se llama a la funcion stringInArray.
}

bool stringInArray(string cadena, string (&arreglo)[8], int lenArreglo){
    for(int cont = 0; cont < lenArreglo; cont ++) if(cadena == arreglo[cont]) return true;
    return false;
}
