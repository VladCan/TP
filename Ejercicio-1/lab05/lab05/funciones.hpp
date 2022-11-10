/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   funciones.hpp
 * Author: alulab14
 *
 * Created on 7 de noviembre de 2022, 03:42 PM
 */

#ifndef FUNCIONES_HPP
#define FUNCIONES_HPP
#define MAX_DATOS 100
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
using namespace std;
void llenarDocentes(ifstream &archMatr, struct Docente &doc);
void llenarAlumnos(ifstream &archMatr, char *&nombre, int &codigo, char *&distr, char *&espe, char *&facu, int &escal, double &valCred, double &creMatri);
void llenarArreglosyEstructuras(char **nombre_al, int *codAlum, char **distrito, char **especialidad, char **facultad, int *escala, double *valorCred,
        double *credMatri, int &cant_Alum, int &cant_Docentes, struct Docente *docentes);
void escribirReporte(char **nombre_al, int *codAlum, char **distrito, char **especialidad, char **facultad, int *escala, double *valorCred,
        double *credMatri, int cant_Alum, int cant_Docentes, struct Docente * docentes);
void escribirLinea(ofstream &arch,int cant,char c);
#endif /* FUNCIONES_HPP */

