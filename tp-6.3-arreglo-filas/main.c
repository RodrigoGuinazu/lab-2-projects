#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "arreglo-de-filas.h"
#include "fila.h"
#include "lista-doble.h"

int main()
{
    celdaEspecie array[20];

    int validos = 0;
    validos = pasarDeArchivoToADF("animales.dat", array, validos);
    //mostrarArrayDeArboles(array, validos);

    printf("\n\n\n_________________________________________Un Archivo Por Especie________________________________________\n\n\n");
    //pasarAArchivoPorEspecie(array, validos); //solo se ejecuta una vez, porque sino el archivo se va agregar la misma info otra vez
    mostrarArchivo("especieNro1.dat"); // NO FUNCIONA EL ARBOL GUARDADOD EN EL ARCHIVO
    return 0;
}
