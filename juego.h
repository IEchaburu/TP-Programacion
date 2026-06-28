#ifndef JUEGO_H
#define JUEGO_H


/// CONSTANTES ///

// Constantes de la partida
const int CANTIDAD_RONDAS = 3;
const int CANTIDAD_DADOS_TORMENTA = 5;
const int CANTIDAD_DADOS_VIENTO = 2; 

// Constantes/valores de las estadisticas
const int TAMANO_NOMBRE = 50;

/// FUNCIONES ///

// Genera un número aleatorio entre 1 y 6
int lanzarDado();

// Muestra las estadisticas de la partida
void mostrarEstadisticas(const char nombreRecord[], int puntajeRecord);
void actualizarRecord(char nombreRecord[], int &puntajeRecord, const char nombreJugador[], int puntajeJugador);

// UI
void pedirNombre(char nombre[], int numeroJugador);
void mostrarDadosViento(int vientos[]);
void mostrarDadosTormenta(int dados[], int cantidad);
char preguntarRiesgo();
bool preguntarOtraPartida();


// LOGICA DEL JUEGO //
bool esTormentaPerfecta(int tiradaDados[], int cantidadTirada, int viento1, int viento2);
int resultado(int dadosDisponibles, int dadosValidos[], int contadorValido);



// Carga el vector de dados (aleatorio o manual según modoSimulado)
// Carga los dados de tormenta (manual o aleatorio)
void cargarDadosTormenta(int dados[], int cantidadDisponible, bool modoSimulado);
// Carga los dados de viento (manual o aleatorio)
void cargarDadosViento(int vientos[], bool modoSimulado);

// Compara tirada vs viento, suma puntos, guarda dados validos, reduce disponibles
int compararDados(int tiradaDados[], int &dadosDisponibles, int viento1, int viento2, int dadosValidos[], int &contadorValido);


// Compara dados de tormenta con los de viento. 
// Modifica la cantidad disponible (resta bloqueados) y devuelve el puntaje de la tirada.
int procesarTirada(int dados[], int cantidadDisponible, int vientos[], int &dadosRestantes, bool &tormentaPerfecta, bool &destruccionTotal);

// Controla el desarrollo de una ronda completa (Modo 1 o 2 jugadores)
int jugarTurnoRonda(const char nombreJugador[], int vientos[], bool modoSimulado);
int jugarRonda(const char nombreJugador[], int vientos[], bool modoSimulado);

// Controla el desarrollo de una partida completa (Modo 1 o 2 jugadores)
void jugarModoUnJugador(char nombreRecord[], int &puntajeRecord, bool modoSimulado);
void jugarModoDosJugadores(char nombreRecord[], int &puntajeRecord);

#endif