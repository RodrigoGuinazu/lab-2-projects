#include <stdio.h>
#include <stdlib.h>
#include "ListaEstudiante.h"
#include "PilaEstudiante.h"

nodoEstudiante * cargarLista (nodoEstudiante * listaEstudiantes, char direccion[]);
void listaAPila(Pila * pilita, nodoEstudiante * lista);

int main()
{
    nodoEstudiante * listaEstudiantes;
    listaEstudiantes= inicListaEstudiante();

    char direccion[]="EstudiantesTUP.dat";

    listaEstudiantes=cargarLista(listaEstudiantes,direccion);

    recorrerYMostrarRecur(listaEstudiantes);



    estudiante arrayEstudiantes[10];

    Pila pilita;
    inicPila(&pilita);

    listaAPila(&pilita, listaEstudiantes);


    return 0;
}

///1-c
nodoEstudiante * cargarLista (nodoEstudiante * listaEstudiantes, char direccion[])
{
    FILE * archivito= fopen(direccion, "r");
    estudiante auxEstudiante;
    nodoEstudiante * aux;
    while(fread(&auxEstudiante, sizeof(estudiante), 1, archivito)>0)
    {

        aux=crearNodoEstudiante(auxEstudiante);
        listaEstudiantes=agregarFinalRecursivo(listaEstudiantes, aux);
    }
    return listaEstudiantes;
}


/// ejercicio 3 -c
void porcentajeConAplazo(nodoEstudiante * lista, int valor)
{
    int totalEstudiantes = contarEstudiantes(lista);
    int estudiantesConAplazo = contarAplazosEstudiantes(lista, valor);

    float porcentaje = (float) (estudiantesConAplazo*100)/totalEstudiantes;

    printf("\nEl porcentaje de estudiantes con aplazo es de %.2f", porcentaje);
}

/// ejercicio 4 - c
void cargarArrayEstudiantes(nodoEstudiante * lista, estudiante arreglo[], int dimension)
{
    nodoEstudiante * aux;
    for(int i =0 ; i< dimension ; i++)
    {
        aux=eliminarNodo(&lista, legajoMayorPromedio(lista));
        arreglo[i]=aux->dato;
    }
}

///ejercicio 5
void mostrarArregloEstudiantes( estudiante arreglo[],int indice, int dimension)
{
    if(indice<dimension)
    {
        mostrarArregloEstudiantes(arreglo, indice+1, dimension);

        printf("\n----------------");
        printf("\nLegajo: %d",arreglo[indice].legajo);
        printf("\nNombre: %s", arreglo[indice].nombre);
        printf("\nApeliido %s", arreglo[indice].apellido);
        printf("\nDNI: %s", arreglo[indice].dni);
        printf("\nEdad: %d", arreglo[indice].edad);
        printf("\nGenero: %c", arreglo[indice].genero);
        printf("\Materias aprobadas: %d", arreglo[indice].cantMateriasAprobadas);
        printf("\nPromedio S/ aplazos: %f", arreglo[indice].promedioConAplazos);
        printf("\nPromedio c/ Aplazos: %f", arreglo[indice].promedioSinAplazos);
        printf("\n----------------");

    }
}

void listaAPila(Pila * pilita, nodoEstudiante * lista)
{
    while(lista)
    {
        if(lista->dato.cantMateriasAprobadas>=10 && lista->dato.promedioSinAplazos>=8)
        {
            apilar(&pilita, lista);
        }


        lista=lista->siguiente;
    }
}
