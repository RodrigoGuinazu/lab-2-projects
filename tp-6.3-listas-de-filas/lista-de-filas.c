#include "lista-de-filas.h"


// PASAR DE ARCHIVO A LDF(LISTA DE FILAS)
nodoCelda* pasarDeArchivoToLDF(char archivoAAbrir[], nodoCelda* ldf){
    FILE *archivo = fopen(archivoAAbrir, "rb");
    registroArchivo nuevoRegistro;
    stAnimal nuevoAnimal;
    stEspecie nuevaEspecie;

    if(archivo){
        while(fread(&nuevoRegistro, sizeof(registroArchivo), 1, archivo) > 0){
            nuevoAnimal.cantidad = nuevoRegistro.cant;
            nuevoAnimal.habitat = nuevoRegistro.habitat;
            strcpy(nuevoAnimal.nombreAnimal, nuevoRegistro.animal);
            nuevaEspecie.id = nuevoRegistro.idEspecie;
            strcpy(nuevaEspecie.nombre, nuevoRegistro.especie);

            ldf = alta(ldf, nuevoAnimal, nuevaEspecie);
        }
        fclose(archivo);
    }else{
        printf("El archivo en NULL");
    }
    return ldf;
}

// PASAR DE LDF A ARCHIVO

void pasarAArchivoPorEspecie(nodoCelda* ldf){
    int pos = 0;
    nodoCelda* lista = ldf;
    char archivo[30];
    while(lista){
        sprintf(archivo, "especieNro%d.dat", pos + 1);
        pasarDeLDFToArchivosPorEspecie(archivo, lista);
        pos++;
        lista = lista-> siguiente;
    }
}

void pasarDeLDFToArchivosPorEspecie(char archivoAAbrir[], nodoCelda* celda){
    FILE *archivo = fopen(archivoAAbrir, "ab");
    registroArchivo nuevoRegistro;

    if(archivo){
        strcpy(nuevoRegistro.especie, celda->especie.nombre);
        nuevoRegistro.idEspecie = celda->especie.id;
        while(celda->dada.fin){
            strcpy(nuevoRegistro.animal, celda->dada.fin->dato.nombreAnimal);
            nuevoRegistro.cant = celda->dada.fin->dato.cantidad;
            nuevoRegistro.habitat = celda->dada.fin->dato.habitat;

            fwrite(&nuevoRegistro, sizeof(registroArchivo), 1, archivo);

            celda->dada.fin = celda->dada.fin->anterior;
        }

        fclose(archivo);
    }else{
        printf("El archivo en NULL");
    }
}

void mostrarArchivo(char archivoAAbrir[]){
    FILE *archivo = fopen(archivoAAbrir, "rb");
    registroArchivo nuevoRegistro;

    if(archivo){
        while(fread(&nuevoRegistro, sizeof(registroArchivo), 1, archivo) > 0){
            printf("\n**********************************************************\n");
            printf("\nAnimal: %s\n", nuevoRegistro.animal);
            printf("\nCantidad: %d\n", nuevoRegistro.cant);
            printf("\nHabitat: %d\n", nuevoRegistro.habitat);
            printf("\nID de especie: %d\n", nuevoRegistro.idEspecie);
            printf("\nEspecie: %s\n", nuevoRegistro.especie);
            printf("\n**********************************************************\n");
        }
        fclose(archivo);
    }
}

// LISTA DE FILAS
nodoCelda* alta(nodoCelda* ldf, stAnimal nuevoAnimal, stEspecie nuevaEspecie){
    nodoCelda* rta = buscarNodoCelda(ldf, nuevaEspecie);

    if(rta == NULL){ // el animal no esta en la lista de arboles
        nodoCelda* nuevaCelda = crearNodoCeldas(nuevaEspecie);
        ldf = agregarAlPpioCeldas(ldf, nuevaCelda);
        rta = ldf;
    }
    agregarAFila(&rta->dada, nuevoAnimal);

    return ldf;
}

nodoCelda* buscarNodoCelda(nodoCelda* ldf, stEspecie nuevaEspecie){
    nodoCelda* rta = NULL;
    nodoCelda* seg = ldf;
    int flag = 0;
    int i = 0;

    while(seg && flag == 0){
        if(strcmp(seg->especie.nombre, nuevaEspecie.nombre) == 0 && seg->especie.id == nuevaEspecie.id){ // en caso de que la especie ya este en el arreglo
            rta = seg;
            flag = 1;
        }
        seg = seg->siguiente;
    }
    return rta;
}

nodoCelda* inicListaCeldas(){
    return NULL;
}

nodoCelda* crearNodoCeldas(stEspecie especie){
    nodoCelda* aux = (nodoCelda*) malloc(sizeof(nodoCelda));
    aux->especie = especie;
    inicFila(&aux->dada);
    aux->siguiente = NULL;

    return aux;
}

nodoCelda* agregarAlPpioCeldas(nodoCelda* lista, nodoCelda* nuevoNodo){
    if(lista == NULL){
        lista = nuevoNodo;
    }else{
        nuevoNodo-> siguiente = lista;
        lista = nuevoNodo;
    }
    return lista; // Se retorna la lista ya que hay que tener en cuenta que en el caso de que el primer primer if sea verdadero debemos retornarla, en el resto de los casos aunque trabajemos sobre el
}

void mostrarListaCeldas(nodoCelda* lista){
    if(lista){
        nodoCelda* seguidora = lista; // copia de seguridad

        printf("\n**************************LDF*********************************\n");
        while(seguidora){
            mostrarCelda(seguidora);
            seguidora = seguidora-> siguiente; // me muevo hacia el siguiente nodo en la lista
            printf("\n########################################################################################################\n");
        }
        printf("\n**************************LDF*********************************\n");
    }else{
        printf("\nLa lista esta vacia!\n");
    }
}

void mostrarCelda(nodoCelda* celda){
    printf("ID de la Especie: %d\n", celda->especie.id);
    printf("\nEspecie.......: %s\n", celda->especie.nombre);
    printf("Lista...........:\n\n");
    mostrarFila(&celda->dada);
}
