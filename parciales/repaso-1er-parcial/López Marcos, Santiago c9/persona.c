
#include "persona.h"
#include "lista.h"

#define AR_PERSONAS "personas.dat"

/*********************************************************//**
*
* \brief Muestra un persona por consola
* \param stPersona c - una persona
* \return void
*
***********************************************************/
void muestraUnaPersona(stPersona c)
{
    printf("\nNombre...............: %s", c.nombre);
    printf("\nApellido.............: %s", c.apellido);
    printf("\nDNI..................: %s", c.dni);
    printf("\nEdad.................: %d", c.edad);
    printf("\nGenero...............: %s", (c.genero=='m')?"Masculino":"Femenino");
    printf("\n----------------------------------------------------------");
}


int sumarListaRecursiva(nodo* lista, int suma){
    int dni = lista->dato.dni - 0;
    if(lista == NULL){
        suma = suma + 0;
    }else if(lista->dato.edad >= 18 && dni %2 = 0)
             {
        int actual = lista->dato.edad;
        suma = actual + sumarListaRecursiva(lista-> siguiente, suma);
    }
    return suma;
}

stPersona masJoven (nodo* lista)
{

    if(lista)
    {
        nodo* aux = lista;
        nodo* seg = lista->siguiente;
        while( seg =! NULL)
        {

            if(seg->dato.edad > aux->dato.edad)
            {
                aux = seg;
            }
            seg = seg->siguiente;

        }

      return seg->dato;

    }
}

void listaToArchi (char archivo[], nodo*lista,char inicial)
{
    FILE*pArchi = fopen(archivo, "ab");
    stPersona aux;

    if(pArchi)
    {
        while(lista =! NULL)
        {
            if(inicial == lista->dato.apellido[0])
            {
            aux = lista->dato;
            fwrite(&aux, sizeof(stPersona),1, pArchi);
            }
            lista = lista->siguiente;
        }
        fclose(pArchi);
    }


}
void mostrarArchivo(char archivo[])
{
    FILE*parchivo= fopen(archivo, "rb");
    stPersona a;

    if(parchivo){

        while(fread(&a,sizeof(stPersona),1,parchivo)>0)
        {
            muestraUnaPersona(a);
        }
        fclose(parchivo);
    }
}

int cantPorEdad (nodo*lista, int edad)
{
    int cant;
    if(lista == NULL)
    {
        cant = 0;
    }
    else if (lista->dato.edad >= edad)
    {
      cant = cantPorEdad(lista->siguiente, edad);
      cant++;
    }
    return cant;

}

int cantTotal (nodo*lista)
{

    int cant=0;

    if(lista == NULL)
    {
        cant = 0;
    }
    else
    {

      cant = cantTotal(lista->siguiente);
      cant++;

    }
    return cant;
}

float porcentajePorEdad (int edad, nodo * lista)
{
    float porcentaje = ((float)cantPorEdad(edad)/(float)cantTotal(lista))*100;

    return porcentaje;
}
