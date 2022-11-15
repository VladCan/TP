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
void escribirReportDePokemonMoves(struct Pokemon *pokemons,int cantPokemons,struct Moves *movimientos,int cantMoves);
void escribirLinea(ofstream &arch,int cant,char c);
void batallaPokemon(struct Pokemon *pokemons,int cantPokemons);
void escribirReporteBatalla(struct Pokemon *equipoA,struct Pokemon *equipoB,int HP_Max_EquipoA,int HP_Max_EquipoB);
void estadisticasEquipoA(ofstream &archBatalla,struct Pokemon *equipoA);
void estadisticasEquipoB(ofstream &archBatalla,struct Pokemon *equipoB);
int mejorPokemonEnLaEstadisticaX(struct Pokemon *equipo,int x);
int peorPokemonEnLaEstadisticaX(struct Pokemon *equipo,int x);
#endif /* FUNCIONES_HPP */

