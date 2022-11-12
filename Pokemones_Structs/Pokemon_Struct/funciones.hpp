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
void valoresAleatorios(int &E1_1,int & E1_2,int & E1_3,int & E1_4,int & E1_5,int & E1_6,int &E2_1,int & E2_2,int & E2_3,int & E2_4,int & E2_5,int & E2_6);
void llenarEquipo(struct Pokemon *equipo,struct Pokemon *pokemons,int v1,int v2,int v3,int v4,int v5,int v6);
void escribirReporteBatalla(struct Pokemon *equipoA,struct Pokemon *equipoB,int HP_Max_EquipoA,int HP_Max_EquipoB);
void estadisticasEquipoA(ofstream &archBatalla,struct Pokemon *equipoA);
void estadisticasEquipoB(ofstream &archBatalla,struct Pokemon *equipoB);
int mejorPokemonEnLaEstadisticaX(struct Pokemon *equipo,int x);
int peorPokemonEnLaEstadisticaX(struct Pokemon *equipo,int x);
#endif /* FUNCIONES_HPP */

