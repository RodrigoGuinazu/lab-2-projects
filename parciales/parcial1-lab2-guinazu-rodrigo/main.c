#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "listas.h"

int main()
{
    //Ejercicio 1
    nodoS* lista = inicLista();
    lista = archivoALista("archivoVendedores.bin", lista);

    printf("\nEjercicio 2\n");
    mostrarLista(lista);

    printf("\nEjercicio 3\n");
    int total = cantSegunRubro(lista, "ropa");
    printf("\nCantidad por sector: %d\n", total);

    printf("\nEjercicio 4 y 5\n");
    Fila dada;
    inicFila(&dada);
    pasarTop10(lista, &dada);
    printf("\n**************************************FILA**********************************\n");
    mostrarFila(&dada);
    printf("\n**************************************FILA**********************************\n");

    return 0;
}
