#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "blade.h"
#include "fila.h"

int main()
{
    // FALTAN EJERCICIOS 4,5,7,9

    // Ejercicio 2
    nodoDoble* lista = inicLista();
    lista = pasarALista("blades.dat", lista);
    printf("\n*****************LISTA*****************************\n");
    mostrarListaRecursiva(lista);
    printf("\n*****************LISTA*****************************\n");

    // Ejercicio 3
    //printf("\n\n\nQUITANDO EL NODO SEGUN EL PILOTO...\n\n");
    //lista = quitarSegunPiloto(lista, "Zeke");
    //printf("\n*****************LISTA*****************************\n");
    //mostrarListaRecursiva(lista);
    //printf("\n*****************LISTA*****************************\n");

    // Ejercicio 6
    Blade mejorAtacante = mayorAtaque(lista, lista->dato);
    printf("\nMejor Atacante: \n");
    mostrarBlade(mejorAtacante);

    // Ejercicio 8
    int dim = cantidadSegunElemento(lista, "Hielo");
    Blade* Array;
    Array = (Blade*)malloc(dim*(sizeof(Blade)));
    int validos = pasarArrayDin(lista, "Hielo", Array);
    printf("\n*****************ARRAY*****************************\n");
    mostrarArrayRecursivo(Array, validos, 0);
    printf("\n*****************ARRAY*****************************\n");

    return 0;
}
