#include <iostream>
#include <vector>

class Trabajador {
private:
    std::string nombre;
    int edad;
    double salario;
    std::vector<Trabajador*> relaciones;
    std::vector<Trabajador*> companeros;
    std::string obtener_informacion() {
    return "Nombre: " + this->nombre + ", Edad: " + std::to_string(this->edad) + ", Salario: " + std::to_string(this->salario);
}

public:
    Trabajador(std::string nombre, int edad, double salario) {
        this->nombre = nombre;
        this->edad = edad;
        this->salario = salario;
    }

    std::string obtener_nombre() {
        return this->nombre;
    }

    void agregar_relacion(Trabajador* trabajador) {
        this->relaciones.push_back(trabajador);
    }

    std::vector<Trabajador*> obtener_relaciones() {
        return this->relaciones;
    }

    void agregar_companero(Trabajador* trabajador) {
        this->companeros.push_back(trabajador);
    }

    std::vector<Trabajador*> obtener_companeros() {
        return this->companeros;
    }
};

class Gerente : public Trabajador {
private:
    Trabajador* trabajadores[10];
    int num_trabajadores;

public:
    Gerente(std::string nombre, int edad, double salario) : Trabajador(nombre, edad, salario) {
        this->num_trabajadores = 0;
    }

    void agregar_trabajador(Trabajador* trabajador) {
        if (this->num_trabajadores < 10) {
            this->trabajadores[this->num_trabajadores] = trabajador;
            this->num_trabajadores++;
        }
    }

    Trabajador** obtener_trabajadores() {
        return this->trabajadores;
    }

    int obtener_num_trabajadores() {
        return this->num_trabajadores;
    }

    void agregarCompanero() {
        for (int i = 0; i < this->num_trabajadores; i++) {
            for (int j = i+1; j < this->num_trabajadores; j++) {
                Trabajador* t1 = this->trabajadores[i];
                Trabajador* t2 = this->trabajadores[j];
                t1->agregar_companero(t2);
                t2->agregar_companero(t1);
            }
        }
    }
};
 
int main(){
    // Crear el objeto Gerente y agregar los trabajadores
Gerente gerente("Ana", 40, 5000.0);
gerente.agregar_trabajador(new Trabajador("Juan", 30, 2500.0));
gerente.agregar_trabajador(new Trabajador("Pedro", 25, 2000.0));
gerente.agregar_trabajador(new Trabajador("Maria", 28, 2200.0));

// Establecer las relaciones entre los trabajadores
gerente.agregarCompanero();

// Obtener los trabajadores del gerente y sus compañeros
Trabajador** trabajadores_gerente = gerente.obtener_trabajadores();
int num_trabajadores_gerente = gerente.obtener_num_trabajadores();

for (int i = 0; i < num_trabajadores_gerente; i++) {
    Trabajador* trabajador_actual = trabajadores_gerente[i];
    std::vector<Trabajador*> companeros = trabajador_actual->obtener_companeros();

    std::cout << "Companeros de " << trabajador_actual->obtener_nombre() << ":" << std::endl;
    for (auto companero : companeros) {
        std::cout << " - " << companero->obtener_nombre() << std::endl;
    }
}
return 0;
}
