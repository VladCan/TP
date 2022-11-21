/* 
 * File:   Personaje.hpp
 * Author: VLADYMIR
 *
 * Created on 19 de noviembre de 2022, 12:15
 */
#ifndef PERSONAJE_HPP
#define PERSONAJE_HPP
#include "Oracion.hpp"
struct Personaje{
    char *nombre;
    struct Oracion *oraciones=new struct Oracion[100];
    int cantOraciones=0;
};


#endif /* PERSONAJE_HPP */

