#ifndef GENERADOR_H
#define GENERADOR_H

#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>  // Para std::rand y std::srand
#include <ctime>    // Para std::time
using namespace std;
class Generador{
    private:
        vector<string> items;
    public:
        Generador();
        bool leerArchivo(const string &nombreArchivo);
        const string &obtenerAlteatorio() const;
        int generarInt(int limiteInferior, int limiteSuperior);

};

#endif //GENERADOR_H