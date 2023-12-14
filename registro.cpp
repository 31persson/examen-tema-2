#include <iostream>
#include <vector>
#include <string>

class Asistencia {
public:
    std::string fecha;
    std::string materia;
    std::string estado;
};

class Estudiante {
public:
    std::string nombre;
    std::vector<Asistencia> asistencias;

    void registrarAsistencia(const std::string& fecha, const std::string& materia, const std::string& estado) {
        Asistencia nuevaAsistencia;
        nuevaAsistencia.fecha = fecha;
        nuevaAsistencia.materia = materia;
        nuevaAsistencia.estado = estado;
        asistencias.push_back(nuevaAsistencia);
    }

    void mostrarAsistencias() const {
        std::cout << "Asistencias de " << nombre << ":\n";
        for (const auto& asistencia : asistencias) {
            std::cout << "Fecha: " << asistencia.fecha << ", Materia: " << asistencia.materia
                      << ", Estado: " << asistencia.estado << "\n";
        }
    }
};

int main() {
    Estudiante estudiante1;
    estudiante1.nombre = "Juan";

    estudiante1.registrarAsistencia("2023-01-01", "Matematicas", "asistio");
    estudiante1.registrarAsistencia("2023-01-02", "Historia", "falta");

    estudiante1.mostrarAsistencias();

    return 0;
}
