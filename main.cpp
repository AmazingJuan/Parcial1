#include "listaLigada.h"
#include "generador.h"
#include "producto.h"
#include "ordenamiento.h"
#include "importaciones.h"
#include "menus.h"
#include "utilidades.h"

#define productos "nombres.txt"
#define msgCriterio 1
#define msgOrdenar 2
#define msgResultado 3
#define precioMinimo 2000
#define precioMaximo 50000
#define fechaMinima 2022
#define fechaMaxima 2024


bool cargarGenerador(Generador &generador){
    return generador.leerArchivo(productos);
}

template <typename Func, typename... Args>
double medirTiempo(Func funcionOrdenamiento, Args&&... args) {
    auto inicio = std::chrono::high_resolution_clock::now();
    
    funcionOrdenamiento(std::forward<Args>(args)...);
    
    auto fin = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duracion = fin - inicio;
    return duracion.count();
}

int main(){
    bool bandera = true;
    string resultado = "";
    unsigned short numCriterio = 0;
    ListaLigada lista;
    unordered_set<unsigned int> codigos;
    unsigned int codigoAux;
    Generador generador;
    string opciones[7] = {"1", "2", "3", "4", "5", "6", "7"};
    unsigned int opcion;

    if(cargarGenerador(generador)){
        for(unsigned int cont = 0; cont < 50; cont++){
            do{
                codigoAux = generador.generarInt(1000000, 9000000);
            }
            while(codigos.find(codigoAux) != codigos.end());
            codigos.insert(codigoAux);
            lista.add(Producto(generador.obtenerAlteatorio(), codigoAux, generador.generarInt(0,500), generador.generarInt(precioMinimo, precioMaximo), generador.fechaAleatoria(fechaMinima, fechaMaxima)));
        }
        while(bandera){
            if(numCriterio == 0){
                numCriterio = menuOpcion(mensajes(msgCriterio), opciones, 6);
                if(numCriterio == 5) bandera = false;
            }
            else{
                opcion = menuOpcion(mensajes(msgOrdenar), opciones, 7);
                if(opcion == 7) bandera = false;
                else{
                    switch(opcion){
                        case 1: 
                            resultado = addResultado(resultado, numCriterio, "Bubblesort", medirTiempo(bubbleSort, numCriterio, lista));
                            lista.setCola(obtenerUltimo(lista.getCabeza()));
                            break;
                        case 2: 
                            resultado = addResultado(resultado, numCriterio, "Mergesort", medirTiempo(mergeSort, numCriterio, lista));
                            lista.setCola(obtenerUltimo(lista.getCabeza()));
                            break;
                        case 3: 
                            resultado = addResultado(resultado, numCriterio, "Quicksort", medirTiempo(quickSort, numCriterio, lista));
                            lista.setCola(obtenerUltimo(lista.getCabeza()));
                            break;
                        case 4:
                            if(resultado != "") menuOpcion(mensajes(msgResultado) + resultado + "1. Seleccione esta opción si termino de visualizar los resultados\n\n", opciones, 1);
                            break;
                        case 5: 
                            resultado = "";
                            break;
                        case 6: 
                            numCriterio = 0;
                            break;
                        default:
                            break;
                    }
                }
            }
        }
    }
    else{
        cout << "No se pudieron cargar los archivos necesarios para ejecutar el programa, lo sentimos.";
    }
    lista.imprimir();
    return 0;
}
