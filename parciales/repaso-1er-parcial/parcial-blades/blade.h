#ifndef BLADE_H_INCLUDED
#define BLADE_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

typedef struct blade{
    char nombre[30];
    char rol[4]; ///ATA (ataque) - DEF (defensa) - SND (sanados)
    char elemento[30]; ///fuego - agua - tierra, etc.
    int ataque;
    float critico; ///porcentaje
    float bloqueo; ///porcentaje
    char piloto[30]; ///Rex, Nia, Tora, Zeke o Morag (solo esos)
}Blade;

typedef struct{
    Blade dato;
    struct nodoDoble* anterior;
    struct nodoDoble* siguiente;
}nodoDoble;

nodoDoble* inicLista();
nodoDoble* crearNodo(Blade datoBlade);
nodoDoble* insertarEnOrden(nodoDoble* lista, nodoDoble* nuevoNodo);
nodoDoble* pasarALista(char archivo[], nodoDoble* lista);
void mostrarBlade(Blade aux);
void mostrarListaRecursiva(nodoDoble* lista);
nodoDoble* quitarSegunPiloto(nodoDoble* lista, char piloto[]);
//Fila pasarSegunPiloto(nodoDoble* lista, char piloto[], Fila dada);
Blade mayorAtaque(nodoDoble* lista, Blade mayor);
int cantidadSegunElemento(nodoDoble* lista, char elemento[]);
int pasarArrayDin(nodoDoble* lista, char elemento[], Blade Array[]);
void mostrarArrayRecursivo(Blade Array[], int validos, int i);

#endif // BLADE_H_INCLUDED
