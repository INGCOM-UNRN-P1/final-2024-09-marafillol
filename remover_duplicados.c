/*
Ejercicio de Examen Final
Mara Fillol - @marafillol - 2024
Dada una lista de palabras almacenada en un archivo de texto,
eliminar los duplicados y guardar las palabras únicas en un nuevo archivo.
Programacion 1 - Ingenieria en computacion
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_CARACTERES 100

typedef struct Palabra {
    char cadena[MAX_CARACTERES]; 
    struct Palabra* siguiente;     
} Palabra;


int compararCadenas(const char* entrada, const char* salida) {
    while (*entrada && (*entrada == *salida)) {
        entrada++;
        salida++;
    }
    return *(unsigned char*)entrada - *(unsigned char*)salida;
}


void limpiarCadenaParaComparar(const char* cadenaOriginal, char* cadenaLimpia) {
    while (*cadenaOriginal) {
        if (isalpha((unsigned char)*cadenaOriginal)) {
            *cadenaLimpia++ = tolower((unsigned char)*cadenaOriginal);
        }
        cadenaOriginal++;
    }
    *cadenaLimpia = '\0';
}


void copiarCadena(char* salida, const char* entrada, size_t limite) {
    size_t i;
    for (i = 0; i < limite - 1 && entrada[i] != '\0'; i++) {
        salida[i] = entrada[i]; 
    }
    salida[i] = '\0';
}


int esDuplicado(Palabra* primer_palabra, const char* cadenaOriginal) {
    Palabra* actual = primer_palabra;
    char cadenaLimpiaOriginal[MAX_CARACTERES];
    limpiarCadenaParaComparar(cadenaOriginal, cadenaLimpiaOriginal);

    while (actual != NULL) {
        char cadenaLimpiaComparar[MAX_CARACTERES];
        limpiarCadenaParaComparar(actual->cadena, cadenaLimpiaComparar);

        if (compararCadenas(cadenaLimpiaComparar, cadenaLimpiaOriginal) == 0) {
            return 1; 
        }
        actual = actual->siguiente; 
    }
    return 0; 
}


void agregarPalabra(Palabra** primer_palabra, const char* cadenaOriginal) {
    if (esDuplicado(*primer_palabra, cadenaOriginal)) {
        return; 
    }

    
    Palabra* nuevaPalabra = (Palabra*)malloc(sizeof(Palabra)); 
    if (nuevaPalabra == NULL) {
        fprintf(stderr, "Error al asignar memoria.\n");
        exit(1);
    }

    copiarCadena(nuevaPalabra->cadena, cadenaOriginal, MAX_CARACTERES);
    nuevaPalabra->siguiente = NULL; 

    if (*primer_palabra == NULL) {
        *primer_palabra = nuevaPalabra;
    } else {
        Palabra* actual = *primer_palabra;
        while (actual->siguiente != NULL) {
            actual = actual->siguiente;
        }
        actual->siguiente = nuevaPalabra; 
    }
}


void leerArchivoEntrada(FILE* archivoEntrada, Palabra** primer_palabra) {
    char cadena[MAX_CARACTERES];
    while (fscanf(archivoEntrada, "%99s", cadena) == 1) {
        agregarPalabra(primer_palabra, cadena);
    }
}


void escribirArchivoSalida(FILE* archivoSalida, Palabra* primer_palabra) {
    Palabra* actual = primer_palabra;
    while (actual != NULL) {
        fprintf(archivoSalida, "%s\n", actual->cadena); 
        actual = actual->siguiente;
    }
}


void liberarMemoria(Palabra* primer_palabra) {
    Palabra* actual = primer_palabra;
    while (actual != NULL) {
        Palabra* siguiente = actual->siguiente;
        free(actual);
        actual = siguiente;
    }
}

int main(int argc, char* argv[]) {
    Palabra* primer_palabra = NULL;

    if (argc != 3) {
        fprintf(stderr, "Para ejecutar: %s <archivo_entrada> <archivo_salida>\n", argv[0]);
        return 1;
    }

    FILE* archivoEntrada = fopen(argv[1], "r");
    if (archivoEntrada == NULL) {
        fprintf(stderr, "Error al abrir el archivo de entrada: %s\n", argv[1]);
        return 1;
    }

    leerArchivoEntrada(archivoEntrada, &primer_palabra);
    fclose(archivoEntrada);

    FILE* archivoSalida = fopen(argv[2], "w");
    if (archivoSalida == NULL) {
        fprintf(stderr, "Error al abrir el archivo de salida: %s\n", argv[2]);
        return 1;
    }

    escribirArchivoSalida(archivoSalida, primer_palabra);
    fclose(archivoSalida); 

    liberarMemoria(primer_palabra);

    return 0; 
}
