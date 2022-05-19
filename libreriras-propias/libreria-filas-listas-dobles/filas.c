#include "filas.h"

void inicFila(Fila* dada){
    dada-> inicio = inicLista();
    dada-> fin = inicLista();
}

void agregarAFila(Fila* dada, int num){
    nodoDoble* nuevoNodo = crearNodo(num);

    dada-> fin = agregarAlFinal(dada-> fin, nuevoNodo);
    dada-> fin = nuevoNodo;

    if(dada-> inicio == NULL){
        dada-> inicio = nuevoNodo;
    }
}

void leer(Fila* dada){
    int num;
    printf("\nIngrese un numero: ");
    scanf("%d", &num);

    agregarAFila(dada, num);
}

int extraer(Fila* dada){
    int rta = primero(dada);
    dada-> inicio = borrarPrimerNodo(dada-> inicio);

    if(dada-> inicio == NULL){
        dada-> fin = inicLista();
    }

    return rta;
}

void mostrarFila(Fila* dada){
    mostrarLista(dada-> inicio);
}

int primero(Fila* dada){
    int rta = -99999;
    if(dada-> inicio){
        rta = retornarPrimerNumero(dada-> inicio);
    }
    return rta;
}

int filaVacia(Fila* dada){
    int rta = listaVacia(dada-> inicio);
    return rta;
}
