#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

// Estructura para representar una materia
struct Materia {
    std::string nombre;
    int creditos;
};

// Estructura Estudiante que incluye un vector de Materias
struct Estudiante {
    std::string nombre;
    int edad;
    double promedio;
    std::vector<Materia> materias;
};

// Función para mostrar la información del estudiante
void mostrarEstudiante(const Estudiante& estudiante) {
    std::cout << "Nombre: " << estudiante.nombre << std::endl;
    std::cout << "Edad: " << estudiante.edad << std::endl;
    std::cout << "Promedio: " << estudiante.promedio << std::endl;

    std::cout << "Materias inscritas:" << std::endl;
    for (const auto& materia : estudiante.materias) {
        std::cout << "  Nombre: " << materia.nombre << ", Creditos: " << materia.creditos << std::endl;
    }
}

// Función para agregar una materia al estudiante
void agregarMateria(Estudiante& estudiante, const std::string& nombreMateria, int creditos) {
    Materia nuevaMateria = {nombreMateria, creditos};
    estudiante.materias.push_back(nuevaMateria);
}

// Función para eliminar una materia del estudiante
void eliminarMateria(Estudiante& estudiante, const std::string& nombreMateria) {
    auto it = std::remove_if(estudiante.materias.begin(), estudiante.materias.end(),
                             [&](const Materia& materia) { return materia.nombre == nombreMateria; });
    estudiante.materias.erase(it, estudiante.materias.end());
}

int main() {
    // Crear un objeto Estudiante
    Estudiante estudiante1;

    // Asignar valores a los campos
    estudiante1.nombre = "Juan";
    estudiante1.edad = 20;
    estudiante1.promedio = 85.5;

    // Agregar materias al estudiante
    agregarMateria(estudiante1, "Matemáticas", 4);
    agregarMateria(estudiante1, "Historia", 3);

    // Mostrar la información del estudiante
    mostrarEstudiante(estudiante1);

    // Eliminar una materia del estudiante
    eliminarMateria(estudiante1, "Matemáticas");

    // Mostrar la información actualizada del estudiante
    mostrarEstudiante(estudiante1);

    return 0;
}
