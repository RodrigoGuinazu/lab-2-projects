#include "lista.h"

// 1)
nodo* inicLista(){
    return NULL;
}
//a)
nodo* crearNodo(stPersona persona){
    nodo* aux = (nodo*) malloc(sizeof(nodo));
    aux-> dato = persona;
    aux-> siguiente = NULL;

    return aux;
}
//b)
nodo* agregarFinalRecursivo(nodo* lista, nodo* nuevoNodo){
    if(lista == NULL){
        lista = nuevoNodo;
    }else{
        lista-> siguiente = agregarFinalRecursivo(lista->siguiente, nuevoNodo);
    }
    return lista;
}
//c)
nodo* archivoALista(char archivo[], nodo* lista){
    FILE * arch = fopen(archivo, "r");
    stPersona auxPersona;
    nodo* auxNodo;
    if(arch){
        while(fread(&auxPersona, sizeof(stPersona), 1, arch) > 0){
            auxNodo = crearNodo(auxPersona);
            lista = agregarFinalRecursivo(lista, auxNodo);
        }
    }
    return lista;
}

void mostrarUnaPersona(stPersona aux){
    printf("\nLegajo...............: %d", aux.legajo);
    printf("\nNombre...............: %s", aux.nombre);
    printf("\nApellido.............: %s", aux.apellido);
    printf("\nDNI..................: %s", aux.dni);
    printf("\nEdad.................: %d", aux.edad);
    printf("\nGenero...............: %s", (aux.genero=='m')?"Masculino":"Femenino");
    printf("\nMaterias Aprobadas...: %d", aux.cantMateriasAprobadas);
    printf("\npromedioSinAplazos...: %f", aux.promedioSinAplazos);
    printf("\npromedioConAplazos...: %f", aux.promedioConAplazos);
    printf("\n\n");
}
//2)
void mostrarLista(nodo* lista){
    if(lista == NULL){
        printf("\n");
    }else{
        mostrarUnaPersona(lista->dato);
        mostrarLista(lista-> siguiente);
    }
}

//3 a)
int cantEstudiantes(nodo* lista){
    int rta = 0;
    if(lista == NULL){
        rta = rta + 0;
    }else{
        rta = cantEstudiantes(lista-> siguiente);
        rta = rta + 1;
    }
    return rta;
}
// b)
int conAplazos(nodo* lista, float aplazo){
    int rta = 0;
    if(lista){
        if(lista-> dato.promedioConAplazos < aplazo){
            rta = 1 + conAplazos(lista-> siguiente, aplazo);
        }else{
            rta = conAplazos(lista-> siguiente, aplazo);
        }
    }
    return rta;
}
// c)
float porcentaje(nodo* lista, float valor){
    int total = cantEstudiantes(lista);
    int aplazados = (lista, valor);
    float rta = (float)(aplazados*100)/total;

    return rta;
}
//4)
//a)
int mayorPromedio(nodo* lista){
    int legajo = lista->dato.legajo;
    float nota = lista->dato.promedioSinAplazos;

    while(lista){
        if(lista->dato.promedioSinAplazos > nota){
            nota = lista->dato.promedioSinAplazos;
            legajo = lista->dato.legajo;
        }
        lista = lista-> siguiente;
    }

    return legajo;
}
//b)
stPersona eliminarPorLegajo(nodo** lista, int legajo){
    stPersona estudiante;
    if(*lista){
        if((*lista)->dato.legajo == legajo){ // 1er nodo
            estudiante = (*lista)->dato;
            nodo* aux = (*lista);
            (*lista) = (*lista)-> siguiente;
            free(aux);
        }else{ // es porque no es el 1ero
            nodo* anterior = (*lista);
            nodo* seguidora = (*lista)->siguiente;
            while(seguidora && seguidora->dato.legajo != legajo){
                anterior = seguidora;
                seguidora = seguidora->siguiente;
            }
            if(seguidora){
                estudiante = seguidora->dato;
                nodo* aux = seguidora;
                anterior-> siguiente = seguidora-> siguiente; // conexion entre el anterior y el nodo que le sigue al borrado
                free(aux);
            }
        }
    }
    return estudiante;
}
//c)
int pasarTop10(nodo* lista, stPersona Array[], int dim){
    int validos = 0;
    stPersona personaAux;
    int legajoAux;
    while(lista && validos < dim){
        legajoAux = mayorPromedio(lista);
        personaAux = eliminarPorLegajo(&lista, legajoAux);
        Array[validos] = personaAux;
        validos++;
    }
    return validos;
}

void mostrarArray(stPersona Array[], int validos, int i){
    if(validos == 0){
        printf("\n");
    }else{
        mostrarArray(Array, validos-1, i+1);
        mostrarUnaPersona(Array[i]);
    }
}

nodo* agregarAlPrincipio(nodo* lista, nodo* nuevoNodo){
    if(lista == NULL){
        lista = nuevoNodo;
    }else{
        nuevoNodo-> siguiente = lista;
        lista = nuevoNodo;
    }
    return lista;
}
