#include "funciones-recursivas.h"

// Funciones Recursivas

void mostrarListaRecursiva(nodo* lista){
    if(lista == NULL){ // Condicion de corte
        printf("\n*****************************************\n");
    }else{
        // en caso de que querramos imprirla en orden ponemos el printf arriba de la llamada recursiva
        mostrarListaRecursiva(lista-> siguiente); /// Llamada recursiva
        printf(" %d", lista-> num); // El printf va debajo de la llamada recursiva ya que la consigna pide que se imprima de atras para delante
    }
}

int sumarListaRecursiva(nodo* lista, int suma){
    if(lista == NULL){
        suma = suma + 0;
    }else{
        int actual = lista-> num;
        suma = actual + sumarListaRecursiva(lista-> siguiente, suma);
    }
    return suma;
}

void mostrarPosicionPar(nodo* lista){
    if(lista){
        lista = lista-> siguiente; // avanzo ya que el primero nodo se que no lo tengo que mostrar, y como despues le voy a pasar lista-> siguiente se que tengo que avanzar otra vez para que quede en una posicion par

        if(lista){
            mostrarPosicionPar(lista-> siguiente);
            printf(" %d", lista-> num); // lo retorno a la vuelta ya que hago lo mismo con la funcion de mostrarListaRecursiva
        }
    }
}

nodo* borrarNodoRecursivo(nodo* lista, int dato){ // em caso de que el nodo a borrar no este en la lista retornamos directamente la misma lista que entro por parametro
    if(lista){
        if(lista-> num == dato){
            nodo* aBorrar = lista; // guardo el dato que quiero borrar en un nodo para luego borrarlo
            lista = lista-> siguiente; // dejo la lista apuntando al siguiente, asi lo retorno y hacemos el bypass con la linea 43
            free(aBorrar);
        }else{
            lista-> siguiente = borrarNodoRecursivo(lista-> siguiente, dato);
            // lista-> siguiente sera igual a lo que devuelva la llamada recursiva (que va ser una lista), entonces cuando insertemos el nodo en la parte de arriba ya recibimos la lista apuntando al aInsertar
        }
    }
    return lista;
}

nodo* insertarEnListaCreciente(nodo* lista, nodo* aInsertar){
    if(lista == NULL){ // para cunado la lista esta vacia, o se llego al NULL del final
        lista = aInsertar;
    }else{
        if(lista-> num < aInsertar-> num){ // aInsertar sea mayor que el de la lista ya que la lista la muestro invertida
            aInsertar-> siguiente = lista; // Apunto aInsertar con lo que vale lista
            lista = aInsertar; // Dejo la lista apuntando a aInsertar, y este va quedar apuntado por la linea 58
        }else{
            lista-> siguiente = insertarEnListaCreciente(lista-> siguiente, aInsertar);
        }
    }
    return lista;
}

nodo* invertirLista(nodo* lista){ // uso esta funicon para solo pasar por parametro a la lista sin neecesidad de pasar NULL
    nodo* anterior = inicLista(); // anterior tiene que valer NULL cuando ejecutemos la funcion
    lista = invertirListaAux(lista, anterior);
    return lista;
}

nodo* invertirListaAux(nodo* lista, nodo* anterior){
    if(lista == NULL){ // chequeo que la lista siga teniendo nodos, cuando finalize de recorrer la lista esta quedara vacia
        lista = anterior; // ahora lista a anterior, la cual a su vez apunta a la seguidilla de nodos ya invertidos
    }else{
        nodo* sig = lista-> siguiente; // guardo el valor del siguiente en sig
        lista-> siguiente = anterior; // lista-> siguiente guarda el valor de anterior (por parametro el primer valor de anterior es NULL, luego ira cambiando a medida que avanze la recursividad)

        lista = invertirListaAux(sig, lista); // lista ahora apuntara al siguiente, y el anterior apuntara a lo que valia la lista del parametro (en la primera ejecucion anterior que es NULL queda apuntado por el valor de la lista del parametro)
    }
    return lista;
}
