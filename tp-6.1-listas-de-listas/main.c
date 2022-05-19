#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "listas-de-listas.h"

int main()
{
    nodoCelda* ldl = inicListaCeldas();
    ldl = pasarDeArchivoToLDL("registroArchivoLDL.dat", ldl);
    mostrarListaCeldas(ldl);

    printf("\n\n\n\n\n___________________Archivo de Aprobados__________________________________________\n\n\n\n\n");
    //pasarDeLDLToArchivoDeAprobados("aprobadosLDL.dat", ldl);
    mostrarArchivo("aprobadosLDL.dat");

    return 0;
}
