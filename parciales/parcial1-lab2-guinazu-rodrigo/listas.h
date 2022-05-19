#ifndef LISTAS_H_INCLUDED
#define LISTAS_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

typedef struct{
 int id;
 char nombreYapellido[40];
 char sector[30];
 int ventasDiarias;
}stVendedor;

typedef struct _nodoS{
    stVendedor dato;
    struct _nodoS* siguiente;
}nodoS;

typedef struct _nodoD{
    stVendedor dato;
    struct _nodoD* anterior;
    struct _nodoD* siguiente;
}nodoD;

typedef struct{
    nodoD* inicio;
    nodoD* fin;
}Fila;

nodoS* inicLista();
nodoS* crearNodo(stVendedor vendedor);
nodoS* agregarAlFinalRecursivo(nodoS* lista, nodoS* nuevoNodo);
nodoS* archivoALista(char archivo[], nodoS* lista);
void mostrarUnVendedor(stVendedor aux);
void mostrarLista(nodoS* lista);
int cantSegunRubro(nodoS* lista, char rubro[]);
int mayorVentas(nodoS* lista);
stVendedor eliminarPorId(nodoS** lista, int id);

//Listas dobles y Filas
nodoD* inicListaDoble();
nodoD* crearNodoDoble(stVendedor vendedor);
nodoD* buscarElUltimo(nodoD* lista);
nodoD* agregarAlFinal(nodoD* lista, nodoD* nuevoNodo);
void inicFila(Fila* dada);
void agregarAFila(Fila* dada, stVendedor vendedor);
void pasarTop10(nodoS* lista, Fila* dada);
void mostrarListaDoble(nodoD* lista);
void mostrarFila(Fila* dada);

#endif // LISTAS_H_INCLUDED
