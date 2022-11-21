/* 
 * File:   Oracion.hpp
 * Author: VLADYMIR
 *
 * Created on 19 de noviembre de 2022, 12:12
 */
#ifndef ORACION_HPP
#define ORACION_HPP
#include "Palabra.hpp"
struct Oracion{
    struct Palabra *listaPalabras = new struct Palabra[500];
    struct Palabra *listaPalabrasNoRep = new struct Palabra[500];
    int sentimineto =0;
    int cantPalabras=0;
    int cantPalabrasNoRep=0;
};


#endif /* ORACION_HPP */

