/* 
 * File:   Pokemon.hpp
 * Author: VLADYMIR
 *
 * Created on 11 de noviembre de 2022, 22:17
 */

#ifndef POKEMON_HPP
#define POKEMON_HPP

struct Pokemon {
    int ID;
    char *nombre;
    char *tipos[2];
    int totalStats;
    int HP;
    int attack;
    int defense;
    int specialAttack;
    int specialDefense;
    int speed;
    int generation;
    bool isLegendary;
};


#endif /* POKEMON_HPP */

