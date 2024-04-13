#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>

int main() {

/*
Ejercicio 5

En el juego conocido como "Generala" se utilizan cinco dados que se lanzan simultáneamente. De acuerdo a los valores obtenidos
en esos dados se tienen las combinaciones ganadoras que se muestran a continuación. Escribir un algoritmo para preparar la tabla
de frecuencias de estas combinaciones, a partir de N lanzamientos de los cinco dados.

5.1 Generala: cuando los cinco dados tienen igual valor.
5.2 Poker: cuando cuatro dados tienen igual valor y el quinto es diferente.
5.3 Foul: cuando tres dados tienen el mismo valor y los otros dos son iguales a otro valor. Ejemplos: (3, 1, 3, 3, 1) o (6, 4, 4, 3, 4)
5.4 Escalera: cuando los valores de los cinco dados forman una secuencia ascendente. Ejemplos: (1, 3, 2, 5, 4) o (5, 4, 2, 6, 3)

*/

srand(time(NULL));

int t, i, j, k, N, dados[5];
int contGenerala = 0, contPoker = 0, contFoul = 0, contEscalera = 0;

printf("Introduzca la cantidad de lanzamientos que desea realizar: \n");
scanf("%d", &N);

for (t = 0; t < N; t++)
{
    for (j = 0; j < 6; j++)
    {
        dados[j] = rand() % 6 + 1;
    }

    bool esGenerala = true; // Se inicializa el true, mas abajo ves por qué
    bool esPoker = false; // Este iniciado en falso
    bool esFoul = false; // Falso
    bool esEscalera = true; // Verdadero

    // Generala

    contGenerala++;

    for (int i = 1; i < 5; i++) { // Acá va comparando los dados, si encuentra que un dado es diferente que otro, generala pasa a "false" (porque para obtener generala todos los dados tienen que ser iguales etc etc)
        if (dados[i] != dados[0]) {
            contGenerala--;
            i = 6;
        }
    }

    // Poker

    int contador2[7] = {0};
    for (int i = 0; i < 5; i++) {
        contador2[dados[i]]++;
        if (contador2[dados[i]] >= 4) {  // Si encuentra que 4 dados son iguales, es poker, pero tmb puede ser generala, mas abajo esta la condición para poker
            esPoker = true;
            contPoker++;
        }
    } 

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
        contFoul++;
    }

    // Escaleraaaaa

    if (esEscalera)
    {
        contEscalera++;
    }

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
            contEscalera--;
            break;
        }
    }
}

printf("Combinación        Frecuencia\n");
printf(" Generala              %d\n", contGenerala);
printf("  Poker                %d\n", contPoker);
printf("  Foul                 %d\n", contFoul);
printf(" Escalera              %d\n", contEscalera);

return 0;

}