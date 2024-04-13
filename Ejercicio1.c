#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main() {

/*
Ejercicio 1

Simular 1000 lanzamientos de una moneda y registrar en cuantos lanzamientos se obtiene
"cara" y en cuantos "cruz".

*/

srand(time(NULL));

int i, num, cara = 0, cruz= 0;

for (i = 0; i < 1000; i++)
{
    num = rand() % 2; // Asigna 1 o 0 a num, si es 0, cara, si es 1, cruz.
    if (num == 0)
    {
        cara += 1;
    }
    else
    {
        cruz += 1;
    }
}

printf("En 1000 lanzamientos se obtuvo cara %d veces y cruz %d veces.", cara, cruz); // Imprime cuantas veces salió cada uno

return 0;

}