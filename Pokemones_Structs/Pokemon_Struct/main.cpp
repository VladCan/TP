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
    //    for(int i=0;i<cantMoves;i++){
    //        cout<<movimientos[i].ID<<endl;
    //        cout<<movimientos[i].nombre<<endl;
    //        cout<<movimientos[i].poder<<endl;
    //        cout<<movimientos[i].powerpoints<<endl;
    //        cout<<movimientos[i].tipo<<endl;
    //        cout<<"============================================"<<endl;
    //    }

//    for (int i = 0; i < cantPokemons; i++) {
//        cout << "ID:  " << pokemons[i].ID << endl;
//        cout << "Nombre Pokemon :  " << pokemons[i].nombre << endl;
//        cout << "Tipo 1 :  " << pokemons[i].tipos[0] << endl;
//        cout << "Tipo 2 :  " << pokemons[i].tipos[1] << endl;
//        cout << "TotalStats :  " << pokemons[i].stats[0] << endl;
//        cout << "HP :  " << pokemons[i].stats[1] << endl;
//        cout << "Attack :  " << pokemons[i].stats[2] << endl;
//        cout << "Defense :  " << pokemons[i].stats[3] << endl;
//        cout << "Special Attack  :  " << pokemons[i].stats[4] << endl;
//        cout << "Special Defense :  " << pokemons[i].stats[5] << endl;
//        cout << "Speed :  " << pokemons[i].stats[6] << endl;
//        cout << "Generation,:  " << pokemons[i].generation << endl;
//        cout << "IsLegendary?:  " << pokemons[i].isLegendary << endl;
//        cout << "Cantidad Movimientos :  " << pokemons[i].cantMoves << endl;
//        cout << "-----------------------" << endl;
//        for (int j = 0; j < pokemons[i].cantMoves; j++) {
//            cout<<"ID Movimiento: "<<pokemons[i].PokemonMoves[j].ID << endl;
//            cout << "Nombre Movimiento:  " << pokemons[i].PokemonMoves[j].nombre << endl;
//            cout << "Tipo Movimiento :  " << pokemons[i].PokemonMoves[j].poder << endl;
//            cout << "Poder del Movimiento :  " << pokemons[i].PokemonMoves[j].powerpoints << endl;
//            cout << "Powerpoints del Movimiento: " << pokemons[i].PokemonMoves[j].tipo << endl;
//        }
//        cout << "============================================" << endl;
//    }

    return 0;
}

