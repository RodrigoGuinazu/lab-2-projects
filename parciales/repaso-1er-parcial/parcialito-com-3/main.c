#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "funciones.h"

int main()
{
    srand(time(NULL)); // PARA LOS NUMERO RAND
    nodo* lista;
    lista = inicLista();
    lista = cargarVariosAlFinal(lista, 5);
    int validosLista = validos(lista);
    printf("\nValidos: %d\n", validosLista);
    printf("\nLista: \n");
    mostrarLista(lista);
    //printf("\nLista al reves: \n");
    //mostrarListaAlReves(lista);
    lista = borrarPosicion(lista, 3);
    printf("\nLista con posicion eliminada: \n");
    mostrarLista(lista);
    lista = eliminarMayores(lista, 50);
    printf("\nLista con mayores eliminados: \n");
    mostrarLista(lista);

    return 0;
}
