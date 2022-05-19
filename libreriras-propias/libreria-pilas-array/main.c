#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int * valores;
    int posTope;
}Pila;

void inicpila(Pila * pila);
void inicpilaFlexible(Pila * pila, int dimension);
void apilar(Pila * pila, int num);
void leer(Pila * pila);
int desapilar(Pila * pila);
int tope(Pila * pila);
int pilavacia(Pila * pila);
void mostrar(Pila * pila);

int main()
{
    printf("Libreria propia de Pilas\n");
    Pila dada;
    inicpila(&dada);
    apilar(&dada, 1);
    apilar(&dada, 2);
    leer(&dada);
    tope(&dada);
    desapilar(&dada);
    pilavacia(&dada);
    mostrar(&dada);
    return 0;
}

void inicpila(Pila * pila){
    pila -> valores = (int*) malloc(sizeof(int) * 100);
    pila-> posTope = 0;
}

void inicpilaFlexible(Pila * pila, int dimension){ /// En esta funcion podemos preguntar por parametro la dimension de la Pila
    pila -> valores = (int*) malloc(sizeof(int) * dimension);
    pila-> posTope = 0;
}

void apilar(Pila * pila, int num){
    pila-> valores[pila-> posTope] = num;
    pila-> posTope++;
}

void leer(Pila * pila){
    int num;
    if(pila-> posTope < 100){
        printf("Ingresa un numero: ");
        scanf("%d", &num);
        apilar(pila, num); /// Uso la funcion apilar que cree antes
    }else{
        printf("La pila esta llena");
    }
}

int desapilar(Pila * pila){
    int num;
    if(pila-> posTope > 0){
        num = pila-> valores[pila-> posTope-1];
        pila-> posTope--;
    }else{
        printf("La pila ya esta vacia");
    }
    return num;
}

int tope(Pila * pila){
    int num;
    if(pila-> posTope > 0){
        num = pila-> valores[pila-> posTope-1];
    }else{
        printf("La pila esta vacia");
        num = 0;
    }
    return num;
}

int pilavacia(Pila * pila){
    if(pila-> posTope >= 1){
        printf("\nLa pila NO esta vacia\n");
        return 1;
    }else{
        printf("\nLa pila ESTA vacia\n");
        return 0;
    }
}

void mostrar(Pila * pila){
    int i;
    if(pila-> posTope > 0){
        printf("\nBase ----------------------------------------- Tope\n\n");

        for(i = 0; i < (pila-> posTope); i++){
            printf(" %d", pila-> valores[i]);
        }

        printf("\n\nBase ----------------------------------------- Tope\n");
    }else{
        printf("La pila esta vacia");
    }
}
