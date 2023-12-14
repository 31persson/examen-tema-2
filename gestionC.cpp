#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definición de la estructura Materia
struct Materia {
    char nombre[50];
    int creditos;
};

// Definición de la estructura Estudiante
struct Estudiante {
    char nombre[50];
    int edad;
    double promedio;
    struct Materia* materias;
    size_t numMaterias; // Número actual de materias
    size_t capacidadMaterias; // Capacidad máxima del arreglo
};

// Función para inicializar un estudiante
void inicializarEstudiante(struct Estudiante* estudiante) {
    estudiante->materias = NULL;
    estudiante->numMaterias = 0;
    estudiante->capacidadMaterias = 0;
}

// Función para liberar la memoria de las materias
void liberarMaterias(struct Estudiante* estudiante) {
    free(estudiante->materias);
    estudiante->materias = NULL;
    estudiante->numMaterias = 0;
    estudiante->capacidadMaterias = 0;
}

// Función para mostrar la información del estudiante
void mostrarEstudiante(const struct Estudiante* estudiante) {
    printf("Nombre: %s\n", estudiante->nombre);
    printf("Edad: %d\n", estudiante->edad);
    printf("Promedio: %lf\n", estudiante->promedio);

    printf("Materias inscritas:\n");
    for (size_t i = 0; i < estudiante->numMaterias; ++i) {
        printf("  Nombre: %s, Créditos: %d\n", estudiante->materias[i].nombre, estudiante->materias[i].creditos);
    }
}

// Función para agregar una materia al estudiante
void agregarMateria(struct Estudiante* estudiante, const char* nombreMateria, int creditos) {
    if (estudiante->numMaterias == estudiante->capacidadMaterias) {
        // Si el arreglo está lleno, se necesita realocar más memoria
        estudiante->capacidadMaterias += 5; // Aumentar la capacidad en bloques de 5
        estudiante->materias = (struct Materia*)realloc(estudiante->materias, estudiante->capacidadMaterias * sizeof(struct Materia));
    }

    // Asignar valores a la nueva materia
    snprintf(estudiante->materias[estudiante->numMaterias].nombre, sizeof(estudiante->materias[0].nombre), "%s", nombreMateria);
    estudiante->materias[estudiante->numMaterias].creditos = creditos;

    // Incrementar el número de materias
    estudiante->numMaterias++;
}

// Función para eliminar una materia del estudiante
void eliminarMateria(struct Estudiante* estudiante, const char* nombreMateria) {
    // Buscar la materia por nombre
    for (size_t i = 0; i < estudiante->numMaterias; ++i) {
        if (strcmp(estudiante->materias[i].nombre, nombreMateria) == 0) {
            // Desplazar las materias restantes para llenar el espacio
            for (size_t j = i; j < estudiante->numMaterias - 1; ++j) {
                estudiante->materias[j] = estudiante->materias[j + 1];
            }

            // Decrementar el número de materias
            estudiante->numMaterias--;

            // Reducir la memoria asignada si es necesario
            if (estudiante->numMaterias < estudiante->capacidadMaterias - 5) {
                estudiante->capacidadMaterias -= 5; // Reducir la capacidad en bloques de 5
                estudiante->materias = (struct Materia*)realloc(estudiante->materias, estudiante->capacidadMaterias * sizeof(struct Materia));
            }

            break; // Terminar después de encontrar la materia
        }
    }
}

// Función para liberar la memoria de un estudiante
void liberarEstudiante(struct Estudiante* estudiante) {
    liberarMaterias(estudiante);
    free(estudiante);
}

int main() {
    // Crear un objeto Estudiante

