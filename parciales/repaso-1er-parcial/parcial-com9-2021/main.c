#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "lista.h"

int main()
{
    nodo* lista;
    lista = inicLista();
    lista = pasarALista("personas.dat", lista);
    mostrarListaRecursiva(lista);
    int suma = sumarEdades(lista);
    printf("\nLa suma de edades es: %d\n", suma);
    stPersona menor = buscarMenor(lista, lista->dato);
    printf("\nEl menor:\n");
    muestraUnaPersona(menor);
    //copiarEnArchivo(lista, 'C', "nuevoArchivo.dat");
    printf("\n\n*********************************************************\n\n");
    printf("\nArchivo segun letra\n");
    archivoMostrar("nuevoArchivo.dat");
    printf("\n\n\nRta: %.2f", porcentaje(lista, 60));

    return 0;
}
