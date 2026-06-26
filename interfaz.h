#ifndef INTERFAZ_H
#define INTERFAZ_H

// Muestra el menú principal y devuelve la opción elegida
int mostrarMenuPrincipal();

// Muestra los créditos del equipo
void mostrarCreditos();

// Muestra el puntaje más alto registrado en la sesión actual
void mostrarEstadisticas(char nombreRecord[], int puntajeRecord);

// Pide y almacena el nombre de un jugador
void pedirNombre(char nombre[], int numeroJugador);

#endif