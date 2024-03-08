#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define TAMANO_STRING 50
#define CANT_JUGADORES 11

typedef struct Jugador {
    char nombre[TAMANO_STRING];
    int edad, partidosJugados;
} Jugador;

Jugador* jugadoresOrdenadosPorCantDePartidos(Jugador equipo[]);

int main() {
    Jugador equipo[] = {
        {"Messi", 34, 800},
        {"Ronaldo", 37, 900},
        {"Neymar Jr.", 29, 500},
        {"Mbappe", 22, 200},
        {"Lewandowski", 33, 700},
        {"Salah", 29, 400},
        {"De Bruyne", 30, 600},
        {"van Dijk", 30, 400},
        {"Ramos", 35, 650},
        {"Neuer", 35, 800},
        {"Davies", 20, 100}
    };
    
    Jugador *equipoOrdenado = jugadoresOrdenadosPorCantDePartidos(equipo);
    for (int i = 0; i < CANT_JUGADORES; i++) {
        printf("Nombre de jugador : %s - Cantidad de partidos: %i\n", equipoOrdenado[i].nombre, equipoOrdenado[i].partidosJugados);
    }
    
    // Liberar la memoria asignada dinámicamente
    free(equipoOrdenado);
    
    return 0;
}

Jugador* jugadoresOrdenadosPorCantDePartidos(Jugador equipo[]) {
    Jugador* equipo_aux = malloc(CANT_JUGADORES * sizeof(Jugador)); // Asignar memoria dinámicamente
    if (equipo_aux == NULL) { // Comprobar si la asignación de memoria fue exitosa
        // Manejar el error de asignación de memoria
        return NULL;
    }

    memcpy(equipo_aux, equipo, sizeof(Jugador) * CANT_JUGADORES); // Copiar la estructura

    int i, j;
    Jugador aux;
    for (i = 0; i < CANT_JUGADORES - 1; i++) {
        for (j = i + 1; j < CANT_JUGADORES; j++) {
            if (equipo_aux[i].partidosJugados < equipo_aux[j].partidosJugados) {
                aux = equipo_aux[i];
                equipo_aux[i] = equipo_aux[j];
                equipo_aux[j] = aux;
            }
        }
    }

    return equipo_aux;
}
