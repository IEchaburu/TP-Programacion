```
TECNICATURA UNIVERSITARIA EN PROGRAMACIÓN
```
(^) PROGRAMACIÓN I (^)

# Trabajo práctico integrador

# Cazadores de Tormentas

```
Categoría: Juego de consola
```
# Cantidad de integrantes: De dos a cuatro

**1. Resumen del Juego**
En **Cazadores de Tormentas** , los jugadores compiten a lo largo de **tres rondas** para
acumular la mayor cantidad de "Kilómetros de Persecución" siguiendo tormentas
eléctricas. En cada ronda, se lanzan dos dados especiales llamados **"Dados de
Viento"** que determinan qué números son peligrosos, y un pool de hasta **cinco
dados de "Tormenta"**.

**2. Mecánica y Reglas del Juego**
    1. **Estructura:** El juego consta de **tres rondas**. Se puede jugar en Modo Un
       Jugador o Modo Dos Jugadores.
    2. **Inicio de Ronda:** Al comenzar cada ronda, se lanzan **dos dados de 6 caras**
       llamados **Dados de Viento (Bloqueadores)**. Los valores obtenidos
       establecerán las "direcciones peligrosas" de la ronda.
    3. **Las Tiradas:** El jugador comienza tirando **cinco dados de Tormenta**
       (también de 6 caras).
          o **Acumulación de Puntos:** Se suman los valores de todos los dados
             de la tirada **cuyos números NO coinciden** con ninguno de los dos
             _Dados de Viento_.
          o **Pérdida de Dados:** Cada dado de Tormenta que **coincida** con un
             _Dado de Viento_ representa una ráfaga que daña el equipo. Ese dado
             **se bloquea y se elimina** para las siguientes tiradas de la ronda,
             reduciendo el pool de dados disponibles.
    4. **Decisión del Jugador:** Después de cada tirada, si le quedan dados
       disponibles, se le pregunta al usuario si desea continuar arriesgándose
       ("S/N").


(^) PROGRAMACIÓN I (^)
o Si elige **No ("N")** , asegura los puntos acumulados en la ronda, se
suman a su puntaje total y finaliza su turno.
o Si elige **Sí ("S")** , vuelve a tirar los dados que le queden disponibles.

5. **Reglas Especiales de Finalización:**
    o **Tormenta Perfecta (Duplicador Obligatorio):** Si en una tirada **_todos_**
       **_los dados disponibles_** **obtienen el mismo número** (y este no
       coincide con los de Viento), el puntaje de esa tirada **se duplica** , pero
       el jugador **está obligado** a tirar de nuevo en la siguiente ronda (no
       puede plantarse).
    o **Destrucción Total (Puntaje Cero):** Si en cualquier tirada el jugador se
       queda con **cero dados disponibles** (porque todos los que le
       quedaban coincidieron con los _Dados de Viento_ ), la ronda termina
       inmediatamente y el puntaje acumulado en esa ronda específica
       **pasa a ser 0**.
**3. Ejemplo**
Ejemplo de un juego modo un jugador.
--------------------------------
** MODO UN JUGADOR **
--------------------------------
Ingrese nombre jugador: Andrés

Andrés comienza la partida
Ronda 1
Jugador #1: Andrés
Puntos Totales: 0
Puntos Ronda: 0
Dados de Viento (Bloqueadores): [3] y [6]
Tirada #1 (5 dados): [1] [3] [4] [5] [3]

Dados bloqueados en esta tirada: Los dos [3]. Quedan 3 dados para la próxima
tirada.
Suma de la tirada: 1 + 4 + 5 = 10 puntos.

¿Seguir jugando?: S


(^) PROGRAMACIÓN I (^)
En la segunda tirada de la ronda 1 el jugador tiene solo 3 dados. Los dados
bloqueadores siguen siendo los mismos durante toda la ronda 1.
Ronda 1
Jugador #1: Andrés
Puntos Totales: 0
Puntos Ronda: 10
Dados de Viento (Bloqueadores): [3] y [6]
Tirada #2 (3 dados): [2] [4] [2]
Dados bloqueados: Ninguno. Quedan 3 dados.
Suma de la tirada: 2 + 4 + 2 = 8 puntos. (Acumulado ronda: 18)
¿Seguir jugando?: N
Como desea asegurarse los puntos obtenidos, el jugador no quiere seguir jugando
la ronda actual y pasa a la siguiente ronda.
Ronda 2
Jugador #1: Andrés
Puntos Totales:
Puntos Ronda: 0
Dados de Viento (Bloqueadores): [ 1 ] y [ 4 ]
Tirada #1 (5 dados): [ 4 ] [ 1 ] [ 1 ] [ 4 ] [ 1 ]
Jugador sin dados: FIN de Ronda
Nótese que al comenzar una nueva ronda se sortean los nuevos Bloqueadores.
Dados bloqueados: El [ 1 ] y los dos [ 4 ].
Resultado: El jugador se quedó con **0 dados disponibles**.
Fin de Ronda: Al quedarse sin dados por bloqueo, el puntaje de la ronda es **0** y
finaliza inmediatamente la ronda.
Ronda 3
Jugador #1: Andrés
Puntos Totales:
Puntos Ronda: 0
Dados de Viento (Bloqueadores): [ 5 ] y [ 3 ]


