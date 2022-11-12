/* 
 * File:   main.cpp
 * Nombre : Vladymir Canchari
 * Codigo : 20195808
 * Created on 7 de noviembre de 2022, 01:04 PM
 */

#include "funciones.hpp"

int main(int argc, char** argv) {
    //Alum : Alumnos; 
    char *nombreAlum[CANT_MAX_ALUM];
    int codAlum[CANT_MAX_ALUM];
    char *distritoAlum[CANT_MAX_ALUM];
    char *especialidad[CANT_MAX_ALUM];
    char *facultad[CANT_MAX_ALUM];
    int escala[CANT_MAX_ALUM];
    double valorCred[CANT_MAX_ALUM];
    double credMatri[CANT_MAX_ALUM];
    int cantAlum = 0;
    int cantDoncent = 0;
    struct Docente docentes[CANT_MAX_DOCENT];
   llenarDatos(nombreAlum,codAlum,distritoAlum,especialidad,facultad,escala,valorCred,credMatri,cantAlum,docentes,cantDoncent);
   ordenarArreglosAlum(nombreAlum,codAlum,distritoAlum,especialidad,facultad,escala,valorCred,credMatri,cantAlum);
   escribirReporte(nombreAlum,codAlum,distritoAlum,especialidad,facultad,escala,valorCred,credMatri,cantAlum,docentes,cantDoncent);
   
    return 0;
}

