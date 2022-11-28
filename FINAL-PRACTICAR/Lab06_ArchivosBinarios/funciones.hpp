/* 
 * File:   funciones.hpp
 * Author: Vladymir Canchari 20195908
 *
 * Created on 21 de noviembre de 2022, 01:06 PM
 */

#ifndef FUNCIONES_HPP
#define FUNCIONES_HPP
#include "Medicinas.hpp"
#include "Pacientes.hpp"
#include <iomanip>
#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;
void crearPacientesBin(const char *nameArchBinP);
void verificarPacientesBin(const char *nameArchBinP);
void crearMedicinasBin(const char *nameArchBinM);
void verificarMedicinasBin(const char *nameArchBinM);
void completarInformacion(const char *nameArchBinP,const char *nameArchBinM);
int buscarPaciente(int dni,const char *nameArchBinP);
double buscarPrecio(int codMed, const char *nameArchBinM);
void ordenarPacientes(const char *nameArchBinP);
void escribirResumen(const char *nameArchBinP);
void escribirFecha(ofstream &archR,int fecha);
void escibirLinea(ofstream &arch,int cant,char c);
void actualizarPaciente(ifstream &archConsultas,struct Paciente &paciente,int fecha,char *buffer,const char *nameArchBinM);
//void verificarOpenArchivo(fstream &arch);
#endif /* FUNCIONES_HPP */

