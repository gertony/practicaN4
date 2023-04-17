#include<iostream>
#include<string>

using namespace std;
class Hijo{
    private:
        string nombre;
    public:
        Hijo(string nombre){
            this->nombre=nombre;
        }
        void setHijo(string nomHijo){
            nombre=nomHijo;
        }
        string getHijo(){
            return nombre;
        }
};  

class Padre{
    private:
        string nombre;
        int numHijos;
        Hijo* hijos[10];
    public:
        Padre(string nombre){
            this->nombre=nombre;
            numHijos=0;
        }
        void agregarHijo(Hijo*hijo){
            if (numHijos<10){
                hijos[numHijos]=hijo;
                numHijos++;
            }
            }
        void setPadre(string NomPad){
            nombre=NomPad;
        }
        string getPadre(){
            return nombre;
        }
        void imprimirInfo(){
            cout<<"El padre: "<<nombre<<" tiene: "<<numHijos<<" hijos y son:"<<endl;
            for (int i=0;i<numHijos;i++){
                cout<<hijos[i]->getHijo()<<endl;
            }
        }
};


int main(){
    Padre padre1("Edgardo Rivero");
    Hijo hijo1("Mariano Sosa");
    Hijo hijo2("Juan Trevino");
    Hijo hijo3("Ronaldinho Gaucho");
    Hijo hijo4("Lionel Pepsi");
    padre1.agregarHijo (& hijo1);
    padre1.agregarHijo (& hijo2);
    padre1.agregarHijo (& hijo3);
    padre1.agregarHijo (& hijo4);
    padre1.imprimirInfo();
    return 0;
}
