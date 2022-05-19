#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

// ESTRUCTURAS

typedef struct{
 int idSucursal;
 char nombreSucursal[25];
 char nombreDisfraz[25];
 char generoDisfraz[25];
 int stockDisfraz;
}registroArchivo;

typedef struct{
 int idSucursal;
 char nombreSucursal[25];
}stSucursal;

typedef struct{
 char nombreDisfraz[25];
 char generoDisfraz[25];
 int stockDisfraz;
}stDisfraz;

typedef struct{
    stDisfraz dato;
    struct nodoArbol* izq;
    struct nodoArbol* der;
}nodoArbol;

typedef struct _nodoCelda{
    stSucursal dato;
    nodoArbol* arbol;
    struct _nodoCelda* siguiente;
}nodoCelda;

// ENCABEZADOS

// EJERCICIO 1
nodoCelda* archivoToLDA(char archivoAAbrir[], nodoCelda* lda);
nodoCelda* alta(nodoCelda* lda, stDisfraz nuevoDisfraz, stSucursal nuevaSucursal);
nodoCelda* buscarNodoCelda(nodoCelda* lda, stSucursal nuevaSucursal);
nodoCelda* inicListaCeldas();
nodoCelda* crearNodoCeldas(stSucursal nuevaSucursal);
nodoCelda* agregarAlPpioCeldas(nodoCelda* lista, nodoCelda* nuevoNodo);
nodoArbol* inicArbol();
nodoArbol* crearNodoArbol(stDisfraz dato);
nodoArbol* insertar(nodoArbol* arbol, stDisfraz dato);

// EJERCICIO 2
void mostrarLDA(nodoCelda* lda);
void mostrarCelda(nodoCelda* celda);
void inOrder(nodoArbol* arbol);
void mostrarDisfraz(stDisfraz dato);

// EJERCICIO 3
int buscarDisfracesEnSucursales(nodoCelda* lda, stSucursal array[], char nombre[], char genero[] ,int validos);
nodoArbol* buscarPorNombreYGenero(nodoArbol* arbol, char nombre[], char genero[]);
void mostrarArray(stSucursal array[], int validos);
void mostrarSucursal(stSucursal dato);

// EJERCICIO 4
stSucursal menorCantPorGenero(nodoCelda* lda, char genero[]);
int sumarCantPorGenero(nodoArbol* arbol, char genero[]);

// EJERCICIO 5
float porcentajeDeStockSegunTienda(nodoCelda* lda, int id);
int sumarStockDeSucursal(nodoCelda* lda, int id);
int sumarStockTotal(nodoCelda* lda);
int sumarStockDelArbol(nodoArbol* arbol);

int main()
{
    // EJERCICIO 1
    printf("\nEJERCICIO 1: \n");
    nodoCelda* lda = inicListaCeldas();
    lda = archivoToLDA("archivoRegistrosDisfraces.bin", lda);

    //EJERCICIO 2
    printf("\nEJERCICIO 2: \n");
    mostrarLDA(lda);

    //EJERCICIO 3
    printf("\nEJERCICIO 3: \n");
    stSucursal array[5];
    int validos = 0;
    validos = buscarDisfracesEnSucursales(lda, array, "payaso", "hombre", validos);
    mostrarArray(array, validos);

    //EJERCICIO 4
    printf("\nEJERCICIO 4: \n");
    stSucursal rta = menorCantPorGenero(lda, "hombre");
    mostrarSucursal(rta);

    //EJERCICIO 5
    printf("\nEJERCICIO 5: \n");
    int tienda = 1;
    float porcentaje = porcentajeDeStockSegunTienda(lda, tienda);
    printf("\nPorcentaje de la tienda %d: %.2f\n", tienda, porcentaje);

    return 0;
}

// FUNCIONES

// EJERCICIO 1

