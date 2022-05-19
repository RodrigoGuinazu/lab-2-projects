#include "listas-dobles.h"

nodoDoble* inicLista(){
    return NULL;
}

nodoDoble* crearNodo(int dato){
    nodoDoble* aux = (nodoDoble*) malloc(sizeof(nodoDoble));
    aux-> num = dato;
    aux-> anterior = NULL;
    aux-> siguiente = NULL;

    return aux;
}

nodoDoble* agregarAlPpio(nodoDoble* lista, nodoDoble* nuevoNodo){
    if(lista == NULL){
        lista = nuevoNodo;
    }else{
        nuevoNodo-> siguiente = lista; // el campo siguiente del nuevo nodo que vamos agregar apuntara a la lista sobre la que estamos trabajando
        lista-> anterior = nuevoNodo; /// donde apuntaba el campo anterior del primer nodo de la lista (antes de que se agregara el nuevoNodo), ahora apunta hacia el nuevoNodo (nueva linea)
        lista = nuevoNodo; // la lista ahora comienza desde el nuevoNodo que agregamos
    }

    return lista;
}

nodoDoble* agregarAlPpioCorta(nodoDoble* lista, nodoDoble* nuevoNodo){ /// esta funcion retorna directamente el nuevoNodo apuntando hacia la lista, SOLO FUNCIONA CON PUNTERO SIMPLE!
    nuevoNodo-> siguiente = lista; // en caso de que la lista tenga elementos o este vacia esta linea se va ejecutar si o si, entonces lo ponemos por fuera del ifs
    if(lista){
        lista-> anterior = nuevoNodo; // donde apuntaba el campo anterior del primer nodo de la lista (antes de que se agregara el nuevoNodo), ahora apunta hacia el nuevoNodo
    }

    return nuevoNodo; /// cuando llamemos a la funcion en el main guardamos el resultado de esta funcion en la lista, de esa forma no hace falta que retornemos la lista dentro de la funcion
}

nodoDoble* cargarListaAlPpio(nodoDoble* lista){
    char control = 's';

    int aux;
    nodoDoble* nuevoNodo;

    while(control=='s'){
        printf("\nIngrese un numero: ");
        scanf("%d", &aux);
        nuevoNodo = crearNodo(aux);
        lista = agregarAlPpioCorta(lista, nuevoNodo);

        printf("\nIngresar otro?\n");
        fflush(stdin);
        scanf("%c", &control);
    }
    return lista;
}

void mostrarNodo(nodoDoble* aux){
    printf("\n-------------------\n");
    printf("\n%d\n", aux-> num);
    printf("\n-------------------\n");
}

void mostrarLista(nodoDoble* lista){
    if(lista){
        nodoDoble* seguidora = lista; // copia de seguridad

        printf("\n**********************************FILA*******************************************\n");
        while(seguidora){
            printf(" %d", seguidora-> num);
            seguidora = seguidora-> siguiente; // me muevo hacia el siguiente nodo en la lista
        }
        printf("\n**********************************************************************************\n");
    }else{
        printf("\nLa lista esta vacia!\n");
    }
}

nodoDoble* buscarElUltimo(nodoDoble* lista){
    nodoDoble* ultimo = lista; // de entrada lo igualamos a lista, ya que si la lista es NULL retornamos eso
    if(ultimo){
        while(ultimo-> siguiente){ // hasta llegar al final
            ultimo = ultimo-> siguiente; // me muevo hacia el siguiente nodo en la lista
        }
    }
    return ultimo;
}

nodoDoble* agregarAlFinal(nodoDoble* lista, nodoDoble* nuevoNodo){
    if(lista == NULL){
        lista = nuevoNodo;
    }else{
        nodoDoble* ultimo = buscarElUltimo(lista);
        nuevoNodo-> anterior = ultimo; /// enlazamos el anterior del nuevoNodo con el ultimo nodo que habia en la lista antes de agregar el nuevoNodo (nueva linea)
        ultimo-> siguiente = nuevoNodo; // el ultimo nodo de la lista ahora apunta hacia el nuevo nodo
    }
    return lista; // Se retorna la lista ya que hay que tener en cuenta que en el caso de que el primer primer if sea verdadero debemos retornarla, en el resto de los casos aunque trabajemos sobre el aux los nodos de la lista van a quedar modificados
}

nodoDoble* nodoABuscar(nodoDoble* lista, int num){
    nodoDoble* seguidora = lista;

    if(lista){
        while(seguidora && seguidora-> num != num){
            seguidora = seguidora-> siguiente;
        }
    }

    return seguidora;
}

