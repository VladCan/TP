/* 
 * File:   main.cpp
 * Author: VLADYMIR
 *
 * Created on 11 de noviembre de 2022, 20:59
 */

#include "funciones.hpp"

int main(int argc, char** argv) {

    struct Pokemon pokemons[200];
    struct Moves movimientos[900];
    int cantPokemons = 0;
    int cantMoves = 0;

    llenarStructPokemns(pokemons, cantPokemons);
    llenarStructMoves(movimientos, cantMoves);
    llenarPokemonMoves(pokemons, cantPokemons, movimientos, cantMoves);
    escribirReportDePokemonMoves(pokemons, cantPokemons, movimientos, cantMoves);   
    batallaPokemon(pokemons,cantPokemons);
    return 0;
}

