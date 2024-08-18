#include "listaLigada.h"
#include "generador.h"
#include "producto.h"
#include "ordenamiento.h"
#include <iostream>
#include <chrono>

#define productos "nombres.txt"
#define precioMinimo 2000
#define precioMaximo 520000

bool cargarGenerador(Generador &generador){
    return generador.leerArchivo(productos);

}

int main(){
    ListaLigada listica;
    Generador generador;
    if(cargarGenerador(generador)){
        for(unsigned int cont = 0; cont < 10; cont++){
            listica.add(Producto(generador.obtenerAlteatorio(), generador.generarInt(1000000, 9000000), 5, 5));
        }
        cout << "Registros creados" << endl;
        cout << "EMPEZANDO";
        mergeSort(1, listica);
        cout << endl << endl << endl;
        listica.imprimir();
    }
    else{
        cout << "No se pudieron cargar los archivos necesarios para ejecutar el programa, lo sentimos.";
    }
    return 0;
}