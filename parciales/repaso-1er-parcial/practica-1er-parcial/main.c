#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "automoviles.h"

int main()
{
    nodoAuto* lista;
    inicLista(&lista);
    agregarMuchos(&lista);
    mostrarLista(lista);
    automovil Array[30];
    int validos = 0;
    validos = pasar(lista, Array, 30);
    printf("\n\n***************************** ARRAY:\n");
    mostrarArrayRecursivo(Array, validos, 0);
    int suma = sumarPares(lista);
    printf("\nLa suma de valores de autos con patentes pares es: %d\n", suma);

    return 0;
}
