#include "arreglos-de-listas.h"

// LISTAS
nodo* inicLista(){
    return NULL;
}

nodo* crearNodo(stNotaAlumno alumno){
    nodo* aux = (nodo*) malloc(sizeof(nodo));
    aux-> dato = alumno;
    aux-> siguiente = NULL;

    return aux;
}

nodo* agregarAlFinal(nodo* lista, nodo* nuevoNodo){
    if(lista == NULL){
        lista = nuevoNodo;
    }else{
        nodo* aux = lista;
        if(aux){
            while(aux-> siguiente != NULL){
                aux = aux-> siguiente; // itero hasta llegar al final de la lista
            }
        }
        aux-> siguiente = nuevoNodo; // hago que el nodo que apuntaba a NULL previamente ahora apunte al nuevoNodo
    }
    return lista; // Se retorna la lista ya que hay que tener en cuenta que en el caso de que el primer primer if sea verdadero debemos retornarla, en el resto de los casos aunque trabajemos sobre el
}

void mostrarLista(nodo* lista){
    if(lista){
        nodo* seguidora = lista; // copia de seguridad

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

// PASAR DE ARCHIVO A ADL (ARREGLO DE LISTAS)

int pasarDeArchivoToADL(char archivoAAbrir[], stCelda array[], int validos){
    FILE *archivo = fopen(archivoAAbrir, "rb");
    registroArchivo nuevoRegistro;
    stMateria materia;
    stNotaAlumno alumno;

    if(archivo){
        while(fread(&nuevoRegistro, sizeof(registroArchivo), 1, archivo) > 0){
            materia = nuevoRegistro.materia;
            alumno = nuevoRegistro.alumno;
            validos = alta(array, materia, alumno, validos);
        }
        fclose(archivo);
    }else{
        printf("El archivo en NULL");
    }
    return validos;
}

// PASAR DE ADL A ARCHIVO APROBADOS

void pasarDeADLToArchivoDeAprobados(char archivoAAbrir[], stCelda array[], int validos){
    FILE *archivo = fopen(archivoAAbrir, "ab");
    registroArchivo nuevoRegistro;
    int i = 0;

    if(archivo){
        while(i < validos){
            while(array[i].lista){
                if(array[i].lista-> dato.nota >= 6){
                    nuevoRegistro.alumno = array[i].lista-> dato;
                    nuevoRegistro.materia = array[i].materia;
                    fwrite(&nuevoRegistro, sizeof(registroArchivo), 1, archivo);
                }
                array[i].lista = array[i].lista-> siguiente;
            }
            i++;
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

// ARRAY DE LISTAS

int ingresarNotasAlumnos(stCelda array[], int dim, int validos){
    stMateria materia;
    stNotaAlumno alumno;
    char control = 's';

    while(control == 's' && validos < dim){
        materia = cargarMateria();
        alumno = cargarNotaAlumno();

        validos = alta(array, materia, alumno, validos);

        printf("\nDesea ingresar mas notas? (s/n)\n");
        control = getch();
    }

    return validos;
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

int alta(stCelda array[], stMateria materia, stNotaAlumno alumno, int validos){
    nodo* alumnoNota = crearNodo(alumno);
    int pos = buscarPosMateria(array, materia, validos);
    if(pos == -1){ // la materia no esta en el array
        validos = agregarCelda(array, materia, validos);
        pos = validos - 1; // la materia quedo en la ultima posicion valida del arreglo
    }
    array[pos].lista = agregarAlFinal(array[pos].lista, alumnoNota); // array[pos].lista es una lista simplemente enlazada

    return validos;
}

int buscarPosMateria(stCelda array[], stMateria materia, int validos){
    int rta = -1;
    int i = 0;
    while(i < validos && rta == -1){
        if(array[i].materia.id == materia.id){ // en caso que el id de la materia que entro por parametro coincida con el id de la materia de la poscion actual del arreglo
            rta = i;
        }
        i++;
    }
    return rta;
}

int agregarCelda(stCelda array[], stMateria materia, int validos){
    array[validos].materia = materia; // seteo la materia
    array[validos].lista = inicLista(); // inicializo la lista de la nueva materia
    validos++; // como agregamos una nueva materia en el arreglo los validos incrementan
    return validos;
}

void mostrarArrayDeListas(stCelda array[], int validos){
    int i = 0;
    printf("\n**************************ADL*********************************\n");
    while(i < validos){
        printf("\nMateria: %s\n", array[i].materia.nombre);
        printf("\nID Materia: %d\n", array[i].materia.id);
        //printf("\nLista de alumnos: %d\n", cuentaAlumnos(array[i].lista));
        mostrarLista(array[i].lista);
        printf("\n########################################################################################################\n");
        i++;
    }
    printf("\n**************************ADL*********************************\n");
}

/*
int cuentaAlumnos(nodo* lista){
    return (lista)?1+cuentaAlumnos(lista-> siguiente):0;
}
*/

// FUNCIONES PARA GENERAR EL ARCHIVO CON LOS DATOS MEZCLADOS

void cargarArchivo(char archivoAAbrir[]){
    char control = 's';
    FILE *archivo = fopen(archivoAAbrir, "ab");
    registroArchivo nuevoRegistro;

    if(archivo){
        printf("\nQuiere cargar un Registro? (s/n)\n");
        fflush(stdin);
        scanf("%c", &control);

        while(control == 's'){
            printf("\n-----------------------CARGANDO REGISTROS---------------------------\n");

            nuevoRegistro.materia = nuevaMateria();
            fflush(stdin);
            nuevoRegistro.alumno = nuevoAlumno();

            fwrite(&nuevoRegistro, sizeof(registroArchivo), 1, archivo);

            printf("\Registro Cargado!\n");
            printf("\nCargar otro Registro? (s/n)\n");
            fflush(stdin);
            scanf("%c", &control);
        }
        fclose(archivo);
    }else {
        printf("El archivo en NULL");
    }
}

stMateria nuevaMateria(){
    stMateria aux;

    printf("\nNombre de la Materia:\n");
    fflush(stdin);
    gets(aux.nombre);

    printf("\nID de la Materia:\n");
    scanf("%d", &aux.id);

    return aux;
}

stNotaAlumno nuevoAlumno(){
    stNotaAlumno aux;

    printf("\nNombre y Apellido del Alumno:\n");
    fflush(stdin);
    gets(aux.nombreApe);

    printf("\nLegajo del Alumno:\n");
    scanf("%d", &aux.legajo);

    printf("\nNota del Alumno:\n");
    scanf("%d", &aux.nota);

    return aux;
}
