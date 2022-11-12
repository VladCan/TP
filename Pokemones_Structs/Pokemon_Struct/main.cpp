/* 
 * File:   main.cpp
 * Author: VLADYMIR
 *
 * Created on 11 de noviembre de 2022, 20:59
 */

#include "funciones.hpp"

int main(int argc, char** argv) {

    struct Pokemon pokemons[200];
    int cantPokemons = 0;
    llenarStructPokemns(pokemons,cantPokemons);
   
    for(int i=0;i<cantPokemons;i++){
        cout<<pokemons[i].ID<<endl;
        cout<<pokemons[i].nombre<<endl;
        cout<<pokemons[i].tipos[0]<<endl;
        cout<<pokemons[i].tipos[1]<<endl;
        cout<<pokemons[i].totalStats<<endl;
        cout<<pokemons[i].HP<<endl;
        cout<<"============================================"<<endl;
    }

    return 0;
}

