/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   funciones.hpp
 * Author: VLADYMIR
 *
 * Created on 27 de noviembre de 2022, 11:00
 */

#ifndef FUNCIONES_HPP
#define FUNCIONES_HPP
#define MAX_CURSOS 100
#define MAX_PROF 50
#include "Sesion.hpp"
#include "Curso.hpp"
#include "Profesor.hpp"
#include <iomanip>
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

void llenarStructCursos(struct Curso *cursos,int &cant);
void llenarStructProfesores(struct Profesor *profesores,int &cant);
void completarStructProfesres(struct Curso *cursos,struct Profesor *profesores,int cantCursos,int cantProf);
void escribirReporte(struct Curso *cursos,struct Profesor *profesores,int cantCursos,int cantProf);
void almacenarDatosDeSecion(ifstream &archSesiones,int &codCur,int &horario,int &numAlu,int &codProf);
int buscarProfesor(struct Profesor *profesores,int codProf,int cantProf);
int buscarCurso(struct Curso *cursos,int codCur,int cantCursos);
void actualisarProfesor(struct Profesor *profesores, struct Curso *cursos, int posocionProf, int posicionCurso, int codCur, int horario, int numAlu, ifstream &archSesiones);
char * cambiarFormatoNombe(char *nombres,char *apellido1,char *apellido2);
char *asignarMemoria(char *buffer);
void escribirLinea(ofstream &archR,int cant,char c);
#endif /* FUNCIONES_HPP */

