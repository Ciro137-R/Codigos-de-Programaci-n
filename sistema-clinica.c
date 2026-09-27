#include <stdio.h>
#include <string.h>

// estructura para almacenar los datos de cada paciente(Parte de Jesús)
typedef struct {
    char nombre[30];
    char cedula[20];
    float peso;
    float altura;
    char tipo_sangre[5];
    char codigo_urgencia;
    float imc;
} Paciente;

// Esta función sirve para limpiar los saltos de línea y caracteres sobrantes en el buffer (stdin) (parte de ciro)
void limpiarBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Función es para registrar los datos de un paciente basándonos en tu formato de entrada (parte de jesús)
void registrarPaciente(Paciente *p, int numero) {
    printf("--- REGISTRO PACIENTE %d ---\n", numero);

    // Lectura de Nombre Completo con fgets y strcspn
    printf("Ingrese su Nombre completo: ");
    fgets(p->nombre, sizeof(p->nombre), stdin);
    p->nombre[strcspn(p->nombre, "\n")] = '\0';

    // Lectura de Cédula
    printf("Ingrese su numero de cedula: ");
    scanf("%19s", p->cedula);

    // Lectura de Peso
    printf("Ingrese su peso(kg): ");
    scanf("%f", &p->peso);

    // Lectura de Altura
    printf("Ingrese su altura: ");
    scanf("%f", &p->altura);
    limpiarBuffer(); // Limpiamos el '\n' sobrante del scanf antes del fgets

    // Lectura del Tipo de Sangre
    printf("Ingrese su tipo de sangre (ej: O+): ");
    fgets(p->tipo_sangre, sizeof(p->tipo_sangre), stdin);
    p->tipo_sangre[strcspn(p->tipo_sangre, "\n")] = '\0';

    // Lectura de Código de Urgencia
    printf("Ingrese codigo de urgencia (A: Alta, M: Media, B: Baja): ");
    scanf(" %c", &p->codigo_urgencia);
    limpiarBuffer(); // Limpiamos el buffer para la lectura del siguiente paciente (Parte de ciro)

    // Cálculo del IMC (Peso / Altura^2)
    p->imc = p->peso / (p->altura * p->altura);
    printf("\n");
}

int main() {
    Paciente p1, p2;

    // --- ENTRADA DE DATOS PARA LOS DOS PACIENTES ---
    registrarPaciente(&p1, 1);
    registrarPaciente(&p2, 2);

    // --- SALIDA Y REPORTES SOLICITADOS ---
    printf("=====================================================================\n");
    printf("                 SISTEMA DE CONTROL DE PACIENTES                     \n");
    printf("=====================================================================\n");

    // Paciente 1
    printf("PACIENTE 1:\n");
    printf(" - Nombre: %s\n", p1.nombre);
    printf(" - Cédula: %s\n", p1.cedula);
    printf(" - Peso (kg): %.1f | Altura (m): %.2f\n", p1.peso, p1.altura);
    printf(" - Tipo Sangre: %s | Nivel de Urgencia: %c\n\n", p1.tipo_sangre, p1.codigo_urgencia);

    // Paciente 2
    printf("PACIENTE 2:\n");
    printf(" - Nombre: %s\n", p2.nombre);
    printf(" - Cédula: %s\n", p2.cedula);
    printf(" - Peso (kg): %.1f | Altura (m): %.2f\n", p2.peso, p2.altura);
    printf(" - Tipo Sangre: %s | Nivel de Urgencia: %c\n\n", p2.tipo_sangre, p2.codigo_urgencia);

    // --- TABLA COMPARATIVA ---
    printf("=====================================================================\n");
    printf("                         RESUMEN DE REGISTRO                         \n");
    printf("=====================================================================\n");
    printf("%-24s %-15s %-10s %-12s %-10s\n", "NOMBRE", "CÉDULA", "SANGRE", "URGENCIA", "IMC (Aprox)");
    printf("---------------------------------------------------------------------\n");

    // Formateo e impresión del Paciente 1
    char urg1[10];
    if (p1.codigo_urgencia == 'A' || p1.codigo_urgencia == 'a') strcpy(urg1, "Alta");
    else if (p1.codigo_urgencia == 'M' || p1.codigo_urgencia == 'm') strcpy(urg1, "Media");
    else strcpy(urg1, "Baja");

    printf("%-24s %-15s %-10s %-12s %-10.2f\n", p1.nombre, p1.cedula, p1.tipo_sangre, urg1, p1.imc);

    // Formateo e impresión del Paciente 2
    char urg2[10];
    if (p2.codigo_urgencia == 'A' || p2.codigo_urgencia == 'a') strcpy(urg2, "Alta");
    else if (p2.codigo_urgencia == 'M' || p2.codigo_urgencia == 'm') strcpy(urg2, "Media");
    else strcpy(urg2, "Baja");

    printf("%-24s %-15s %-10s %-12s %-10.2f\n", p2.nombre, p2.cedula, p2.tipo_sangre, urg2, p2.imc);

    printf("=====================================================================\n");

    return 0;
}
