#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/*
1. Calcular el factorial de un número en forma recursiva.
2. Calcular la potencia de un número en forma recursiva.
3. Recorrer un arreglo y mostrar sus elementos en forma recursiva.
4. Recorrer un arreglo comenzando desde la posición 0 y mostrar sus elementos en
forma invertida (recursivo).
5. Determinar en forma recursiva si un arreglo es capicúa.
6. Sumar en forma recursiva los elementos de un arreglo de enteros y retornar el total de la suma.
7. Buscar el menor elemento de un arreglo en forma recursiva.
8. Buscar el menor elemento de un archivo de números enteros de forma recursiva.
9. Invertir los elementos de un archivo de números enteros de forma recursiva.
10. Recorrer un archivo y mostrar sus elementos en forma invertida de forma recursiva.
11. Ingresar valores a una variable de tipo char (por teclado) y mostrarlo en el orden inverso (hasta ingresar un ‘*’) de forma recursiva. NO usar arreglos.
12. Determinar si un arreglo contiene un determinado elemento de forma recursiva.
*/

int factorialRecursivo(int x);
int potenciaRecursiva(int x, int exponente);
void recorrerArregloRecursivamente(int array[], int validos, int i);
void recorrerArregloRecursivamenteInvertido(int array[], int validos, int i);
int esCapicua(int array[], int validos, int i);
void sumaRecursiva(int array[], int validos, int i, int *suma);
void menorElemento(int array[], int validos, int i, int *menor);
void cargarNumeros(char archivoNumeros[]);
int mostrarArchivo(char archivoNumeros[]);
int abrirArchivoRecursivoBuscandoElMenor(char archivoNumeros[]);
int buscarMenorEnArchivo(FILE * archivo);
FILE * abrirArchivo(char archivoNumeros[]);
void cerrarArchivo(FILE * archivo);
void abrirArchivoRecursivamenteInvirtiendolo(char archivoNumeros[], int validos);
void invertirArchivoRecursivamente(FILE * archivo, int validos, int i);
FILE * abrirArchivoParaInvertir(char archivoNumeros[]);
void imprimirHasta();
int contieneElElemento(int array[], int validos, int i, int num);

int main()
{
    printf("\nEjercicio 1\n");
    int nro = 5;
    int rta1 = factorialRecursivo(nro);
    printf("El factorial de %d es: %d\n", nro, rta1);

    printf("\nEjercicio 2\n");
    int potencia = 3;
    int rta2 = potenciaRecursiva(nro, potencia);
    printf("%d elevado a %d es: %d\n", nro, potencia, rta2);

    printf("\nEjercicio 3\n");
    int array[5] = {1, 2, 3, 4, -1};
    int validos = 5;
    recorrerArregloRecursivamente(array, validos, 0);

    printf("\nEjercicio 4\n");
    recorrerArregloRecursivamenteInvertido(array, validos, 0);

    printf("\nEjercicio 5\n");
    int arrayCapicua[5] = {1, 2, 3, 2, 1};
    int capicua = esCapicua(arrayCapicua, validos, 0);
    if(capicua == 0){
        printf("\nEl array NO es capicua!\n");
    }else{
        printf("\nEl array ES capicua!\n");
    }

    printf("\nEjercicio 6\n");
    int suma = 0;
    sumaRecursiva(array, validos, 0, &suma);
    printf("\nLa suma de los elementos del array es: %d\n", suma);

    printf("\nEjercicio 7\n");
    int menor;
    menorElemento(array, validos, 0, &menor);
    printf("\nEl menor elemento del array es: %d\n", menor);

    printf("\nEjercicio 8\n");
    //cargarNumeros("archivoNumeros.dat");
    printf("\nListado de numeros:\n");
    int validosArchivo = mostrarArchivo("archivoNumeros.dat");
    int menorDelArchivo = abrirArchivoRecursivoBuscandoElMenor("archivoNumeros.dat");
    printf("\n\nEl menor del archivo es el: %d\n", menorDelArchivo);

    printf("\nEjercicio 9 y 10\n");
    abrirArchivoRecursivamenteInvirtiendolo("archivoNumeros.dat", validosArchivo); // validosArchivo lo saco del ej 8 cuando ejecuto mostrar archivo

    printf("\nEjercicio 11\n");
    imprimirHasta();

    printf("\nEjercicio 12\n");
    int rta3 = contieneElElemento(array, validos, 0, 4);
    if(rta3 == 1){
        printf("\nEl numero que ingresaste se encuentra en el array!\n");
    }else{
        printf("\nEl numero que ingresaste NO se encuentra en el array\n");
    }

    return 0;
}

