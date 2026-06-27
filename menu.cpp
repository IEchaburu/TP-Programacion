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

void menuPrincipal() {
    
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
                //jugar();
                break;
            case 2:
                //mostrarEstadisticas();
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

