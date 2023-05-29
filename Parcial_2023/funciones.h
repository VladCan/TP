

#ifndef FUNCIONES_H
#define FUNCIONES_H

void escribirLinea(ofstream &arch,int cant,char c);
void procesarArchivos(ifstream &achAlmacen,ifstream &achProductos,ifstream &achStock,
        ifstream &achTransacciones,ofstream &archReporte);
void escribirNombreAlmacen(ifstream &achAlmacen,ofstream &archReporte,int &n);

void procesarStockProductos(int codAlm,ifstream &achProductos,ifstream &achStock,ofstream &archReporte);
void  escribirNombrePoducto(ifstream &achProductos,ofstream &archReporte,int codProd,int &n);
void escribirEncabezado(ofstream &archReporte);

#endif /* FUNCIONES_H */

