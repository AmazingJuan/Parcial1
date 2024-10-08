#include "menus.h"

int menuOpcion(string mensaje, string (&opciones)[8], int lenOpcion){
    bool bandera = true; //Se inicializa una bandera que indica si el usuario termino de escoger o no.
    bool error = false; //Se inicializa un booleano error, si este es verdadero entonces mostrara un mensaje indicando que el usuario se equivoco al escoger la opcion.
    string entrada = "";
    while(bandera){ //Ciclo que siempre esta presente hasta que el usuario escoja una opcion valida.
        cout << mensaje; //Se imprime el mensaje que se le quiere mostrar al usuario
        //De la linea 10 a 17 se discierne entre mostrarle al usuario un mensaje indicando que ingrese la entrada, o uno que le haga saber que se equivoco y que debe escoger una opcion valida.
        if(!error) cout << "Escoja la opcion que desee: ";
        else cout << "Ingreso una opcion incorrecta, vuelva a ingresar la opcion por favor: ";
        getline(cin, entrada); //Se obtiene la entrada del usuario
        if(validarOpcion(entrada, opciones, lenOpcion)){ //Valida la entrada del usuario haciendo uso de la funcion validarOpcion.
            limpiarPantalla(); //Se limpia la pantalla.
            return stoi(entrada); //Devuelve la entrada del usuario convertida a entero.
        }
        else error = true; //Si la opcion no es valida se activa el booleano error.
        limpiarPantalla(); //Se limpia la pantalla.
    }
}