/* 
 * File:   main.cpp
 * Author: VLADYMIR
 *
 * Created on 19 de noviembre de 2022, 11:16
 */
#include "funciones.hpp"

int main(int argc, char** argv) {
    
    struct Personaje personajes[100];
    int cantPersonajes=0;
    
    llenarStructPersonajes(personajes,cantPersonajes);
    
    for(int i=0;i<cantPersonajes;i++){
        cout<<i<<"/"<<personajes[i].nombre<<endl;
    }
    
    return 0;
}

