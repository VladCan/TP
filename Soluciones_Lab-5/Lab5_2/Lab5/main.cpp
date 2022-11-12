/* 
 * File:   main.cpp
 * Author: alulab14
 *
 * Created on 7 de noviembre de 2022, 03:27 PM
 */

#include "funciones.hpp"

using namespace std;

int main(int argc, char** argv) {

    char *nombreAum[MAX_ALUM];
    int codAlum[MAX_ALUM];
    char *distritoArr[MAX_ALUM];
    char *especialiadadArr[MAX_ALUM];
    char *facultadArr[MAX_ALUM];
    int escalaArr[MAX_ALUM];
    double valorCredArr[MAX_ALUM];
    double credMatriArr[MAX_ALUM];
    int cantAlum=0;
    int cantDocent=0;
    struct Docente docentes[MAX_DOCENT];
    
    llenarDatos(nombreAum,codAlum,distritoArr,especialiadadArr,facultadArr,escalaArr,valorCredArr,credMatriArr,cantAlum,docentes,cantDocent);
    
//    for(int i=0;i<cantDocent;i++){
//        cout<<docentes[i].nombre<<endl;
//    }
    
    return 0;
}

