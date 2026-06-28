#include <iostream>
#include <cstdlib>
#include <cstring>
#include "juego.h"
using namespace std;

int lanzarDado() {
    return (rand() % 6) + 1;
}

/// FUNCIONES INICIO DE PARTIDA ///
void pedirNombre(char nombre[], int numeroJugador) {
    cout << "Ingrese el nombre del jugador " << numeroJugador << ": ";
    cin.ignore(1000, '\n'); // Ignora el salto de linea anterior
    cin.getline(nombre, TAMANO_NOMBRE);
}

/// FUNCIONES DE LA LOGICA DEL JUEGO ///

void cargarDadosTormenta(int dados[], int cantidadDisponible, bool modoSimulado) {
    if (modoSimulado) {
        for (int i = 0; i < cantidadDisponible; i++) {
            do {
                cout << "Dado tormenta [" << i + 1 << "]: ";
                cin >> dados[i];
            } while (dados[i] < 1 || dados[i] > 6);
        }
    } else {
        for (int i = 0; i < cantidadDisponible; i++) {
            dados[i] = lanzarDado();
        }
    }
}

void cargarDadosViento(int vientos[], bool modoSimulado) {
    if (modoSimulado) {
        cout << "Carga Manual - Dado Viento 1: ";
        cin >> vientos[0];
        cout << "Carga Manual - Dado Viento 2: ";
        cin >> vientos[1];
    } else {
        vientos[0] = lanzarDado();
        vientos[1] = lanzarDado();
    }
}

 //comparar dados y sumar puntos
 ///Declarar afuera y antes de las llamdas de las funcines
 // int DadosValidos[5];
 // int ContadorValido = 0;
 // int DadosDisponibles = 5;

int compararDados(int tiradaDados[], int &dadosDisponibles, int viento1, int viento2, int dadosValidos[], int &contadorValido) {
    int dadosBloqueados = 0;  
    int puntaje = 0;

    for (int i = 0; i < dadosDisponibles; i++) {
        if (tiradaDados[i] == viento1 || tiradaDados[i] == viento2) {
            dadosBloqueados++;
        } else {
            puntaje += tiradaDados[i];
            dadosValidos[contadorValido] = tiradaDados[i];
            contadorValido++;
        }
    }
    dadosDisponibles -= dadosBloqueados;
    return puntaje;
}

// -1 es "desastre total" y los punto se tiene que restableser a 0 (puntos=0)
// -2 es "tormeta perfecta" los punto se tiene que multiplicar por dos (puntos*2)
// 0 es no hay cambios en la puntuacion

 //Destruccion total

int resultado(int dadosDisponibles, int dadosValidos[], int contadorValido) {
    //Destruccion total
    if (dadosDisponibles == 0) {
        return -1;
    }

    int auxiliarDado = dadosValidos[0];
    bool tormentaPerfecta = true;
    for (int i = 1; i < contadorValido; i++) {
        if (dadosValidos[i] != auxiliarDado) {
            tormentaPerfecta = false;
            break;
        }
    }

    if (tormentaPerfecta) {
        return -2;
    }
    return 0;
}

/// Logica de la tirada
int procesarTirada(int dados[], int cantidadDisponible, int vientos[], int &dadosRestantes, bool &tormentaPerfecta, bool &destruccionTotal) {

    int dadosValidos[CANTIDAD_DADOS_TORMENTA];
    int contadorValido = 0;
    int disponibles = cantidadDisponible;

    tormentaPerfecta = false;
    destruccionTotal = false;

    int puntajeTirada = compararDados(dados, disponibles, vientos[0], vientos[1], dadosValidos, contadorValido);
    int resultadoTirada = resultado(disponibles, dadosValidos, contadorValido);

    if (resultadoTirada == -1) {
        destruccionTotal = true;
        return 0;
    } 

    if (resultadoTirada == -2) {
        tormentaPerfecta = true;
        return puntajeTirada * 2;
    }

    return puntajeTirada;
}

/// Funcion que controla el desarrollo de una ronda completa (Modo 1 o 2 jugadores)

int jugarTurnoRonda(const char nombreJugador[], int vientos[], bool modoSimulado) {

    int dadosTormenta[CANTIDAD_DADOS_TORMENTA];
    int dadosRestantes = CANTIDAD_DADOS_TORMENTA;
    int puntajeRonda = 0;
    bool forzarSiguienteTirada = false;

    cout << "\n--- Turno de " << nombreJugador << " ---" << endl;
    mostrarDadosViento(vientos);

    while (dadosRestantes > 0) {
        cargarDadosTormenta(dadosTormenta, dadosRestantes, modoSimulado);
        mostrarDadosTormenta(dadosTormenta, dadosRestantes);

        bool tormentaPerfecta = false;
        bool destruccionTotal = false;

        int puntajeTirada = procesarTirada(dadosTormenta, dadosRestantes, vientos, dadosRestantes, tormentaPerfecta, destruccionTotal);

        if (destruccionTotal) {
            cout << "Destruccion total! Pierde los puntos de esta ronda.\n";
            return 0;
        }

        puntajeRonda += puntajeTirada;
        cout << "Puntaje de la tirada: " << puntajeTirada << endl;
        cout << "Puntaje acumulado en la ronda: " << puntajeRonda << endl;
        cout << "Dados restantes: " << dadosRestantes << endl;

        if (tormentaPerfecta) {
            cout << "Tormenta perfecta! Debe tirar de nuevo.\n";
            forzarSiguienteTirada = true;
        }

        if (forzarSiguienteTirada) {
            forzarSiguienteTirada = false;
            continue;
        }

        if (dadosRestantes == 0) {
            break;
        }

        if (preguntarRiesgo() == 'N') {
            break;
        }
    }

    return puntajeRonda;
}

