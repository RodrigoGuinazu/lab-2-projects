#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "arboles.h"

int main()
{
    int array[10] = {30, 4, 19, 55, 78, 3, 99, 23, 85, 100};
    nodoArbol* arbol = inicArbol();
    for(int i = 0; i < 10; i++){
        arbol = insertar(arbol, array[i]);
    }

    printf("\npreOrder: \n");
    printf("\n*****************************************************\n");
    preOrder(arbol);
    printf("\n*****************************************************\n");

    printf("\ninOrder: \n");
    printf("\n*****************************************************\n");
    inOrder(arbol);
    printf("\n*****************************************************\n");

    printf("\npostOrder: \n");
    printf("\n*****************************************************\n");
    postOrder(arbol);
    printf("\n*****************************************************\n");

    printf("\nBuscar un Nodo: \n");
    nodoArbol* rta = buscarNodo(arbol, 100);

    if(rta == NULL){
        printf("\nNo se encontro el nodo\n");
    }else{
        mostrarNodo(rta);
    }

    return 0;
}
