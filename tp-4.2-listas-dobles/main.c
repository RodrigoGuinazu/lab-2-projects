#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "listas-dobles.h"
#include "filas.h"

/*
Codifique las funciones básicas que dan funcionamiento a la Lista Doblemente Enlazada que figuran en el apunte teórico compartido en el Campus.
Modificar la función borrarNodo() de listas simples y transformarla para el caso de una lista doblemente vinculada.
Crear una función recursiva que determine si una lista doblemente vinculada es capicúa. (Después de ver recursividad)
Dada una lista doblemente enlazada ordenada de enteros, eliminar el  nodo que se encuentra en el punto medio de la lista, si la cantidad de nodos es par, eliminar el inmediatamente superior.
Crear el TDA Fila, implementada con listas doblemente vinculadas. Se puede trabajar con librerías separadas, una para la lista doble y otra para el TDA Fila.
Conviene utilizar dos punteros, uno con la dirección de memoria del primer elemento y otro con la del último. Esas dos variables forman parte de una estructura (ojo, pensarlo bien!!). El comportamiento está dado por las siguientes funciones:
a) inicfila.
b) agregar //agrega un elemento al final de la lista
c) extraer //saca un elemento del principio de la lista
d) mostrar
e) leer
f) primero //similar a tope
g) filavacía //similar a pilavacia
*/


int main()
{
    nodoDoble* lista;
    lista = inicLista();
    lista = cargarListaAlPpio(lista);
    lista = borrarElDelMedio(lista);
    mostrarLista(lista);

    /*
    nodoDoble* ultimo = buscarElUltimo(lista);
    int rta1 = esCapicua(lista, ultimo);
    if(rta1 == 1){
        printf("\nEs capicua\n");
    }else{
        printf("\nNO es capicua\n");
    }

    Fila dada;
    inicFila(&dada);

    int rta = filaVacia(&dada);
    printf("\nRta: %d\n", rta);

    agregarAFila(&dada, 1);
    agregarAFila(&dada, 4);
    agregarAFila(&dada, 7);
//    leer(&dada);
//    leer(&dada);
//    leer(&dada);

    mostrarFila(&dada);

    int primeroFila = primero(&dada);
    printf("\nEl primero es: %d\n", primeroFila);

    int extraido = extraer(&dada);
    printf("\nEl extraido es: %d\n", extraido);

    mostrarFila(&dada);

    rta = filaVacia(&dada);
    printf("\nRta: %d\n", rta);
    */
    return 0;
}
