#include "arboles.h"

nodoArbol* inicArbol(){
    return NULL;
}

nodoArbol* crearNodoArbol(persona dato){
    nodoArbol* aux = malloc(sizeof(nodoArbol));

    aux-> dato = dato;
    aux-> izq = NULL;
    aux-> der = NULL;

    return aux;
}

nodoArbol* insertar(nodoArbol* arbol, persona dato){
    if(arbol == NULL){
        arbol = crearNodoArbol(dato);
    }else{
        if(dato.legajo > arbol-> dato.legajo){
            arbol-> der = insertar(arbol-> der, dato);
        }else{
            arbol-> izq = insertar(arbol-> izq, dato);
        }
    }
    return arbol;
}

nodoArbol* buscarNodo(nodoArbol* arbol, persona dato){
    nodoArbol* rta = NULL;
    if(arbol){
        if(dato.legajo == arbol-> dato.legajo){
            rta = arbol;
        }else{
            if(dato.legajo > arbol-> dato.legajo){
                rta = buscarNodo(arbol-> der, dato);
            }else{
                rta = buscarNodo(arbol-> izq, dato);
            }
        }
    }
    return rta;
}

persona cargarPersona(){
    persona aux;
    printf("\nIngrese el Legajo: ");
    scanf("%d", &aux.legajo);
    printf("\nIngrese el Nombre: ");
    fflush(stdin);
    gets(&aux.nombre);
    printf("\nIngrese la edad: ");
    scanf("%d", &aux.edad);

    return aux;
}

void mostrarUnaPersona(persona dato){
    printf("\n*******************************");
    printf("\nLegajo...: %d", dato.legajo);
    printf("\nNombre...: %s", dato.nombre);
    printf("\nEdad.....: %d", dato.edad);
    printf("\n*******************************\n");
}

void preOrder(nodoArbol* arbol){
    if(arbol){
        mostrarUnaPersona(arbol-> dato);
        preOrder(arbol-> izq);
        preOrder(arbol-> der);
    }
}

void inOrder(nodoArbol* arbol){
    if(arbol){
        inOrder(arbol-> izq);
        mostrarUnaPersona(arbol-> dato);
        inOrder(arbol-> der);
    }
}

void postOrder(nodoArbol* arbol){
    if(arbol){
        postOrder(arbol-> izq);
        postOrder(arbol-> der);
        mostrarUnaPersona(arbol-> dato);
    }
}

nodoS* inicLista(){
    return NULL;
}

nodoS* crearNodo(persona dato){
    nodoS* aux = (nodoS*) malloc(sizeof(nodoS));

    aux-> dato = dato;
    aux-> siguiente = NULL;

    return aux;
}

nodoS* insertarEnListaAlFinal(nodoS* lista, nodoS* nuevoNodo){
    if(lista == NULL){
        lista = nuevoNodo;
    }else{
        nodoS* aux = lista;
        if(aux){
            while(aux-> siguiente){
                aux = aux-> siguiente;
            }
        }
        aux-> siguiente = nuevoNodo;
    }
    return lista;
}

nodoS* copiarALista(nodoArbol* arbol, nodoS* lista){
    if(arbol){
        lista = insertarEnListaAlFinal(lista, crearNodo(arbol-> dato)); // preOrder
        lista = copiarALista(arbol-> izq, lista);
        lista = copiarALista(arbol-> der, lista);
    }
    return lista;
}

void mostrarLista(nodoS* lista){
    if(lista){
        printf("\n**********************************LISTA*******************************************\n");
        while(lista){
            mostrarUnaPersona(lista-> dato);
            lista = lista-> siguiente;
        }
        printf("\n**********************************************************************************\n");
    }else{
        printf("\nLa lista esta vacia!\n");
    }
}

nodoArbol* buscarPorLegajo(nodoArbol* arbol, int legajo){  // como el arbol esta ordenado por el legajo tengo que ir recorriendo segun el nro de legajo
    nodoArbol* rta = NULL;
    if(arbol){
        if(legajo == arbol-> dato.legajo){
            rta = arbol;
        }else{
            if(legajo > arbol-> dato.legajo){ // voy evaluando si voy para la derecha o la izquierda
                rta = buscarPorLegajo(arbol-> der, legajo);
            }else{
                rta = buscarPorLegajo(arbol-> izq, legajo);
            }
        }
    }
    return rta;
}

nodoArbol* buscarPorNombre(nodoArbol* arbol, char nombre[]){ // como el arbol esta ordenado por el legajo tengo que recorrer todo el arbol
    nodoArbol* rta = NULL;
    if(arbol){
        if(strcmpi(nombre, arbol-> dato.nombre) == 0){
            rta = arbol;
        }else{
            rta = buscarPorNombre(arbol-> izq, nombre);
            if(rta == NULL){ // en caso de que lo haya encontrado en el lado izquierdo me ahorro recorrer el lado derecho
                rta = buscarPorNombre(arbol-> der, nombre);
            }
        }
    }
    return rta;
}

