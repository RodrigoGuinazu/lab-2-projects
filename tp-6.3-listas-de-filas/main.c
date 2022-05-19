#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "lista-de-filas.h"
#include "filas.h"
#include "listas-dobles.h"

int main()
{
    nodoCelda* ldf = inicListaCeldas();
    ldf = pasarDeArchivoToLDF("animales.dat", ldf);

    mostrarListaCeldas(ldf);

    printf("\n\n\n_________________________________________Un Archivo Por Especie________________________________________\n\n\n");
    //pasarAArchivoPorEspecie(ldf);
    mostrarArchivo("especieNro2.dat");

    return 0;
}
