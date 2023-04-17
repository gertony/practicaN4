#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Libro
    {
        private:
            string nombre;
            string autor;
            int isbn;
        public:
            Libro(string nombre, string autor, int isbn)
            {
                this->nombre = nombre;
                this->autor = autor;
                this->isbn = isbn;
            }
            string getNombre()
            {
                return nombre;
            }
    };


class Biblioteca
   {
        private:
            vector<Libro*> lista_libros;
        public:

            void agregarLibro(Libro* libro)
            {
                lista_libros.push_back(libro);
            }
            void eliminarLibro(Libro* libro) 
            {
                for (int i = 0; i <lista_libros.size(); i++)
                {
                    if(lista_libros[i] == libro)
                    {
                        lista_libros.erase(lista_libros.begin() + i);
                        return;
                    }
                } 
            }
            Libro* buscarLibro(string nombre) 
            {
                for (int i = 0; i < lista_libros.size(); i++) 
                {
                    if (lista_libros[i]->getNombre() == nombre) 
                    {
                        return lista_libros[i];
                    }
                }
            return 0;
            }
   };


int main() {

    Libro* libro1 = new Libro("El Quijote", "Miguel de Cervantes", 01);
    Libro* libro2 = new Libro("Cien años de soledad", "Gabriel García Márquez",02);
    Libro* libro3 = new Libro("La Iliada", "Homero",03);
    

    Biblioteca miBiblioteca;
    

    miBiblioteca.agregarLibro(libro1);
    miBiblioteca.agregarLibro(libro2);
    miBiblioteca.agregarLibro(libro3);
    

    Libro* libroBuscado = miBiblioteca.buscarLibro("Cien años de soledad");
    
    if (libroBuscado) {
        cout << "El libro " << libroBuscado->getNombre() << " fue encontrado en la biblioteca." << endl;
    } else {
        cout << "El libro buscado no se encuentra en la biblioteca." << endl;
    }
    

    miBiblioteca.eliminarLibro(libro1);
    

    libroBuscado = miBiblioteca.buscarLibro("El Quijote");
    
    if (libroBuscado) {
        cout << "El libro " << libroBuscado->getNombre() << " fue encontrado en la biblioteca." << endl;
    } else {
        cout << "El libro buscado no se encuentra en la biblioteca." << endl;
    }
    

    delete libro1;
    delete libro2;
    delete libro3;
    
    return 0;
}
