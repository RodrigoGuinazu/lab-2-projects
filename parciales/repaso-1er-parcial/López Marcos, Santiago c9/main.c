#include <stdio.h>
#include <stdlib.h>
#include "persona.h"
#include <conio.h>
#include <string.h>
#include "lista.h"

#define AR_PERSONAS "personas.dat"

int main()
{
    ///ej1
    nodo* lista;
    lista = inicLista();
    lista = archivoToList(AR_PERSONAS, lista);
    mostrarLista(lista);

    ///ej2

    int sumaEdades = sumarListaRecursiva(lista, sumaEdades);

    printf("\n La suma de las edades de dichas personas es : %i", sumaEdades);

    ///ej3

    stPersona menor;
    menor = masJoven(lista);

    ///ej4

    listaToArchi("porInicial.bin", lista, f);
    mostrarArchivo("porInicial.bin");

    ///ej5

    int edad = 25;
    int cantidadPorEdad = cantPorEdad(lista, edad);

    printf("\n La cantidad de personas mayores a 25 es : %i", cantidadPorEdad);

    ///ej6

    float porcentaje = porcentajePorEdad(edad, lista);

    printf("\n Y el porcentaje de personas mayores de 25 anios es : %f", porcentaje);





    return 0;
}

