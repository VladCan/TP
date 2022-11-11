/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "docentes.hpp"
#include "funciones.hpp"

void llenarAlumnos(ifstream &arch, char *&nombre, int &codigo, char *&distr, char *&espe, char *&facu, int &escal, double &valCred, double &creMatri) {
    char nombres[100];
    char apellido_pat[50];
    char apellido_mat[50];
    arch.getline(apellido_pat, 50, '/');
    arch.getline(apellido_mat, 50, '/');
    arch.getline(nombres, 100, ',');
    nombre = new char[strlen(nombres) + strlen(apellido_pat) + strlen(apellido_mat) + 3];
    strcpy(nombre, nombres);
    strcat(nombre, " ");
    strcat(nombre, apellido_pat);
    strcat(nombre, " ");
    strcat(nombre, apellido_mat);
    arch>>codigo;
    arch.get();
    char buffer[100];
    arch.getline(buffer, 100, ',');
    distr = new char[strlen(buffer) + 1];
    strcpy(distr, buffer);
    arch.getline(buffer, 100, ',');
    espe = new char[strlen(buffer) + 1];
    strcpy(espe, buffer);
    arch.getline(buffer, 100, ',');
    facu = new char[strlen(buffer) + 1];
    strcpy(facu, buffer);
    arch>>escal;
    arch.get();
    arch>>valCred;
    arch.get();
    arch>>creMatri;
    arch>>ws;
}

void llenarDocentes(ifstream &arch, struct Docente &doc) {
    char nombres[100];
    char apellido_pat[50];
    char apellido_mat[50];
    arch.getline(apellido_pat, 50, '/');
    arch.getline(apellido_mat, 50, '/');
    arch.getline(nombres, 100, ',');
    doc.nombre = new char[strlen(nombres) + strlen(apellido_pat) + strlen(apellido_mat) + 3];
    strcpy(doc.nombre, nombres);
    strcat(doc.nombre, " ");
    strcat(doc.nombre, apellido_pat);
    strcat(doc.nombre, " ");
    strcat(doc.nombre, apellido_mat);
    arch >> doc.codigo;
    arch.get();
    char buffer[100];
    arch.getline(buffer, 100, ',');
    doc.distrito = new char[strlen(buffer) + 1];
    strcpy(doc.distrito, buffer);
    arch.getline(buffer, 100, ',');
    doc.categoria = new char[strlen(buffer) + 1];
    strcpy(doc.categoria, buffer);
    arch.getline(buffer, 100, ',');
    doc.dedicacion = new char[strlen(buffer) + 1];
    strcpy(doc.dedicacion, buffer);
    arch.getline(buffer, 100, ',');
    doc.seccion = new char[strlen(buffer) + 1];
    strcpy(doc.seccion, buffer);
    arch.getline(buffer, 100, ',');
    doc.grado = new char[strlen(buffer) + 1];
    strcpy(doc.grado, buffer);
    arch >> doc.sueldo>>ws;
}

void llenarArreglosyEstructuras(char **nombre_al, int *codAlum, char **distrito,
        char **especialidad, char **facultad, int *escala, double *valorCred,
        double *credMatri, int &cant_Alum, int &cant_Docentes, struct Docente *docentes) {
    ifstream archMatr("MiembrosDeTP.csv", ios::in);
    if (not archMatr.is_open()) {
        cout << "gg" << endl;
        exit(1);
    }
    char dato;
    char *nombre;
    int codigo;
    char *distr;
    char *espe;
    char *facu;
    int escal;
    double valCred;
    double creMatri;
    struct Docente docente;
    while (true) {
        if (archMatr.eof()) break;
        archMatr>>dato;
        archMatr.get();
        if (dato == 'A') {
            llenarAlumnos(archMatr, nombre, codigo, distr, espe, facu, escal, valCred, creMatri);
            nombre_al[cant_Alum] = nombre;
            codAlum[cant_Alum] = codigo;
            distrito[cant_Alum] = distr;
            especialidad[cant_Alum] = espe;
            facultad[cant_Alum] = facu;
            escala[cant_Alum] = escal;
            valorCred[cant_Alum] = valCred;
            credMatri[cant_Alum] = creMatri;
            cant_Alum++;
        } else if (dato == 'D') {
            llenarDocentes(archMatr, docente);
            docentes[cant_Docentes] = docente;
            //            cout << docentes[cant_Docentes].codigo << endl;
            //            cout << docentes[cant_Docentes].nombre << endl;
            //            cout << docentes[cant_Docentes].distrito << endl;
            //            cout << docentes[cant_Docentes].categoria << endl;
            //            cout << docentes[cant_Docentes].dedicacion << endl;
            //            cout << docentes[cant_Docentes].seccion << endl;
            //            cout << docentes[cant_Docentes].grado << endl;
            //            cout << docentes[cant_Docentes].sueldo << endl;
            cant_Docentes++;
        }
    }
}