int esHoja(nodoArbol* arbol){
    if(arbol-> izq == NULL && arbol-> der == NULL){
        return 1;
    }else{
        return 0;
    }
}

int mayor(int izq, int der){
    int rta = 0;
    if(izq > der){
        rta = izq;
    }else{
        rta = der;
    }
    return rta; // devuelve la altura del lado izquierdo o del derecho
}

int alturaDelArbol(nodoArbol* arbol){
    int rta = 0;
    if(arbol){
        rta = 1 + mayor(alturaDelArbol(arbol-> izq), alturaDelArbol(arbol-> der));
        // sumamos 1 ya que tenemos que tener en cuenta la raiz, despues a eso le sumamos la cant de niveles del lado mas alto
    }
    return rta;
}

int contarNodos(nodoArbol* arbol){
    int rta = 0;
    if(arbol){
        rta = 1 + contarNodos(arbol-> izq) + contarNodos(arbol-> der);
    }
    return rta;
}

int contarHojas(nodoArbol* arbol){
    int rta = 0;
    if(arbol){
        if(esHoja(arbol)){
            rta = 1 + contarHojas(arbol-> izq) + contarHojas(arbol-> der);
        }else{
            rta = contarHojas(arbol-> izq) + contarHojas(arbol-> der);
        }
    }
    return rta;
}

nodoArbol* borrarArbol(nodoArbol* arbol){
    if(arbol){
        if(esHoja(arbol)){
            nodoArbol* aux = arbol;
            free(aux);
            arbol = NULL; // como la otra vuelta recursiva espera a un arbol, si solo lo libero estaria rompiedo la funcion, por eso debo devolver un NULL
        }else{
            arbol-> izq = borrarArbol(arbol-> izq);
            arbol-> der = borrarArbol(arbol-> der);
            if(esHoja(arbol)){ // tengo que comparar una vez mas ya que, a la vuelta de la ultima iteracion recursiva, quedara la raiz sola, convirtiendose en una hoja
                nodoArbol* aux = arbol;
                free(aux);
                arbol = NULL;
            }
        }
    }
    return arbol;
}

nodoArbol* borrarNodoArbol(nodoArbol* arbol, int legajo){
    if(arbol){
        if(legajo > arbol-> dato.legajo){ // en caso de que el legajo a buscar sea mayor que la raiz busca hacia la derecha
            arbol-> der = borrarNodoArbol(arbol-> der, legajo);
        }else if(legajo < arbol-> dato.legajo){ // en caso de que el legajo a buscar sea menor que la raiz busca hacia la izquierda
            arbol-> izq = borrarNodoArbol(arbol-> izq, legajo);
        }else if(legajo == arbol-> dato.legajo){ /// una vez que encontramos el legajo
            if(arbol-> izq){ // si el nodo que encontramos tiene un hijo a la izquierda y/o derecha
                arbol-> dato = (nodoMasDer(arbol-> izq))-> dato; // el nodo a borrar ahora va ser el nodo mas grande del lado izquierdo (el mayor de los menores)

                arbol-> izq = borrarNodoArbol(arbol-> izq, arbol-> dato.legajo); // ahora lo que hace es buscar el nodo que subimos en la linea anterior y lo borramos del arbol
            }else if(arbol-> der){  /// si el nodo que encontramos tiene un hijo a la derecha
                arbol-> dato = (nodoMasIzq(arbol-> der))-> dato; // el nodo a borrar ahora va ser el nodo mas pequeno del lado derecho (el menor de los mayores)

                arbol-> der = borrarNodoArbol(arbol-> der, arbol-> dato.legajo); // ahora lo que hace es buscar el nodo que subimos en la linea anterior y lo borramos del arbol
            }else{ /// En caso de que el nodo sea Hoja
                free(arbol);
                arbol = NULL;
            }
        }
    }
    return arbol;
}

nodoArbol* nodoMasIzq(nodoArbol* arbol){ // devuelve el nodo en el extremo izquierdo del arbol
    if(arbol-> izq){
        arbol = nodoMasIzq(arbol-> izq);
    }
    return arbol; // si el arbol esta vacio retorna NULL
}

nodoArbol* nodoMasDer(nodoArbol* arbol){ // devuelve el nodo en el extremo derecho del arbol
    if(arbol-> der){
        arbol = nodoMasDer(arbol-> der);
    }
    return arbol; // si el arbol esta vacio retorna NULL
}
