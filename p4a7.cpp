#include <iostream>
#include <string>

using namespace std;

using namespace std;

class Personas
{
    private:
        string nombre;
        string apellidopaterno;
        int edad;

    public:

    int dni;
    Personas(string nombre,string apellidopaterno, int edad, int dni)
    {
        this->nombre = nombre;
        this->edad = edad;
        this->dni = dni;
        this->apellidopaterno = apellidopaterno;
    }
    virtual string getNombre()
    {
        return nombre;
    }

    virtual int getEdad()
    {
        return edad;
    }

    virtual string getApellidoPaterno()
    {
        return apellidopaterno;
    }

    virtual void setEdad(int newEdad)
    {
        edad = newEdad;
    }
    
    virtual void setNombre(string newNombre)
    {
        nombre = newNombre;
    }

    virtual void setApellido(string newApellido)
    {
        apellidopaterno = newApellido;
    }   
};

class Alumno : public Personas
{
    private:
        int codigo;
        
    public:
        string carrera;
        Alumno(string nombre, string apellidopaterno,int edad, int dni, int codigo, string carrera) : Personas(nombre, apellidopaterno, edad, dni)
        {
            this->codigo = codigo;
            this->carrera = carrera;
        }  

        void setCodigo(int newCodigo)
        {
            codigo = newCodigo;
        }

        int getCodigo()
        {
            return codigo;
        }

        void obtenerCorreo()
        {
            string ucsm = "@ucsm.edu.pe";
            string nombre1,apellido1;
            nombre1 = getNombre();
            apellido1 = getApellidoPaterno();
            cout << "Correo Institucional: " <<  nombre1 <<"."<< apellido1 <<ucsm<<endl;
        }

        ~Alumno() 
        {
        }
};
int main()
{
    Alumno* alumno1 = new Alumno("Juan","Martinez",15,72685428,2022802411,"Ing de sistemas");

    cout << alumno1->dni << endl;
    cout << alumno1->getNombre() << endl;
    cout << alumno1->getApellidoPaterno() << endl;
    cout << alumno1->getEdad() << endl;

    cout << alumno1->carrera << endl;
    cout << alumno1->getCodigo() << endl;
    alumno1->obtenerCorreo();

    alumno1->setEdad(19);
    alumno1->setCodigo(202280441);
    alumno1->setNombre("Juan Pablo");
    alumno1->setApellido("Rodriguez");
    alumno1->dni = 72685438;
    alumno1->carrera = "Ing Mecanica";
    delete alumno1;
    return 0;

}
