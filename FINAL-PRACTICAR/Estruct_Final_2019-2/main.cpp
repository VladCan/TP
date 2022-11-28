/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: VLADYMIR
 *
 * Created on 27 de noviembre de 2022, 10:36
 */

#include "funciones.hpp"

int main(int argc, char** argv) {
    struct Curso cursos[MAX_CURSOS];
    struct Profesor profesores[MAX_PROF];
    int cantCursos = 0;
    int cantProf = 0;
    llenarStructCursos(cursos, cantCursos);
    llenarStructProfesores(profesores, cantProf);
    completarStructProfesres(cursos, profesores, cantCursos, cantProf);
    escribirReporte(cursos, profesores, cantCursos, cantProf);

    return 0;
}

