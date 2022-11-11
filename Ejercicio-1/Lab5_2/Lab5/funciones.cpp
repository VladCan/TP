#include "funciones.hpp"

void llenarArreglos(char **nombreAum, int *codAlum, char **distritoAlum, char **especialiadad, char **facultad, int *escala, double *valorCred, double *credMatri, int &cantAlum,
        struct Docente *docentes, int &cantDocent) {
    ifstream archMatri("MiembrosDeTP.csv", ios::in);
    if (not archMatri.is_open()) {
        cout << "Error archivo";
        exit(1);
    }
    char tipo;
    while (true) {
        if (archMatri.eof()) break;
        tipo = archMatri.get();
        archMatri.get();
        if (tipo == 'A') {
            llenarArrglos(archMatri, nombreAum, codAlum, distritoAlum, especialiadad, facultad, escala, valorCred, credMatri, cantAlum);
          //  cout << nombreAum[cantAlum - 1] << endl;
        } else if (tipo == 'D') {
            llenarStruct(archMatri, docentes, cantDocent);
        }
    }
      
    for(int i=0;i<cantDocent;i++){
        cout<<docentes[i].nombre<<endl;
        cout<<docentes[i].codigo<<endl;
        cout<<docentes[i].categoria<<endl;
        cout<<docentes[i].dedicacion<<endl;
        cout<<docentes[i].distrito<<endl;
        cout<<docentes[i].grado<<endl;
        cout<<docentes[i].seccion<<endl;
        cout<<docentes[i].sueldo<<endl;
        cout<<"====================================================="<<endl;
    }

}

void llenarArrglos(ifstream &archMatri, char **nombreAum, int *codAlum, char **distritoAlum, char **especialiadad, char **facultad, int *escala, double *valorCred, double *credMatri, int &cantAlum) {
    char buffer[200];
    char *nombre;
    quitarBarra(archMatri, nombre);
    nombreAum[cantAlum] = nombre;
    archMatri >> codAlum[cantAlum];
    archMatri.get();
    archMatri.getline(buffer, 200, ',');
    distritoAlum[cantAlum] = new char(strlen(buffer) + 1);
    strcpy(distritoAlum[cantAlum], buffer);
    archMatri.getline(buffer, 200, ',');
    especialiadad[cantAlum] = new char(strlen(buffer) + 1);
    strcpy(especialiadad[cantAlum], buffer);
    archMatri.getline(buffer, 200, ',');
    facultad[cantAlum] = new char(strlen(buffer) + 1);
    strcpy(facultad[cantAlum], buffer);
    archMatri >> escala[cantAlum];
    archMatri.get();
    archMatri >> valorCred[cantAlum];
    archMatri.get();
    archMatri >> credMatri[cantAlum];
    archMatri>>ws;
    cantAlum++;
}

void llenarStruct(ifstream &archMatri, struct Docente *docentes, int &cantDocent) {
    char buffer[200];
    char *nombre;
    quitarBarra(archMatri, nombre);
    docentes[cantDocent].nombre = nombre;
    archMatri >> docentes[cantDocent].codigo;
    archMatri.get();
    archMatri.getline(buffer, 200, ',');
    docentes[cantDocent].distrito = new char[strlen(buffer) + 1];
    strcpy(docentes[cantDocent].distrito, buffer);
    archMatri.getline(buffer, 200, ',');
    docentes[cantDocent].categoria = new char[strlen(buffer) + 1];
    strcpy(docentes[cantDocent].categoria, buffer);
    archMatri.getline(buffer, 200, ',');
    docentes[cantDocent].dedicacion = new char[strlen(buffer) + 1];
    strcpy(docentes[cantDocent].dedicacion, buffer);
    archMatri.getline(buffer, 200, ',');
    docentes[cantDocent].seccion = new char[strlen(buffer) + 1];
    strcpy(docentes[cantDocent].seccion, buffer);
    archMatri.getline(buffer, 200, ',');
    docentes[cantDocent].grado = new char[strlen(buffer) + 1];
    strcpy(docentes[cantDocent].grado, buffer);
    archMatri >> docentes[cantDocent].sueldo;
    archMatri>>ws;
    cantDocent++;
}

void quitarBarra(ifstream &archMatri, char *&nombre) {
    char apellido1[50];
    char apellido2[50];
    char nombres[100];
    archMatri.getline(apellido1, 50, '/');
    archMatri.getline(apellido2, 50, '/');
    archMatri.getline(nombres, 100, ',');
    nombre = new char[strlen(apellido1) + strlen(apellido2) + strlen(nombres) + 4];

    strcpy(nombre, nombres);
    strcat(nombre, " ");
    strcat(nombre, apellido1);
    strcat(nombre, " ");
    strcat(nombre, apellido2);
}