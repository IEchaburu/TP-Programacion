#include <iostream>
#include <cstring>
#include "menu.h"
#include "juego.h"
using namespace std;


void mostrarCreditos() {
    cout << endl;
    cout << "--------------------------------" << endl;
    cout << "**       C R E D I T O S      **" << endl;
    cout << "--------------------------------" << endl;
    cout << "EQUIPO: CAZADORES DE CODIGOS UTR FRGP" << endl;
    cout << endl;
    cout << "-LEGAJO    APELLIDO    NOMBRE-" << endl;
    cout << "-34488     hernandez cabral      juan-" << endl;
    cout << "-34386     Alvez    Joaquin-" << endl;
    cout << "-34454     Echaburu        Iñaki-" << endl;
    cout << "-35005     Ruiz Diaz     Rodrigo-" << endl;
    cout << "---------------------------------" << endl;
    cout << endl;
}


void mostrarReglas()
{
    cout << endl;
    cout << "========================================" << endl;
    cout << "          REGLAS DEL JUEGO              " << endl;
    cout << "========================================" << endl;
    cout << "- Cada ronda se tiran dados de tormenta y de viento." << endl;
    cout << "- Los dados de viento bloquean dados de tormenta iguales." << endl;
    cout << "- Se suman los puntos de los dados validos restantes." << endl;
    cout << "- Tormenta Perfecta: duplica puntos y obliga a seguir." << endl;
    cout << "- Destruccion Total: sin dados, pierdes todo el acumulado." << endl;
    cout << "- El juego consta de 3 rondas." << endl;
    cout << "========================================" << endl;
    cout << endl;
}

void opcionesMenuPrincipal() {
    
    cout << "========================================" << endl;
    cout << "          CAZADORES DE DADOS            " << endl;
    cout << "========================================" << endl;
    cout << "1. JUGAR" << endl;
    cout << "2. ESTADISTICAS" << endl;
    cout << "3. CREDITOS" << endl;
    cout << "0. SALIR" << endl;
    cout << "---------------------------------" << endl;
    cout << "Seleccione una opcion: " << endl;
}

void mostrarModoJuego() {
    cout << "=================================" << endl;
    cout << "     MODOS DE JUEGO      " << endl;
    cout << "=================================" << endl;
    cout << "1. MODO UN JUGADOR" << endl;
    cout << "2. MODO DOS JUGADORES" << endl;
    cout << "3. REGLAS" << endl;
    cout << "0. VOLVER" << endl;
    cout << "---------------------------------" << endl;
    cout << "Seleccione una opcion: " << endl;
}

void elegirModoJuego(char nombreRecord[], int &puntajeRecord) {
    while (true) {

        int modoJuego;
        system("cls");
        mostrarModoJuego();
        cin >> modoJuego;
    
        switch (modoJuego) {
            case 0:
                return;
            case 1:
                jugarModoUnJugador(nombreRecord, puntajeRecord, false);
                break;
            case 2:
                jugarModoDosJugadores(nombreRecord, puntajeRecord, false);
                break;
            case 3:
                mostrarReglas();
                system("pause");
                break;
            case 99: // se mantiene oculto, es para testing
                jugarModoUnJugador(nombreRecord, puntajeRecord, true); // se usa para testing
                break;
            case 9: // se mantiene oculto, es para testing
                jugarModoDosJugadores(nombreRecord, puntajeRecord, true); // se usa para testing
                break;
        }
    }
}

void menuPrincipal() {
    char nombreRecord[50] = "";
    int puntajeRecord = 0;

    while (true) {
        int opcion;

        system("cls");
        opcionesMenuPrincipal();
        cin >> opcion;

        switch (opcion) {
            case 0:
                cout << "Saliendo del juego..." << endl;
                return;
           
            case 1:
                elegirModoJuego(nombreRecord, puntajeRecord);
                break;
            case 2:
                mostrarEstadisticas(nombreRecord, puntajeRecord);
                system("pause");
                break;
            case 3:
                mostrarCreditos();
                system("pause");
                break;
            default:
                cout << "Opcion no valida\n";
                break;
        }
    }
}

