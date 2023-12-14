#include <stdio.h>
#include <string.h>

// Definición de la estructura Estudiante
struct Estudiante {
    char nombre[50];
    int edad;
    double promedio;
};

// Función para mostrar la información del estudiante
void mostrarEstudiante(const struct Estudiante* estudiante) {
    printf("Nombre: %s\n", estudiante->nombre);
    printf("Edad: %d\n", estudiante->edad);
    printf("Promedio: %lf\n", estudiante->promedio);
}

int main() {
    // Crear una estructura Estudiante
    struct Estudiante estudiante1;

    // Asignar valores a los campos
    strncpy(estudiante1.nombre, "Juan", sizeof(estudiante1.nombre));
    estudiante1.edad = 20;
    estudiante1.promedio = 85.5;

    // Mostrar la información del estudiante
    mostrarEstudiante(&estudiante1);

    return 0;
}
