#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estructura para la Asistencia
struct Asistencia {
    char fecha[20];
    char materia[50];
    char estado[20];
};

// Estructura para el Estudiante
struct Estudiante {
    char nombre[50];
    struct Asistencia asistencias[100];
    size_t numAsistencias;
};

// Excepción personalizada
struct Exception {
    const char* message;
};

// Función para registrar la asistencia de un estudiante
void registrarAsistencia(struct Estudiante* estudiante, const char* fecha, const char* materia, const char* estado) {
    if (strlen(fecha) != 10 || fecha[4] != '-' || fecha[7] != '-') {
        // Lanzar excepción
        struct Exception ex = { "Error: Formato de fecha inválido" };
        throw(ex);
    }

    // Validar si la materia está registrada (solo como ejemplo, agregar lógica específica)
    if (strcmp(materia, "Matemáticas") != 0 && strcmp(materia, "Historia") != 0) {
        // Lanzar excepción
        struct Exception ex = { "Error: Materia no registrada" };
        throw(ex);
    }

    struct Asistencia nuevaAsistencia;
    strcpy(nuevaAsistencia.fecha, fecha);
    strcpy(nuevaAsistencia.materia, materia);
    strcpy(nuevaAsistencia.estado, estado);

    estudiante->asistencias[estudiante->numAsistencias++] = nuevaAsistencia;
}

// Función para mostrar las asistencias de un estudiante
void mostrarAsistencias(const struct Estudiante* estudiante) {
    printf("Asistencias de %s:\n", estudiante->nombre);
    for (size_t i = 0; i < estudiante->numAsistencias; ++i) {
        printf("Fecha: %s, Materia: %s, Estado: %s\n",
               estudiante->asistencias[i].fecha,
               estudiante->asistencias[i].materia,
               estudiante->asistencias[i].estado);
    }
}

int main() {
    // Crear un objeto Estudiante
    struct Estudiante estudiante1;
    strcpy(estudiante1.nombre, "Juan");
    estudiante1.numAsistencias = 0;

    // Utilizar bloques try-catch en C++
#ifdef __cplusplus
    try {
#endif

        // Registrar asistencias
        registrarAsistencia(&estudiante1, "2023-01-01", "Matemáticas", "asistió");
        registrarAsistencia(&estudiante1, "2023-01-02", "Historia", "falta");
        // Error: Formato de fecha inválido
        registrarAsistencia(&estudiante1, "2023-13-01", "Física", "asistió");

        // Error: Materia no registrada
        registrarAsistencia(&estudiante1, "2023-01-03", "Química", "asistió");

        // Mostrar asistencias
        mostrarAsistencias(&estudiante1);

#ifdef __cplusplus
    } catch (struct Exception ex) {
        // Manejar excepción en C++
        printf("Excepcion capturada: %s\n", ex.message);
    }
#endif

    return 0;
}
