#ifndef GENERADOR_H
#define GENERADOR_H

#include "importaciones.h"
class Generador{
    private:
        vector<string> items;
    public:
        Generador();
        bool leerArchivo(const string &nombreArchivo);
        const string &obtenerAlteatorio() const;
        const string fechaAleatoria(unsigned short fechaInicial, unsigned short fechaFinal) const;
        int generarInt(int limiteInferior, int limiteSuperior);


};

#endif //GENERADOR_H
