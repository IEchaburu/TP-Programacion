#include <iostream>
#include <cstring>
#include "menu.h"
#include "juego.h"
using namespace std;


void mostrarCreditos() {
    cout << "--- CREDITOS ---\n";
    cout << "Equipo: Los Tormentosos de Pacheco\n";
    cout << "Legajo: 88888 - GARCIA, CARLOS\n"; // Completar con sus datos reales
    cout << "Legajo: 88888 - GARCIA, CARLOS\n"; // Completar con sus datos reales
    cout << "Legajo: 88888 - GARCIA, CARLOS\n"; // Completar con sus datos reales
}

void opcionesMenuPrincipal() {
    
    cout << "=================================" << endl;    
    cout << "     CAZADORES DE TORMENTAS      " << endl;
    cout << "=================================" << endl;
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

