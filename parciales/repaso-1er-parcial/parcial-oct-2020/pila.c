#include "pila.h"
// 7)
void inicPila(Pila* dada){
    *dada = inicLista();
}

void apilar(Pila* dada, stPersona aux){
    nodo* nuevoNodo = crearNodo(aux);
    (*dada) = agregarAlPrincipio(*dada, nuevoNodo);
}

void mostrarPila(Pila* dada){
    mostrarLista(*dada);
}

void pasarAPila(Pila* dada, nodo* lista){
    stPersona aux;
    while(lista){
        if(lista->dato.cantMateriasAprobadas > 10 && lista->dato.promedioSinAplazos <= 8){
            aux = lista->dato;
            apilar(dada, aux);
        }
        lista = lista-> siguiente;
    }
}
