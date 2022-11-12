/* 
 * File:   Pokemon.hpp
 * Author: VLADYMIR
 *
 * Created on 11 de noviembre de 2022, 22:17
 */

#ifndef POKEMON_HPP
#define POKEMON_HPP
//#include "Moves.hpp";
struct Pokemon {
    int ID;
    char *nombre;
    char *tipos[2];
    int stats[7];
    int generation;
    bool isLegendary;
    struct Moves *PokemonMoves;
    int cantMoves = 0;
};


#endif /* POKEMON_HPP */

