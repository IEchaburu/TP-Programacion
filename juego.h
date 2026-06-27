#ifndef JUEGO_H
#define JUEGO_H

// Genera un número aleatorio entre 1 y 6
int lanzarDado();

// Muestra las estadisticas de la partida
void mostrarEstadisticas(char nombreRecord[], int puntajeRecord);

// Pide y almacena el nombre de un jugador
void pedirNombre(char nombre[], int numeroJugador);

// Carga el vector de dados (aleatorio o manual según modoSimulado)
void cargarDadosTormenta(int dados[], int cantidadDisponible, bool modoSimulado);
void cargarDadosViento(int vientos[], bool modoSimulado);

// Compara dados de tormenta con los de viento. 
// Modifica la cantidad disponible (resta bloqueados) y devuelve el puntaje de la tirada.
int procesarTirada(int dados[], int cantidadDisponible, int vientos[], int &dadosRestantes, bool &tormentaPerfecta);

// Controla el desarrollo de una partida completa (Modo 1 o 2 jugadores)
void jugarPartida(int modo, char nombreRecord[], int &puntajeRecord, bool modoSimulado);

#endif