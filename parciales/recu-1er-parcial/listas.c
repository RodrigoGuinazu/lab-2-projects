#include "listas.h"

// Ejercicio 1

nodoD* inicListaDoble()
{
    return NULL;
}

void crearNodoDoble(stYoutuber youtuber, nodoD** aux)
{
    *aux = (nodoD*) malloc(sizeof(nodoD));
    (*aux)-> dato = youtuber;
    (*aux)-> anterior = NULL;
    (*aux)-> siguiente = NULL;
}

nodoD* buscarElUltimo(nodoD* lista)
{
    nodoD* ultimo = lista;
    if(ultimo)
    {
        while(ultimo-> siguiente)
        {
            ultimo = ultimo-> siguiente;
        }
    }
    return ultimo;
}

nodoD* agregarAlFinal(nodoD* lista, nodoD* nuevoNodo)
{
    if(lista == NULL)
    {
        lista = nuevoNodo;
    }
    else
    {
        nodoD* ultimo = buscarElUltimo(lista);
        nuevoNodo-> anterior = ultimo;
        ultimo-> siguiente = nuevoNodo;
    }
    return lista;
}

void inicFila(Fila* dada)
{
    dada-> inicio = inicListaDoble();
    dada-> fin = inicListaDoble();
}

void agregarAFila(Fila* dada, stYoutuber youtuber)
{
    nodoD* nuevoNodo = crearNodoDoble(youtuber);

    dada-> fin = agregarAlFinal(dada-> fin, nuevoNodo);
    dada-> fin = nuevoNodo;

    if(dada-> inicio == NULL)
    {
        dada-> inicio = nuevoNodo;
    }
}

Fila* archivoAFila(char archivo[], Fila* dada)
{
    FILE * arch = fopen(archivo, "rb");
    stYoutuber auxYoutuber;
    nodoD* auxNodo;
    if(arch)
    {
        while(fread(&auxYoutuber, sizeof(stYoutuber), 1, arch) > 0)
        {
            agregarAFila(dada, auxYoutuber-> dato);
        }
        fclose(arch);
    }

    return dada;
}

// Ejercicio 2

void mostrarUnYoutuber(stYoutuber aux)
{
    printf("\nID..................: %d", aux.id);
    printf("\nNombre del canal....: %s", aux.nombreCanal);
    printf("\nRubro...............: %s", aux.rubro);
    printf("\nSuscriptores........: %d", aux.cantSuscriptores);
    printf("\nVisitas del Semestre: %d", aux.cantVistasSemestre);
    printf("\n\n");
}

void mostrarListaDoble(nodoD* lista)
{
    if(lista == NULL)
    {
        printf("\n");
    }
    else
    {
        mostrarListaDoble(lista-> siguiente);
        mostrarUnYoutuber(lista-> dato);
    }
}

void mostrarFila(Fila* dada)
{
    mostrarListaDoble(dada-> inicio);
}

// Ejercicio 3

void totalesAAbonarSegunRubro(nodoDoble* lista, float *totalFan, float *totalCre, float *totalAcc, float *totalAve, float *totalRet, float *totalCon)
{
    if(lista)
    {
        nodoD* seguidora = lista;
        while(seguidora)
        {
            if(strcmp(seguidora-> dato.rubro, "fantasia") == 0)
            {
                *totalFan += (seguidora-> dato.cantVistasSemestre)*0.2;
            }
            else if(strcmp(seguidora-> dato.rubro, "creativos") == 0)
            {
                *totalCre += (seguidora-> dato.cantVistasSemestre)*0.2;
            }
            else if(strcmp(seguidora-> dato.rubro, "accion") == 0)
            {
                *totalAcc += (seguidora-> dato.cantVistasSemestre)*0.2;
            }
            else if(strcmp(seguidora-> dato.rubro, "aventura") == 0)
            {
                *totalAve += (seguidora-> dato.cantVistasSemestre)*0.2;
            }
            else if(strcmp(seguidora-> dato.rubro, "retro") == 0)
            {
                *totalRet += (seguidora-> dato.cantVistasSemestre)*0.2;
            }
            else if(strcmp(seguidora-> dato.rubro, "construccion") == 0)
            {
                *totalCon += (seguidora-> dato.cantVistasSemestre)*0.2;
            }
            seguidora = seguidora-> siguiente;
        }
    }
}

