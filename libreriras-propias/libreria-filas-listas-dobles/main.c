#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "listas-dobles.h"
#include "filas.h"

int main()
{
    Fila dada;
    inicFila(&dada);

    int rta = filaVacia(&dada);
    printf("\nRta: %d\n", rta);

    agregarAFila(&dada, 1);
    agregarAFila(&dada, 4);
    agregarAFila(&dada, 7);
//    leer(&dada);
//    leer(&dada);
//    leer(&dada);

    mostrarFila(&dada);

    int primeroFila = primero(&dada);
    printf("\nEl primero es: %d\n", primeroFila);

    int extraido = extraer(&dada);
    printf("\nEl extraido es: %d\n", extraido);

    mostrarFila(&dada);

    rta = filaVacia(&dada);
    printf("\nRta: %d\n", rta);

    return 0;
}
