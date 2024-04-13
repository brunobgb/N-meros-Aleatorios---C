#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main() {

/*
Ejercicio 2

Simular N lanzamientos de una moneda y calcular la probabilidad de aparición de una "cara" y
de una "cruz" (la probabilidad de una "cara" se calcula dividiendo el número de caras obtenidas
entre el número de lanzamientos "N"). Probar el algoritmo con los siguientes valores de N: 10, 100,
1000, 10000, 100000 y verificar si a medida que aumenta N, la probabilidad se acerca a un valor fijo.

*/

srand(time(NULL));

int i, N, num, cara = 0, cruz = 0;

printf("Introduzca la cantidad de lanzamientos a calcular: \n");
scanf("%d", &N);

for (i = 0; i < N; i++)
{
    num = rand() % 2;
    if (num == 0)
    {
        cara += 1;
    }
    else
    {
        cruz += 1;
    }
}

float prob_cara = (float) cara / N * 100;
float prob_cruz = (float) cruz / N * 100;

printf("La probabilidad de cara es del %.2f por ciento\n", prob_cara);
printf("La probabilidad de cruz es del %.2f por ciento\n", prob_cruz);

return 0;

// N = 10 --> 70 y 30
// N = 100 --> 53 y 47
// N = 1000 --> 52.9 y 47.1
// N = 10000 --> 50.09 y 49.91
// N = 100000 --> 50.07 y 49.93
// N = 1000000000 --> 50 y 50

// A medida que N crece, las probabilidades se acercan más a 50.

}