/* 
 * File:   funciones.hpp
 * Author: VLADYMIR
 *
 * Created on 19 de noviembre de 2022, 11:54
 */
#ifndef FUNCIONES_HPP
#define FUNCIONES_HPP
#include "Palabra.hpp"
#include "Oracion.hpp"
#include "Personaje.hpp"
#include <iomanip>
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
void llenarStructPersonajes(struct Personaje *personajes,int &cantPersonajes);
int buscarPesonaje(struct Personaje *personajes,char *buffer,int &cantPersonajes);
void actualizarPersonaje(ifstream &archHarry,struct Personaje *personajes,int posicion);
void insertarPersonaje(ifstream &archHarry,struct Personaje *personajes,char *buffer,int &cantPersonajes);
char *asignarMenoria(const char *buffer);
void escribirLinea(ofstream &arch,int cant,char c);

#endif /* FUNCIONES_HPP */