/// Funciones de la UI

void mostrarDadosViento(int vientos[]) {
    cout << "Dados de viento (bloqueadores): "
         << vientos[0] << " - " << vientos[1] << endl;
}

void mostrarDadosTormenta(int dados[], int cantidad) {
    cout << "Dados de tormenta: ";
    for (int i = 0; i < cantidad; i++) {
        cout << dados[i];
        if (i < cantidad - 1) cout << " - ";
    }
    cout << endl;
}

char preguntarRiesgo() {
    char respuesta;
    do {
        cout << "Desea seguir arriesgando? (S/N): ";
        cin >> respuesta;
        respuesta = toupper(respuesta);
    } while (respuesta != 'S' && respuesta != 'N');
    return respuesta;
}

bool preguntarOtraPartida() {
    return preguntarRiesgo() == 'S';
}


/// FUNCIONES DE LAS ESTADISTICAS ///

void mostrarEstadisticas(const char nombreRecord[], int puntajeRecord) {
    cout << "=================================\n";
    cout << "        ESTADISTICAS\n";
    cout << "=================================\n";

    if (nombreRecord[0] == '\0') {
        cout << "No hay records registrados aun.\n";
    } else {
        cout << "Mejor puntaje de la sesion:\n";
        cout << "Jugador: " << nombreRecord << "\n";
        cout << "Puntaje: " << puntajeRecord << " puntos\n";
    }

    cout << "---------------------------------\n";
}

void actualizarRecord(char nombreRecord[], int &puntajeRecord, const char nombreJugador[], int puntajeJugador) {
    if (puntajeJugador > puntajeRecord) {
        puntajeRecord = puntajeJugador;
        strcpy(nombreRecord, nombreJugador);

    }
}


// Modo de juego un jugador.

void jugarModoUnJugador(char nombreRecord[], int &puntajeRecord, bool modoSimulado) {

    char nombreJugador[TAMANO_NOMBRE];
    bool jugarDeNuevo;

    do {
        int puntajeTotal = 0;
        pedirNombre(nombreJugador, 1);

        for (int ronda = 1; ronda <= CANTIDAD_RONDAS; ronda++) {
            int vientos[CANTIDAD_DADOS_VIENTO];

            cout << "========== RONDA " << ronda << " ==========" << endl;
            cargarDadosViento(vientos, modoSimulado);

            int puntajeRonda = jugarTurnoRonda(nombreJugador, vientos, modoSimulado);
            puntajeTotal += puntajeRonda;

            cout << "Puntaje de la ronda " << ronda << ": " << puntajeRonda << endl;
            cout << "Puntaje total: " << puntajeTotal << endl;
        }

        cout << "\nPartida finalizada." << endl;
        cout << "Puntaje final de " << nombreJugador << ": " << puntajeTotal << endl;

        actualizarRecord(nombreRecord, puntajeRecord, nombreJugador, puntajeTotal);
        mostrarEstadisticas(nombreRecord, puntajeRecord);

        jugarDeNuevo = preguntarOtraPartida();

    } while (jugarDeNuevo);
}


// Modo de juego dos jugadores.

void jugarModoDosJugadores(char nombreRecord[], int &puntajeRecord) {
    char nombreJugador1[TAMANO_NOMBRE];
    char nombreJugador2[TAMANO_NOMBRE];

    int puntajeJugador1 = 0;
    int puntajeJugador2 = 0;

    pedirNombre(nombreJugador1, 1);
    pedirNombre(nombreJugador2, 2);
    // Estructura de las 3 rondas. 
    // Uso de vectores fijos obligatorios: int dadosTormenta[5]; int dadosViento[2];
    // Al finalizar, comparar el puntaje con puntajeRecord y actualizar de ser necesario.
    // Mostrar el puntaje final y las estadisticas de la partida.
    // Preguntar si desea jugar otra partida.
    // Si desea jugar otra partida, repetir el proceso.
    // Si no desea jugar otra partida, salir del juego.
    //cout << "Puntaje final: " << puntajeTotal << endl;
    actualizarRecord(nombreRecord, puntajeRecord, nombreJugador1, puntajeJugador1);
    actualizarRecord(nombreRecord, puntajeRecord, nombreJugador2, puntajeJugador2);
}   

