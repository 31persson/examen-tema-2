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
    struct Asistencia asistencias[100]; // Se asume un límite de 100 asistencias por estudiante
    size_t numAsistencias; // Número actual de asistencias
};

// Función para registrar la asistencia de un estudiante
void registrarAsistencia(struct Estudiante* estudiante, const char* fecha, const char* materia, const char* estado) {
    if (estudiante->numAsistencias < sizeof(estudiante->asistencias) / sizeof(estudiante->asistencias[0])) {
        struct Asistencia nuevaAsistencia;
        snprintf(nuevaAsistencia.fecha, sizeof(nuevaAsistencia.fecha), "%s", fecha);
        snprintf(nuevaAsistencia.materia, sizeof(nuevaAsistencia.materia), "%s", materia);
        snprintf(nuevaAsistencia.estado, sizeof(nuevaAsistencia.estado), "%s", estado);

        estudiante->asistencias[estudiante->numAsistencias++] = nuevaAsistencia;
    }
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
    snprintf(estudiante1.nombre, sizeof(estudiante1.nombre), "%s", "Juan");
    estudiante1.numAsistencias = 0;

    // Registrar asistencias
    registrarAsistencia(&estudiante1, "2023-01-01", "Matematicas", "asistio");
    registrarAsistencia(&estudiante1, "2023-01-02", "Historia", "falta");

    // Mostrar asistencias
    mostrarAsistencias(&estudiante1);

    return 0;
}
