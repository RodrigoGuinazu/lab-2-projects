#include "listas-de-listas.h"

// LISTAS nodoNota
nodoNota* inicListaNotas(){
    return NULL;
}

nodoNota* crearNodoNotas(stNotaAlumno alumno){
    nodoNota* aux = (nodoNota*) malloc(sizeof(nodoNota));
    aux-> dato = alumno;
    aux-> siguiente = NULL;

    return aux;
}

nodoNota* agregarAlFinalNotas(nodoNota* lista, nodoNota* nuevoNodo){
    if(lista == NULL){
        lista = nuevoNodo;
    }else{
        nodoNota* aux = lista;
        if(aux){
            while(aux-> siguiente != NULL){
                aux = aux-> siguiente; // itero hasta llegar al final de la lista
            }
        }
        aux-> siguiente = nuevoNodo; // hago que el nodo que apuntaba a NULL previamente ahora apunte al nuevoNodo
    }
    return lista; // Se retorna la lista ya que hay que tener en cuenta que en el caso de que el primer primer if sea verdadero debemos retornarla, en el resto de los casos aunque trabajemos sobre el
}

void mostrarListaNotas(nodoNota* lista){
    if(lista){
        nodoNota* seguidora = lista; // copia de seguridad

        printf("\n**********************************LISTA*******************************************\n");
        while(seguidora){
            mostrarAlumno(seguidora-> dato);
            seguidora = seguidora-> siguiente; // me muevo hacia el siguiente nodo en la lista
        }
        printf("\n**********************************************************************************\n");
    }else{
        printf("\nLa lista esta vacia!\n");
    }
}

void mostrarAlumno(stNotaAlumno alumno){
    printf("\nNombre: %s\n", alumno.nombreApe);
    printf("Legajo: %d\n", alumno.legajo);
    printf("Nota: %d\n", alumno.nota);
}

// LISTAS nodoCelda

nodoCelda* inicListaCeldas(){
    return NULL;
}

nodoCelda* crearNodoCeldas(stMateria materia){
    nodoCelda* aux = (nodoCelda*) malloc(sizeof(nodoCelda));
    aux-> materia = materia;
    aux-> lista = NULL;
    aux-> siguiente = NULL;

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

        printf("\n**************************LDL*********************************\n");
        while(seguidora){
            mostrarCelda(seguidora);
            seguidora = seguidora-> siguiente; // me muevo hacia el siguiente nodo en la lista
            printf("\n########################################################################################################\n");
        }
        printf("\n**************************LDL*********************************\n");
    }else{
        printf("\nLa lista esta vacia!\n");
    }
}

void mostrarCelda(nodoCelda* celda){
    printf("ID de la Materia: %d\n", celda->materia.id);
    printf("\Materia........: %s\n", celda->materia.nombre);
    printf("Lista de Notas\n\n");
    mostrarListaNotas(celda->lista);
}

// PASAR DE ARCHIVO A LDL (LISTA DE LISTAS)

nodoCelda* pasarDeArchivoToLDL(char archivoAAbrir[], nodoCelda* ldl){
    FILE *archivo = fopen(archivoAAbrir, "rb");
    registroArchivo nuevoRegistro;
    stMateria materia;
    stNotaAlumno alumno;

    if(archivo){
        while(fread(&nuevoRegistro, sizeof(registroArchivo), 1, archivo) > 0){
            materia = nuevoRegistro.materia;
            alumno = nuevoRegistro.alumno;
            ldl = alta(ldl, materia, alumno);
        }
        fclose(archivo);
    }else{
        printf("El archivo en NULL");
    }
    return ldl;
}

// PASAR DE LDL A ARCHIVO APROBADOS

void pasarDeLDLToArchivoDeAprobados(char archivoAAbrir[], nodoCelda* ldl){
    FILE *archivo = fopen(archivoAAbrir, "ab");
    registroArchivo nuevoRegistro;
    nodoCelda* seguidoraCelda = ldl;

    if(archivo){
        while(seguidoraCelda){
            while(seguidoraCelda->lista){
                if(seguidoraCelda->lista->dato.nota >= 6){
                    nuevoRegistro.alumno = seguidoraCelda->lista->dato;
                    nuevoRegistro.materia = seguidoraCelda-> materia;
                    fwrite(&nuevoRegistro, sizeof(registroArchivo), 1, archivo);
                }
                seguidoraCelda->lista = seguidoraCelda->lista->siguiente;
            }
            seguidoraCelda = seguidoraCelda-> siguiente;
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
            printf("\nNombre de la Materia: %s\n", nuevoRegistro.materia.nombre);
            printf("\nID de la Materia: %d\n", nuevoRegistro.materia.id);
            printf("\nNombre y Apellido del Alumno: %s\n", nuevoRegistro.alumno.nombreApe);
            printf("\nLegajo del Alumno: %d\n", nuevoRegistro.alumno.legajo);
            printf("\nNota del Alumno: %d\n", nuevoRegistro.alumno.nota);
            printf("\n**********************************************************\n");
        }
        fclose(archivo);
    }
}

// LISTAS DE LISTAS

void ingresarNotasAlumnos(nodoCelda* ldl){
    stMateria materia;
    stNotaAlumno alumno;
    char control = 's';

    while(control == 's'){
        materia = cargarMateria();
        alumno = cargarNotaAlumno();

        ldl = alta(ldl, materia, alumno);

        printf("\nDesea ingresar mas notas? (s/n)\n");
        control = getch();
    }
}

stMateria cargarMateria(){
    stMateria materia;

    printf("\nIngrese el nombre de la materia\n");
    fflush(stdin);
    gets(materia.nombre);
    printf("\nIngrese el id de la materia\n");
    fflush(stdin);
    scanf("%d", &materia.id);

    return materia;
}

stNotaAlumno cargarNotaAlumno(){
    stNotaAlumno alumno;

    printf("\nIngrese el legajo del alumno\n");
    scanf("%d", &alumno.legajo);
    printf("\nIngrese el nombre del alumno\n");
    fflush(stdin);
    gets(alumno.nombreApe);
    printf("\nIngrese la nota del alumno\n");
    fflush(stdin);
    scanf("%d", &alumno.nota);

    return alumno;
}

nodoCelda* alta(nodoCelda* ldl, stMateria materia, stNotaAlumno alumno){
    nodoNota* nuevaNota = crearNodoNotas(alumno);
    nodoCelda* rta = buscarNodoCelda(ldl, materia);

    if(rta == NULL){ // la materia no esta en la LDL
        nodoCelda* nuevaCelda = crearNodoCeldas(materia);
        ldl = agregarAlPpioCeldas(ldl, nuevaCelda); // la agrego al ppio de la lista de celdas
        rta = ldl; // como el nodo lo agrege al principio directamente igualo rta a la lista, si lo agrego al final o en orden deberia encontrar nuevamente el nodo que agregamos para poder agregar la nota en la lista de notas
    }
    rta->lista = agregarAlFinalNotas(rta->lista, nuevaNota);

    return ldl;
}

nodoCelda* buscarNodoCelda(nodoCelda* ldl, stMateria materia){
    nodoCelda* seg = ldl;
    nodoCelda* rta = NULL;
    int flag = 0;

    while(seg && flag == 0){
        if(seg->materia.id == materia.id && strcmp(seg->materia.nombre, materia.nombre) == 0){ // en caso que la materia se encuentre en la LDL
            rta = seg;
            flag = 1;
        }
        seg = seg->siguiente;
    }
    return rta;
}
