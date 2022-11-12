
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
        escribirLinea(archrReporte, 50, '-');
        for (int j = 0; j < pokemons[i].cantMoves; j++) {
            archrReporte << "ID Movimiento: " << pokemons[i].PokemonMoves[j].ID << endl;
            archrReporte << "Nombre Movimiento:  " << pokemons[i].PokemonMoves[j].nombre << endl;
            archrReporte << "Tipo Movimiento :  " << pokemons[i].PokemonMoves[j].poder << endl;
            archrReporte << "Poder del Movimiento :  " << pokemons[i].PokemonMoves[j].powerpoints << endl;
            archrReporte << "Powerpoints del Movimiento: " << pokemons[i].PokemonMoves[j].tipo << endl;
        }
        escribirLinea(archrReporte, 50, '=');
    }
}

void escribirLinea(ofstream &arch, int cant, char c) {
    for (int i = 0; i < cant; i++)
        arch.put(c);
    arch << endl;
}

void batallaPokemon(struct Pokemon *pokemons, int cantPokemons) {

    struct Pokemon equipoA[6];

    struct Pokemon equipoB[6];
    int E1_1, E1_2, E1_3, E1_4, E1_5, E1_6;
    int E2_1, E2_2, E2_3, E2_4, E2_5, E2_6;

    valoresAleatorios(E1_1, E1_2, E1_3, E1_4, E1_5, E1_6, E2_1, E2_2, E2_3, E2_4, E2_5, E2_6);

    llenarEquipo(equipoA, pokemons, E1_1, E1_2, E1_3, E1_4, E1_5, E1_6);
    llenarEquipo(equipoB, pokemons, E2_1, E2_2, E2_3, E2_4, E2_5, E2_6);

    int HP_Max_EquipoA = 0;
    for (int i = 0; i < 6; i++) {
        HP_Max_EquipoA += equipoA[i].stats[1];
    }

    int HP_Max_EquipoB = 0;
    for (int i = 0; i < 6; i++) {
        HP_Max_EquipoB += equipoB[i].stats[1];
    }
    escribirReporteBatalla(equipoA, equipoB, HP_Max_EquipoA, HP_Max_EquipoB);
}

void escribirReporteBatalla(struct Pokemon *equipoA, struct Pokemon *equipoB, int HP_Max_EquipoA, int HP_Max_EquipoB) {

    ofstream archBatalla("ResumenBatalla.txt", ios::out);
    if (not archBatalla.is_open()) {
        cout << "El archivo no se pudo abrir" << endl;
        exit(1);
    }
    archBatalla << setw(40) << "Resumen de Batalla Pokemon" << endl;
    escribirLinea(archBatalla, 60, '=');
    archBatalla << "Equipo A " << HP_Max_EquipoA << " HP" << setw(15) << " ";
    archBatalla << "Equipo B " << HP_Max_EquipoB << " HP" << endl;
    for (int i = 0; i < 6; i++) {
        archBatalla << equipoA[i].nombre << setw(30 - strlen(equipoA[i].nombre)) << " ";
        archBatalla << equipoB[i].nombre << endl;
    }
    escribirLinea(archBatalla, 60, '=');
    archBatalla << "Resumen de Estadisticas Pokemon" << endl;
    estadisticasEquipoA(archBatalla, equipoA);
    estadisticasEquipoB(archBatalla, equipoB);
    archBatalla << "Ganador" << endl;
    if (HP_Max_EquipoA < HP_Max_EquipoB)
        archBatalla << "Equipo B" << endl;
    else if (HP_Max_EquipoA > HP_Max_EquipoB)
        archBatalla << "Equipo A" << endl;
    else
        archBatalla << "Empate" << endl;
}

