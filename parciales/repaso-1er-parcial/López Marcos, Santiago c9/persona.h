#ifndef PERSONA_H_INCLUDED
#define PERSONA_H_INCLUDED
#include "lista.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

typedef struct{
    int id;
    char nombre[30];
    char apellido[30];
    char dni[20];
    int edad;
    char genero;
} stPersona;


void muestraUnaPersona(stPersona c);
int sumarListaRecursiva(nodo* lista, int suma);
stPersona masJoven (nodo* lista);
int cantPorEdad (nodo*lista, int edad);
int cantTotal (nodo*lista);
float porcentajePorEdad (int edad, nodo * lista);
void mostrarArchivo(char archivo[]);
void listaToArchi (char archivo[], nodo*lista,char inicial);

#endif // CLIENTE_H_INCLUDED
