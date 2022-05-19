#ifndef AUTOMOVILES_H_INCLUDED
#define AUTOMOVILES_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

typedef struct {
   char patente[6];
   int valor;
   char marca[10];
} automovil;

typedef struct {
   automovil dato;
   struct nodoAuto * siguiente;
} nodoAuto;

void inicLista(nodoAuto** lista);
automovil nuevoVehiculo();
nodoAuto* crearNodo(automovil vehiculo);
void agregarAlFinal(nodoAuto** lista, nodoAuto*  nuevoNodo);
void mostrarAuto(automovil aux);
void mostrarLista(nodoAuto* lista);
int insertarCelda(automovil Array[], int dim, automovil dato, int validos);
void agregarMuchos(nodoAuto** lista);
void mostrarArrayRecursivo(automovil Array[], int validos, int i);
int pasar(nodoAuto* lista, automovil Array[], int dim);
int sumarPares(nodoAuto* lista);

#endif // AUTOMOVILES_H_INCLUDED
