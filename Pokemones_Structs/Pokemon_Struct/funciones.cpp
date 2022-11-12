
#include "funciones.hpp"

void llenarStructPokemns(struct Pokemon *pokemons, int &cantPokemons) {
    ifstream archPokemon("pokemon.csv", ios::in);
    if (not archPokemon.is_open()) {
        cout << "El archivo no se pudo abrir";
        exit(1);
    }
    char buffer[50];
    char coma;
    while (true) {
        if (archPokemon.eof()) break;
        archPokemon >> pokemons[cantPokemons].ID;
        archPokemon.get();
        archPokemon.getline(buffer, 50, ',');
        pokemons[cantPokemons].nombre = asignarMemoria(buffer);
        archPokemon.getline(buffer, 50, ',');
        pokemons[cantPokemons].tipos[0] = asignarMemoria(buffer);
        archPokemon.getline(buffer, 50, ',');
        pokemons[cantPokemons].tipos[1] = asignarMemoria(buffer);
        archPokemon >> pokemons[cantPokemons].stats[0] >> coma >> pokemons[cantPokemons].stats[1] >> coma >> pokemons[cantPokemons].stats[2] >> coma;
        archPokemon >> pokemons[cantPokemons].stats[3] >> coma >> pokemons[cantPokemons].stats[4] >> coma >> pokemons[cantPokemons].stats[5] >> coma;
        archPokemon >> pokemons[cantPokemons].stats[6] >> coma >> pokemons[cantPokemons].generation>>coma;
        archPokemon.getline(buffer, 50, '\n');
        if (strcmp(buffer, "False") == 0)
            pokemons[cantPokemons].isLegendary = 0;
        else if (strcmp(buffer, "True") == 0)
            pokemons[cantPokemons].isLegendary = 1;
        cantPokemons++;
        archPokemon>>ws;
    }
}

void llenarStructMoves(struct Moves *movimientos, int &cantMoves) {
    ifstream archMoves("moves.csv", ios::in);
    if (not archMoves.is_open()) {
        cout << "Error el abrir el achivo";
        exit(1);
    }
    char buffer[100];
    while (true) {
        if (archMoves.eof()) break;
        archMoves >> movimientos[cantMoves].ID;
        archMoves.get();
        archMoves.getline(buffer, 100, ',');
        movimientos[cantMoves].nombre = asignarMemoria(buffer);
        archMoves >> movimientos[cantMoves].tipo;
        archMoves.get();
        archMoves.getline(buffer, 100, ',');
        movimientos[cantMoves].poder = asignarMemoria(buffer);
        archMoves >> movimientos[cantMoves].powerpoints;
        archMoves>>ws;
        cantMoves++;
    }

}

void llenarPokemonMoves(struct Pokemon *pokemons, int cantPokemons, struct Moves *movimientos, int cantMoves) {
    ifstream archPokemonMoves("pokemon_moves.csv", ios::in);
    if (not archPokemonMoves.is_open()) {
        cout << "Error al abrir el archivo";
        exit(1);
    }
   // int i=0;
    int idP;
    int idM;
    int level;
    while (true) {
        if (archPokemonMoves.eof()) break;
        //cout<<i<<endl;
        archPokemonMoves>>idP;
        archPokemonMoves.get();
        archPokemonMoves>>idM;
        archPokemonMoves.get();
        archPokemonMoves>>level;
        archPokemonMoves>>ws;
        pokemons[idP-1].PokemonMoves = new struct Moves[10];
        pokemons[idP-1].PokemonMoves[pokemons[idP].cantMoves] = movimientos[idM-1];
         cout<<pokemons[0].PokemonMoves[0].ID<<" / ";
        pokemons[idP-1].cantMoves++;
      //  i++;
    }
    cout<<pokemons[0].PokemonMoves[0].ID;

}

char *asignarMemoria(const char *buffer) {
    char *str;
    str = new char[strlen(buffer) + 1];
    strcpy(str, buffer);
    return str;

}
