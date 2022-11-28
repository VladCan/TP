/* 
 * File:   main.cpp
 * Author: VLADYMIR
 *
 * Created on 27 de noviembre de 2022, 22:24
 */

#include "funciones.hpp"


int main(int argc, char** argv) {
    struct Alumno *alumnos = new struct Alumno[100];
    struct Curso *cursos = new struct Curso[50];
    struct Escala *escalas = new struct Escala[200];
    
    int cantCur=0,cantAlu=0,cantEscala=0;
    
    llenarStructAlumnos(alumnos,cantAlu);
    llenarStructCursos(cursos,cantCur);
    llenarStructEscalas(escalas,cantEscala);
    completarDatosAlum(alumnos,cantAlu);
    for(int i=0;i<cantAlu;i++){
        cout<<alumnos[i].codigo<<"  "<<alumnos[i].nombre<<endl;
        for(int j=0;j<alumnos[i].numCur;j++){
            cout<<alumnos[i].cursosM[j].cod<<endl;
        }
    }
    return 0;
}

