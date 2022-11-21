#include "funciones.hpp"

void llenarStructPersonajes(struct Personaje *personajes, int &cantPersonajes) {
    ifstream archHarry("HarryPotterPhilosopherStone.csv");
    if (not archHarry.is_open()) {
        cout << "Error al abir el archivo" << endl;
        exit(1);
    }
    char buffer[50];
    int posicion;
    while (true) {
        if (archHarry.eof()) break;
        archHarry.getline(buffer, 50, ',');
       // cout<<buffer;
        posicion = buscarPesonaje(personajes, buffer, cantPersonajes);
        if (posicion == -1) {
            insertarPersonaje(archHarry, personajes, buffer, cantPersonajes);
            cantPersonajes++;
        } else {
            actualizarPersonaje(archHarry, personajes, posicion);
        }
    }

}

void actualizarPersonaje(ifstream &archHarry, struct Personaje *personajes, int posicion) {
    archHarry.ignore(3000, '\n');
    archHarry>>ws;

}

void insertarPersonaje(ifstream &archHarry, struct Personaje *personajes, char *buffer, int &cantPersonajes) {
    personajes[cantPersonajes].nombre = asignarMenoria(buffer);
    char buffer2[500];
    int numPelicula;
    archHarry.getline(buffer2,500,',');
    archHarry>>numPelicula;
    archHarry.get();
    archHarry>>ws;
    
}

int buscarPesonaje(struct Personaje *personajes, char *buffer, int &cantPersonajes) {
    for (int i = 0; i < cantPersonajes; i++) {
        if ((strcmp(personajes[i].nombre, buffer) == 0)) {
            return i;
        }
    }
    return -1;
}

void escribirLinea(ofstream &arch, int cant, char c) {
    for (int i = 0; i < cant; i++)
        arch.put(c);
    arch << endl;
}

char *asignarMenoria(const char *buffer) {
    char *str;
    str = new char[strlen(buffer) + 1];
    strcpy(str, buffer);
    return str;
}