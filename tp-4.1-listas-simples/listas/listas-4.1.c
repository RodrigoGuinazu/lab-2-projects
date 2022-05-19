#include "listas-4.1.h"

void invertirLista(nodo** lista){
    nodo* seguidora = *lista;
    nodo* invertida;
    inicLista(&invertida);
    nodo* aux;
    while(seguidora){
        crearNodo(seguidora-> num, &aux);
        agregarAlPpio(aux, &invertida);
        seguidora = seguidora-> siguiente;
    }
    *lista = invertida;
}

nodo* ultimoNodo(nodo* lista, nodo* ultimo){
    while(lista-> siguiente){
        lista = lista-> siguiente; // itero hasta llegar al final de la lista
    }
    ultimo = lista;

    return ultimo;
}

nodo* intercalarListas(nodo* lista1, nodo* lista2, nodo* listaFinal){
    nodo* aux;
    while(lista1 && lista2){
        // comparar elementos
        if(lista1-> num < lista2-> num){
            aux = lista1;             // aux apunta a lista
            lista1 = lista1->siguiente; // ahora lista apunta al siguiente
            aux->siguiente=NULL;            //desvinculo el nodo aux de la lista
            listaFinal = agregarAlFinal(aux, listaFinal);
        }else{
            aux = lista2;
            lista2 = lista2->siguiente;
            aux->siguiente=NULL;
            listaFinal = agregarAlFinal(aux, listaFinal);
        }
    }
    if(lista1){
        listaFinal = agregarAlFinal(lista1, listaFinal);
        // tener en cuenta si una de las listas todavia tiene elementos despues del while
        // Solo haria falta conectar el nodo en el quedo suspendido (y todos los nodos que le sigan) despues del while y conectarlo con la lista intercalada
    }else if(lista2){
        listaFinal = agregarAlFinal(lista2, listaFinal);
        // tener en cuenta si una de las listas todavia tiene elementos despues del while
        // Solo haria falta conectar el nodo en el quedo suspendido (y todos los nodos que le sigan) despues del while y conectarlo con la lista intercalada
    }
    return listaFinal;
}

nodo* agregarAlFinal(nodo* nuevoNodo, nodo* lista){
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
    return lista;
}

void cargarListaEnOrden(nodo** lista){
    char control = 's';

    int aux;
    nodo* nuevoNodo;

    while(control=='s'){
        printf("\nIngrese un numero: \n");
        scanf("%d", &aux);
        crearNodo(aux, &nuevoNodo);
        insertarEnOrden(lista, nuevoNodo);

        printf("\nIngresar otro?\n");
        fflush(stdin);
        scanf("%c", &control);
    }
}

void cargarListaAlPpio(nodo** lista){
    char control = 's';

    int aux;
    nodo* nuevoNodo;

    while(control=='s'){
        printf("\nIngrese un numero: \n");
        scanf("%d", &aux);
        crearNodo(aux, &nuevoNodo);
        agregarAlPpio(nuevoNodo, lista);

        printf("\nIngresar otro?\n");
        fflush(stdin);
        scanf("%c", &control);
    }
}

int nodoABuscar(nodo** lista, int num){
    int flag = 0;
    nodo* aux = *lista;

    if(*lista){
        while(aux && aux-> num != num){
            aux = aux-> siguiente;
        }
        if(aux){
            flag = 1;
        }
    }
    return flag;
}

void pasarArchivoAListaOrdenado(FILE * archivo, nodo** lista){
    int numero;
    nodo* nuevoNodo;
    if(archivo){
        while(fread(&numero, sizeof(int), 1, archivo) > 0){
            crearNodo(numero, &nuevoNodo);
            insertarEnOrden(lista, nuevoNodo);
        }
    }
    cerrarArchivo(archivo);
}

void insertarEnOrden(nodo** lista, nodo* nuevoNodo){
    if(*lista == NULL){ // en caso de que la lista este vacia
        *lista = nuevoNodo;
    }else{
        if((*lista)-> num > nuevoNodo-> num){ // este caso seria que el dato que queremos ingresar es menor que el primer dato de la lista
            nuevoNodo-> siguiente = *lista; // el nodo que ingresa ahora apunta al primer nodo de la lista
            *lista = nuevoNodo; // la lista comienza desde el nuevoNodo ya que quedo en la primera posicion de la lista
        }else{ // se encuentra en otra posicion que no sea la primera
            nodo* anterior = *lista; // necesitamos el anterior y el siguiente, ya que una vez que borremos el nodo que esta en el medio de estos dos hay que conectarlos entre ellos
            nodo* seguidora = (*lista)-> siguiente; // necesitamos el anterior y el siguiente, ya que una vez que borremos el nodo que esta en el medio de estos dos hay que conectarlos entre ellos

            while(seguidora != NULL && (seguidora-> num) < (nuevoNodo-> num)){ // verifico que seguidora no sea NULL y que el dato de seguidora sea menor al del nuevoNodo
                anterior = seguidora;             //hasta que no se cumpla la condicion del while muevo el anterior y la seguidora
                seguidora = seguidora-> siguiente;
            }
            nuevoNodo-> siguiente = seguidora; // el nuevo nodo queda apuntando hacia donde quedo siguiente
            anterior-> siguiente = nuevoNodo; // el nuevo nodo es apuntado por donde quedo anterior
        }
    }
}

void pasarArchivoALista(FILE * archivo, nodo** lista){
    int numero;
    nodo* nuevoNodo;
    if(archivo){
        while(fread(&numero, sizeof(int), 1, archivo) > 0){
            crearNodo(numero, &nuevoNodo);
            agregarAlPpio(nuevoNodo, lista);
        }
    }
    cerrarArchivo(archivo);
}

void agregarAlPpio(nodo* nuevoNodo, nodo** lista){
    if(*lista == NULL){
        (*lista) = nuevoNodo; // en caso de que no haya nodos en la lista, el puntero lista guarda la direccion de memoria del nuevoNodo
    }else{
        nuevoNodo-> siguiente = (*lista); // el nuevo nodo queda apuntando a lo que previamente se encontraba en primer lugar de la lista
        (*lista) = nuevoNodo; // el primer nodo de la lista ahora seria el nuevoNodo que agregamos recien
    }
}

void mostrarLista(nodo* lista){
    if(lista){
        nodo* seguidora = lista;

        printf("\n**********************************LISTA*******************************************\n");
        while(seguidora){
            printf(" %d", seguidora-> num);
            seguidora = seguidora-> siguiente; // me muevo hacia el siguiente nodo en la lista
        }
        printf("\n**********************************************************************************\n");
    }else{
        printf("\nLa lista esta vacia!\n");
    }
}

void inicLista(nodo** lista){
    (*lista) = NULL;
}

void crearNodo(int numero, nodo** nuevoNodo){
    *nuevoNodo = (nodo*) malloc(sizeof(nodo));
    (*nuevoNodo)-> num = numero;
    (*nuevoNodo)-> siguiente = NULL;
}

FILE * abrirArchivo(char archivoNumeros[]){
    FILE * archivo = fopen(archivoNumeros, "rb");

    return archivo;
}

void cerrarArchivo(FILE * archivo){
    fclose(archivo);
}
