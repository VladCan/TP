/* 
 * File:   funciones.hpp
 * Nombre : Vladymir Canchari
 * Codigo : 20195808
 * Created on 7 de noviembre de 2022, 01:04 PM
 */

#ifndef FUNCIONES_HPP
#define FUNCIONES_HPP
#define CANT_MAX_ALUM 100
#define CANT_MAX_DOCENT 100
#include "Docente.hpp"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;

void llenarDatos(char **nombreAlum, int *codAlum, char **distritoAlum, char **especialidad, char **facultad, int *escala,double *valorCred,double *credMatri, int &cantAlum,
        struct Docente *docentes, int &cantDoncent);
void llenarArregloAlum(ifstream &achrMiembro, char **nombreAlum, int *codAlum, char **distritoAlum, char **especialidad, char **facultad, int *escala,double *valorCred,double *credMatri, int &cantAlum);
void llenarArrStructDocent(ifstream &achrMiembro, struct Docente *docentes, int &cantDoncent);
void quitarBarra(char *&nombre,ifstream &achrMiembro);
void ordenarArreglosAlum(char **nombreAlum, int *codAlum, char **distritoAlum, char **especialidad, char **facultad, int *escala,double *valorCred,double *credMatri, int cantAlum);
void escribirReporte(char **nombreAlum, int *codAlum, char **distritoAlum, char **especialidad, char **facultad, int *escala,double *valorCred,double *credMatri, int cantAlum,
        struct Docente *docentes, int cantDoncent);
void escribirLinea(ofstream &archReporte,int cant ,char c);
#endif /* FUNCIONES_HPP */

