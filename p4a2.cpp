#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
class Curso;
class Estudiante{
    private:
        string nombreCompleto, idEstudiante, correo, DNI;
        vector<Curso*>cursos;
    public:
        Estudiante(string nombreCompleto, string idEstudiante, string correo, string DNI){
            this->nombreCompleto=nombreCompleto;
            this->idEstudiante=idEstudiante;
            this->correo=correo;
            this->DNI=DNI;
        }
        void agregarCurso(Curso * curso){
            cursos.push_back(curso);
        }
        int numCursos(){
            return cursos.size();
        }
        void eliminarCurso(Curso * curso){
            ///Para eliminar el curso es diferente a solo colocar .erase() como en el caso de push_back.
            cursos.erase(remove(cursos.begin(),cursos.end(),curso),cursos.end());
        }
        string& getNombreCompleto(){
            return nombreCompleto;
        }
        vector<Curso*>& getCursos(){
            return cursos;
        }

};
class Estudiante;
class Curso{
    private:
        string nombre, descripcion, codigo, fechaIncio, fechaFinalizacion;
        vector<Estudiante*>estudiantes;
    public:
        Curso(string nombre, string descripcion, string codigo, string fechaInicio, string fechaFinalizacion){
            this->nombre=nombre;
            this->descripcion=descripcion;
            this->codigo=codigo;
            this->fechaIncio=fechaInicio;
            this->fechaFinalizacion=fechaFinalizacion;
        }
        void agregarEstudiante(Estudiante * estudiante){
            estudiantes.push_back(estudiante);
        }
        int numEstudiantes(){
            return estudiantes.size();
        }
        void eliminarEstudiante(Estudiante * estudiante){
            ///Para eliminar a un estudiante es diferente a solo colocar .erase() como en el caso de push_back.
            estudiantes.erase(remove(estudiantes.begin(),estudiantes.end(),estudiante),estudiantes.end());
        }
        string& getNombreCurso(){
            return nombre;
        }
        vector<Estudiante*>& getNombreEstudiante(){
            return estudiantes;
        }

};

int main(){
    Curso curso1("Matematica", "Curso de Matematica" ,"AV-232", "28/04", "29/07");
    Curso curso2("Comunicacion", "Curso de comunicacion", "AV-301","29/03","26/07");
    Estudiante estudiante1("Luis Torres", "2022250761", "tluis4671@hotmail.com", "73999505");
    Estudiante estudiante2("Carlos Mondongo", "2022435623", "carmondo@gmail.com","74905346");
    Estudiante estudiante3("Gabriel Paricagua", "2022253674", "gabipa2324@gmail.com", "93454273");
    Estudiante estudiante4("Fabricio Miota", "2022536593", "miotafa23@gmail.com", "69593943");
    curso1.agregarEstudiante(& estudiante1);
    curso1.agregarEstudiante(& estudiante3);
    curso1.agregarEstudiante(& estudiante4);
    curso2.agregarEstudiante(& estudiante2);
    curso2.agregarEstudiante(& estudiante1);
    curso2.agregarEstudiante(& estudiante4);
    estudiante1.agregarCurso(& curso1);
    estudiante1.agregarCurso(& curso2);
    estudiante2.agregarCurso(& curso2);
    estudiante3.agregarCurso(& curso1);
    estudiante4.agregarCurso(& curso1);
    estudiante4.agregarCurso(& curso2);
    cout<<"El curso de "<<curso1.getNombreCurso()<<" tiene "<<curso1.numEstudiantes()<<" estudiantes y son:"<<endl;
    for (auto& estudiante:curso1.getNombreEstudiante()){
        cout<<"- "<<estudiante->getNombreCompleto()<<endl;
    }
    cout<<"El curso de "<<curso2.getNombreCurso()<<" tiene "<<curso2.numEstudiantes()<<" estudiantes y son:"<<endl;
    for (auto& estudiante:curso2.getNombreEstudiante()){
        cout<<"- "<<estudiante->getNombreCompleto()<<endl;
    }
    cout<<"El alumno "<<estudiante1.getNombreCompleto()<<" esta en "<<estudiante1.numCursos()<<" cursos y estos son:"<<endl;
    for(auto& curso:estudiante1.getCursos()){
        cout<<"- "<<curso->getNombreCurso()<<endl;
    }
    cout<<"El alumno "<<estudiante3.getNombreCompleto()<<" esta en "<<estudiante3.numCursos()<<" cursos y estos son:"<<endl;
    for(auto& curso:estudiante3.getCursos()){
        cout<<"- "<<curso->getNombreCurso()<<endl;
    }
    curso1.eliminarEstudiante(& estudiante3);
    estudiante3.eliminarCurso(& curso1);
    cout<<"El curso de "<<curso1.getNombreCurso()<<" tiene "<<curso1.numEstudiantes()<<" estudiantes y son:"<<endl;
    for (auto& estudiante:curso1.getNombreEstudiante()){
        cout<<"- "<<estudiante->getNombreCompleto()<<endl;
    }
    cout<<"El alumno "<<estudiante3.getNombreCompleto()<<" esta en "<<estudiante3.numCursos()<<" cursos y estos son:"<<endl;
    for(auto& curso:estudiante3.getCursos()){
        cout<<"- "<<curso->getNombreCurso()<<endl;
    }


    return 0;
}
