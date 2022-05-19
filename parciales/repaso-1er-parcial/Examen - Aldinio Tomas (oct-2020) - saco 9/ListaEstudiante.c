#include "ListaEstudiante.h"

nodoEstudiante * inicListaEstudiante ()
{
return NULL;
}

/// ejercicio 1
///a
nodoEstudiante * crearNodoEstudiante(estudiante nuevo)
{
    nodoEstudiante * aux = (nodoEstudiante*) malloc(sizeof(nodoEstudiante));

    aux->dato=nuevo;

    aux->siguiente=NULL;

    return aux;
}

///b
nodoEstudiante * agregarFinalRecursivo (nodoEstudiante * lista, nodoEstudiante * nuevo)
{
    if(lista==NULL)
    {
        lista=nuevo;
        printf("primer");
        mostrarNodo(nuevo);

    }else
    {
        lista->siguiente=agregarFinalRecursivo(lista->siguiente, nuevo);
    }
    return lista;
}

///Ejercicio 2
void recorrerYMostrarRecur(nodoEstudiante * lista)
{
    if(lista)
    {
        mostrarNodo(lista);
        recorrerYMostrarRecur(lista->siguiente);
    }
}

void mostrarNodo(nodoEstudiante * lista)
{
    printf("\n----------------");
    printf("\nLegajo: %d",lista->dato.legajo);
    printf("\nNombre: %s", lista->dato.nombre);
    printf("\nApeliido %s", lista->dato.apellido);
    printf("\nDNI: %s", lista->dato.dni);
    printf("\nEdad: %d", lista->dato.edad);
    printf("\nGenero: %c", lista->dato.genero);
    printf("\nMaterias aprobadas: %d", lista->dato.cantMateriasAprobadas);
    printf("\nPromedio S/ aplazos: %f", lista->dato.promedioConAplazos);
    printf("\nPromedio c/ Aplazos: %f", lista->dato.promedioSinAplazos);
    printf("\n----------------");
}

///ejercicio 3
///a
int contarEstudiantes(nodoEstudiante * lista)
{
    int contador;
    if(lista==NULL)
    {
        contador=0;

    } else
    {
        contador=contarEstudiantes(lista->siguiente);
        contador=contador+1;

    }

    return contador;
}

///b
int contarAplazosEstudiantes(nodoEstudiante * lista, int valor)
{
    int contador;
    if(lista==NULL)
    {
        contador=0;

    } else
    {
        contador=contarEstudiantes(lista->siguiente);

        if(lista->dato.promedioConAplazos>=valor)
            contador=contador+1;

    }

    return contador;
}


///ejericio 4
/// a
int legajoMayorPromedio (nodoEstudiante * lista)
{
    int legajo=lista->dato.legajo;
    int nota=lista->dato.promedioSinAplazos;
    while(lista)
    {
        if(lista->dato.promedioSinAplazos > nota)
        {
            legajo=lista->dato.legajo;
        }

        lista=lista->siguiente;
    }
    return legajo;
}

///b
nodoEstudiante * eliminarNodo(nodoEstudiante ** lista, int legajo)
{
    nodoEstudiante * aux;
    aux= inicListaEstudiante();

    if (lista)
    {
        nodoEstudiante * aux;

        if((*lista)->dato.legajo== legajo)
        {
            aux=(*lista);
            (*lista)=(*lista)->siguiente;
        }
        else
        {
            nodoEstudiante * ante;
            nodoEstudiante * seg=(*lista);
            while(seg && seg->dato.legajo!= legajo)
            {
                ante=seg;
                seg=seg->siguiente;
            }

            if(seg!=NULL)
            {
                ante->siguiente=seg->siguiente;
                aux=seg;
            }
        }
    }
    return aux;
}

/// ejercicio 6
nodoEstudiante * agregarPpio(nodoEstudiante * lista, nodoEstudiante * nuevo)
{
    if(lista)
    {
        nuevo->siguiente=lista;
        lista=nuevo;

    }
    else
    {
        lista=nuevo;
    }
    return lista;
}

