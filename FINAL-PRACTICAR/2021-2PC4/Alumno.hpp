/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   Alumno.hpp
 * Author: VLADYMIR
 *
 * Created on 27 de noviembre de 2022, 22:25
 */

#ifndef ALUMNO_HPP
#define ALUMNO_HPP
struct Alumno{
    int codigo;
    char *nombre;
    char *escala;
    struct CursoM *cursosM = new struct CursoM[20];
    int numCur=0;
    double promedio;
    double credApro;
    double pagoT;
};


#endif /* ALUMNO_HPP */

