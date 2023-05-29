#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
using namespace std;
#include "funciones.h"

void procesarArchivos(ifstream &achAlmacen, ifstream &achProductos, ifstream &achStock, ifstream &achTransacciones, ofstream &archReporte) {

    escribirEncabezado(archReporte);

    int codAlm, codDis;
    int n;
    while (1) {
        achAlmacen>>codAlm;
        if (achAlmacen.eof()) break;
        archReporte << "Almacen: " << codAlm << " - ";
        escribirNombreAlmacen(achAlmacen, archReporte, n);
        achAlmacen>>codDis;
        archReporte << setw(50 - n) << "Distrito : " << codDis << '\n';
        escribirLinea(archReporte, 100, '=');
        procesarStockProductos(codAlm, achProductos, achStock, archReporte);

    }




}

void procesarStockProductos(int codAlm, ifstream &achProductos, ifstream &achStock, ofstream &archReporte) {

    int codProd, almcen, stock, n;
    archReporte << setw(30) << "PRODUCTO" << setw(60) << "STOCK INICIAL" << endl;
    achStock.clear();
    achStock.seekg(0, ios::beg);
    while (1) {
        achStock >> codProd >> almcen>>stock;
        if (achStock.eof()) break;      
        if (codAlm == almcen) {
            archReporte << setw(15) << codProd<<" - ";
            escribirNombrePoducto(achProductos, archReporte, codProd, n);
            archReporte << setw(65 - n) << stock << endl;
            escribirLinea(archReporte,100,'-');
        }
    }

}

void escribirNombrePoducto(ifstream &achProductos, ofstream &archReporte, int codProd, int &n) {
    int cod;
    char c;
    n = 0;
    achProductos.seekg(0, ios::beg);
    while (1) {
        achProductos>>cod;
        if (cod == codProd) {
            achProductos>>ws;
            while (1) {
                c = achProductos.get();
                if (c == '(') c = ' ';
                if (c == ')')break;
                archReporte.put(c);
                n++;
            }
            break;
        } else {
            achProductos.ignore(100, '\n');
        }
    }


}

void escribirNombreAlmacen(ifstream &achAlmacen, ofstream &archReporte, int &n) {
    char c;
    n = 0;
    achAlmacen>>ws;

    while (1) {
        c = achAlmacen.get();
        if (c == ' ')break;
        if (c == '_') c = ' ';
        archReporte.put(c);
        n++;
    }
}

void escribirLinea(ofstream &arch, int cant, char c) {
    for (int i = 0; i < cant; i++)
        arch.put(c);
    arch << endl;
}

void escribirEncabezado(ofstream &archReporte) {
    archReporte << setw(30) << " " << "DETALLE DE MOVIMIENTOS DE ALMACENES\n";
    escribirLinea(archReporte, 100, '=');

}




