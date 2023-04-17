#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Estudiante {
private:
    string nombre;
    int edad;
    vector<string> cursos;

public:
    Estudiante(string nombre_, int edad_) {
        nombre = nombre_;
        edad = edad_;
    }

    void agregarCurso(string curso) {
        cursos.push_back(curso);
    }

    void imprimirInformacion() {
        cout << "Nombre: " << nombre << endl;
        cout << "Edad: " << edad << endl;
        cout << "Cursos: ";
        for (string curso : cursos) {
            cout << curso << ", ";
        }
        cout << endl;
    }
};

class Docente {
private:
    string nombre;
    int edad;
    string departamento;

public:
    Docente(string nombre_, int edad_, string departamento_) {
        nombre = nombre_;
        edad = edad_;
        departamento = departamento_;
    }

    void imprimirInformacion() {
        cout << "Nombre: " << nombre << endl;
        cout << "Edad: " << edad << endl;
        cout << "Departamento: " << departamento << endl;
    }
};

class Curso {
private:
    string nombre;
    Docente* profesor;
    vector<Estudiante*> estudiantes;

public:
    Curso(string nombre_, Docente* profesor_) {
        nombre = nombre_;
        profesor = profesor_;
    }

    void agregarEstudiante(Estudiante* estudiante) {
        estudiantes.push_back(estudiante);
    }

    void imprimirInformacion() {
        cout << "Nombre del curso: " << nombre << endl;
        cout << "Profesor: ";
        profesor->imprimirInformacion();
        cout << "Estudiantes: " << endl;
        for (Estudiante* estudiante : estudiantes) {
            estudiante->imprimirInformacion();
        }
    }
};
class Asociacion {
private:
    Estudiante* estudiante;
    Docente* docente;
    Curso* curso;

public:
    Asociacion(Estudiante* estudiante_, Docente* docente_, Curso* curso_) {
        estudiante = estudiante_;
        docente = docente_;
        curso = curso_;
    }

    void imprimirInformacion() {
        cout << "Asociación: " << endl;
        cout << "Estudiante: ";
        estudiante->imprimirInformacion();
        cout << "Docente: ";
        docente->imprimirInformacion();
        cout << "Curso: ";
        curso->imprimirInformacion();
    }
};
int main() {
    // Creamos un objeto de la clase "Estudiante" y establecemos sus atributos
    Estudiante* estudiante1 = new Estudiante("Juan", 20);
    estudiante1->agregarCurso("Matemáticas");
    estudiante1->agregarCurso("Física");

    Estudiante* estudiante2 = new Estudiante("María", 21);
    estudiante2->agregarCurso("Química");
    estudiante2->agregarCurso("Biología");

    // Creamos un objeto de la clase "Docente" y establecemos sus atributos
    Docente* docente1 = new Docente("Ana", 35, "Matemáticas");
    Docente* docente2 = new Docente("Pedro", 40, "Química");

    // Creamos un objeto de la clase "Curso" y establecemos sus atributos
    Curso* curso1 = new Curso("Cálculo", docente1);
    curso1->agregarEstudiante(estudiante1);

    Curso* curso2 = new Curso("Química Orgánica", docente2);
    curso2->agregarEstudiante(estudiante2);

    // Creamos objetos de la clase "Asociacion" y establecemos sus atributos
    Asociacion* asociacion1 = new Asociacion(estudiante1, docente1, curso1);
    Asociacion* asociacion2 = new Asociacion(estudiante2, docente2, curso2);

    // Obtenemos la información de los estudiantes
    cout << "Información del estudiante 1: " << endl;
    estudiante1->imprimirInformacion();
    cout << endl;

    cout << "Información del estudiante 2: " << endl;
    estudiante2->imprimirInformacion();
    cout << endl;

    // Obtenemos la información de los docentes
    cout << "Información del docente 1: " << endl;
    docente1->imprimirInformacion();
    cout << endl;
    cout << "Información del docente 2: " << endl;
    docente2->imprimirInformacion();
    cout << endl;

    // Obtenemos la información de los cursos
    cout << "Información del curso 1: " << endl;
    curso1->imprimirInformacion();
    cout << endl;

    cout << "Información del curso 2: " << endl;
    curso2->imprimirInformacion();
    cout << endl;

    // Mostramos la información de las asociaciones
    asociacion1->imprimirInformacion();
    asociacion2->imprimirInformacion();

    // Liberamos la memoria de las instancias creadas
    delete estudiante1;
    delete estudiante2;
    delete docente1;
    delete docente2;
    delete curso1;
    delete curso2;
    delete asociacion1;
    delete asociacion2;

    return 0;
}
