#include "generador.h"

Generador::Generador(){
    srand(static_cast<int>(std::time(0))); //Se inicializa la semilla en el constructor (esto se hace una vez por programa)
}

bool Generador::leerArchivo(const string &nombreArchivo)
{
    ifstream archivo(nombreArchivo); //Se crea una instancia de ifstream dandole un nombre de archivo para abrir.
    if(archivo.is_open()){ //Si el archivo se abrio correctamente se ejecuta el siguiente bloque
        string textoAux; //Almacenará el texto de cada linea
        while(getline(archivo,textoAux)) items.push_back(textoAux); //Se introduce al vector de items cada linea de texto.
        archivo.close(); //Se cierra el archivo finalmente.
        return true; //Dado que las operaciones se completaron satisfactoriamente se retorna true.
    }
    else{
        return false; //Como el archivo no se abrio se devuelve falso.
    }
}

const string &Generador::obtenerAlteatorio() const
{
    return items[rand() % items.size()]; //Obtiene un string aleatorio del vector de items.
}


//FUNCION RECUPERADA DE LOS CODIGOS MOSTRADOS EN CLASE.
const string Generador::fechaAleatoria(unsigned short fechaInicial, unsigned short fechaFinal) const
{
    unsigned short diasEnMes[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; //Se define un arreglo de elementos, donde cada indice representa el numero de dias que tiene el mes en su indice.
    int year = fechaInicial + std::rand() % (fechaFinal - fechaInicial + 1); //Se consigue un año aleatorio en los limites indicados.
    int mes = 1 + std::rand() % 12; //Se obtiene el mes aleatorio.
    int dia = 1 + std::rand() % diasEnMes[mes - 1]; //Se indexa el arreglo de meses para obtener el numero maximo de dias que tiene el mes generado.
    //Se forma un string con 

    std::stringstream ss; //Se le da formato a los numeros de tal manera que siga el DD/MM/YYYY
    ss << std::setw(2) << std::setfill('0') << dia << "/"
       << std::setw(2) << std::setfill('0') << mes << "/"
       << year;
    return ss.str();
}

int Generador::generarInt(int limiteInferior, int limiteSuperior)
{
    return limiteInferior + rand() % (limiteSuperior + 1); //Genera un enteroentre los limites dados.
}
