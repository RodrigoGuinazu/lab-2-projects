#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "LDA.h"

int main()
{
    nodoCelda* lda = inicListaCeldas();
    lda = pasarDeArchivoToLDA("animales.dat", lda);

    //mostrarListaCeldas(lda);

    printf("\n\n\n_________________________________________Un Archivo Por Especie________________________________________\n\n\n");
    //pasarAArchivoPorEspecie(lda);
    mostrarArchivo("especieNro1.dat");

    return 0;
}
