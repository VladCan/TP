
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
        archMoves >> movimientos[cantMoves].poder;
        if (archMoves.fail()) {
            archMoves.clear();
            movimientos[cantMoves].poder = -1;
        }
        archMoves.get();
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
    int idP;
    int idM;
    int level;
    while (true) {
        if (archPokemonMoves.eof()) break;
        archPokemonMoves>>idP;
        archPokemonMoves.get();
        archPokemonMoves>>idM;
        archPokemonMoves.get();
        archPokemonMoves>>level;
        archPokemonMoves>>ws;
        pokemons[idP - 1].PokemonMoves[pokemons[idP - 1].cantMoves] = movimientos[idM - 1];
        pokemons[idP - 1].cantMoves++;
    }

}

char *asignarMemoria(const char *buffer) {
    char *str;
    str = new char[strlen(buffer) + 1];
    strcpy(str, buffer);
    return str;

}

void escribirReportDePokemonMoves(struct Pokemon *pokemons, int cantPokemons, struct Moves *movimientos, int cantMoves) {
    ofstream archrReporte("ReporteDePokemosConSusMovimientos.txt", ios::out);
    if (not archrReporte.is_open()) {
        cout << "El archivo no se pudo abrir";
        exit(1);
    }

    for (int i = 0; i < cantPokemons; i++) {
        archrReporte << "ID:  " << pokemons[i].ID << endl;
        archrReporte << "Nombre Pokemon :  " << pokemons[i].nombre << endl;
        archrReporte << "Tipo 1 :  " << pokemons[i].tipos[0] << endl;
        archrReporte << "Tipo 2 :  " << pokemons[i].tipos[1] << endl;
        archrReporte << "TotalStats :  " << pokemons[i].stats[0] << endl;
        archrReporte << "HP :  " << pokemons[i].stats[1] << endl;
        archrReporte << "Attack :  " << pokemons[i].stats[2] << endl;
        archrReporte << "Defense :  " << pokemons[i].stats[3] << endl;
        archrReporte << "Special Attack  :  " << pokemons[i].stats[4] << endl;
        archrReporte << "Special Defense :  " << pokemons[i].stats[5] << endl;
        archrReporte << "Speed :  " << pokemons[i].stats[6] << endl;
        archrReporte << "Generation,:  " << pokemons[i].generation << endl;
        archrReporte << "IsLegendary?:  " << pokemons[i].isLegendary << endl;
        archrReporte << "Cantidad Movimientos :  " << pokemons[i].cantMoves << endl;
        escribirLinea(archrReporte,50,'-');
        for (int j = 0; j < pokemons[i].cantMoves; j++) {
            archrReporte << "ID Movimiento: " << pokemons[i].PokemonMoves[j].ID << endl;
            archrReporte << "Nombre Movimiento:  " << pokemons[i].PokemonMoves[j].nombre << endl;
            archrReporte << "Tipo Movimiento :  " << pokemons[i].PokemonMoves[j].poder << endl;
            archrReporte << "Poder del Movimiento :  " << pokemons[i].PokemonMoves[j].powerpoints << endl;
            archrReporte << "Powerpoints del Movimiento: " << pokemons[i].PokemonMoves[j].tipo << endl;
        }
        escribirLinea(archrReporte,50,'=');
    }
}
void escribirLinea(ofstream &arch,int cant,char c){
    for(int i=0;i<cant;i++)
        arch.put(c);
    arch<<endl;
}