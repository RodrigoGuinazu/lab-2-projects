#include "arreglos-de-arboles.h"

// FUNCIONES DE ARBOLES

nodoArbol* inicArbol(){
    return NULL;
}

nodoArbol* crearNodoArbol(stAnimal dato){
    nodoArbol* aux = malloc(sizeof(nodoArbol));

    aux-> dato = dato;
    aux-> izq = NULL;
    aux-> der = NULL;

    return aux;
}

nodoArbol* insertar(nodoArbol* arbol, stAnimal dato){
    if(arbol == NULL){
        arbol = crearNodoArbol(dato);
    }else{
        if(dato.cantidad > arbol-> dato.cantidad){
            arbol-> der = insertar(arbol-> der, dato);
        }else{
            arbol-> izq = insertar(arbol-> izq, dato);
        }
    }
    return arbol;
}

void mostrarUnAnimal(stAnimal dato){
    printf("\n**********************************************************************");
    printf("\nNombre..............................................: %s", dato.nombreAnimal);
    printf("\nCantidad............................................: %d", dato.cantidad);
    printf("\nHabitat (1 = Selva; 2 = Savana; 3 = Bosque; 4 = Mar): %d", dato.habitat);
    printf("\n**********************************************************************\n\n");
}

void preOrder(nodoArbol* arbol){
    if(arbol){
        mostrarUnAnimal(arbol-> dato);
        preOrder(arbol-> izq);
        preOrder(arbol-> der);
    }
}

// PASAR DE ARCHIVO A ADA(ARREGLO DE ARBOLES)

int pasarDeArchivoToADA(char archivoAAbrir[], celdaEspecie array[], int validos){
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

// PASAR DE ADA A ARCHIVO

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
        archivo = arbolAArchivo(array[pos].arbolDeAnimales, archivo, nuevoRegistro);

        fclose(archivo);
    }else{
        printf("El archivo en NULL");
    }
}

FILE* arbolAArchivo(nodoArbol* arbol, FILE* archivo, registroArchivo nuevoRegistro){
    if(arbol){
        strcpy(nuevoRegistro.animal, arbol->dato.nombreAnimal);
        nuevoRegistro.cant = arbol->dato.cantidad;
        nuevoRegistro.habitat = arbol->dato.habitat;
        fwrite(&nuevoRegistro, sizeof(registroArchivo), 1, archivo);
        arbolAArchivo(arbol-> izq, archivo, nuevoRegistro);
        arbolAArchivo(arbol-> der, archivo, nuevoRegistro);
    }
}

// ARRAY DE ARBOLES

int ingresarAnimales(celdaEspecie array[], int dim, int validos){
    stAnimal nuevoAnimal;
    stEspecie nuevaEspecie;
    char control = 's';

    while(control == 's' && validos < dim){
        nuevoAnimal = cargarAnimal();
        nuevaEspecie = cargarEspecie();

        validos = alta(array, nuevoAnimal, nuevaEspecie, validos);

        printf("\nDesea ingresar mas notas? (s/n)\n");
        control = getch();
    }

    return validos;
}

stAnimal cargarAnimal(){
    stAnimal nuevoAnimal;

    printf("\nIngrese el nombre del Animal: \n");
    fflush(stdin);
    gets(nuevoAnimal.nombreAnimal);
    printf("\nIngrese la cantidad: \n");
    fflush(stdin);
    scanf("%d", &nuevoAnimal.cantidad);
    printf("\nIngrese el habitat (1 = Selva; 2 = Savana; 3 = Bosque; 4 = Mar): \n");
    fflush(stdin);
    scanf("%d", &nuevoAnimal.habitat);

    return nuevoAnimal;
}

stEspecie cargarEspecie(){
    stEspecie nuevaEspecie;

    printf("\nIngrese el nombre de la Especie: \n");
    fflush(stdin);
    gets(nuevaEspecie.nombre);
    printf("\nIngrese el ID de la Especie: \n");
    fflush(stdin);
    scanf("%d", &nuevaEspecie.id);

    return nuevaEspecie;
}

int alta(celdaEspecie array[], stAnimal nuevoAnimal, stEspecie nuevaEspecie, int validos){
    nodoArbol* animal = crearNodoArbol(nuevoAnimal); /// para que hago esto aca si despues hago el nodo en la linea 192
    int pos = buscarPosAnimal(array, nuevaEspecie, validos);
    if(pos == -1){ // el animal no esta en el array
        validos = agregarCelda(array, nuevoAnimal, nuevaEspecie, validos);
        pos = validos - 1; // el animal quedo en la ultima posicion valida del arreglo
    }
    array[pos].arbolDeAnimales = insertar(array[pos].arbolDeAnimales, nuevoAnimal); // insertar en el arbol

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
    array[validos].arbolDeAnimales = inicArbol(); // inicializo el arbol de animales
    validos++; // como agregamos una nueva materia en el arreglo los validos incrementan
    return validos;
}

void mostrarArrayDeArboles(celdaEspecie array[], int validos){
    int i = 0;
    printf("\n**************************ADA*********************************\n");
    while(i < validos){
        printf("\ID de la Especie.....: %d\n", array[i].especie.id);
        printf("\nNombre de la Especie: %s\n", array[i].especie.nombre);
        preOrder(array[i].arbolDeAnimales);
        printf("\n########################################################################################################\n\n");
        i++;
    }
    printf("\n**************************ADA*********************************\n");
}
