#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main() {

/*
Ejercicio 4

En cierto juego se lanzan dos dados y se registra la suma de los valores que resultan en cada uno de ellos.
Escribir un algoritmo que simule P lanzamientos y elabore una tabla de frecuencias para los valores posibles
de la suma (una tabla de frecuencia contiene cada valor posible y la cantidad de veces que el mismo se ha presentado).

*/

srand(time(NULL));

int i,P, dado[2], frecuencia[12] = {0}; // Vector que almacena dos dados, la suma de los valores de estos puede dar 12 valores diferentes, por eso el vector frecuencia[12]

printf("Introduzca la cantidad de lanzamientos a simular: \n");
scanf("%d", &P);

for (i = 0; i < P; i++)
{
    dado[0] = rand() % 6 + 1;   // Se asignan valores a los dados
    dado[1] = rand() % 6 + 1;

    int suma = dado[0] + dado[1];  // Se suman los valores

    frecuencia[suma - 2] ++; // La frecuencia de 5 por ejemplo, se almacena en frecuencia[3] (el cuarto valor del vector), 5 es el cuarto numero que puede salir como suma (2, 3, 4, 5 ... 12)
}

printf("Número  -   Frecuencia: \n");

for (i = 0; i < 11; i++)
{
    printf("  %d -----------> %d\n", i + 2, frecuencia[i]); // i vale 0, se le suma 2 para que se imprima 2 como mínimo (0 y 1 no pueden salir)
}

return 0;

}