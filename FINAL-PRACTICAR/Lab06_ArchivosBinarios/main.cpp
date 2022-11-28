/* 
 * File:   main.cpp
 * Author: Vladymir Canchari 20195908
 *
 * Created on 21 de noviembre de 2022, 01:06 PM
 */

#include "funciones.hpp"



int main(int argc, char** argv) {
    crearPacientesBin("Pacientes.bin");
    verificarPacientesBin("Pacientes.bin");
    crearMedicinasBin("Medicinas.bin");
    verificarMedicinasBin("Medicinas.bin");
    completarInformacion("Pacientes.bin","Medicinas.bin");
    ordenarPacientes("Pacientes.bin");
    escribirResumen("Pacientes.bin");
    
    
    return 0;
}

