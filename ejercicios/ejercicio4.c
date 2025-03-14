#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Crea un tipo de dato estudiante que guarde el nombre del estudiante max. 40 caracteres y su edad
typedef struct {
    char nombre[40];
    int edad;    
} Estudiante;

int main() {

    int size = 2;
    // Crea un arreglo dinámico usando malloc de tamaño size
    Estudiante *estudiantes = (Estudiante *)malloc(size * sizeof(Estudiante));
    
    //Si el arreglo es nulo imprime el mensaje
    if (estudiantes == NULL) {
        printf("Error: No se pudo asignar memoria.\n");
        return 1;
    }

    int count = 0;
    char nombre[50];
    int edad;
    printf("Ingrese estudiantes (nombre y edad, ingrese 'fin' para terminar):\n");
    while (1) {
        printf("Nombre: ");
        scanf("%s", nombre);
        if (strcmp(nombre, "fin") == 0) break;

        printf("Edad: ");
        scanf("%d", &edad);

        if (count >= size) {
            size *= 2;
           Estudiante *temp = (Estudiante*)realloc(estudiantes, size*sizeof(Estudiante)); //Cambia el tamaño del arreglo
           if (temp == NULL) {  
            printf("Error: No se pudo reasignar memoria.\n");
            free(estudiantes); 
            return 1;
            }
            estudiantes = temp;
        }
        //copia el nombre leido en el nuevo estudiante y su edad
        strcpy(estudiantes[count].nombre, nombre); 
        estudiantes[count].edad = edad; 
        
        count++;
    }

    printf("Lista de estudiantes:\n");
    for (int i = 0; i < count; i++) {
        printf("Nombre: %s, Edad: %d\n", estudiantes[i].nombre, estudiantes[i].edad);
    }

    //libera la memoria
    free(estudiantes);
    return 0;
}
