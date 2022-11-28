/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   funciones.hpp
 * Author: VLADYMIR
 *
 * Created on 27 de noviembre de 2022, 22:26
 */

#ifndef FUNCIONES_HPP
#define FUNCIONES_HPP
#include "CursoM.hpp"
#include "Escala.hpp"
#include "Alumno.hpp"
#include "Curso.hpp"
#include <iomanip>
#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

void llenarStructAlumnos(struct Alumno *,int &);
void llenarStructCursos(struct Curso *,int &);
void llenarStructEscalas(struct Escala *,int &);
char * asignarMemoria(char *);
void completarDatosAlum(struct Alumno *,int );
int buscarAlumno(struct Alumno *,int ,int);
#endif /* FUNCIONES_HPP */

