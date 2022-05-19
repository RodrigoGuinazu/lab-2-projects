#include "arreglo-de-filas.h"

// PASAR DE ARCHIVO A ADF(ARREGLO DE FILAS)
int pasarDeArchivoToADF(char archivoAAbrir[], celdaEspecie array[], int validos){
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

            validos = alta(array, nuevoAnimal, nuevaEspecie, validos);
        }
        fclose(archivo);
    }else{
        printf("El archivo en NULL");
    }
    return validos;
}

// PASAR DE ADF A ARCHIVO

void pasarAArchivoPorEspecie(celdaEspecie array[], int validos){
    int pos = 0;
    char archivo[30];
    while(pos < validos){
        sprintf(archivo, "especieNro%d.dat", pos + 1);
        pasarDeADAToArchivosPorEspecie(archivo, array, pos);
        pos++;
    }
}

void pasarDeADAToArchivosPorEspecie(char archivoAAbrir[], celdaEspecie array[], int pos){
    FILE *archivo = fopen(archivoAAbrir, "ab");
    registroArchivo nuevoRegistro;

    if(archivo){
        strcpy(nuevoRegistro.especie, array[pos].especie.nombre);
        nuevoRegistro.idEspecie = array[pos].especie.id;
        while(array[pos].dada.fin){
            strcpy(nuevoRegistro.animal, array[pos].dada.fin->dato.nombreAnimal);
            nuevoRegistro.cant = array[pos].dada.fin->dato.cantidad;
            nuevoRegistro.habitat = array[pos].dada.fin->dato.habitat;

            fwrite(&nuevoRegistro, sizeof(registroArchivo), 1, archivo);

            array[pos].dada.fin = array[pos].dada.fin->anterior;
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

// ARRAY DE FILAS
int alta(celdaEspecie array[], stAnimal nuevoAnimal, stEspecie nuevaEspecie, int validos){
    int pos = buscarPosAnimal(array, nuevaEspecie, validos);
    if(pos == -1){ // el animal no esta en el array
        validos = agregarCelda(array, nuevoAnimal, nuevaEspecie, validos);
        pos = validos - 1; // el animal quedo en la ultima posicion valida del arreglo
    }
    agregarAFila(&array[pos].dada, nuevoAnimal);

    return validos;
}

int buscarPosAnimal(celdaEspecie array[], stEspecie nuevaEspecie, int validos){
    int rta = -1;
    int i = 0;
    while(i < validos && rta == -1){
        if(strcmpi(array[i].especie.nombre, nuevaEspecie.nombre) == 0){ // en caso de que la especie ya este en el arreglo
            rta = i;
        }
        i++;
    }
    return rta;
}

int agregarCelda(celdaEspecie array[], stAnimal nuevoAnimal, stEspecie nuevaEspecie, int validos){
    array[validos].especie = nuevaEspecie; // seteo la especie
    inicFila(&array[validos].dada); // inicializo la fila de animales
    validos++; // como agregamos una nueva materia en el arreglo los validos incrementan
    return validos;
}

void mostrarArrayDeArboles(celdaEspecie array[], int validos){
    int i = 0;
    printf("\n**************************ADF*********************************\n");
    while(i < validos){
        printf("\ID de la Especie.....: %d\n", array[i].especie.id);
        printf("\nNombre de la Especie: %s\n", array[i].especie.nombre);
        mostrarFila(&array[i].dada);
        printf("\n########################################################################################################\n\n");
        i++;
    }
    printf("\n**************************ADF*********************************\n");
}