(^) PROGRAMACIÓN I (^)
Tirada #1 (5 dados): [ 1 ] [ 2 ] [ 5 ] [ 4 ] [ 5 ]
Dados bloqueados: El [5] y los dos [3]. El jugador se queda con 3 dados.
Suma de la tirada: 1 + 2 + 4 = 7 puntos. (Acumulado ronda: 7)
¿Seguir jugando?: N
Como el jugador decide no continuar, la ronda finaliza y dado que estaba en la
última ronda, también finaliza el juego.
FINAL DEL JUEGO
Jugador #1: Andrés
Puntos Totales: 25

**4. Interfaces (Pantallas)**

**Pantalla principal**
--------------------------------
** CAZADORES DE TORMENTAS **
--------------------------------
1 - MODO UN JUGADOR
2 - MODO DOS JUGADORES
2 - ESTADÍSTICAS
3 - CRÉDITOS
0 - SALIR

Menú principal con opciones: 1. MODO UN JUGADOR, 2. MODO DOS
JUGADORES, 3. ESTADÍSTICAS (Record temporal), 4. CRÉDITOS (Legajos y
nombres), 0. SALIR.

**Modo un jugador**
Debe permitir a un jugador comenzar una nueva partida de Cazadores de
Tormentas. Antes de iniciar, deberá solicitar su nombre. Al finalizar la partida, en
caso de ser el puntaje más alto, se deberá registrar su nombre y dicho puntaje.

**Modo dos jugadores**
Debe permitir a dos jugadores comenzar una nueva partida de Cazadores de
Tormentas. Antes de iniciar, deberá solicitar ambos nombres. Al finalizar la


(^) PROGRAMACIÓN I (^)
partida, en caso de que alguno sea el puntaje más alto, se deberá registrar su
nombre y dicho puntaje.
**Estadísticas**
--------------------------------
** E S T A D I S T I C A S **
--------------------------------
RANKING JUGADOR PUNTAJE
1 LORENZO 110 PUNTOS
Deberá mostrar, si existe, el nombre y el puntaje del jugador que haya obtenido el
puntaje más alto. Tener en cuenta que al cerrar la aplicación el puntaje se
restablecerá.
**Créditos**
--------------------------------
** C R É D I T O S **
--------------------------------
EQUIPO: CAZADORES DE TORMENTAS DE LA UTN FRGP
LEGAJO APELLIDO NOMBRE
88888 GARCÍA CARLOS
77777 RODRÍGUEZ MARTINA
66666 LÓPEZ JULIÁN
55555 ÁLVAREZ SOFÍA
Deberá mostrar el nombre del equipo (inventar uno) junto con sus respectivos
legajos, apellidos y nombres.
**Salir**
Debe salir del programa.

**5. Restricciones Técnicas**

```
● Entorno: Proyecto de aplicación de consola en C++.
● Vectores: Uso obligatorio de vectores estilo C (ej. int tiradaDados[5]). NO
PERMITIDO el uso de #include <vector>.
```


(^) PROGRAMACIÓN I (^)
● **Funciones:** Uso obligatorio de funciones para modularizar la lógica (generar
azar, carga de dados, mostrar menús, etc.). **NO PERMITIDO** el uso de
variables globales.
● **Flujo:** No utilizar la instrucción goto.
● **Aleatoriedad:** Implementación de srand y rand() para garantizar
aleatoriedad real en cada ejecución.
● Al momento de la entrega y defensa el **programa debe compilar**
correctamente.
● **NOTA** : el programa debe tener una opción (MODO SIMULADO) para
cargar los valores de los dados de manera manual (se ingresan por teclado
los valores de cada dado), en lugar de que los valores se asignan de
manera aleatoria. Esta opción se puede mantener oculta, y habilitarse al
momento de la corrección.


