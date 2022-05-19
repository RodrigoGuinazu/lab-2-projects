#include "listas-puntero-doble.h"

void inicLista(nodo** lista){
    *lista = NULL;
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

void crearNodo(Persona nuevaPersona, nodo** nuevoNodo){
    *nuevoNodo = (nodo*) malloc(sizeof(nodo));
    (*nuevoNodo)-> dato = nuevaPersona;
    (*nuevoNodo)-> siguiente = NULL;
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

void agregarAlPpio(nodo* nuevoNodo, nodo** lista){
    if(*lista == NULL){
        *lista = nuevoNodo; // en caso de que no haya nodos en la lista, el puntero lista guarda la direccion de memoria del nuevoNodo
    }else{
        nuevoNodo-> siguiente = *lista; // el nuevo nodo queda apuntando a lo que previamente se encontraba en primer lugar de la lista
        *lista = nuevoNodo; // el primer nodo de la lista ahora seria el nuevoNodo que agregamos recien
    }
}

void agregarAlFinal(nodo* nuevoNodo, nodo** lista){
    if(*lista == NULL){
        *lista = nuevoNodo;
    }else{
        nodo* aux = *lista;
        if(aux){
            while(aux-> siguiente != NULL){
                aux = aux-> siguiente; // itero hasta llegar al final de la lista
            }
        }
        aux-> siguiente = nuevoNodo; // hago que el nodo que apuntaba a NULL previamente ahora apunte al nuevoNodo
    }
}

void insertarEnOrden(nodo** lista, nodo* nuevoNodo){
    if(*lista == NULL){ // en caso de que la lista este vacia
        *lista = nuevoNodo;
    }else{
        if((*lista)-> dato.edad > nuevoNodo-> dato.edad){ // este caso seria que el dato que queremos ingresar es menor que el primer dato de la lista
            nuevoNodo-> siguiente = *lista; // el nodo que ingresa ahora apunta al primer nodo de la lista
            *lista = nuevoNodo; // la lista comienza desde el nuevoNodo ya que quedo en la primera posicion de la lista
        }else{ // se encuentra en otra posicion que no sea la primera
            nodo* anterior = *lista; // necesitamos el anterior y el siguiente, ya que una vez que borremos el nodo que esta en el medio de estos dos hay que conectarlos entre ellos
            nodo* seguidora = (*lista)-> siguiente; // necesitamos el anterior y el siguiente, ya que una vez que borremos el nodo que esta en el medio de estos dos hay que conectarlos entre ellos

            while(seguidora != NULL && (seguidora-> dato.edad) < (nuevoNodo-> dato.edad)){ // verifico que seguidora no sea NULL y que el dato de seguidora sea menor al del nuevoNodo
                anterior = seguidora;             //hasta que no se cumpla la condicion del while muevo el anterior y la seguidora
                seguidora = seguidora->siguiente;
            }
            nuevoNodo-> siguiente = seguidora; // el nuevo nodo queda apuntando hacia donde quedo siguiente
            anterior-> siguiente = nuevoNodo; // el nuevo nodo es apuntado por donde quedo anterior
        }
    }
}

void eliminarDeLaLista(nodo** lista, int edad){
    if(*lista){ // verifico que la lista no sea NULL
        if((*lista)-> dato.edad == edad){ // en caso de que el dato a eliminar sea el primero en la lista
            nodo* aBorrar = *lista; // guardo la direccion de memoria del elemento a borrar
            *lista = (*lista)-> siguiente; // La lista ahora queda apuntando al siguiente nodo, haciendolo el primer elemento de la lista
            free(aBorrar); // libera el espacio de memoria del nodo que queriamos borrar
        }else{ // en caso de que el elemento no sea el primero en la lista
            nodo* anterior = *lista; // necesitamos el anterior y el siguiente, ya que una vez que borremos el nodo que esta en el medio de estos dos hay que conectarlos entre ellos
            nodo* seguidora = (*lista)-> siguiente; // necesitamos el anterior y el siguiente, ya que una vez que borremos el nodo que esta en el medio de estos dos hay que conectarlos entre ellos

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
}

void buscarElUltimo(nodo** lista, nodo** ultimo){
    *ultimo = *lista;
    if(*ultimo){
        while((*ultimo)-> siguiente){
            *ultimo = (*ultimo)-> siguiente;
        }
    }
}

void nodoABuscar(nodo** lista, int edad){
    nodo* aux = *lista;

    if(*lista){
        while(aux && aux-> dato.edad != edad){
            aux = aux-> siguiente;
        }
        if(aux){
            printf("\nResultado de la busqueda: \n");
            mostrarPersona(aux-> dato);
        }else{
            printf("\nEl nodo que buscas no existe en la lista\n");
        }
    }
}

void borrarListaCompleta(nodo** lista){
    if(*lista != NULL){ //  En caso de que la lista apunte a algo
        nodo* aBorrar = *lista; // guardo la direccion de memoria del elemento a borrar
        printf("\nVaciando la lista...\n");
        while(*lista != NULL){
            free(aBorrar); // libera el espacio de memoria del nodo que queriamos borrar
            aBorrar = *lista; // aBorrar ahora apunta a donde la lista apuntaba antes
            *lista = (*lista)-> siguiente; // lista ahora apunta al siguiente nodo
        }
        free(aBorrar); // Boraramos el ultimo ya que lista apuntaba a null pero el ultimo a borrar no se borro ya que no entro en el while anterior
    }else{
        printf("\nEsta lista ya se encuentra vacia\n");
    }
}

void cargarListaAlPpio(nodo** lista){
    char control = 's';

    Persona aux;
    nodo* nuevoNodo;

    while(control=='s'){
        aux = cargarPersona();
        crearNodo(aux, &nuevoNodo);
        agregarAlPpio(nuevoNodo, lista);

        printf("\nIngresar otro?\n");
        fflush(stdin);
        scanf("%c", &control);
    }
}

void cargarListaAlFinal(nodo** lista){
    char control = 's';

    Persona aux;
    nodo* nuevoNodo;

    while(control=='s'){
        aux = cargarPersona();
        crearNodo(aux, &nuevoNodo);
        agregarAlFinal(nuevoNodo, lista);

        printf("\nIngresar otro?\n");
        fflush(stdin);
        scanf("%c", &control);
    }
}

void cargarListaEnOrden(nodo** lista){
    char control = 's';

    Persona aux;
    nodo* nuevoNodo;

    while(control=='s'){
        aux = cargarPersona();
        crearNodo(aux, &nuevoNodo);
        insertarEnOrden(lista, nuevoNodo);

        printf("\nIngresar otro?\n");
        fflush(stdin);
        scanf("%c", &control);
    }
}
