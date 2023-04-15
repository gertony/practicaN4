#include <iostream>
#include <string>
using namespace std;

class Celular{
    private:
        string marca;
        string modelo;
        int almacenamiento; //en GB
        int ram; //en GB
    public:
        Celular(string marca, string modelo, int almacenamiento, int ram){
            this->marca = marca;
            this->modelo = modelo;
            this -> almacenamiento = almacenamiento;
            this -> ram = ram;
        }
        string getMarca(){return marca;}
        string getModelo(){return modelo;}
        int getAlmacenamiento(){return almacenamiento;}
        int getRam(){return ram;}
};

class Almacen{
    private:
        string nombre;
        Celular* celulares[100];
        int numCelulares;
    public:
        Almacen(string nombre){
            this -> nombre = nombre;
            numCelulares = 0;
        }

        void agregarCelular(Celular* celular) {
        if (numCelulares < 100) {
            celulares[numCelulares++] = celular;
        }else {
        cout << "No se pueden agregar más celulares" << endl;
        }
        }

        void Mostrar(){
            cout<<"Lista de celulares en almacén: "<<endl;
            for (int i = 0; i<numCelulares; i++){
                cout<<"Celular #"<<i+1<<endl;
                cout<<"Marca: "<< celulares[i]->getMarca()<<endl;
                cout<<"Modelo: "<< celulares[i]->getModelo()<<endl;
                cout<<"Almacenamiento "<< celulares[i]->getAlmacenamiento()<<endl;
                cout<<"Ram: "<< celulares[i]->getRam()<<endl;
            }
        }         

};

int main(){

    Celular* c1 = new Celular("Samsung", "S23", 256, 8);
    Celular* c2 = new Celular("Apple", "iPhone 11", 128, 8);
    Celular* c3 = new Celular("Xiaomi", "Redmi Note 10", 64, 4);
    Celular* c4 = new Celular("Huawei", "P20", 64, 6);

    Almacen* a1 = new Almacen("Almacen Arequipa");
        a1 -> agregarCelular(c1);
        a1 -> agregarCelular(c2);
        a1 -> agregarCelular(c3);
        a1 -> agregarCelular(c4);
        a1 -> Mostrar();

    delete c1; 
    delete c2;
    delete c3;
    delete c4;
    delete a1;

    return 0;
}