/*  En el main
nodoDoble* busqueda = nodoABuscar(lista, 420); /// en caso de que exista no puedo retornar seguidora ya que es NULL
if(busqueda){
    mostrarNodo(busqueda);
}else{
    printf("\nEl nodo buscado no existe en la lista\n");
}
*/

int retornarPrimerNumero(nodoDoble* lista){
    int rta = -1;
    if(lista){
        rta = lista-> num;
    }
    return rta;
}

nodoDoble* borrarPrimerNodo(nodoDoble* lista){
    if(lista){
        nodoDoble* aBorrar = lista;
        lista = lista-> siguiente; // lista ahora apunta al siguiente nodo
        if(lista != NULL){
            lista-> anterior = NULL; /// nueva linea
        }
        free(aBorrar);
    }

    return lista;
}

nodoDoble* borrarListaCompleta(nodoDoble* lista){
    nodoDoble* aBorrar;

    while(lista != NULL){ // mientras la lista tenga algo
        aBorrar = lista; // aBorrar ahora apunta a donde apunta la lista
        lista = lista-> siguiente; // lista ahora apunta al siguiente nodo
        free(aBorrar); // libero el espacio
    }

    return lista;
}

nodoDoble* insertarEnOrden(nodoDoble* lista, nodoDoble* nuevoNodo){
    if(lista == NULL){ // en caso de que la lista este vacia
        lista = nuevoNodo; // el campo anterior del nodo seguidora (nodo a la derecha de donde quedo insertado el nuevoNodo) apunta hacia el nuevoNodo
    }else{
        if(lista-> num > nuevoNodo-> num){ // en caso de que haya que insertar el nodo en la 1ra posicion
            nuevoNodo-> siguiente = lista; // nuevo nodo ahora apunta hacia el que le sigue en la lista
            if(lista-> siguiente){ // en caso que la lista NO este posicionado en NULL (fin de la lista), si la lista esta posicionado en el NULL salteamos el if, ya que NULL no es un nodo y por ende no tiene un campo anterior
                lista-> anterior = nuevoNodo; // el campo anterior del nodo que esta delante del nuevoNodo ahora apunta hacia el nuevoNodo
            }
            lista = nuevoNodo; // ahora la lista apunta a el nuevoNodo
        }else{ // en caso de que haya que insertarlo en cualquier lugar menos el primero
            nodoDoble* ante = lista;
            nodoDoble* seguidora = lista-> siguiente; // arrancamos la seguidora desde el segundo nodo, ya que nosotros evaluamos si el nodo a insertar debia ir primero en la linea 156, como no cumplio esa condicion ya sabemos que el primer elemento es menor al del nuevoNodo

            while(seguidora && (seguidora-> num) < (nuevoNodo-> num)){ // en caso de que seguidora no sea NULL y que el nuevoNodo sea mayor al nodo de seguidora
                ante = seguidora; // avanzo hacia el siguiente
                seguidora = seguidora-> siguiente; // avanzo hacia el siguiente
            }

            ante-> siguiente = nuevoNodo; // el campo siguiente del nodo que se encuentra a la izquierda de donde vamos a insertar el nuevoNodo apunta hacia nuevoNodo
            nuevoNodo-> siguiente = seguidora; // el campo siguiente de nuevoNodo ahora apunta hacia donde quedo posicionado la variable seguidora
            nuevoNodo-> anterior = ante; // el campo anterior de nuevoNodo ahora apunta hacia donde quedo posicionado la variable ante
            if(seguidora){ // en caso que seguidora no este posicionado en NULL (fin de la lista), si la lista esta posicionado en el NULL salteamos el if
                seguidora-> anterior = nuevoNodo; // el campo anterior del nodo seguidora (nodo a la derecha de donde quedo insertado el nuevoNodo) apunta hacia el nuevoNodo
            }
        }
    }
    return lista;
}

