#include <iostream>
#include <stdexcept>
#include <vector>

class FechaInvalidaException : public std::exception {
public:
    const char* what() const noexcept override {
        return "Error: Formato de fecha inválido";
    }
};

class MateriaNoRegistradaException : public std::exception {
public:
    const char* what() const noexcept override {
        return "Error: Materia no registrada";
    }
};

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
        if (fecha.size() != 10 || fecha[4] != '-' || fecha[7] != '-') {
            throw FechaInvalidaException();
        }

        // Validar si la materia está registrada (solo como ejemplo, agregar lógica específica)
        if (materia != "Matematicas" && materia != "Historia") {
            throw MateriaNoRegistradaException();
        }

        Asistencia nuevaAsistencia;
        nuevaAsistencia.fecha = fecha;
        nuevaAsistencia.materia = materia;
        nuevaAsistencia.estado = estado;
        asistencias.push_back(nuevaAsistencia);
    }
};

int main() {
    Estudiante estudiante1;
    estudiante1.nombre = "Juan";

    try {
        estudiante1.registrarAsistencia("2023-01-01", "Matematicas", "asistio");
        estudiante1.registrarAsistencia("2023-01-02", "Historia", "falta");
        estudiante1.registrarAsistencia("2023-13-01", "Fisica", "asistio"); // Error: Formato de fecha inválido
    } catch (const std::exception& e) {
        std::cerr << "Excepcion capturada: " << e.what() << std::endl;
    }

    try {
        estudiante1.registrarAsistencia("2023-01-03", "Quimica", "asistio"); // Error: Materia no registrada
    } catch (const std::exception& e) {
        std::cerr << "Excepcion capturada: " << e.what() << std::endl;
    }

    return 0;
}
