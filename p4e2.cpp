#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Proveedor {
private:
    string nombre;
    string direccion;
public:
    Proveedor() {}
    Proveedor(string nombre, string direccion) {
        this->nombre = nombre;
        this->direccion = direccion;
    }
    string getNombre() {
        return nombre;
    }
    string getDireccion() {
        return direccion;
    }
};

class Producto {
private:
    string codigo;
    string descripcion;
    double precio;
    Proveedor proveedor;
public:
    Producto(string codigo, string descripcion, double precio, Proveedor proveedor) {
        this->codigo = codigo;
        this->descripcion = descripcion;
        this->precio = precio;
        this->proveedor = proveedor;
    }
    string getCodigo() {
        return codigo;
    }
    string getDescripcion() {
        return descripcion;
    }
    double getPrecio() {
        return precio;
    }
    Proveedor getProveedor() {
        return proveedor;
    }
};

class Pago {
private:
    string fecha;
    double monto;
public:
    Pago(string fecha, double monto) {
        this->fecha = fecha;
        this->monto = monto;
    }
    string getFecha() {
        return fecha;
    }
    double getMonto() {
        return monto;
    }
};

class Venta {
private:
    string numeroFactura;
    string fecha;
    vector<Producto> productos;
public:
    Venta(string numeroFactura, string fecha, vector<Producto> productos) {
        this->numeroFactura = numeroFactura;
        this->fecha = fecha;
        this->productos = productos;
    }
    string getNumeroFactura() {
        return numeroFactura;
    }
    string getFecha() {
        return fecha;
    }
    vector<Producto> getProductos() {
        return productos;
    }
};

class Cliente {
private:
    string nombre;
    string direccion;
    string telefono;
    vector<Venta> comprasRealizadas;
    vector<Pago> pagosRealizados;
public:
    Cliente(string nombre, string direccion, string telefono) {
        this->nombre = nombre;
        this->direccion = direccion;
        this->telefono = telefono;
    }
    string getNombre() {
        return nombre;
    }
    string getDireccion() {
        return direccion;
    }
    string getTelefono() {
        return telefono;
    }
    vector<Venta> getComprasRealizadas() {
        return comprasRealizadas;
    }
    vector<Pago> getPagosRealizados() {
        return pagosRealizados;
    }
    void agregarCompra(Venta compra) {
        comprasRealizadas.push_back(compra);
    }
    void agregarPago(Pago pago) {
        pagosRealizados.push_back(pago);
    }
};
int main() {

    // Crear un proveedor
    Proveedor proveedor("Adidas", "Lima, Miraflores");
    
    // Crear un producto asociado al proveedor
    Producto producto("P001", "Camiseta", 10.99, proveedor);
    
    // Crear un cliente
    Cliente cliente("Guchi", "Paucarpata", "946764123");
    
    // Imprimir los datos del proveedor
    cout<<"Proveedor: "<<proveedor.getNombre()<<endl;
    cout<<"Direccion: "<<proveedor.getDireccion()<<endl;
    
    // Imprimir los datos del producto
    cout<<"Producto: "<<producto.getDescripcion()<<endl;
    cout<<"Codigo: "<<producto.getCodigo()<<endl;
    cout<<"Precio: "<<producto.getPrecio()<<endl;
    cout<<"Proveedor: "<<producto.getProveedor().getNombre()<<endl;
    
    // Imprimir los datos del cliente
    cout<<"Cliente: "<<cliente.getNombre()<<endl;
    cout<<"Direccion: "<<cliente.getDireccion()<<endl;
    cout<<"Telefono: "<<cliente.getTelefono()<<endl;

    return 0;
}
