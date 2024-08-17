#include "generador.h"

Generador::Generador(){
    srand(static_cast<int>(std::time(0)));
}

bool Generador::leerArchivo(const string &nombreArchivo)
{
    ifstream archivo(nombreArchivo);
    if(archivo.is_open()){
        string textoAux;
        while(getline(archivo,textoAux)) items.push_back(textoAux);
        archivo.close();
        return true;
    }
    else{
        return false;
    }
}

const string &Generador::obtenerAlteatorio() const
{
    return items[rand() % items.size()];
}

int Generador::generarInt(int limiteInferior, int limiteSuperior)
{
    return limiteInferior + rand() % limiteSuperior;
}
