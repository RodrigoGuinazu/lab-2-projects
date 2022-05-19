#include "arboles.h"

nodoArbol* inicArbol(){ // igual a listas
    return NULL;
}

nodoArbol* crearNodoArbol(int dato){ // igual a listas
    nodoArbol* aux = malloc(sizeof(nodoArbol));

    aux-> dato = dato;
    aux-> izq = NULL;
    aux-> der = NULL;

    return aux;
}

nodoArbol* insertar(nodoArbol* arbol, int dato){
    if(arbol == NULL){ // condicion de corte
        arbol = crearNodoArbol(dato); // solucion trivial, el dato siempre se va insertar en esta linea, dependiendo donde quedo apuntando el arbol con las llamadas anteriores
    }else{
        if(dato > arbol-> dato){ // evaluo que camino debo tomar, si el dato a insertar es mayor voy a la derecha, si es menor a la izquierda
            arbol-> der = insertar(arbol-> der, dato); // acercamiento hacia la condicion de corte
        }else{
            arbol-> izq = insertar(arbol-> izq, dato); // acercamiento hacia la condicion de corte
        }
    }
    return arbol;
}

nodoArbol* buscarNodo(nodoArbol* arbol, int dato){  // busqueda binaria, voy descartando la mitad de los datos a medida que llamo a la recursion, ya que si se que el numero que busco es menor a la raiz ya puedo descartar todo lo que baje hacia la derecha en el arbol, y asi con cada llamada que haga
    nodoArbol* rta = NULL; // si no se encuentra el dato inicializamos la rta en NULL para reornarlo, en caso de que se encuentre lo igualaremos al nodo que buscamos
    if(arbol != NULL){ // condicion de corte
        if(dato == arbol-> dato){
            rta = arbol; // rta ahora guarda el nodo con el dato que pasamos por parametro
        }else{
            if(dato > arbol-> dato){ // evaluo que camino debo tomar, si el dato a buscar es mayor voy a la derecha, si es menor a la izquierda
                rta = buscarNodo(arbol-> der, dato); // acercamiento hacia la condicion de corte
            }else{
                rta = buscarNodo(arbol-> izq, dato); // acercamiento hacia la condicion de corte
            }
        }
    }
    return rta;
}

/// MOSTRAR UN ARBOL

void mostrarNodo(nodoArbol* nodo){
    printf(" %d ", nodo-> dato);
}

// preOrder => la raiz se muestra primero
void preOrder(nodoArbol* arbol){
    if(arbol){
        mostrarNodo(arbol);
        preOrder(arbol-> izq);
        preOrder(arbol-> der);
    }
}

// inOrder => la raiz se muestra en el medio
void inOrder(nodoArbol* arbol){
    if(arbol){
        inOrder(arbol-> izq);
        mostrarNodo(arbol);
        inOrder(arbol-> der);
    }
}

// postOrder => la raiz se muestra al final
void postOrder(nodoArbol* arbol){
    if(arbol){
        postOrder(arbol-> izq);
        postOrder(arbol-> der);
        mostrarNodo(arbol);
    }
}
