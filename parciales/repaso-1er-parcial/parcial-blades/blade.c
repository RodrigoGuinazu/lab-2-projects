#include "blade.h"

// Ejercicio 2

nodoDoble* inicLista(){
    return NULL;
}

nodoDoble* crearNodo(Blade datoBlade){
    nodoDoble* aux = (nodoDoble*) malloc(sizeof(nodoDoble));
    aux-> dato = datoBlade;
    aux-> anterior = NULL;
    aux-> siguiente = NULL;

    return aux;
}

nodoDoble* insertarEnOrden(nodoDoble* lista, nodoDoble* nuevoNodo){
    if(lista == NULL){
        lista = nuevoNodo;
    }else{
        if(strcmp(nuevoNodo-> dato.nombre , lista-> dato.nombre) < 0){
            nuevoNodo-> siguiente = lista;
            if(lista-> siguiente){
                lista-> anterior = nuevoNodo;
            }
            lista = nuevoNodo;
        }else{
            nodoDoble* ante = lista;
            nodoDoble* seguidora = lista-> siguiente;

            while(seguidora && strcmp(nuevoNodo-> dato.nombre, lista-> dato.nombre) >= 0){
                ante = seguidora;
                seguidora = seguidora-> siguiente;
            }

            ante-> siguiente = nuevoNodo;
            nuevoNodo-> siguiente = seguidora;
            nuevoNodo-> anterior = ante;
            if(seguidora){
                seguidora-> anterior = nuevoNodo;
            }
        }
    }
    return lista;
}

nodoDoble* pasarALista(char archivo[], nodoDoble* lista){
    FILE * arch = fopen(archivo, "r");
    Blade auxBlade;
    nodoDoble* auxNodo;
    if(arch){
        while(fread(&auxBlade, sizeof(Blade), 1, arch) > 0){
            auxNodo = crearNodo(auxBlade);
            lista = insertarEnOrden(lista, auxNodo);
        }
        fclose(arch);
    }
    return lista;
}

void mostrarBlade(Blade aux){
    printf("\nNombre...............: %s", aux.nombre);
    printf("\nElemento.............: %s", aux.elemento);
    printf("\nAtaque...............: %d", aux.ataque);
    printf("\nCritico..............: %f", aux.critico);
    printf("\nBloqueo..............: %f", aux.bloqueo);
    printf("\nPiloto...............: %s", aux.piloto);
    printf("\n\n");
}

void mostrarListaRecursiva(nodoDoble* lista){
    if(lista == NULL){
        printf("\n");
    }else{
        mostrarBlade(lista-> dato);
        mostrarListaRecursiva(lista-> siguiente);
    }
}

// Ejercicio 3

nodoDoble* quitarSegunPiloto(nodoDoble* lista, char piloto[]){
    if(lista){
        if(strcmp(lista-> dato.piloto, piloto) == 0){
            nodoDoble* aBorrar = lista;
            lista = lista-> siguiente;
            if(lista){
                lista-> anterior = NULL;
            }
            free(aBorrar);
        }else{
            nodoDoble* seguidora = lista-> siguiente;

            while(seguidora && strcmp(seguidora-> dato.piloto, piloto) != 0){
                seguidora = seguidora-> siguiente;
            }

            if(seguidora){
                nodoDoble* ante = seguidora-> anterior;
                ante-> siguiente = seguidora-> siguiente;
                if(seguidora-> siguiente){
                    nodoDoble* sig = seguidora-> siguiente;
                    sig-> anterior = ante;
                }
                free(seguidora);
            }else{
                printf("\nEl elemento que deseas borrar no existe en la lista\n");
            }
        }
    }
    return lista;
}

// Ejercicio 4 y 5

/*Fila pasarSegunPiloto(nodoDoble* lista, char piloto[], Fila dada){
    if(lista){
        while(lista){
            if(strcmp(lista-> dato.piloto, piloto) == 0){
                agregarFila(dada, lista->dato);
            }
            lista = lista-> siguiente;
        }
    }
    return dada;
}

void mostrarFila(Fila dada){
   // ?
}
*/

// Ejercicio 6

Blade mayorAtaque(nodoDoble* lista, Blade mayor){ //mayor = lista-> dato
    if(lista == NULL){
        mayor = mayor;
    }else{
        if(lista-> dato.ataque > mayor.ataque){
            mayor = lista-> dato;
        }
        mayor = mayorAtaque(lista-> siguiente, mayor);
    }
    return mayor;
}

// Ejercicio 8

int cantidadSegunElemento(nodoDoble* lista, char elemento[]){
    int validos = 0;
    while(lista){
        if(strcmp(lista->dato.elemento, elemento) == 0){
            validos++;
        }
        lista = lista-> siguiente;
    }
    return validos;
}

int pasarArrayDin(nodoDoble* lista, char elemento[], Blade Array[]){
    int validos = 0;
    Blade aux;
    while(lista){
        if(strcmp(lista->dato.elemento, elemento) == 0){
            aux = lista-> dato;
            Array[validos] = aux;
            validos++;
        }
        lista = lista-> siguiente;
    }
    return validos;
}

void mostrarArrayRecursivo(Blade Array[], int validos, int i){
    if(validos == 0){
        printf("\n");
    }else{
        mostrarBlade(Array[i]);
        mostrarArrayRecursivo(Array, validos-1, i+1);
    }
}
