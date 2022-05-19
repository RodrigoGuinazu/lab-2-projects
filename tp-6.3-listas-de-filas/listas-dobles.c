#include "listas-dobles.h"

nodoDoble* inicLista(){
    return NULL;
}

nodoDoble* crearNodo(stAnimal animal){
    nodoDoble* aux = (nodoDoble*) malloc(sizeof(nodoDoble));
    aux-> dato = animal;
    aux-> anterior = NULL;
    aux-> siguiente = NULL;

    return aux;
}

void mostrarUnAnimal(stAnimal dato){
    printf("\n**********************************************************************");
    printf("\nNombre..............................................: %s", dato.nombreAnimal);
    printf("\nCantidad............................................: %d", dato.cantidad);
    printf("\nHabitat (1 = Selva; 2 = Savana; 3 = Bosque; 4 = Mar): %d", dato.habitat);
    printf("\n**********************************************************************\n\n");
}

void mostrarLista(nodoDoble* lista){
    if(lista){
        nodoDoble* seguidora = lista; // copia de seguridad

        printf("\n**********************************FILA*******************************************\n");
        while(seguidora){
            mostrarUnAnimal(seguidora->dato);
            seguidora = seguidora-> siguiente; // me muevo hacia el siguiente nodo en la lista
        }
        printf("\n**********************************************************************************\n");
    }else{
        printf("\nLa lista esta vacia!\n");
    }
}

nodoDoble* agregarAlFinal(nodoDoble* lista, nodoDoble* nuevoNodo){
    if(lista == NULL){
        lista = nuevoNodo;
    }else{
        nodoDoble* ultimo = buscarElUltimo(lista);
        nuevoNodo-> anterior = ultimo; /// enlazamos el anterior del nuevoNodo con el ultimo nodo que habia en la lista antes de agregar el nuevoNodo (nueva linea)
        ultimo-> siguiente = nuevoNodo; // el ultimo nodo de la lista ahora apunta hacia el nuevo nodo
    }
    return lista; // Se retorna la lista ya que hay que tener en cuenta que en el caso de que el primer primer if sea verdadero debemos retornarla, en el resto de los casos aunque trabajemos sobre el aux los nodos de la lista van a quedar modificados
}

nodoDoble* buscarElUltimo(nodoDoble* lista){
    nodoDoble* ultimo = lista; // de entrada lo igualamos a lista, ya que si la lista es NULL retornamos eso
    if(ultimo){
        while(ultimo-> siguiente){ // hasta llegar al final
            ultimo = ultimo-> siguiente; // me muevo hacia el siguiente nodo en la lista
        }
    }
    return ultimo;
}

int listaVacia(nodoDoble* lista){
    if(lista == NULL){
        return 1;
    }else{
        return 0;
    }
}
