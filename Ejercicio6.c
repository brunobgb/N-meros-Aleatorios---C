#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h> // <-- para poder utilizar booleanos

// Una función para el dado, para que no tengas que repetir cada rato el código, solo "llamás" la función
int lanzarDado() {
    return rand() % 6 + 1; // Tira valores del 1 al 6
}

int main() {

/*
Ejercicio 6

En realidad, las reglas del juego "Generala" permiten que el jugador realice hasta un máximo de tres lanzamientos de los dados para
buscar alguna de las combinaciones ganadoras. En la primera oportunidad el jugador debe lanzar los cinco dados. Para la segunda
oportunidad, el jugador puede conservar algunos de los dados lanzados y lanzar solo los restantes. En la tercera oportunidad, si aún
no ha obtenido una combinación ganadora, puede proceder como en la segunda oportunidad. Escribir un algoritmo que permita realizar hasta
tres lanzamientos siguiendo las reglas de este juego y que detecte cuando aparece una combinación ganadora, imprimiendo nombre.

// Los comentarios son exactamente iguales en los dos, son casi el mismo ejercicio xddd

*/

    srand(time(NULL)); // Creo que era para que la "semilla" que genera los aleatorios cambie o algo así

    int i, intento, mantener = 0, dados[5]; // Hay 5 dados
    bool primerIntento = true;

    for (intento = 1; intento <= 3; intento++) { // Todo el sistema de tres lanzamientos, se inicializa en 1 para no mostrar "intento 0" en el printf

        mantener--;

        printf("\nIntento %d:\n", intento);

        for (int i = 0; i < 5; i++)
        {
            if (primerIntento)
            {
                dados[i] = lanzarDado();
                printf("Dado %d: %d\n", i + 1, dados[i]);
            }
        }

        // La parte de las combinaciones ganadoras

        bool esGenerala = true; // Se inicializa el true, mas abajo ves por qué
        bool esPoker = false; // Este iniciado en falso
        bool esFoul = false; // Falso
        bool esEscalera = true; // Verdadero

        // Foul
        int contador[7] = {0}; // Como en el 4, frecuencia
        for (int i = 0; i < 5; i++) {
            contador[dados[i]]++; // Cuenta cuantas veces salió un número de los dados
        }
        int valor1 = 0, valor2 = 0; // Para asignar los valores si se repiten 3 y 2 veces
        for (int i = 1; i <= 6; i++) { // Para comprobar cuantas veces salió un valor y asignar
            if (contador[i] == 3) {
                valor1 = i;
            } else if (contador[i] == 2) {
                valor2 = i;
            }
        }
        if (valor1 != 0 && valor2 != 0) { // Si entraron dos números, es un foul
            esFoul = true;
        }

        // Escaleraaaaa
        // Ordenar los dados
        for (int i = 0; i < 4; i++) {
            for (int j = i + 1; j < 5; j++) {
                if (dados[i] > dados[j]) {
                    int temp = dados[i];
                    dados[i] = dados[j];
                    dados[j] = temp;
                }
            }
        }
        // Si es ascendente
        for (int i = 0; i < 4; i++) {
            if (dados[i] + 1 != dados[i + 1]) {
                esEscalera = false;
                break;
            }
        }

        // Generala

        for (int i = 1; i < 5; i++) { // Acá va comparando los dados, si encuentra que un dado es diferente que otro, generala pasa a "false" (porque para obtener generala todos los dados tienen que ser iguales etc etc)
            if (dados[i] != dados[0]) {
                esGenerala = false;
            }
        }

        // Poker

        int contador2[7] = {0};
        for (int i = 0; i < 5; i++) {
            contador2[dados[i]]++;
            if (contador2[dados[i]] >= 4) {  // Si encuentra que 4 dados son iguales, es poker, pero tmb puede ser generala, mas abajo esta la condición para poker
                esPoker = true;
            }
        }

        // Se imprimen las combinaciones

        if (esGenerala) {
            printf("Se obtuvo Generala\n");
            break;
        } else if (esPoker && !esGenerala) { // Si un  número es poker y generala (tipo, 5 5 5 5 5) se imprime como generala
            printf("Se obtuvo Poker\n");
            break;
        } else if (esFoul) {
            printf("Se obtuvo Foul\n");
            break;
        } else if (esEscalera) {
            printf("Se obtuvo Escalera\n");
            break;
        }
        
        

        // En casp de ya ser el tercer intento
        if (intento == 3) {
            printf("Perdiste!\n");
            break;
        }
        else
        {
            // Elección del dado a mantener

            primerIntento = false;
    
            printf("¿Qué dado desea mantener? (1-5)\n");
            scanf("%d", &mantener);
            while (mantener < 1 || mantener > 5)
            {
                printf("Por favor, introduzca un número válido. (1-5)\n");
                scanf("%d", &mantener);
            }

            for (int i = 0; i < 5; i++)
            {
                if (i != mantener)
                {
                    dados[i] = lanzarDado();
                }
                printf("Dado %d: %d\n", i + 1, dados[i]);
            }
        }   
    }

return 0;

}