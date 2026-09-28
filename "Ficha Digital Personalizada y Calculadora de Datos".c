#include <stdio.h>
#include <string.h>

#define ANIO_ACTUAL 2026

int main(void) {
    // Declaración de variables con tipos de datos adecuados
    char nombre[100];
    int edad;
    float estatura;
    float promedio;
    char inicial_carrera;
    int anio_nacimiento;

    // --- ENTRADA DE DATOS ---
    printf("=== REGISTRO DE DATOS ESTUDIANTIL ===\n");

    // 1. Lectura del nombre completo con fgets y eliminación de '\n'
    printf("Ingrese su nombre completo: ");
    if (fgets(nombre, sizeof(nombre), stdin) != NULL) {
        size_t len = strlen(nombre);
        if (len > 0 && nombre[len - 1] == '\n') {
            nombre[len - 1] = '\0'; // Reemplazar salto de línea por fin de cadena
        }
    }

    // 2. Lectura de edad, estatura y promedio
    printf("Ingrese su edad: ");
    scanf("%d", &edad);

    printf("Ingrese su estatura (m): ");
    scanf("%f", &estatura);

    printf("Ingrese su promedio general: ");
    scanf("%f", &promedio);

    // 3. Lectura del carácter para la inicial de la carrera
    // El espacio antes de %c (" %c") descarta saltos de línea pendientes en el buffer
    printf("Ingrese la inicial de su carrera (S/I/C): ");
    scanf(" %c", &inicial_carrera);

    // --- PROCESAMIENTO ---
    // Cálculo aproximado del año de nacimiento
    anio_nacimiento = ANIO_ACTUAL - edad;

    // --- SALIDA DE DATOS ---
    // Uso de caracteres de escape (\n, \t) para dar formato alineado
    printf("\n============================================\n");
    printf("\t   FICHA ACADÉMICA FINAL\n");
    printf("============================================\n");
    printf("Nombre del Estudiante:\t%s\n", nombre);
    printf("Inicial de Carrera:\t%c\n", inicial_carrera);
    printf("Año Nacimiento (Aprox):\t%d\n", anio_nacimiento);
    printf("Estatura:\t\t%.2f m\n", estatura);
    printf("Promedio General:\t%.2f / 100.00\n", promedio);
    printf("============================================\n");

    return 0;
}
