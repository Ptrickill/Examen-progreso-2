#include <stdio.h>
#include "maze.h"
#include "player.h"

void juegoNuevo() {
    int laberinto[ROWS][COLS] = {
        {0, 1, 0, 0, 0},
        {0, 1, 1, 1, 0},
        {0, 0, 0, 0, 0},
        {0, 1, 0, 1, 0},
        {1, 0, 0, 1, 0}
    };

    int filaJugador = 0;
    int columnaJugador = 0;
    int movimientos = 0;

    printf("¡Bienvenido al juego del laberinto!\n");

    while (1) {
        imprimirLaberinto(laberinto, filaJugador, columnaJugador);

        printf("Movimientos: %d\n", movimientos);
        printf("Jugador: (%d, %d)\n", filaJugador, columnaJugador);

        if (haGanado(filaJugador, columnaJugador)) {
            printf("¡Ganaste!\n");

            if (movimientos <= 8) {
                printf("Eres un Pro!\n");
            } else if (movimientos <= 15) {
                printf("Eres novato\n");
            } else {
                printf("Eres un noob!\n");
            }

            break;
        }

        moverJugador(laberinto, &filaJugador, &columnaJugador, &movimientos);
    }
}

int main() {
    int opcion;

    do {
        printf("=== Menú Principal ===\n");
        printf("1. Juego Nuevo\n");
        printf("2. Salir\n");
        printf("Ingrese una opción: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                juegoNuevo();
                break;
            case 2:
                printf("¡Hasta luego!\n");
                break;
            default:
                printf("Opción inválida. Por favor, seleccione una opción válida.\n");
                break;
        }

        printf("\n");
    } while (opcion != 2);

    return 0;
}
