#include "listaLigada.h"
#include "generador.h"
#include "producto.h"
#include <iostream>
#include <chrono>

#define productos "nombres.txt"
#define precioMinimo 2000
#define precioMaximo 520000

bool cargarGenerador(Generador &generador){
    return generador.leerArchivo(productos);

}

int main(){
    std::chrono::year_month_day hola;
    ListaLigada listica;
    Generador generador;
    if(cargarGenerador(generador)){
        cout << generador.obtenerAlteatorio();
    }
    else{
        cout << "No se pudieron cargar los archivos necesarios para ejecutar el programa, lo sentimos.";
    }
    return 0;
}