/* 
 * File:   funciones.hpp
 * Author: VLADYMIR
 *
 * Created on 11 de noviembre de 2022, 22:17
 */

#ifndef FUNCIONES_HPP
#define FUNCIONES_HPP
#include "Moves.hpp"
#include "Pokemon.hpp"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>

using namespace std;

void llenarStructPokemns(struct Pokemon *pokemons,int &cantPokemons);
void llenarStructMoves(struct Moves *movimientos,int &cantMoves);
void llenarPokemonMoves(struct Pokemon *pokemons,int cantPokemons,struct Moves *movimientos,int cantMoves);
char *asignarMemoria(const char *buffer);


#endif /* FUNCIONES_HPP */

