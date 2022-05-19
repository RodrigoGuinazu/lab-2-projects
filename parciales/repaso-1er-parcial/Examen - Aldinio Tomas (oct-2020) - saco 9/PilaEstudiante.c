#include "PilaEstudiante.h"

void inicPila(Pila * pilita)
{
    (*pilita)=inicListaEstudiante();
}

void apilar (Pila * pilita, nodoEstudiante * nuevo)
{
    (*pilita)= agregarPpio(*pilita, nuevo);
}


void mostrar(Pila * pilita)
{
    printf("\n\tTOPE");
    recorrerYMostrarRecur(*pilita);
    printf("\n\tBASE");
}
