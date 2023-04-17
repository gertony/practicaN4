#include <iostream>
#include <string>
#include <vector>

using namespace std;

//Creamos las clases
class Profesor;
class Alumno;

class Asignatura{

    private:
        string nombre;
        int codigo;
        string descripcion;
        int notas;
        int faltas;
        vector<Profesor*> profesores; //Asignamos que cada asignatura puede tener una lista de objetos tipo Profesor
        vector<Alumno*> alumnos;    //Y Alumno

    public:
        Asignatura(string nombre, int codigo, string descripcion, int notas, int faltas){
            this -> nombre = nombre;
            this -> codigo = codigo;
            this -> descripcion = descripcion;
            this -> notas = notas;
            this -> faltas = faltas;
        }

        //Setters y Getters
        string getNombre(){return nombre;}
        int getCodigo(){return codigo;}
        string getDescripcion(){return descripcion;}
        int getNotas(){return notas;}
        int getFaltas(){return faltas;}
        vector<Profesor*> getProfesores(){return profesores;}
        vector<Alumno*> getAlumnos(){return alumnos;}

        //Metodos para agregar objetos al vector profesores dentro de la asignatura
        void agregarProfesor(Profesor* profesor){
            profesores.push_back(profesor);
        }
        void agregarAlumno(Alumno* alumno){
            alumnos.push_back(alumno);
        }
      
};

//Clase Padre
class Persona{

    private:

        string nombre;
        string direccion;

    public:

        Persona(string nombre, string direccion){
            this -> nombre = nombre;
            this -> direccion = direccion;
        }
        string getNombre(){return nombre;}
        string getDireccion(){return direccion;}
};

	class Alumno : public Persona{ //Herencia

    private:

        int nMatricula;
        int nota;
        int faltas;

    public:

        Alumno(string nombre, string direccion, int nMatricula, int nota, int faltas) : Persona(nombre, direccion){
            this -> nMatricula = nMatricula;
            this -> nota = nota;
            this -> faltas = faltas;
        }

        int getNMatricula(){return nMatricula;}
        int getNota(){return nota;}
        int getFaltas(){return faltas;}

};
class Profesor : public Persona{    //Herencia
    
    private:
        int nTelefono;

    public:
        Profesor(string nombre, string direccion, int nTelefono) : Persona(nombre, direccion){
            this -> nTelefono = nTelefono;
        }
        int getNTelefono(){return nTelefono;}
};

class Registro{
    
    private:
        vector<Asignatura*> asignaturas; //Asignamos un vector de "asignaturas"

    public:
        Registro(){}

        void agregarAsignatura(Asignatura* asignatura) {
        asignaturas.push_back(asignatura);
    }     
        
        //Funcion para mostrar todo el registro
        void mostrarRegistro(){

            //Recorrer todas las asignaturas en el registro
            for (int i = 0; i < asignaturas.size(); i++){
                cout<<"Asignatura: "<<asignaturas[i]->getNombre()<<endl;
                cout<<"Codigo: "<<asignaturas[i]->getCodigo()<<endl;
                
                //Recorrer profesores asignados en el curso

                cout<<"Profesores Responsables: "<<endl;

                vector<Profesor*> profesores = asignaturas[i]->getProfesores();
                for (int j = 0; j < profesores.size(); j++) {
                    cout << profesores[j]->getNombre() <<" - Numero de telefono: "<<profesores[j]->getNTelefono()<< endl;
                }
                cout<<"Alumnos matriculados: "<<endl;

                //Recorrer cada alumno matriculado en el curso
                vector<Alumno*> alumnos = asignaturas[i]->getAlumnos();
                for (int j = 0; j < alumnos.size(); j++) {
                    cout << alumnos[j]->getNombre() <<endl;
                    cout<< "Numero de matricula: "<<alumnos[j]->getNMatricula()<<" - Nota final: "<<alumnos[j]->getNota()<<" - Faltas: "<<alumnos[j]->getFaltas()<<endl;
                } } 
        }
};
int main() {
    //Iniciamos un registro vacio
    Registro registro;
    
    //Instanciamos las clases
    Profesor* profesor1 = new Profesor("Oscar Flores", "URB. San Antonio D-11", 912123123);
    Profesor* profesor2 = new Profesor("Angel Ramos", "Calle Proceres 21", 998877665);
    Profesor* profesor3 = new Profesor("Jorge Luna", "Calle Guevara 456", 900900901);

    Alumno* alumno1 = new Alumno("Pedro Lopez", "Calle Pumacahua 201", 0001, 20, 0);
    Alumno* alumno2 = new Alumno("Hernan Crespo", "URB. Los Angeles K-11", 0002, 12, 4);
    Alumno* alumno3 = new Alumno("Martin Palermo", "Calle Arequipa 102", 0003, 15, 1);

    //Instanciamos una nueva asignatura
    Asignatura* asignatura1 = new Asignatura("Programación", 123, "Introducción a la programación", 3, 0);

    //Asignamos lo antes creado
    asignatura1->agregarProfesor(profesor1);
    asignatura1->agregarProfesor(profesor2);
    asignatura1->agregarAlumno(alumno1);
    asignatura1->agregarAlumno(alumno2);
    
    //Añadimos la asignatura al registro
    registro.agregarAsignatura(asignatura1);
    
    //Repetimos todo con otra asignatura
    Asignatura* asignatura2 = new Asignatura("FITI", 112, "Fundamentos de ITI", 3, 0);

    asignatura2->agregarProfesor(profesor3);
    asignatura2->agregarAlumno(alumno3);

    registro.agregarAsignatura(asignatura2);

    //Imprimimos todo el registro
    registro.mostrarRegistro();
    
    //Limpiamos la memoria
    delete profesor1;
    delete profesor2;
    delete profesor3;
    delete alumno1;
    delete alumno2;
    delete alumno3;
    delete asignatura1;
    delete asignatura2;
    
    return 0;
}
