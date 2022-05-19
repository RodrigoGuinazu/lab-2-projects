#include <stdio.h>
#include <stdlib.h>
#include "listas-puntero-simple.h"
#include "pilas-puntero-doble.h"

int main()
{
    Pila dada1, dada2;
    inicPila(&dada1);
    inicPila(&dada2);

    apilar(&dada1, 1);
    apilar(&dada1, 2);
    leer(&dada1);
    leer(&dada1);

    printf("\nDADA 1\n");
    mostrar(&dada1);

    int tope1 = tope(&dada1);
    printf("\nTope DADA 1: %d\n", tope1);

    printf("\nDADA 2\n");
    mostrar(&dada2);

    printf("\n--------------------------------------------------------------\n");

    while(!pilaVacia(&dada1)){
        apilar(&dada2, desapilar(&dada1));
    }

    printf("\nDADA 1\n");
    mostrar(&dada1);

    printf("\nDADA 2\n");
    mostrar(&dada2);

    printf("\n--------------------------------------------------------------\n");

    printf("\nPasar una pila a una lista\n");
    nodo* lista;
    lista = inicLista();
    pasarALista(&lista, &dada2);
    printf("\nPILA DADA 2\n");
    mostrar(&dada2);
    printf("\nLISTA\n");
    mostrarLista(lista);

    printf("\n--------------------------------------------------------------\n");

    return 0;
}
