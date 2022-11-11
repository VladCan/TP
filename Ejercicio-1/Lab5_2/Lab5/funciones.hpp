
/* 
 * File:   funciones.hpp
 * Author: alulab14
 *
 * Created on 7 de noviembre de 2022, 03:28 PM
 */

#ifndef FUNCIONES_HPP
#define FUNCIONES_HPP
#define MAX_ALUM 100
#define MAX_DOCENT 100
#include "Docentes.hpp"
#include <fstream>
#include <iomanip>
#include <iostream>
#include <cstring>
using namespace std;

void  llenarArreglos(char **nombreAum,int *codAlum,char **distritoAlum,char **especialiadad,char **facultad,int *escala,double *valorCred,double *credMatri,int &cantAlum,
          struct Docente *docentes,int &cantDocent);
void llenarArrglos(ifstream &archMatri,char **nombreAum, int *codAlum, char **distritoAlum, char **especialiadad, char **facultad, int *escala, double *valorCred, double *credMatri, int &cantAlum);
 void llenarStruct(ifstream &archMatri,struct Docente *docentes, int &cantDocent);
void quitarBarra(ifstream &archMatri,char *&nombre);
#endif /* FUNCIONES_HPP */