nodoDoble* borrarNodo(nodoDoble* lista, int num){
    if(lista){ // solo si la lista contiene algo, en caso de que este vacia saltamos este if y retornamos la lista
        if(lista-> num == num){ // en caso de que el nodo a borrar este en la 1ra posicion
            nodoDoble* aBorrar = lista; // guardamos el aBorrar igualando a lista, ya que lista apunta hacia el primer nodo
            lista = lista-> siguiente; // lista ahora apunta al segundo nodo de la lista, que seria el siguiente de la lista
            if(lista){ // en caso que la lista NO este posicionado en NULL (fin de la lista), si la lista esta posicionado en el NULL salteamos el if, ya que NULL no es un nodo y por ende no tiene un campo anterior
                lista-> anterior = NULL; // el campo anterior del nodo que esta delante del nuevoNodo ahora apunta hacia el nuevoNodo
            }
            free(aBorrar); // borramos el nodo que guardamos en la variable aBorrar
        }else{ // en caso de que el nodo a borrar se encuentre en cualquier posicion de la lista menos en la 1ra posicion
            nodoDoble* seguidora = lista-> siguiente; // arrancamos una poscion mas adelante ya que sabemos que el primero no es el nodo a borrar, tampoco necesitamos ante

            while(seguidora && seguidora-> num != num){ // iteramos mientras seguidora no sea NULL y el numero del nodo sea desigual al del elemento que queremos borrar
                seguidora = seguidora-> siguiente; // avanzamos
                // no usamos ante ya que podemos acceder atraves del campo anterior del nodo seguidora
            }

            if(seguidora){ // en caso de que seguidora contenga algo, esto quiere decir que seguidora es el nodo a borrar
                nodoDoble* ante = seguidora-> anterior; // declaro la variable ante, que guarda el nodo que va antes del nodo seguidora (seguidora-> anterior)
                ante-> siguiente = seguidora-> siguiente; // el siguiente del nodo ante es igual al nodo que le sigue al nodo seguidora
                if(seguidora-> siguiente){ // si seguidora siguiente no es NULL
                    nodoDoble* sig = seguidora-> siguiente; // creamos una variable extra para poder guardar al siguiente de la variable seguidora, ya que seguidora es el nodo que vamos a borrar
                    sig-> anterior = ante; // el campo anterior del nodo que creamos arriba es igual al nodo ante que creamos unas lineas mas arriba
                }
                free(seguidora); // borramos el nodo seguidora que es donde se encuentra el campo que pasamos por parametro
            }else{ // en caso de que seguidora sea NULL, esto quiere decir que el elemento buscado no existia en la listas
                printf("\nEl elemento que deseas borrar no existe en la lista\n");
            }
        }
    }
    return lista;
}

int listaVacia(nodoDoble* lista){
    if(lista == NULL){
        return 1;
    }else{
        return 0;
    }
}

int esCapicua(nodoDoble* principio, nodoDoble* fin){
    int flag = 1;
    if(principio && fin && (principio != fin)){
        if(principio-> num == fin-> num){
            flag = esCapicua(principio-> siguiente, fin-> anterior);
        }else{
            flag = 0;
        }
    }
    return flag;
}

int validos(nodoDoble* lista){
    int validos = 0;
    nodoDoble* seguidora = lista;
    while(seguidora){
        validos++;
        seguidora = seguidora-> siguiente;
    }
    return validos;
}

nodoDoble* borrarElDelMedio(nodoDoble* lista){
  int i = validos(lista);
  int posicionCentral = i/2 + 1;

  int posicion = 1;

  nodoDoble* nodoActual = lista;
  while(nodoActual != NULL){
    if(posicion == posicionCentral){
      lista = borrarNodo(lista, nodoActual-> num);
      break;
    }
    posicion++;
    nodoActual = nodoActual-> siguiente;
  }

  return lista;
}

/*
nodoDoble* borrarElDelMedio(nodoDoble* lista){
    int i = validos(lista);
    nodoDoble* principio = lista;
    nodoDoble* fin = buscarElUltimo(lista);

    if(i%2 == 0){
        int i;
        while(i/2 != i){
            principio = principio-> siguiente;
            fin = fin-> anterior;
            i++;
        }
        if(principio-> num > fin-> num){
            nodoDoble* aBorrar = principio;
            principio-> siguiente = fin-> anterior;
            fin-> siguiente = principio-> anterior;
            free(aBorrar);
        }else{
            nodoDoble* aBorrar = fin;
            principio-> siguiente = fin-> anterior;
            fin-> siguiente = principio-> anterior;
            free(aBorrar);
        }
    }else{
        while(principio != fin){
            principio = principio-> siguiente;
            fin = fin-> anterior;
        }
        nodoDoble* aBorrar = principio;
        principio-> siguiente = fin-> anterior;
        fin-> siguiente = principio-> anterior;
        free(aBorrar);
    }
    return lista;
}
*/
