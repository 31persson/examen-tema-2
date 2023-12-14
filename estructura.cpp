#include <iostream>
#include <string>

// Definición de la estructura Estudiante
struct Estudiante {
    std::string nombre;
    int edad;
    double promedio;
};

// Función para mostrar la información del estudiante
void mostrarEstudiante(const Estudiante& estudiante) {
    std::cout << "Nombre: " << estudiante.nombre << std::endl;
    std::cout << "Edad: " << estudiante.edad << std::endl;
    std::cout << "Promedio: " << estudiante.promedio << std::endl;
}

int main() {
    // Crear un objeto Estudiante
    Estudiante estudiante1;

    // Asignar valores a los campos
    estudiante1.nombre = "Juan";
    estudiante1.edad = 20;
    estudiante1.promedio = 85.5;

    // Mostrar la información del estudiante
    mostrarEstudiante(estudiante1);

    return 0;
}
