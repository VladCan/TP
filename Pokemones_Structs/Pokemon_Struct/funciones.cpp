
#include "funciones.hpp"

void llenarStructPokemns(struct Pokemon *pokemons,int &cantPokemons){
 ifstream archPokemon("pokemon.csv", ios::in);
    if (not archPokemon.is_open()) {
        cout << "El archivo no se pudo abrir";
        exit(1);
    }    
    char buffer[50];
    while (true) {
        if(archPokemon.eof()) break;
        archPokemon >> pokemons[cantPokemons].ID;
        archPokemon.get();
        archPokemon.getline(buffer, 50, ',');
        pokemons[cantPokemons].nombre = asignarMemoria(buffer);
        archPokemon.getline(buffer, 50, ',');
        pokemons[cantPokemons].tipos[0] = asignarMemoria(buffer);
        archPokemon.getline(buffer, 50, ',');
        pokemons[cantPokemons].tipos[1] = asignarMemoria(buffer);
        archPokemon >> pokemons[cantPokemons].totalStats;
        archPokemon.get();
        archPokemon >> pokemons[cantPokemons].HP;
        archPokemon.get();
        archPokemon >> pokemons[cantPokemons].attack;
        archPokemon.get();
        archPokemon >> pokemons[cantPokemons].defense;
        archPokemon.get();
        archPokemon >> pokemons[cantPokemons].specialAttack;
        archPokemon.get();
        archPokemon >> pokemons[cantPokemons].specialDefense;
        archPokemon.get();
        archPokemon >> pokemons[cantPokemons].speed;
        archPokemon.get();
        archPokemon >> pokemons[cantPokemons].generation;
        archPokemon.get();
        archPokemon.getline(buffer, 50, '\n');
        if (strcmp(buffer, "False") == 0)
            pokemons[cantPokemons].isLegendary = 0;
        else if (strcmp(buffer, "True") == 0)
            pokemons[cantPokemons].isLegendary = 1;
        cantPokemons++;
        archPokemon>>ws;
    }
}
char *asignarMemoria(const char *buffer){
    char *str;
    str = new char[strlen(buffer)+1];
    strcpy(str,buffer);
    return str;

}