nodoCelda* archivoToLDA(char archivoAAbrir[], nodoCelda* lda){
    FILE *archivo = fopen(archivoAAbrir, "rb");
    registroArchivo nuevoRegistro;
    stSucursal nuevaSucursal;
    stDisfraz nuevoDisfraz;

    if(archivo){
        while(fread(&nuevoRegistro, sizeof(registroArchivo), 1, archivo) > 0){
            nuevaSucursal.idSucursal = nuevoRegistro.idSucursal;
            strcpy(nuevaSucursal.nombreSucursal, nuevoRegistro.nombreSucursal);
            strcpy(nuevoDisfraz.generoDisfraz, nuevoRegistro.generoDisfraz);
            strcpy(nuevoDisfraz.nombreDisfraz, nuevoRegistro.nombreDisfraz);
            nuevoDisfraz.stockDisfraz = nuevoRegistro.stockDisfraz;

            lda = alta(lda, nuevoDisfraz, nuevaSucursal);
        }
        fclose(archivo);
    }else{
        printf("El archivo en NULL");
    }
    return lda;
}


nodoCelda* alta(nodoCelda* lda, stDisfraz nuevoDisfraz, stSucursal nuevaSucursal){
    nodoCelda* rta = buscarNodoCelda(lda, nuevaSucursal);

    if(rta == NULL){
        nodoCelda* nuevaCelda = crearNodoCeldas(nuevaSucursal);
        lda = agregarAlPpioCeldas(lda, nuevaCelda);
        rta = lda;
    }
    rta->arbol = insertar(rta->arbol, nuevoDisfraz);

    return lda;
}