void escribirReporte(char **nombre_al, int *codAlum, char **distrito, char **especialidad, char **facultad, int *escala, double *valorCred,
        double *credMatri, int cant_Alum, int cant_Docentes, struct Docente * docentes) {
    ofstream archReporte("Reporte.txt", ios::out);
    if (not archReporte.is_open()) {
        cout << "Error al abrir el archivo";
        exit(1);
    }
    
    archReporte << setw(50) << "Repoerte de Miembros" << endl;
    escribirLinea(archReporte, 200, '=');
    escribirReporteAlumnos(archReporte, nombre_al,codAlum,distrito,especialidad,facultad, escala,valorCred,credMatri,cant_Alum);
    escribirReporteDocente(archReporte,cant_Docentes,docentes);
    
}

void escribirReporteAlumnos(ofstream &archReporte, char **nombre_al, int *codAlum, char **distrito, char **especialidad, char **facultad, int *escala, double *valorCred,
        double *credMatri, int cant_Alum) {
    archReporte << "Reporte por Alumnos" << endl;
    escribirLinea(archReporte, 200, '-');
    archReporte << "CODIGO" << setw(20) << " " << "NOMBRE" << setw(30) << " " << "DISTRITO" << setw(35) << "ESPECIALIDAD" << setw(21) << "FACULTAD";
    archReporte << setw(11) << "ESCALA" << setw(10) << "ValorCred" << setw(12) << "CredMatri" << setw(12) << "PAGO" << endl;
    escribirLinea(archReporte, 200, '=');

    for (int i = 0; i < cant_Alum; i++) {
        archReporte << codAlum[i] << setw(5) << " " << nombre_al[i] << setw(45 - strlen(nombre_al[i])) << " " << distrito[i] << setw(35 - strlen(distrito[i])) << " ";
        archReporte << especialidad[i] << setw(25 - strlen(especialidad[i])) << " " << facultad[i] << setw(15 - strlen(facultad[i])) << " " << escala[i] << setw(5) << " ";
        archReporte << fixed << setprecision(2) << valorCred[i] << setw(6) << " ";

        archReporte << fixed << setw(5) << credMatri[i] << setw(10 - (credMatri[i] / 100)) << " ";

        archReporte << setprecision(3) << credMatri[i] * valorCred[i] << endl;
    }
    escribirLinea(archReporte, 200, '=');

}
void escribirReporteDocente(ofstream &archReporte, int cant_Docentes, struct Docente * docentes){
    archReporte << "Reporte por Profesores" << endl;
    escribirLinea(archReporte, 200, '-');
    archReporte << "CODIGO" << setw(20) << " " << "NOMBRE" << setw(30) << " " << "DISTRITO" << setw(35) << "CATEGORIA" << setw(21) << "DEDICACION";
    archReporte << setw(11) << "SECCION" << setw(10) << "GRADO" << setw(12) << "SUELDO" << endl;
    escribirLinea(archReporte, 200, '=');
    for (int i = 0; i < cant_Docentes; i++) {
        archReporte << docentes[cant_Docentes].codigo << endl;
//                setw(5) << " " << docentes[cant_Docentes].nombre  << setw(45 - strlen(docentes[cant_Docentes].nombre)) << " " << docentes[cant_Docentes].distrito << setw(10) << " ";
//        archReporte << docentes[cant_Docentes].categoria << setw(25) << " " << docentes[cant_Docentes].dedicacion << setw(15) << " " << docentes[cant_Docentes].seccion << setw(5) << " ";
//        archReporte << fixed << setprecision(2) << docentes[cant_Docentes].sueldo << endl;
    }


}

void escribirLinea(ofstream &arch, int cant, char c) {
    for (int i = 0; i < cant; i++)
        arch.put(c);
    arch << endl;
}