/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: alulab14
 *
 * Created on 7 de noviembre de 2022, 03:41 PM
 */
#include "docentes.hpp"
#include "funciones.hpp"

int main(int argc, char** argv) {
    char *nombre_al[MAX_DATOS];
    int codAlum[MAX_DATOS];
    char *distrito[MAX_DATOS];
    char *especialidad[MAX_DATOS];
    char *facultad[MAX_DATOS];
    int escala[MAX_DATOS];
    double valorCred[MAX_DATOS];
    double credMatri[MAX_DATOS];
    int cant_Alum = 0;
    int cant_Docentes = 0;
    struct Docente docentes[MAX_DATOS];

    llenarArreglosyEstructuras(nombre_al, codAlum, distrito, especialidad, facultad, escala, valorCred, credMatri, cant_Alum, cant_Docentes, docentes);
   
    escribirReporte(nombre_al, codAlum, distrito, especialidad, facultad, escala, valorCred, credMatri, cant_Alum,cant_Docentes, docentes);
    return 0;
}

