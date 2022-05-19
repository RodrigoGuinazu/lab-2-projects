#include "listas-puntero-simple.h"

// CODIFICAR RETORNAR EL PRIMER DATO Y BORRAR EL 1ER NODO

void borrarMenores(nodo** lista){

}

int primerElemento(nodo* lista){
    int primero;
    nodo* primer = lista;
    primero = primer-> num;

    return primero;
}

nodo* eliminarElPrimero(nodo* lista){
    nodo* aBorrar = lista;
    lista = lista-> siguiente;
    free(aBorrar);

    return lista;
}

nodo* inicLista(){
    return NULL;
}

nodo* crearNodo(int num){
    nodo* aux = (nodo*) malloc(sizeof(nodo));
    aux-> num = num;
    aux-> siguiente = NULL;

    return aux;
}

void mostrarLista(nodo* lista){
    if(lista){
        nodo* seguidora = lista; // copia de seguridad

        printf("\n\nTOPE ************************************************************************ BASE\n\n");
        while(seguidora){
            printf(" %d", seguidora-> num);
            seguidora = seguidora-> siguiente; // me muevo hacia el siguiente nodo en la lista
        }
        printf("\n\nTOPE ************************************************************************ BASE\n\n");
    }else{
        printf("\nLa pila esta vacia!\n");
    }
}

nodo* agregarAlPpio(nodo* lista, nodo* nuevoNodo){
    if(lista == NULL){
        lista = nuevoNodo; // en caso de que no haya nodos en la lista, el puntero lista guarda la direccion de memoria del nuevoNodo
    }else{
        nuevoNodo-> siguiente = lista; // el nuevo nodo queda apuntando a lo que previamente se encontraba en primer lugar de la lista
        lista = nuevoNodo; // el primer nodo de la lista ahora seria el nuevoNodo que agregamos recien
    }
    return lista;
}

nodo* agregarAlFinal(nodo* lista, nodo* nuevoNodo){
    if(lista == NULL){
        lista = nuevoNodo;
    }else{
        nodo* aux = lista;
        if(aux){
            while(aux-> siguiente != NULL){
                aux = aux-> siguiente; // itero hasta llegar al final de la lista
            }
        }
        aux-> siguiente = nuevoNodo; // hago que el nodo que apuntaba a NULL previamente ahora apunte al nuevoNodo
    }
    return lista; // Se retorna la lista ya que hay que tener en cuenta que en el caso de que el primer primer if sea verdadero debemos retornarla, en el resto de los casos aunque trabajemos sobre el aux los nodos de la lista van a quedar modificados
}

nodo* eliminarDeLaLista(nodo* lista, int num){
    if(lista){ // verifico que la lista no sea NULL
        if(lista->num == num){ // en caso de que el dato a eliminar sea el primero en la lista
            nodo* aBorrar = lista; // guardo la direccion de memoria del elemento a borrar
            lista = lista-> siguiente; // La lista ahora queda apuntando al siguiente nodo, haciendolo el primer elemento de la lista
            free(aBorrar); // libera el espacio de memoria del nodo que queriamos borrar
        }else{ // en caso de que el elemento no sea el primero en la lista
            nodo* anterior = lista; // necesitamos el anterior y el siguiente, ya que una vez que borremos el nodo que esta en el medio de estos dos hay que conectarlos entre ellos
            nodo* seguidora = lista-> siguiente; // necesitamos el anterior y el siguiente, ya que una vez que borremos el nodo que esta en el medio de estos dos hay que conectarlos entre ellos

            while(seguidora != NULL && seguidora-> num != num){ // verifico que seguidora no sea NULL y que el dato de seguidora sea desigual al del nuevoNodo
                anterior = seguidora;             //hasta que no encuentro el dato muevo la pareja
                seguidora = seguidora->siguiente;
            }

            if(seguidora != NULL){ // si luego de iterar se encuentra lo que estamos buscando lo borramos
                anterior-> siguiente = seguidora-> siguiente; // hago la conceccion y ahora antes queda apuntando a lo que apuntaba siguiente, ya que siguiente lo vamos a eliminar de la lista
                free(seguidora); // el elemento que queremos borrar quedo almacenado en seguidora
            }else{
                printf("\nEl elemento que deseas borrar no existe en la lista\n");
            }
        }
    }
    return lista;
}

nodo* nodoABuscar(nodo* lista, int num){
    nodo* aux = lista;

    if(lista){

        while(aux && aux-> num != num){
            aux = aux-> siguiente;
        }
    }
    return aux;
}

nodo* borrarListaCompleta(nodo* lista){
    nodo* aBorrar;

    while(lista != NULL){ // mientras la lista tenga algo
        aBorrar = lista; // aBorrar ahora apunta a donde apunta la lista
        lista = lista-> siguiente; // lista ahora apunta al siguiente nodo
        free(aBorrar); // libero el espacio
    }

    return lista;
}

nodo* insertarEnOrden(nodo* lista, nodo* nuevoNodo){
    if(lista == NULL){ // en caso de que la lista este vacia
        lista = nuevoNodo;
    }else{
        if(lista-> num > nuevoNodo-> num){ // este caso seria que el dato que queremos ingresar es menor que el primer dato de la lista
            nuevoNodo-> siguiente = lista; // el nodo que ingresa ahora apunta al primer nodo de la lista
            lista = nuevoNodo; // la lista comienza desde el nuevoNodo ya que quedo en la primera posicion de la lista
        }else{ // se encuentra en otra posicion que no sea la primera
            nodo* anterior = lista; // necesitamos el anterior y el siguiente, ya que una vez que borremos el nodo que esta en el medio de estos dos hay que conectarlos entre ellos
            nodo* seguidora = lista-> siguiente; // necesitamos el anterior y el siguiente, ya que una vez que borremos el nodo que esta en el medio de estos dos hay que conectarlos entre ellos

            while(seguidora != NULL && (seguidora-> num) < (nuevoNodo-> num)){ // verifico que seguidora no sea NULL y que el dato de seguidora sea menor al del nuevoNodo
                anterior = seguidora;             //hasta que no se cumpla la condicion del while muevo el anterior y la seguidora
                seguidora = seguidora->siguiente;
            }
            nuevoNodo-> siguiente = seguidora; // el nuevo nodo queda apuntando hacia donde quedo siguiente
            anterior-> siguiente = nuevoNodo; // el nuevo nodo es apuntado por donde quedo anterior
        }
    }
    return lista;
}

nodo* cargarListaAlPpio(nodo* lista){
    char control = 's';

    int aux;
    nodo* nuevoNodo;

    while(control=='s'){
        printf("\nIngrese un numero entero: ");
        scanf("%d", &aux);
        nuevoNodo = crearNodo(aux);
        lista = agregarAlPpio(lista, nuevoNodo);

        printf("\nIngresar otro?\n");
        fflush(stdin);
        scanf("%c", &control);
    }
    return lista;
}

nodo* cargarListaAlFinal(nodo* lista){
    char control = 's';

    int aux;
    nodo* nuevoNodo;

    while(control=='s'){
        printf("\nIngrese un numero entero: ");
        scanf("%d", &aux);
        nuevoNodo = crearNodo(aux);
        lista = agregarAlFinal(lista, nuevoNodo);

        printf("\nIngresar otro?\n");
        fflush(stdin);
        scanf("%c", &control);
    }
    return lista;
}
