#include "listas.h"

// Ejercicio 1

nodoS* inicLista(){
    return NULL;
}

//1.a)
nodoS* crearNodo(stVendedor vendedor){
    nodoS* aux = (nodoS*) malloc(sizeof(nodoS));
    aux-> dato = vendedor;
    aux-> siguiente = NULL;

    return aux;
}

//1.b)
nodoS* agregarAlFinalRecursivo(nodoS* lista, nodoS* nuevoNodo){
    if(lista == NULL){
        lista = nuevoNodo;
    }else{
        lista-> siguiente = agregarAlFinalRecursivo(lista-> siguiente, nuevoNodo);
    }
    return lista;
}

//1.c)
nodoS* archivoALista(char archivo[], nodoS* lista){
    FILE * arch = fopen(archivo, "rb"); // modo de apertura para lectura es rb
    stVendedor auxVendedor;
    nodoS* auxNodo;
    if(arch){
        while(fread(&auxVendedor, sizeof(stVendedor), 1, arch) > 0){
            auxNodo = crearNodo(auxVendedor);
            lista = agregarAlFinalRecursivo(lista, auxNodo);
        }
        fclose(arch);
    }

    return lista;
}

// Ejercicio 2

//2.b)
void mostrarUnVendedor(stVendedor aux){
    printf("\nID...............: %d", aux.id);
    printf("\nNombre y Apellido: %s", aux.nombreYapellido);
    printf("\nSector...........: %s", aux.sector);
    printf("\nVentas Diarias...: %d", aux.ventasDiarias);
    printf("\n\n");
}

//2.a)
void mostrarLista(nodoS* lista){
    while(lista){
        mostrarUnVendedor(lista-> dato);
        lista = lista-> siguiente;
    }
}


// Ejercicio 3

int cantSegunRubro(nodoS* lista, char rubro[]){ // Funciona con todos los rubros, hay que pasarle por parametro en el main el rubro a trabajar
    int rta = 0;
    if(lista){
        if(strcmp(lista-> dato.sector, rubro) == 0){
            rta = 1 + cantSegunRubro(lista-> siguiente, rubro);
        }else{
            rta = cantSegunRubro(lista-> siguiente, rubro);
        }
    }
    return rta;
}

// Ejercicio 4

//4.a)
int mayorVentas(nodoS* lista){
    int id = lista-> dato.id;
    int ventas = lista-> dato.ventasDiarias;

    while(lista){
        if(lista-> dato.ventasDiarias > ventas){
            id = lista-> dato.id;
            ventas = lista-> dato.ventasDiarias;
        }
        lista = lista-> siguiente;
    }

    return id;
}

//4.b)
stVendedor eliminarPorId(nodoS** lista, int id){
    stVendedor vendedor;
    if(*lista){
        if((*lista)-> dato.id == id){
            vendedor = (*lista)-> dato;
            nodoS* aux = *lista;
            *lista = (*lista)-> siguiente;
            free(aux);
        }else{
            nodoS* anterior = *lista;
            nodoS* seguidora = (*lista)-> siguiente;
            while(seguidora && seguidora-> dato.id != id){
                anterior = seguidora;
                seguidora = seguidora-> siguiente;
            }
            if(seguidora){
                vendedor = seguidora-> dato;
                nodoS* aux = seguidora;
                anterior-> siguiente = seguidora-> siguiente;
                free(aux);
            }
        }
    }
    return vendedor;
}

//4.c)

nodoD* inicListaDoble(){
    return NULL;
}

nodoD* crearNodoDoble(stVendedor vendedor){
    nodoD* aux = (nodoD*) malloc(sizeof(nodoD));
    aux-> dato = vendedor;
    aux-> anterior = NULL;
    aux-> siguiente = NULL;

    return aux;
}

nodoD* buscarElUltimo(nodoD* lista){
    nodoD* ultimo = lista;
    if(ultimo){
        while(ultimo-> siguiente){
            ultimo = ultimo-> siguiente;
        }
    }
    return ultimo;
}

nodoD* agregarAlFinal(nodoD* lista, nodoD* nuevoNodo){
    if(lista == NULL){
        lista = nuevoNodo;
    }else{
        nodoD* ultimo = buscarElUltimo(lista);
        nuevoNodo-> anterior = ultimo;
        ultimo-> siguiente = nuevoNodo;
    }
    return lista;
}

void inicFila(Fila* dada){
    dada-> inicio = inicListaDoble();
    dada-> fin = inicListaDoble();
}

void agregarAFila(Fila* dada, stVendedor vendedor){
    nodoD* nuevoNodo = crearNodoDoble(vendedor);

    dada-> fin = agregarAlFinal(dada-> fin, nuevoNodo);
    dada-> fin = nuevoNodo;

    if(dada-> inicio == NULL){
        dada-> inicio = nuevoNodo;
    }
}

void pasarTop10(nodoS* lista, Fila* dada){
    stVendedor vendedorAux;
    int idAux;
    int i = 0;
    while(lista && i<10){
        idAux = mayorVentas(lista);
        vendedorAux = eliminarPorId(&lista, idAux);
        agregarAFila(dada, vendedorAux);
        i++;
    }
}

// Ejercicio 5

void mostrarListaDoble(nodoD* lista){
    if(lista == NULL){
        printf("\n");
    }else{
        mostrarListaDoble(lista-> siguiente);
        mostrarUnVendedor(lista-> dato); // la muestro a la vuelta
    }
}

void mostrarFila(Fila* dada){
    mostrarListaDoble(dada-> inicio);
}
