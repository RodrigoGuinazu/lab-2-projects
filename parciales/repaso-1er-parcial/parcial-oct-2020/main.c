#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "lista.h"
#include "pila.h"

int main()
{
    nodo* lista = inicLista();
    lista = archivoALista("EstudiantesTUP.dat", lista);
    printf("\n\n***********************************LISTA***************************************\n\n");
    mostrarLista(lista);
    printf("\n\n***********************************LISTA***************************************\n\n");
    int totalAlumnos = cantEstudiantes(lista);
    printf("\n\nCant Alumnos: %d\n", totalAlumnos);

    int aplazados = conAplazos(lista, 5.00);
    printf("\n\nCant Alumnos con aplazos: %d\n", aplazados);

    float procentajeAplazados = porcentaje(lista, 5.00);
    printf("\n\nEl %.2f de los estudiantes aplazo\n", procentajeAplazados);

    //int legajoMayor = mayorPromedio(lista);
    //printf("\n\nEl estudiante con legajo %d tiene el mayor promedio sin aplazos\n", legajoMayor);

    //stPersona estudiante = eliminarPorLegajo(&lista, legajoMayor);
    //mostrarUnaPersona(estudiante);
    /*
    stPersona arrayEstudiantes[10];
    int validos = pasarTop10(lista, arrayEstudiantes, 10);

    printf("\n\n***********************************LISTA***************************************\n\n");
    mostrarLista(lista);
    printf("\n\n***********************************LISTA***************************************\n\n");

    printf("\n\n***********************************ARRAY***************************************\n\n");
    mostrarArray(arrayEstudiantes, validos, 0);
    printf("\n\n***********************************ARRAY***************************************\n\n");
    */
    Pila dada;
    inicPila(&dada);

    pasarAPila(&dada, lista);
    printf("\n\n***********************************PILA***************************************\n\n");
    mostrarPila(&dada);
    printf("\n\n***********************************PILA***************************************\n\n");

    return 0;
}