int factorialRecursivo(int x){
    int rta;
    if(x==0){
        rta = 1;
    }else{
        rta = x * factorialRecursivo(x-1);
    }
    return rta;
}

int potenciaRecursiva(int base, int exponente){
    int rta = base;
    if(exponente==0){
        rta = 1;
    }else{
        rta = rta * potenciaRecursiva(base, exponente-1);
    }
    return rta;
}

void recorrerArregloRecursivamente(int array[], int validos, int i){
    if(validos==0){
        printf("\n");
    }else{
        printf(" %d", array[i]);
        recorrerArregloRecursivamente(array, validos-1, i+1);
    }
}

void recorrerArregloRecursivamenteInvertido(int array[], int validos, int i){
    if(validos==0){
        printf("");
    }else{
        recorrerArregloRecursivamenteInvertido(array, validos-1, i+1);
        printf(" %d", array[i]);
    }
}

int esCapicua(int array[], int validos, int i){
    int rta;
    if(i == validos-i || validos-i == 1){ // Cuando válidos es par corta cuando i es igual a válidos, y si válidos es impar va a cortar cuando i valga uno menos que válidos
        if(array[i] == array[(validos-1)-i]){ // Comparo que los numeros sean iguales en ambas posiciones
            rta=1;
        }
    }else{
       if(array[i] == array[(validos-1)-i]){ // Comparo que los numeros sean iguales en ambas posiciones
           rta = esCapicua(array, validos, i+1); // En vez de modificar válidos, hago que se aumente el i y el válidos lo resto por el i
       }else{
           rta = 0; // En caso de que no sean iguales retorna un 0
       }
    }
    return rta;
}

void sumaRecursiva(int array[], int validos, int i, int *suma){
    if(validos == 0){
        *suma = *suma + validos;
    }else{
        *suma = *suma + array[i];
        sumaRecursiva(array, validos-1, i+1, &*suma);
    }
}

void menorElemento(int array[], int validos, int i, int *menor){
    if(validos == 0){
        *menor = *menor + 0;
    }else{
        if(*menor > array[i]){
            *menor = array[i];
        }
        menorElemento(array, validos-1, i+1, &*menor);
    }
}

void cargarNumeros(char archivoNumeros[]){
    char control = 's';
    int numero;
    FILE *archivo = fopen(archivoNumeros, "ab");
    if(archivo){
        printf("\nQuiere cargar Numeros al archivo? (s/n)\n");
        fflush(stdin);
        scanf("%c", &control);
        while(control == 's'){
            printf("\nIngrese un numero: ");
            scanf("%i", &numero);

            fwrite(&numero, sizeof(int), 1, archivo);

            printf("\nCargar otro Numero? (s/n)\n");
            fflush(stdin);
            scanf("%c", &control);
        }
        fclose(archivo);
    }else {
        printf("El archivo en NULL");
    }
}

int mostrarArchivo(char archivoNumeros[]){
    FILE *archivo = fopen(archivoNumeros, "rb");
    int i = 0;
    int numero;
    if(archivo){
        while(fread(&numero, sizeof(int), 1, archivo) > 0){
            printf("\n%d", numero);
            i++;
        }
        fclose(archivo);
    }
    return i; // validos del archivo
}

int abrirArchivoRecursivoBuscandoElMenor(char archivoNumeros[]){ // con esta funcion evitamos abrir y cerrar el archivo al trabajar con recursividad
    FILE * archivo = abrirArchivo(archivoNumeros);
    int menor;

    if(archivo){
        menor = buscarMenorEnArchivo(archivo); // aca el archivo ya se abrio y no se va cerrar hasta que termine de trabajar en buscarMenorEnArchivo();
    }

    cerrarArchivo(archivo); // cierra el archivo una sola vez
    return menor;
}