nodoCelda* buscarNodoCelda(nodoCelda* lda, stSucursal nuevaSucursal){
    nodoCelda* rta = NULL;
    nodoCelda* seg = lda;
    int flag = 0;
    int i = 0;

    while(seg && flag == 0){
        if(seg->dato.idSucursal == nuevaSucursal.idSucursal){
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

nodoCelda* crearNodoCeldas(stSucursal nuevaSucursal){
    nodoCelda* aux = (nodoCelda*) malloc(sizeof(nodoCelda));
    aux->dato = nuevaSucursal;
    aux->arbol = inicArbol();
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
    return lista;
}

nodoArbol* inicArbol(){
    return NULL;
}

nodoArbol* crearNodoArbol(stDisfraz dato){
    nodoArbol* aux = malloc(sizeof(nodoArbol));

    aux-> dato = dato;
    aux-> izq = NULL;
    aux-> der = NULL;

    return aux;
}

nodoArbol* insertar(nodoArbol* arbol, stDisfraz dato){
    if(arbol == NULL){
        arbol = crearNodoArbol(dato);
    }else{
        if(strcmp(dato.nombreDisfraz, arbol->dato.nombreDisfraz) > 0){
            arbol-> der = insertar(arbol-> der, dato);
        }else{
            arbol-> izq = insertar(arbol-> izq, dato);
        }
    }
    return arbol;
}

// 2 MOSTRAR INORDER (ORDEN ALFABETICO)

void mostrarLDA(nodoCelda* lda){
    if(lda){
        nodoCelda* seguidora = lda;
        printf("\n*******************************LDA****************************************************\n");
        while(seguidora){
            mostrarCelda(seguidora);
            seguidora = seguidora->siguiente;
            printf("\n###############################################################################\n");
        }
        printf("\n*******************************LDA****************************************************\n");
    }else{
        printf("\nLDA Vacia!\n");
    }
}

void mostrarCelda(nodoCelda* celda){
    printf("\nId Sucursal: %d", celda->dato.idSucursal);
    printf("\nNombre de la Sucursal: %s", celda->dato.nombreSucursal);
    printf("\nArbol:\n");
    inOrder(celda->arbol);
}

void inOrder(nodoArbol* arbol){
    if(arbol){
        inOrder(arbol->izq);
        mostrarDisfraz(arbol->dato);
        inOrder(arbol->der);
    }
}

void mostrarDisfraz(stDisfraz dato){
    printf("\nNombre del Disfraz: %s", dato.nombreDisfraz);
    printf("\nGenero del Disfraz: %s", dato.generoDisfraz);
    printf("\nStock: %d\n", dato.stockDisfraz);
}

// EJERCICIO 3

int buscarDisfracesEnSucursales(nodoCelda* lda, stSucursal array[], char nombre[], char genero[] ,int validos){
    nodoArbol* rta = NULL;
    if(lda){
        nodoCelda* seguidora = lda;
        while(seguidora){
            if(seguidora->arbol){
                rta = buscarPorNombreYGenero(seguidora->arbol, nombre, genero);
                if(rta){
                    array[validos] = seguidora->dato;
                    validos ++;
                }
            }
            seguidora = seguidora->siguiente;
            rta = NULL;
        }
    }
    return validos;
}

nodoArbol* buscarPorNombreYGenero(nodoArbol* arbol, char nombre[], char genero[]){
    nodoArbol* rta = NULL;
    if(arbol){
        if(strcmpi(nombre, arbol->dato.nombreDisfraz) == 0 && strcmpi(genero, arbol->dato.generoDisfraz) == 0 && arbol->dato.stockDisfraz > 0){
            rta = arbol;
        }else{
            rta = buscarPorNombreYGenero(arbol->izq, nombre, genero); // mal, el arbol estaba ordenado por nombre, tendria que haber recorrido el arbol sabiendo que podia ir a la izq o der
            if(rta == NULL){
                rta = buscarPorNombreYGenero(arbol->der, nombre, genero);
            }
        }
    }
    return rta;
}

void mostrarArray(stSucursal array[], int validos){
    int i = 0;
    while(i < validos){
        mostrarSucursal(array[i]);
        i++;
    }
}

void mostrarSucursal(stSucursal dato){
    printf("\n-------------------------------------\n");
    printf("\nId Sucursal: %d", dato.idSucursal);
    printf("\nSucursal: %s", dato.nombreSucursal);
    printf("\n-------------------------------------\n");
}

// EJERCICIO 4

stSucursal menorCantPorGenero(nodoCelda* lda, char genero[]){
    stSucursal rta;
    if(lda){
        nodoCelda* seguidora = lda;
        rta = seguidora->dato;
        int rtaSuma = 9999; // no hardcodear, inicilizar con la suma de la primera tienda
        int cantidad = 0;

        while(seguidora){
            cantidad = sumarCantPorGenero(seguidora->arbol, genero);
            if(cantidad < rtaSuma){
                rta = seguidora->dato;
                rtaSuma = cantidad;
            }
            seguidora = seguidora->siguiente;
        }
    }
    return rta;
}

int sumarCantPorGenero(nodoArbol* arbol, char genero[]){
    int rta = 0;
    if(arbol){
        if(strcmp(arbol->dato.generoDisfraz, genero) == 0){
            rta = 1 + sumarCantPorGenero(arbol->izq, genero) + sumarCantPorGenero(arbol->der, genero); // mal, tenia que sumar arbol->dato.stockDisfraz en vez de poner 1
        }else{
            rta = sumarCantPorGenero(arbol->izq, genero) + sumarCantPorGenero(arbol->der, genero);
        }
    }
    return rta;
}

// EJERCICIO 5

float porcentajeDeStockSegunTienda(nodoCelda* lda, int id){
    int total = sumarStockTotal(lda);
    int totalTienda = sumarStockDeSucursal(lda, id);
    float rta = (float) totalTienda*100 / (float) total;

    return rta;
}

int sumarStockDeSucursal(nodoCelda* lda, int id){
    int rta = 0;
    if(lda){
        nodoCelda* seguidora = lda;
        int flag = 0;
        while(flag == 0 && seguidora){
            if(seguidora->dato.idSucursal == id){
                rta = sumarStockDelArbol(seguidora->arbol);
                flag = 1;
            }
            if(flag == 0){
                seguidora = seguidora->siguiente;
            }
        }
        if(seguidora == NULL){
            printf("\nEl ID de la sucursal que ingresaste no es correcto\n");
            rta = 0;
        }
    }
    return rta;
}

int sumarStockTotal(nodoCelda* lda){
    int rta = 0;
    if(lda){
        nodoCelda* seguidora = lda;
        while(seguidora){
            rta = rta + sumarStockDelArbol(seguidora->arbol);
            seguidora = seguidora->siguiente;
        }
    }
    return rta;
}

int sumarStockDelArbol(nodoArbol* arbol){
    int rta = 0;
    if(arbol){
        rta = arbol->dato.stockDisfraz + sumarStockDelArbol(arbol->izq) + sumarStockDelArbol(arbol->der);
    }
    return rta;
}
