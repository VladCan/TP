#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;
#include "funciones.h"

int main(int argc, char** argv) {
    
    ifstream achAlmacen("Almacen.txt",ios::in);
     if (not achAlmacen.is_open()) {
        cout << "El archivo no se pudo abrir Almacen";
        exit(1); 
    }
     ifstream achProductos("Productos.txt",ios::in);
     if (not achProductos.is_open()) {
        cout << "El archivo no se pudo abrir";
        exit(1);
    }
     ifstream achStock("StockProductos.txt",ios::in);
     if (not achStock.is_open()) {
        cout << "El archivo no se pudo abrir";
        exit(1);
    }
      ifstream achTransacciones("Transacciones.txt",ios::in);
     if (not achTransacciones.is_open()) {
        cout << "El archivo no se pudo abrir";
        exit(1);
    }
      ofstream archReporte("ReporteAlmacenes.txt",ios::out);
    if (not archReporte.is_open()) {
        cout << "El archivo no se pudo abrir";
        exit(1);
    }
      
      
      
   procesarArchivos(achAlmacen,achProductos,achStock,achTransacciones,archReporte);
      
      
    return 0;
}