void estadisticasEquipoA(ofstream &archBatalla, struct Pokemon *equipoA) {
    int posicion;
    archBatalla << "Equipo A " << endl;
    archBatalla << "Pokemon mas rapido :";
    posicion = mejorPokemonEnLaEstadisticaX(equipoA, 6);
    archBatalla << equipoA[posicion].nombre << endl;
    archBatalla << "Pokemon mas defensivo: ";
    posicion = mejorPokemonEnLaEstadisticaX(equipoA, 3);
    archBatalla << equipoA[posicion].nombre << endl;
    archBatalla << "Pokemon mas ofensivo: ";
    posicion = mejorPokemonEnLaEstadisticaX(equipoA, 2);
    archBatalla << equipoA[posicion].nombre << endl;
    archBatalla << "Lista de ataques del pokemon mas lento: ";
    posicion = peorPokemonEnLaEstadisticaX(equipoA, 6);
    archBatalla << equipoA[posicion].nombre << endl;
    for (int i = 0; i < equipoA[posicion].cantMoves; i++) {
        archBatalla << equipoA[posicion].PokemonMoves[i].nombre << ",";
        if (i % 18 == 0)
            archBatalla << endl;
    }
    archBatalla << endl;
}

void estadisticasEquipoB(ofstream &archBatalla, struct Pokemon *equipoB) {
    int posicion;
    archBatalla << "Equipo B " << endl;
    archBatalla << "Pokemon mas rapido :";
    posicion = mejorPokemonEnLaEstadisticaX(equipoB, 6);
    archBatalla << equipoB[posicion].nombre << endl;
    archBatalla << "Pokemon mas especialmente defensivo :";
    posicion = mejorPokemonEnLaEstadisticaX(equipoB, 5);
    archBatalla << equipoB[posicion].nombre << endl;
    archBatalla << "Pokemon mas especialmente ofensivo :";
    posicion = mejorPokemonEnLaEstadisticaX(equipoB, 4);
    archBatalla << equipoB[posicion].nombre << endl;
    archBatalla << "Lista de ataques del pokemon mas lento: ";
    posicion = peorPokemonEnLaEstadisticaX(equipoB, 6);
    archBatalla << equipoB[posicion].nombre << endl;
    for (int i = 0; i < equipoB[posicion].cantMoves; i++) {
        archBatalla << equipoB[posicion].PokemonMoves[i].nombre << ",";
        if (i % 18 == 0)
            archBatalla << endl;
    }
    archBatalla << endl;
}

int mejorPokemonEnLaEstadisticaX(struct Pokemon *equipo, int x) {
    int mayor;
    int posision;
    for (int i = 0; i < 6; i++) {
        mayor = equipo[i].stats[x];
        for (int j = i; j < 6; j++) {
            if (equipo[j].stats[x] > mayor)
                posision = j;
        }
    }
    return posision;
}

int peorPokemonEnLaEstadisticaX(struct Pokemon *equipo, int x) {
    int menor;
    int posision;
    for (int i = 0; i < 6; i++) {
        menor = equipo[i].stats[x];
        for (int j = i; j < 6; j++) {
            if (equipo[j].stats[x] < menor)
                posision = j;
        }
    }
    return posision;
}

void valoresAleatorios(int &E1_1, int & E1_2, int & E1_3, int & E1_4, int & E1_5, int & E1_6, int &E2_1,
        int & E2_2, int & E2_3, int & E2_4, int & E2_5, int & E2_6) {
    srand(time(0));
    E1_1 = rand() % 150 + 1; // E1_1 in the range 1 to 150
    E1_2 = rand() % 150 + 1; // E1_2 in the range 1 to 150
    E1_3 = rand() % 150 + 1; // E1_3 in the range 1 to 150
    E1_4 = rand() % 150 + 1; // E1_4 in the range 1 to 150
    E1_5 = rand() % 150 + 1; // E1_5 in the range 1 to 150
    E1_6 = rand() % 150 + 1; // E1_6 in the range 1 to 150
    E2_1 = rand() % 150 + 1; // E2_1 in the range 1 to 150
    E2_2 = rand() % 150 + 1; // E2_2 in the range 1 to 150
    E2_3 = rand() % 150 + 1; // E2_3 in the range 1 to 150
    E2_4 = rand() % 150 + 1; // E2_4 in the range 1 to 150
    E2_5 = rand() % 150 + 1; // E2_5 in the range 1 to 150
    E2_6 = rand() % 150 + 1; // E2_6 in the range 1 to 150
}

void llenarEquipo(struct Pokemon *equipo, struct Pokemon *pokemons, int v1, int v2, int v3, int v4, int v5, int v6) {
    equipo[0] = pokemons[v1];
    equipo[1] = pokemons[v2];
    equipo[2] = pokemons[v3];
    equipo[3] = pokemons[v4];
    equipo[4] = pokemons[v5];
    equipo[5] = pokemons[v6];
}