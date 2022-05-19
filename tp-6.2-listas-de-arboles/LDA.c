#include "LDA.h"

// ARBOLES

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

// LISTAS nodoCelda

nodoCelda* inicListaCeldas(){
    return NULL;
}

nodoCelda* crearNodoCeldas(stEspecie especie){
    nodoCelda* aux = (nodoCelda*) malloc(sizeof(nodoCelda));
    aux->especie = especie;
    aux->arbolDeAnimales = inicArbol();
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

        printf("\n**************************LDA*********************************\n");
        while(seguidora){
            mostrarCelda(seguidora);
            seguidora = seguidora-> siguiente; // me muevo hacia el siguiente nodo en la lista
            printf("\n########################################################################################################\n");
        }
        printf("\n**************************LDA*********************************\n");
    }else{
        printf("\nLa lista esta vacia!\n");
    }
}

void mostrarCelda(nodoCelda* celda){
    printf("ID de la Especie: %d\n", celda->especie.id);
    printf("\nEspecie.......: %s\n", celda->especie.nombre);
    printf("Arbol de Animales:\n\n");
    preOrder(celda->arbolDeAnimales);
}

// PASAR DE ARCHIVO A LDA (LISTA DE ARBOLES)

nodoCelda* pasarDeArchivoToLDA(char archivoAAbrir[], nodoCelda* lda){
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

            lda = alta(lda, nuevoAnimal, nuevaEspecie);
        }
        fclose(archivo);
    }else{
        printf("El archivo en NULL");
    }
    return lda;
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

//PASAR DE LDA A ARCHIVO POR ESPECIE

void pasarAArchivoPorEspecie(nodoCelda* lda){
    int pos = 0;
    nodoCelda* lista = lda;
    char archivo[30];
    while(lista){
        sprintf(archivo, "especieNro%d.dat", pos + 1);
        pasarDeLDAToArchivosPorEspecie(archivo, lista);
        pos++;
        lista = lista->siguiente;
    }
}

void pasarDeLDAToArchivosPorEspecie(char archivoAAbrir[], nodoCelda* celda){
    FILE *archivo = fopen(archivoAAbrir, "ab");
    registroArchivo nuevoRegistro;

    if(archivo){
        strcpy(nuevoRegistro.especie, celda->especie.nombre);
        nuevoRegistro.idEspecie = celda->especie.id;
        archivo = arbolAArchivo(celda->arbolDeAnimales, archivo, nuevoRegistro);

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

// LISTA DE ARBOLES (LDA)

void ingresarAnimales(nodoCelda* lda, int dim){
    stAnimal nuevoAnimal;
    stEspecie nuevaEspecie;
    char control = 's';

    while(control == 's'){
        nuevoAnimal = cargarAnimal();
        nuevaEspecie = cargarEspecie();

        lda = alta(lda, nuevoAnimal, nuevaEspecie);

        printf("\nDesea ingresar mas notas? (s/n)\n");
        control = getch();
    }
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

nodoCelda* alta(nodoCelda* lda, stAnimal nuevoAnimal, stEspecie nuevaEspecie){
    nodoCelda* rta = buscarNodoCelda(lda, nuevaEspecie);

    if(rta == NULL){ // el animal no esta en la lista de arboles
        nodoCelda* nuevaCelda = crearNodoCeldas(nuevaEspecie);
        lda = agregarAlPpioCeldas(lda, nuevaCelda);
        rta = lda;
    }
    rta->arbolDeAnimales = insertar(rta->arbolDeAnimales, nuevoAnimal); // insertar en el arbol

    return lda;
}

nodoCelda* buscarNodoCelda(nodoCelda* lda, stEspecie nuevaEspecie){
    nodoCelda* rta = NULL;
    nodoCelda* seg = lda;
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
