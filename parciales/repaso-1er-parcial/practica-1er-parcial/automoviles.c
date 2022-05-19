#include "automoviles.h"

void inicLista(nodoAuto** lista){
    *lista = NULL;
}

automovil nuevoVehiculo(){
    automovil vehiculo;

    printf("\nPatente: ");
    fflush(stdin);
    gets(vehiculo.patente);
    printf("\nValor: ");
    fflush(stdin);
    scanf("%d", &vehiculo.valor);
    printf("\nMarca: ");
    fflush(stdin);
    gets(vehiculo.marca);

    return vehiculo;
}

nodoAuto* crearNodo(automovil vehiculo){
    nodoAuto* aux = (nodoAuto*) malloc(sizeof(nodoAuto));
    aux-> dato = vehiculo;
    aux-> siguiente = NULL;

    return aux;
}

void agregarAlFinal(nodoAuto** lista, nodoAuto*  nuevoNodo){
    if(*lista == NULL){
        *lista = nuevoNodo;
    }else{
        nodoAuto* aux = *lista;
        if(aux){
            while(aux-> siguiente != NULL){
                aux = aux-> siguiente;
            }
            aux-> siguiente = nuevoNodo;
        }
    }
}

void mostrarAuto(automovil aux){
    printf("\nPatente: %s", aux.patente);
    printf("\nPrecio: %d", aux.valor);
    printf("\nMarca: %s\n", aux.marca);
}

void mostrarLista(nodoAuto* lista){
    nodoAuto* aux = lista;
    printf("\n*********************LISTA*****************************\n");
    while(aux){
        mostrarAuto(aux-> dato);
        aux = aux-> siguiente;
    }
    printf("\n\n*********************LISTA*****************************\n");
}

int insertarCelda(automovil Array[], int dim, automovil dato, int validos){ // VER PORQUE DEVUELVE BASURA EN LA ULTIMA POSICION
    int i = validos-1; // Arranco desde el final
    while(i >= 0 && Array[i].valor > dato.valor){ // Voy de atras para adelante y evaluo si el dato de la posicon actual del array es mayor a la del dato a insertar
        Array[i+1] = Array[i]; // Copio lo que hay en la posicion actual uno a la derecha (i+1)
        i--; // Voy yendo para el principio del array
    }
    Array[i+1] = dato; // Cuando se encontro el lugar para guardar el dato lo guardo en la posicion i+1 ya que i quedo posicionado sobre el numero mas chico, entonces lo tenemos que guardar a la derecha de este

    return validos + 1; // Retorno validos + 1 ya que hay un nuevo elemento en el array
}

void agregarMuchos(nodoAuto** lista){
    char control = 's';

    while(control == 's'){
        automovil vehiculo = nuevoVehiculo();
        nodoAuto* nuevoNodo = crearNodo(vehiculo);
        agregarAlFinal(lista, nuevoNodo);

        printf("\nAgregar otro vehiculo (s/n)\n");
        fflush(stdin);
        scanf("%c", &control);
    }
}

int pasar(nodoAuto* lista, automovil Array[], int dim){
    nodoAuto* aux = lista;
    int i = 0;
    while(aux && i < dim){ // Mientras haya elementos en aux e i sea menor a la dimension del array
        automovil dato = aux-> dato;
        i = insertarCelda(Array, dim, dato, i);
        aux = aux-> siguiente;
    }
    return i;
}

void mostrarArrayRecursivo(automovil Array[], int validos, int i){
    if(i < validos){
        mostrarAuto(Array[i]);
        mostrarArrayRecursivo(Array, validos, i+1);
    }
}

int sumarPares(nodoAuto* lista){
    int suma = 0;
    while(lista){
        int validos = strlen(lista-> dato.patente); // Obtengo la cantidad de caracteres que hay en la patente
        int numero = (int)lista-> dato.patente[validos-1]; // Obtengo el ultimo digito de la patente para poder evaluar si el numero es par o impar (casteo el valor del string con int)
        if(numero%2==0){ // Evaluo si el numero que obtuve es par o no
            suma = suma + lista-> dato.valor;
        }
        lista = lista-> siguiente;
    }
    return suma;
}
