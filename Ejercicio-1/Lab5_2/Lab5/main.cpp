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
    char *distritoAlum[MAX_ALUM];
    char *especialiadad[MAX_ALUM];
    char *facultad[MAX_ALUM];
    int escala[MAX_ALUM];
    double valorCred[MAX_ALUM];
    double credMatri[MAX_ALUM];
    int cantAlum=0;
    int cantDocent=0;
    struct Docente docentes[MAX_DOCENT];
    
    llenarArreglos(nombreAum,codAlum,distritoAlum,especialiadad,facultad,escala,valorCred,credMatri,cantAlum,docentes,cantDocent);
    
//    for(int i=0;i<cantDocent;i++){
//        cout<<docentes[i].nombre<<endl;
//    }
    
    return 0;
}

