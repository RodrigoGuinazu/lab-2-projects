#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "arreglos-de-listas.h"

int main()
{
    //cargarArchivo("registroArchivo.dat");
    //mostrarArchivo("registroArchivo.dat");

    stCelda array[20];

    int validos = 0;
    validos = pasarDeArchivoToADL("registroArchivo.dat", array, validos);
    mostrarArrayDeListas(array, validos);

    printf("\n\n\n\n\n___________________Archivo de Aprobados__________________________________________\n\n\n\n\n");

    //pasarDeADLToArchivoDeAprobados("aprobados.dat", array, validos);
    mostrarArchivo("aprobados.dat");

    return 0;
}
