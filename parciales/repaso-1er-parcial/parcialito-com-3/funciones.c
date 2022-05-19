#include "funciones.h"

nodo* inicLista(){
    return NULL;
}

nodo* crearNodo(){
    nodo* aux = (nodo*) malloc(sizeof(nodo));
    aux-> num = rand()%100;
    aux-> siguiente = NULL;
    return aux;
}

void mostrarNodo(nodo* aux){
    printf(" %d ", aux-> num);
}

nodo* agregarAlFinal(nodo* lista, nodo* nuevoNodo){
    if(lista == NULL){
        lista = nuevoNodo;
    }else{
        nodo* aux = lista;
        while(aux-> siguiente){
            aux = aux-> siguiente;
        }
        aux-> siguiente = nuevoNodo;
    }
    return lista;
}

nodo* cargarVariosAlFinal(nodo* lista, int cant){
    int i = 0;
    nodo* nuevoNodo;
    while(i < cant){
        nuevoNodo = crearNodo();
        lista = agregarAlFinal(lista, nuevoNodo);
        i++;
    }
    return lista;
}

void mostrarLista(nodo* lista){
    if(lista){
        mostrarNodo(lista);
        mostrarLista(lista-> siguiente);
    }
}

void mostrarListaAlReves(nodo* lista){
    if(lista){
        mostrarListaAlReves(lista-> siguiente);
        mostrarNodo(lista);
    }
}

int validos(nodo* lista){
    int i = 0;
    while(lista){
        lista = lista-> siguiente;
        i++;
    }

    return i;
}

nodo* borrarPosicion(nodo* lista, int posicion){
    if(lista){
        int maximo = validos(lista);

        while(posicion > maximo || posicion < 1){
            printf("\n\nEse inidice no existe en la lista, ingrese otro: ");
            fflush(stdin);
            scanf("%d", &posicion);
        }

        if(posicion == 1){
            nodo* aBorrar = lista;
            lista = lista-> siguiente;
            free(aBorrar);
        }else{
            nodo* anterior = lista;
            nodo* seguidora = lista-> siguiente;
            int posicionActual = 2;
            while(posicion != posicionActual){
                anterior = seguidora;
                seguidora = seguidora-> siguiente;
                posicionActual++;
            }
            nodo* aBorrar = seguidora;
            anterior-> siguiente = seguidora-> siguiente;
            free(aBorrar);
        }
    }else{
        printf("\nLa lista esta vacia\n");
    }
    return lista;
}

nodo* eliminarMayores(nodo* lista, int numero){
    if(lista){
        // ????
    }else{
        printf("\nLa lista esta vacia\n");
    }
    return lista;
}
