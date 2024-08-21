#ifndef VALIDACION_H
#define VALIDACION_H

#include "importaciones.h"

bool validarOpcion(string entrada, string (&opciones)[8], int lenOpciones);
bool stringInArray(string cadena, string (&arreglo)[8], int lenArreglo);
#endif // VALIDACION_H
