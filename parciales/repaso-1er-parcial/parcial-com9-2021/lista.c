#include "lista.h"

nodo* inicLista(){
    return NULL;
}

nodo* crearNodo(stPersona persona){
    nodo* aux = (nodo*) malloc(sizeof(nodo));
    aux-> dato = persona;
    aux-> siguiente = NULL;

    return aux;
}

nodo* insertarEnOrden(nodo* lista, nodo* nuevoNodo){
    if(lista == NULL){ // en caso de que la lista este vacia
        lista = nuevoNodo;
    }else{
        if(strcmp(nuevoNodo-> dato.apellido, lista-> dato.apellido) < 0){ // 1er nodo
            nuevoNodo-> siguiente = lista;
            lista = nuevoNodo;
        }else{ // en caso de que este en el medio
            nodo* anterior = lista;
            nodo* seguidora = lista-> siguiente;

            while(seguidora && strcmp(nuevoNodo-> dato.apellido, lista-> dato.apellido) >= 0){
                anterior = seguidora;
                seguidora = seguidora->siguiente;
            }
            nuevoNodo-> siguiente = seguidora;
            anterior-> siguiente = nuevoNodo;
        }
    }
    return lista;
}

nodo* pasarALista(char archivo[], nodo* lista){
    FILE * arch = fopen(archivo, "r");
    stPersona auxPersona;
    nodo* auxNodo;
    if(arch){
        while(fread(&auxPersona, sizeof(stPersona), 1, arch) > 0){
            auxNodo = crearNodo(auxPersona);
            lista = insertarEnOrden(lista, auxNodo);
        }
        fclose(arch);
    }
    return lista;
}

void muestraUnaPersona(stPersona c){
    printf("\nNombre...............: %s", c.nombre);
    printf("\nApellido.............: %s", c.apellido);
    printf("\nDNI..................: %s", c.dni);
    printf("\nEdad.................: %d", c.edad);
    printf("\nGenero...............: %s", (c.genero=='m')?"Masculino":"Femenino");
    printf("\n----------------------------------------------------------");
}

void mostrarListaRecursiva(nodo* lista){
    if(lista == NULL){
        printf("\n");
    }else{
        muestraUnaPersona(lista-> dato);
        mostrarListaRecursiva(lista-> siguiente);
    }
}

int sumarEdades(nodo* lista){
    int rta = 0;
    if(lista == NULL){
        rta = rta;
    }else{
        if(lista->dato.edad >= 18 && (atoi(lista-> dato.dni))%2 == 0){ // atoi pasa de string a numero
            rta = lista->dato.edad + sumarEdades(lista-> siguiente);
        }else{
            rta = sumarEdades(lista-> siguiente);
        }
    }
    return rta;
}

stPersona buscarMenor(nodo* lista, stPersona menor){ // menor => lista-> dato
    if(lista == NULL){
        menor = menor;
    }else{
        if(lista->dato.edad < menor.edad){
            menor = lista-> dato;
        }
        menor = buscarMenor(lista-> siguiente, menor);
    }
    return menor;
}

void copiarEnArchivo(nodo* lista, char letra, char archivo[]){
    FILE * arch = fopen(archivo, "ab");
    stPersona auxPersona;
    nodo* auxNodo;
    if(arch){
        while(lista){
            if(lista->dato.apellido[0] == letra){
                auxPersona = lista->dato;
                fwrite(&auxPersona, sizeof(stPersona), 1, arch);
            }
            lista = lista-> siguiente;
        }
        fclose(arch);
    }
}

void archivoMostrar(char nombreArchivo[]){
   FILE *arch = fopen(nombreArchivo,"rb");

   if(arch){
      stPersona auxPersona;
      while(fread(&auxPersona,sizeof(stPersona),1,arch) >0){
          muestraUnaPersona(auxPersona);
      }
      fclose(arch);
   }else{
      printf("ERROR al abrir el archivo\n");
   }
}

int contarMayores(nodo* lista, int edad){
    int rta = 0;
    if(lista == NULL){
        rta = rta;
    }else{
        if(lista->dato.edad > edad){
            rta = 1 + contarMayores(lista-> siguiente, edad);
        }else{
            rta = contarMayores(lista-> siguiente, edad);
        }
    }
    return rta;
}

int cantPersonas(nodo* lista){
    int rta = 0;
    if(lista == NULL){
        rta = rta;
    }else{
        rta = 1 + cantPersonas(lista-> siguiente);
    }
    return rta;
}

float porcentaje(nodo* lista, int edad){
    int total = cantPersonas(lista);
    int mayores = contarMayores(lista, edad);
    float rta = (float)mayores*100/total;

    return rta;
}