// Ejercicio 4

nodoS* inicLista()
{
    return NULL;
}

nodoS* crearNodo(stYoutuber youtuber)
{
    nodoS* aux = (nodoS*) malloc(sizeof(nodoS));
    aux-> dato = youtuber;
    aux-> siguiente = NULL;

    return aux;
}

nodoS* insertarEnOrden(nodoS* lista, nodoS* nuevoNodo)
{
    if(lista == NULL)
    {
        lista = nuevoNodo;
    }
    else
    {
        if(lista-> dato.cantVistasSemestre > nuevoNodo-> dato.cantVistasSemestre)
        {
            nuevoNodo-> siguiente = lista;
            lista = nuevoNodo;
        }
        else
        {
            nodoS* anterior = lista;
            nodoS* seguidora = lista-> siguiente;

            while(seguidora != NULL && (seguidora-> dato.cantVistasSemestre) < (nuevoNodo-> dato.cantVistasSemestre))
            {
                anterior = seguidora;
                seguidora = seguidora->siguiente;
            }
            nuevoNodo-> siguiente = seguidora;
            anterior-> siguiente = nuevoNodo;
        }
    }
    return lista;
}

stYoutuber* retornarPrimerYoutuber(Fila* dada)
{
    if(dada)
    {
        stYoutuber* aux = dada-> inicio;
    }
    return aux;
}

stYoutuber primero(Fila* dada)
{
    stYoutuber rta;
    if(dada-> inicio)
    {
        rta = retornarPrimerYoutuber(dada-> inicio);
    }
    return rta;
}

nodoD* borrarPrimerNodo(nodoD* lista)
{
    if(lista)
    {
        nodoD* aBorrar = lista;
        lista = lista-> siguiente;
        if(lista != NULL)
        {
            lista-> anterior = NULL;
        }
        free(aBorrar);
    }

    return lista;
}

stYoutuber extraer(Fila* dada)
{
    stYoutuber rta = primero(dada);
    dada-> inicio = borrarPrimerNodo(dada-> inicio);

    if(dada-> inicio == NULL)
    {
        dada-> fin = inicLista();
    }

    return rta;
}

nodoS* pasarFilaALista(Fila* dada)
{
    nodoS* lista = inicLista();
    stYoutuber youtuber;
    while(dada)
    {
        youtuber = extraer(dada);
        lista = insertarEnOrden(lista, crearNodo(youtuber));
    }

    return lista;
}

int cantSegunVisitas(nodoS* lista, int visitas)
{
    int rta = 0;
    if(lista)
    {
        if(lista-> dato.cantVistasSemestre > visitas)
        {
            rta = 1 + cantSegunVisitas(lista-> siguiente, visitas);
        }
        else
        {
            rta = cantSegunVisitas(lista-> siguiente, visitas);
        }
    }
    return rta;
}

int cantSegunVisitasMenores(nodoS* lista, int visitas)
{
    int rta = 0;
    if(lista)
    {
        if(lista-> dato.cantVistasSemestre < visitas)
        {
            rta = 1 + cantSegunVisitas(lista-> siguiente, visitas);
        }
        else
        {
            rta = cantSegunVisitas(lista-> siguiente, visitas);
        }
    }
    return rta;
}

int totalAPagar(nodoS* lista)
{
    int aPagar = 0;
    int mayoresA = cantSegunVisitas(lista, 100000);
    int menoresA = cantSegunVisitasMenores(lista, 100000)
                   aPagar = (mayoresA * 20000) + (menoresA * 10000);

    return aPagar;
}
