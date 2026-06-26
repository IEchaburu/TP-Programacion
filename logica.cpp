#include <iostream>
#include <cstdlib>
#include "logica.h"
using namespace std;

int lanzarDado() {
    return (rand() % 6) + 1;
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

// Aquí X y Z resolverán el procesamiento matemático fuerte de los vectores estilo C
int procesarTirada(int dados[], int cantidadDisponible, int vientos[], int &dadosRestantes, bool &tormentaPerfecta) {
    int sumaTirada = 0;
    int bloqueadosEnTirada = 0;
    bool todosIguales = true;

    // Lógica para evaluar cuáles coinciden con vientos[0] y vientos[1]
    // Calcular si se cumple Tormenta Perfecta (todos los dados iguales sin ser bloqueados)
    // Actualizar los dadosRestantes restando los bloqueados en esta tirada
    
    return sumaTirada; 
}

void jugarPartida(int modo, char nombreRecord[], int &puntajeRecord, bool modoSimulado) {
    // Estructura de las 3 rondas. 
    // Uso de vectores fijos obligatorios: int dadosTormenta[5]; int dadosViento[2];
    // Al finalizar, comparar el puntaje con puntajeRecord y actualizar de ser necesario.
}