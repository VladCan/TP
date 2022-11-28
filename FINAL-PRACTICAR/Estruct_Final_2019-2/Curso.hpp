/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   Curso.hpp
 * Author: VLADYMIR
 *
 * Created on 27 de noviembre de 2022, 10:43
 */

#ifndef CURSO_HPP
#define CURSO_HPP
struct Curso{
    int codigo;
    char *nombreCrur;
    double numCred;
    char *especialidad;
    int horario; 
    int numMatriculados;
    struct Sesion *sesiones;
    int numSesions=0;
};


#endif /* CURSO_HPP */