int buscarMenorEnArchivo(FILE * archivo){
    int valor;
    int menor;
    if(archivo){
        if(fread(&valor, sizeof(int), 1, archivo) == 0){
            fseek(archivo, -1 * sizeof(int), SEEK_END);
            fread(&valor, sizeof(int), 1, archivo);
            menor = valor;
        }
        else{
            menor = buscarMenorEnArchivo(archivo);
            if(menor > valor){
                menor = valor;
            }
        }
    }

    return menor;
}

FILE* abrirArchivo(char archivoNumeros[]){ // auxiliares para hacer mas flexible las funciones
    FILE * archivo = fopen(archivoNumeros, "rb");

    if(archivo){
        return archivo;
    }
}

void cerrarArchivo(FILE * archivo){ // auxiliares para hacer mas flexible las funciones
    fclose(archivo);
}


void abrirArchivoRecursivamenteInvirtiendolo(char archivoNumeros[], int validos){
    FILE * archivo = abrirArchivoParaInvertir(archivoNumeros);

    if(archivo){
        invertirArchivoRecursivamente(archivo, validos, 0); // aca el archivo ya se abrio y no se va cerrar hasta que termine de trabajar en invertirArchivoRecursivamente();
    }

    cerrarArchivo(archivo); // cierra el archivo una sola vez

    validos = mostrarArchivo(archivoNumeros); // muestro el archivo invertido
}

void invertirArchivoRecursivamente(FILE * archivo, int validos, int i){
    int principio, fin;
    if(archivo){
        if(i < validos){
            fseek(archivo, sizeof(int)*(validos-1), 0); // validos-1 ya que para leer la ultima posicion del archivo nos tenemops que volver un paso atras
            fread(&fin, sizeof(int), 1, archivo); // guardo el ultimo numero del archivo, y a medida que se ejecuta la recursividad pasaria al anteultimo, y asi consecutivamente

            fseek(archivo, sizeof(int)*i, 0);
            fread(&principio, sizeof(int), 1, archivo); // guardo el primer numero del archivo, y a medida que se ejecuta la recursividad pasaria al segundo, y asi consecutivamente

            fseek(archivo, sizeof(int)*i, 0); // me posiciono en el principio del archivo, y a medida que se ejecuta la recursividad pasaria al segundo, y asi consecutivamente
            fwrite(&fin, sizeof(int), 1, archivo); // escribo en la posicion del fseek de arriba el numero que guarde en la variable fin

            fseek(archivo, sizeof(int)*(validos-1), 0); // me posiciono en el final del archivo, y a medida que se ejecuta la recursividad pasaria al anteultimo, y asi consecutivamente
            fwrite(&principio, sizeof(int), 1, archivo); // escribo en la posicion del fseek de arriba el numero que guarde en la variable principio

            invertirArchivoRecursivamente(archivo, validos-1, i+1); // vamos restando los validos y sumando el i para que se corte la condicion de i < validos
        }
    }
}

FILE * abrirArchivoParaInvertir(char archivoNumeros[]){
    FILE * archivo = fopen(archivoNumeros, "r+b"); // r+b ya que vamos a intercambiar los valores del archivo

    if(archivo){
        return archivo;
    }
}

void imprimirHasta(){
    char letra;
    printf("\nIngrese una letra, si no desea cargar mas letras ingrese el caracter '*'\n");
    fflush(stdin);
    scanf("%c", &letra);
    if(letra != '*'){ // solucion trivial implicita
        imprimirHasta();
        printf(" %c", letra); // printf abajo de la llamada recursiva imprime en orden inverso, si estuviese arriba los imprimira en orden
    }
}

int contieneElElemento(int array[], int validos, int i, int num){
    int rta = 0; // supongo que no existe
    if(validos > i){
        if(array[i]==num){
            rta = 1;
        }else{
            rta = contieneElElemento(array, validos, i+1, num);
        }
    }
    return rta;
}
