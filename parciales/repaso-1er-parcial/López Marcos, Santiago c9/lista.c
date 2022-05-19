#include "lista.h"
#include "persona.h"


nodo* crearNodo (stPersona dato)
{
    nodo* aux = (nodo*)malloc(sizeof(stPersona));
    aux->dato= dato;
    aux->siguiente = NULL;

    return aux;
}

nodo * inicLista ()
{
return NULL;
}

nodo* insertarEnOrden(nodo* lista, nodo* nuevoNodo){
    if(lista == NULL){
        lista = nuevoNodo;
    }else{
        if(lista->dato.apellido > nuevoNodo->dato.apellido){
            nuevoNodo-> siguiente = lista;
            lista = nuevoNodo;
        }else{
            nodo* anterior = lista;
            nodo* seguidora = lista-> siguiente;

            while(seguidora != NULL && (seguidora->dato.apellido) < (nuevoNodo->dato.apellido)){
                anterior = seguidora;
                seguidora = seguidora->siguiente;
            }
            nuevoNodo-> siguiente = seguidora;
            anterior-> siguiente = nuevoNodo;
        }
    }
    return lista;
}

nodo* archivoToList (char archivo[], nodo* lista)
{
    FILE* pArchi = fopen(archivo, "rb");
    nodo * nuevoNodo;
    stPersona aux;
    if(pArchi)
    {
        while(fread(&aux, sizeof(stPersona),1,pArchi)>0)
        {
            nuevoNodo = crearNodo(aux);
            lista = insertarEnOrden(lista, nuevoNodo);

        }
      fclose(pArchi);
    }
    return lista;
}

void mostrarLista(nodo* lista){
    if(lista){
        nodo* seguidora = lista;

        printf("\n\nTOPE ************************************************************************ BASE\n\n");
        while(seguidora){
            muestraUnaPersona(seguidora->dato);
            seguidora = seguidora-> siguiente;
        }
        printf("\n\nTOPE ************************************************************************ BASE\n\n");
    }else{
        printf("\nLa pila esta vacia!\n");
    }
}
