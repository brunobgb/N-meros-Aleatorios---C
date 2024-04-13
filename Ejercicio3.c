#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main() {

/*
Ejercicio 3

Si se lanzan tres monedas al mismo tiempo, estimar la probabilidad de que las tres resulten "cara" o "cruces".

*/

srand(time(NULL));

int i, N, triple = 0, Moneda[3]; // Vector que almacena las tres monedas

printf("¿Cuántos lanzamientos de tres monedas desea realizar? \n");
scanf("%d", &N);

for (i = 0; i < N; i++)
{
    Moneda[0] = rand() % 2;
    Moneda[1] = rand() % 2;  // Se asignan los valores a las tres monedas
    Moneda[2] = rand() % 2;

    if (Moneda[0] == Moneda[1] && Moneda[0] == Moneda[2]) 
    { 
        triple += 1; // Si coinciden, se cuenta
    } 
}

float prob_triple = (float) triple / N * 100; // Calculo de la probabilidad

printf("La probabilidad de que las tres monedas resulten iguales es del %.2f por ciento", prob_triple);

return 0;

}