#include <iostream>
#include <vector>
#include <string>

class Empleado {
public:
    int numeroCarnet;
    std::string nombre;
    std::string fechaNacimiento;
    std::string categoria;
    double salario;
    std::string direccion;
    std::string telefono;
    std::string correo;

    Empleado(int carnet, std::string nombre, std::string fechaNacimiento, std::string categoria = "Peon",
        double salario = 250000, std::string direccion = "San Jose", std::string telefono = "", std::string correo = "")
        : numeroCarnet(carnet), nombre(nombre), fechaNacimiento(fechaNacimiento), categoria(categoria),
        salario(salario), direccion(direccion), telefono(telefono), correo(correo) {}

    void mostrarInformacion() {
        std::cout << "Carnet: " << numeroCarnet
            << "\nNombre: " << nombre
            << "\nFecha de Nacimiento: " << fechaNacimiento
            << "\nCategoria: " << categoria
            << "\nSalario: " << salario
            << "\nDireccion: " << direccion
            << "\nTelefono: " << telefono
            << "\nCorreo: " << correo
            << "\n----------------------------" << std::endl;
    }
};

class Proyecto {
public:
    int codigo;
    std::string nombre;
    std::string fechaInicio;
    std::string fechaFin;

    Proyecto(int codigo, std::string nombre, std::string fechaInicio, std::string fechaFin)
        : codigo(codigo), nombre(nombre), fechaInicio(fechaInicio), fechaFin(fechaFin) {}

    void mostrarInformacion() {
        std::cout << "Codigo: " << codigo
            << "\nNombre: " << nombre
            << "\nFecha Inicio: " << fechaInicio
            << "\nFecha Fin: " << fechaFin
            << "\n----------------------------" << std::endl;
    }
};

class GestorAsignaciones {
public:
    std::vector<std::pair<int, int>> asignaciones; //aqui estan los pares 

    void asignarEmpleadoAProyecto(int idEmpleado, int idProyecto) {
        for (const auto& asignacion : asignaciones) {
            if (asignacion.first == idEmpleado && asignacion.second == idProyecto) {
                std::cerr << "Error: El empleado ya esta asignado a este proyecto." << std::endl;
                return;
            }
        }
        asignaciones.push_back({ idEmpleado, idProyecto });
    }

    void listarEmpleadosPorProyecto(int idProyecto) {
        std::cout << "Empleados asignados al proyecto " << idProyecto << ":\n";
        for (auto& asignacion : asignaciones) {
            if (asignacion.second == idProyecto) {
                std::cout << "Empleado ID: " << asignacion.first << std::endl;
            }
        }
    }

    void listarProyectosPorEmpleado(int idEmpleado) {
        std::cout << "Proyectos asignados al empleado " << idEmpleado << ":\n";
        for (auto& asignacion : asignaciones) {
            if (asignacion.first == idEmpleado) {
                std::cout << "Proyecto ID: " << asignacion.second << std::endl;
            }
        }
    }
};

int main() {
    
    Empleado emp1(1, "Juan Perez", "2000-01-15", "Administrador", 300000, "Cartago", "8888-8888", "juan@mail.com");
    Empleado emp2(2, "Maria Gomez", "1995-06-22", "Operario", 250000, "San Jose", "7777-7777", "maria@mail.com");

    
    Proyecto proj1(101, "Proyecto A", "2024-01-01", "2024-06-01");
    Proyecto proj2(102, "Proyecto B", "2024-02-01", "2024-07-01");

    
    GestorAsignaciones gestor;

    
    gestor.asignarEmpleadoAProyecto(emp1.numeroCarnet, proj1.codigo);
    gestor.asignarEmpleadoAProyecto(emp1.numeroCarnet, proj2.codigo);
    gestor.asignarEmpleadoAProyecto(emp2.numeroCarnet, proj1.codigo);

    
    emp1.mostrarInformacion();
    emp2.mostrarInformacion();
    proj1.mostrarInformacion();
    proj2.mostrarInformacion();

    
    gestor.listarEmpleadosPorProyecto(proj1.codigo);
    gestor.listarProyectosPorEmpleado(emp1.numeroCarnet);

    return 0;
}

