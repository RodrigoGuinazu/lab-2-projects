#include "pilas-puntero-doble.h"

void pasarALista(nodo** lista, Pila* dada){
    Pila auxPila;
    inicPila(&auxPila);
    nodo* auxNodo;
    int auxNum;

    while(!pilaVacia(dada)){
        auxNum = desapilar(dada);
        apilar(&auxPila, auxNum);
        auxNodo = crearNodo(auxNum);
        *lista = agregarAlFinal(*lista, auxNodo);
    }
    while(!pilaVacia(&auxPila)){
        apilar(dada, desapilar(&auxPila));
    }
}

void inicPila(Pila* dada){
    *dada = inicLista();
}

void apilar(Pila* dada, int num){
    nodo* nuevoNodo = crearNodo(num);
    *dada = agregarAlPpio(*dada ,nuevoNodo);
}

void leer(Pila* dada){
    int num;
    printf("\nIngrese un numero: ");
    scanf("%d", &num);
    apilar(dada, num);
}

int desapilar(Pila* dada){
    int rta = -999;
    if(*dada){
        rta = (*dada)-> num;
        *dada = eliminarElPrimero(*dada);
    }else{
        printf("\nLa pila esta vacia, se retornara -999\n");
    }

    return rta;
}

int tope(Pila* dada){
    int rta = -999;
    if(*dada){
        rta = primerElemento(*dada);
        return rta;
    }else{
        printf("\nLa pila esta vacia, se retornara -999\n");
    }
    return rta;
}

int pilaVacia(Pila* dada){
    if(*dada == NULL){
        return 1;
    }else{
        return 0;
    }
}

void mostrar(Pila* dada){
    mostrarLista(*dada);
}
