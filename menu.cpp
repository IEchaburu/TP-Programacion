#include <iostream>
#include "menu.h"
using namespace std;

int mostrarMenuPrincipal() {
    int opcion;
    cout << "=================================\n";
    cout << "     CAZADORES DE TORMENTAS      \n";
    cout << "=================================\n";
    cout << "1. MODO UN JUGADOR\n";
    cout << "2. MODO DOS JUGADORES\n";
    cout << "3. ESTADISTICAS\n";
    cout << "4. CREDITOS\n";
    cout << "0. SALIR\n";
    cout << "---------------------------------\n";
    cout << "Seleccione una opcion: ";
    cin >> opcion;
    return opcion;
}

void mostrarCreditos() {
    cout << "--- CREDITOS ---\n";
    cout << "Equipo: Los Tormentosos de Pacheco\n";
    cout << "Legajo: 88888 - GARCIA, CARLOS\n"; // Completar con sus datos reales
    // ...
}

void mostrarEstadisticas(char nombreRecord[], int puntajeRecord) {
    cout << "--- ESTADISTICAS ---\n";
    if (puntajeRecord == 0) {
        cout << "No hay records registrados aun.\n";
    } else {
        cout << "RANKING JUGADOR PUNTAJE\n";
        cout << "1. " << nombreRecord << " - " << puntajeRecord << " PUNTOS\n";
    }
}

void pedirNombre(char nombre[], int numeroJugador) {
    cout << "Ingrese nombre del Jugador #" << numeroJugador << ": ";
    cin >> nombre;
}