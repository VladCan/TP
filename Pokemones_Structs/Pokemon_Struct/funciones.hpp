/* 
 * File:   funciones.hpp
 * Author: VLADYMIR
 *
 * Created on 11 de noviembre de 2022, 22:17
 */

#ifndef FUNCIONES_HPP
#define FUNCIONES_HPP
#include "Pokemon.hpp"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>

using namespace std;

void llenarStructPokemns(struct Pokemon *pokemons,int &cantPokemons);
char *asignarMemoria(const char *buffer);

#endif /* FUNCIONES_HPP */

