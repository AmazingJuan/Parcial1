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

const string Generador::fechaAleatoria(unsigned short fechaInicial, unsigned short fechaFinal) const
{
    unsigned short diasEnMes[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int year = fechaInicial + std::rand() % (fechaFinal - fechaInicial + 1);
    int mes = 1 + std::rand() % 12;
    int dia = 1 + std::rand() % diasEnMes[mes - 1];

    std::stringstream ss;
    ss << std::setw(2) << std::setfill('0') << dia << "/"
       << std::setw(2) << std::setfill('0') << mes << "/"
       << year;
    return ss.str();
}

int Generador::generarInt(int limiteInferior, int limiteSuperior)
{
    return limiteInferior + rand() % limiteSuperior;
}
