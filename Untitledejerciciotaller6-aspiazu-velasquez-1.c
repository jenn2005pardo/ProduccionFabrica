#include <stdio.h>
#include <string.h>

#define MAX 5
#define TAM 30

char nombres[MAX][TAM];
int cantidades[MAX];
int tiempos[MAX];
int recursos[MAX];
int total = 0;

void ingresar() {
    if (total >= MAX) {
        printf("Ya se ingresaron los %d productos.\n", MAX);
        return;
    }

    printf("\nIngrese nombre del producto: ");
    scanf(" %[^\n]", nombres[total]);

    printf("Ingrese cantidad demandada: ");
    scanf("%d", &cantidades[total]);

    printf("Ingrese tiempo de fabricacion por unidad: ");
    scanf("%d", &tiempos[total]);

    printf("Ingrese recursos por unidad: ");
    scanf("%d", &recursos[total]);

    total++;
}

void mostrar() {
    if (total == 0) {
        printf("\nNo hay productos ingresados.\n");
        return;
    }

    printf("\n Lista de productos \n");
    for (int i = 0; i < total; i++) {
        printf("%d) %s - Cantidad: %d - Tiempo: %d - Recursos: %d\n", i+1, nombres[i], cantidades[i], tiempos[i], recursos[i]);
    }
}

void editar() {
    char buscar[TAM];
    int pos = -1;

    printf("\nIngrese el nombre del producto a editar: ");
    scanf(" %[^\n]", buscar);

    for (int i = 0; i < total; i++) {
        if (strcmp(nombres[i], buscar) == 0) {
            pos = i;
            break;
        }
    }

    if (pos == -1) {
        printf("Producto no encontrado.\n");
        return;
    }

    printf("Nuevo nombre: ");
    scanf(" %[^\n]", nombres[pos]);

    printf("Nueva cantidad: ");
    scanf("%d", &cantidades[pos]);

    printf("Nuevo tiempo por unidad: ");
    scanf("%d", &tiempos[pos]);

    printf("Nuevos recursos por unidad: ");
    scanf("%d", &recursos[pos]);

    printf("Producto editado con exito.\n");
}

void eliminar() {
    char buscar[TAM];
    int pos = -1;

    printf("\nIngrese el nombre del producto a eliminar: ");
    scanf(" %[^\n]", buscar);

    for (int i = 0; i < total; i++) {
        if (strcmp(nombres[i], buscar) == 0) {
            pos = i;
            break;
        }
    }

    if (pos == -1) {
        printf("Producto no encontrado.\n");
        return;
    }

    for (int i = pos; i < total - 1; i++) {
        strcpy(nombres[i], nombres[i + 1]);
        cantidades[i] = cantidades[i + 1];
        tiempos[i] = tiempos[i + 1];
        recursos[i] = recursos[i + 1];
    }

    total--;
    printf("Producto eliminado con exito.\n");
}

void calcular(int tiempoDisponible, int recursosDisponibles) {
    int tiempoTotal = 0, recursosTotales = 0;

    for (int i = 0; i < total; i++) {
        tiempoTotal += cantidades[i] * tiempos[i];
        recursosTotales += cantidades[i] * recursos[i];
    }

    printf("\nTiempo total requerido: %d\n", tiempoTotal);
    printf("Recursos totales necesarios: %d\n", recursosTotales);

    if (tiempoTotal <= tiempoDisponible && recursosTotales <= recursosDisponibles) {
        printf("La fabrica PUEDE cumplir con la demanda.\n");
    } else {
        printf("La fabrica NO PUEDE cumplir con la demanda.\n");
    }
}

int main() {
    int opcion;
    int tiempoDisponible, recursosDisponibles;

    printf("Ingrese tiempo disponible de produccion: ");
    scanf("%d", &tiempoDisponible);

    printf("Ingrese recursos disponibles: ");
    scanf("%d", &recursosDisponibles);

    do {
        printf("\n Menu \n");
        printf("1. Ingresar producto\n");
        printf("2. Mostrar productos\n");
        printf("3. Editar producto\n");
        printf("4. Eliminar producto\n");
        printf("5. Calcular produccion\n");
        printf("6. Salir\n");
        printf("Elija una opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1: ingresar(); break;
            case 2: mostrar(); break;
            case 3: editar(); break;
            case 4: eliminar(); break;
            case 5: calcular(tiempoDisponible, recursosDisponibles); break;
            case 6: printf("Fin del programa.\n"); break;
            default: printf("Opcion invalida.\n");
        }

    } while (opcion != 6);

    return 0;
}
