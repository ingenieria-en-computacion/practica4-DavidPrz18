#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    printf("Ingrese el tamaño del arreglo: \n");
    scanf("%d", &n);
    

    int *arr = (int*)malloc(n *sizeof(int));
    if (arr == NULL) {
        printf("Error: No se pudo asignar memoria.\n");
        return 1;
    }

    printf("Ingrese %d valores:\n", n);
    for (int i = 0; i < n; i++) {
        printf("Valor %d: ", i + 1);  // Opcional, solo para mejorar la legibilidad
        scanf("%d", &arr[i]);
    }

    printf("El arreglo es: \n");
    for (int i = 0; i < n; i++) {
        printf("arr[%d] = %d\n", i + 1, arr[i]);
        
    }
    printf("\n");
    free(arr);

    
    return 0;
}
