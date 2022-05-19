#include "listas-puntero-simple.h"

nodo* inicLista(){
    return NULL;
}

Persona cargarPersona(){
    Persona aux;

    printf("\nNombre de la persona: ");
    fflush(stdin);
    gets(aux.nombre);
    printf("\nEdad: ");
    scanf("%d", &aux.edad);

    return aux;
}

nodo* crearNodo(Persona nuevaPersona){
    nodo* aux = (nodo*) malloc(sizeof(nodo));
    aux-> dato = nuevaPersona;
    aux-> siguiente = NULL;

    return aux;
}

void mostrarPersona(Persona aux){
    printf("\nNombre: %s\n", aux.nombre);
    printf("Edad: %d\n", aux.edad);
}

void mostrarLista(nodo* lista){
    if(lista){
        nodo* seguidora = lista; // copia de seguridad

        printf("\n**********************************LISTA*******************************************\n");
        while(seguidora){
            mostrarPersona(seguidora-> dato);
            seguidora = seguidora-> siguiente; // me muevo hacia el siguiente nodo en la lista
        }
        printf("\n**********************************************************************************\n");
    }else{
        printf("\nLa lista esta vacia!\n");
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

nodo* insertarEnOrden(nodo* lista, nodo* nuevoNodo){
    if(lista == NULL){ // en caso de que la lista este vacia
        lista = nuevoNodo;
    }else{
        if(lista-> dato.edad > nuevoNodo-> dato.edad){ // este caso seria que el dato que queremos ingresar es menor que el primer dato de la lista
            nuevoNodo-> siguiente = lista; // el nodo que ingresa ahora apunta al primer nodo de la lista
            lista = nuevoNodo; // la lista comienza desde el nuevoNodo ya que quedo en la primera posicion de la lista
        }else{ // se encuentra en otra posicion que no sea la primera
            nodo* anterior = lista; // necesitamos el anterior y el siguiente, ya que una vez que borremos el nodo que esta en el medio de estos dos hay que conectarlos entre ellos
            nodo* seguidora = lista-> siguiente; // necesitamos el anterior y el siguiente, ya que una vez que borremos el nodo que esta en el medio de estos dos hay que conectarlos entre ellos

            while(seguidora != NULL && (seguidora-> dato.edad) < (nuevoNodo-> dato.edad)){ // verifico que seguidora no sea NULL y que el dato de seguidora sea menor al del nuevoNodo
                anterior = seguidora;             //hasta que no se cumpla la condicion del while muevo el anterior y la seguidora
                seguidora = seguidora->siguiente;
            }
            nuevoNodo-> siguiente = seguidora; // el nuevo nodo queda apuntando hacia donde quedo siguiente
            anterior-> siguiente = nuevoNodo; // el nuevo nodo es apuntado por donde quedo anterior
        }
    }
    return lista;
}

nodo* eliminarDeLaLista(nodo* lista, int edad){
    if(lista){ // verifico que la lista no sea NULL
        if(lista-> dato.edad == edad){ // en caso de que el dato a eliminar sea el primero en la lista
            nodo* aBorrar = lista; // guardo la direccion de memoria del elemento a borrar
            lista = lista-> siguiente; // La lista ahora queda apuntando al siguiente nodo, haciendolo el primer elemento de la lista
            free(aBorrar); // libera el espacio de memoria del nodo que queriamos borrar
        }else{ // en caso de que el elemento no sea el primero en la lista
            nodo* anterior = lista; // necesitamos el anterior y el siguiente, ya que una vez que borremos el nodo que esta en el medio de estos dos hay que conectarlos entre ellos
            nodo* seguidora = lista-> siguiente; // necesitamos el anterior y el siguiente, ya que una vez que borremos el nodo que esta en el medio de estos dos hay que conectarlos entre ellos

            while(seguidora != NULL && seguidora-> dato.edad != edad){ // verifico que seguidora no sea NULL y que el dato de seguidora sea desigual al del nuevoNodo
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

nodo* buscarElUltimo(nodo* lista){
    nodo* ultimo = lista; // de entrada lo igualamos a lista, ya que si la lista es NULL retornamos eso
    if(ultimo){
        while(ultimo-> siguiente){ // hasta llegar al final
            ultimo = ultimo-> siguiente; // me muevo hacia el siguiente nodo en la lista
        }
    }
    return ultimo;
}

nodo* nodoABuscar(nodo* lista, int edad){
    nodo* aux = lista;

    if(lista){

        while(aux && aux-> dato.edad != edad){
            aux = aux-> siguiente;
        }
    }
    return aux;
}

nodo* borrarListaCompleta(nodo* lista){
    nodo* aBorrar;
    printf("\nVaciando la lista...\n");
    while(lista != NULL){ // mientras la lista tenga algo
        aBorrar = lista; // aBorrar ahora apunta a donde apunta la lista
        lista = lista-> siguiente; // lista ahora apunta al siguiente nodo
        free(aBorrar); // libero el espacio
    }

    return lista;
}

nodo* cargarListaAlPpio(nodo* lista){
    char control = 's';

    Persona aux;
    nodo* nuevoNodo;

    while(control=='s'){
        aux = cargarPersona();
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

    Persona aux;
    nodo* nuevoNodo;

    while(control=='s'){
        aux = cargarPersona();
        nuevoNodo = crearNodo(aux);
        lista = agregarAlFinal(lista, nuevoNodo);

        printf("\nIngresar otro?\n");
        fflush(stdin);
        scanf("%c", &control);
    }
    return lista;
}

nodo* cargarListaEnOrden(nodo* lista){
    char control = 's';

    Persona aux;
    nodo* nuevoNodo;

    while(control=='s'){
        aux = cargarPersona();
        nuevoNodo = crearNodo(aux);
        lista = insertarEnOrden(lista, nuevoNodo);

        printf("\nIngresar otro?\n");
        fflush(stdin);
        scanf("%c", &control);
    }
    return lista;
}
