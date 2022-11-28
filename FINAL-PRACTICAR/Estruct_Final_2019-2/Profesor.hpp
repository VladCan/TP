/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   Profesor.hpp
 * Author: VLADYMIR
 *
 * Created on 27 de noviembre de 2022, 10:43
 */

#ifndef PROFESOR_HPP
#define PROFESOR_HPP
struct Profesor{
    int codigo;
    char *nombre;
    char *categoria;
    char *dedicacion;
    struct Curso *cursos;
    int numCur = 0;
};


#endif /* PROFESOR_HPP */

