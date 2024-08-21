#include "listaLigada.h"
#include "generador.h"
#include "producto.h"
#include "ordenamiento.h"
#include "importaciones.h"
#include "menus.h"
#include "utilidades.h"


//SE DEFINEN MACROS PARA MEJORAR LA LEGIBILIDAD DEL CODIGO
#define productos "nombres.txt"
#define msgCriterio 1
#define msgOrdenar 2
#define msgResultado 3
#define precioMinimo 2000
#define precioMaximo 50000
#define fechaMinima 2022
#define fechaMaxima 2024
#define stockMaximo 900
#define stockMinimo 0


bool cargarGenerador(Generador &generador){
    return generador.leerArchivo(productos); //FUNCIÓN QUE PERMITE CARGAR EL NOMBRE DE LOS ARCHIVOS
}


//ACONDICIONAMIENTO DEL CODIGO MOSTRADO EN CLASE PARA MEDIR TIEMPO
template <typename Func, typename... Args> 
double medirTiempo(Func funcionOrdenamiento, Args&&... args) { //SE INCLUYE LOS ARGUMENTOS DE LA FUNCION DE ORDENAMIENTO YA QUE ERAN 2 EN VEZ DE 1
    auto inicio = std::chrono::high_resolution_clock::now(); //TOMA EL TIEMPO ANTES DE EJECUTAR LA FUNCION DE ORDENAMIENTO
    
    funcionOrdenamiento(std::forward<Args>(args)...); //SE INVOCA LA FUNCION DE ORDENAMIENTO
    
    auto fin = std::chrono::high_resolution_clock::now(); //TOMA EL TIEMPO DESPUES DE EJECUTAR LA FUNCION DE ORDENAMIENTO
    std::chrono::duration<double> duracion = fin - inicio; //CALCULA EL LAPSO DE TIEMPO ENTRE EL FIN Y EL INICIO.
    return duracion.count();
}

int main(){
    bool bandera = true; //BANDERA DE CONTROL PARA CONTROLAR EL INICIO Y FIN DEL PROGRAMA
    string resultado = ""; //STRING QUE ALMACENARÁ EL RESULTADO QUE SE MUESTRE AL USUARIO
    unsigned short numCriterio = 0; //NUMERO DE CRITERIO ELEGIDO POR EL USUARIO
    ListaLigada lista; //INSTANCIA DE LA LISTA LIGADA
    unordered_set<unsigned int> codigos; //CODIGOS DE PRODUCTO INGRESADOS HASTA EL MOMENTO
    unsigned int codigoAux; //Variable que almacena el codigo generado por el generador.
    Generador generador; //Generador para generar enteros y nombres aleatorios de un alista.
    string opciones[8] = {"1", "2", "3", "4", "5", "6", "7", "8"}; //Conglomerado total de opciones que puede elegir el usuario
    unsigned int opcion; //Opcion que haya elegido el usuario

    if(cargarGenerador(generador)){ //Si cargar los datos fue exitoso ocurre el bloque if
        for(unsigned int cont = 0; cont < 250000; cont++){
            //El bloque do-while pretende generar codigos hasta que se logre obtener un codigo que no este contenido en la lista de codigos.
            do{
                codigoAux = generador.generarInt(1000000, 9000000);
            }
            while(codigos.find(codigoAux) != codigos.end());
            codigos.insert(codigoAux); //Si se logra salir del while se inserta el codigo generado y se crea el producto.
            lista.add(Producto(generador.obtenerAlteatorio(), codigoAux, generador.generarInt(stockMinimo, stockMaximo), generador.generarInt(precioMinimo, precioMaximo), generador.fechaAleatoria(fechaMinima, fechaMaxima)));
        }
        //Después de la generación de registros se inicia un bucle infinito que integrará los menus y las opciones de usuario
        while(bandera){
            if(numCriterio == 0){ //Si el usuario no ha escogido un criterio lo pone a escoger
                numCriterio = menuOpcion(mensajes(msgCriterio), opciones, 6); //Se usa la funcion menuOpcion y se obtiene un mensaje para el usuario de la funcion mensajes.
                if(numCriterio == 5) bandera = false; //La opcion 5 en este menu es para salir del programa, entonces desactiva la bandera.
            }
            else{
                opcion = menuOpcion(mensajes(msgOrdenar), opciones, 8); //Muestra las opciones que tiene el usuario después de haber elegido un criterio de comapración.
                if(opcion == 8) bandera = false; //Opcion que termina la ejecución del programa.
                else{
                    switch(opcion){
                        case 1: //Opcion 1, ordena la listas con bubblesort con el criterio indicado.
                            resultado = addResultado(resultado, numCriterio, "Bubblesort", medirTiempo(bubbleSort, numCriterio, lista));
                            lista.setCola(obtenerUltimo(lista.getCabeza()));
                            break;
                        case 2: //Opcion 1, ordena la listas con mergesort con el criterio indicado.
                            resultado = addResultado(resultado, numCriterio, "Mergesort", medirTiempo(mergeSort, numCriterio, lista));
                            lista.setCola(obtenerUltimo(lista.getCabeza()));
                            break;
                        case 3: //Opcion 1, ordena la listas con quicksort con el criterio indicado.
                            resultado = addResultado(resultado, numCriterio, "Quicksort", medirTiempo(quickSort, numCriterio, lista));
                            lista.setCola(obtenerUltimo(lista.getCabeza()));
                            break;
                        case 4: //Muestra los resultados obtenidos de el ordenamiento de las listas
                            if(resultado != "") menuOpcion(mensajes(msgResultado) + resultado + "1. Seleccione esta opción si termino de visualizar los resultados\n\n", opciones, 1);
                            break;
                        case 5: //Borra los resultados obtenidos hasta ahora
                            resultado = ""; //Borra el string que contiene los resultados
                            break;
                        case 6: //Opcion para cambiar el criterio de comparación
                            numCriterio = 0; //Hace numCriterio = 0 para poder activar el condicional que permite elegir criterio
                            break;
                        case 7: //Permite imprimir 10 elementos de la lista para evidenciar de alguna forma el ordenamiento
                            lista.imprimir(10); //Se imprimen 10 elementos
                            menuOpcion("1. Seleccione esta opción si termino de visualizar la lista\n\n", opciones, 1);
                            break;
                        default:
                            break;
                    }
                }
            }
        }
    }
    else{ //Se le indica al usuario que no se pudo cargar los archivos necesarios para correr el programa, por lo cual no puede hacer nada mas.
        cout << "No se pudieron cargar los archivos necesarios para ejecutar el programa, lo sentimos.";
    }
    return 0;
}
