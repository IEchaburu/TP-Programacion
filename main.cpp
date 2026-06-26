#include <iostream>
#include <ctime>
#include <cstdlib>
#include "menu.h"
#include "juego.h"

using namespace std;

int main() {
    srand(time(0)); // Inicializa la semilla aleatoria
    
    // Variables para el record temporal (Vectores de caracteres estilo C para nombres)
    char nombreRecord[50] = "";
    int puntajeRecord = 0;
    
    // Cambiar a 'true' secretamente para activar el ingreso manual en la corrección
    bool modoSimulado = false; 

    int opcion;
    do {
        opcion = mostrarMenuPrincipal();
        
        switch(opcion) {
            case 1:
                jugarPartida(1, nombreRecord, puntajeRecord, modoSimulado);
                break;
            case 2:
                jugarPartida(2, nombreRecord, puntajeRecord, modoSimulado);
                break;
            case 3:
                mostrarEstadisticas(nombreRecord, puntajeRecord);
                break;
            case 4:
                mostrarCreditos();
                break;
            case 0:
                cout << "Saliendo del juego. ¡Gracias por jugar!\n";
                break;
            case 9: // Opción oculta para activar el modo simulado en la entrega
                modoSimulado = !modoSimulado;
                cout << "Modo Simulado: " << (modoSimulado ? "ACTIVADO" : "DESACTIVADO") << endl;
                break;
            default:
                cout << "Opcion incorrecta.\n";
        }
        system("pause"); // Pausa para que el usuario lea la pantalla antes de limpiar
        system("cls");   // Limpia la consola
    } while(opcion != 0);

    return 0;
}