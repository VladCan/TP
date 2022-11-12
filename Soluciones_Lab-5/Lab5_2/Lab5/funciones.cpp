#include "funciones.hpp"

void llenarDatos(char **nombreAlum, int *codAlum, char **distritoArr, char **especialiadadArr, char **facultadArr, int *escalaArr, double *valorCredArr, double *credMatriArr, int &cantAlum,
        struct Docente *docentes, int &cantDocent) {
    ifstream archMatri("MiembrosDeTP.csv", ios::in);
    if (not archMatri.is_open()) {
        cout << "Error archivo";
        exit(1);
    }

    char buffer[200];
    char tipo;
    char *nombre;
    int codigo;
    char *distrito;
    char *especialiadad;
    char *facultad;
    int escala;
    double valorCred;
    double credMatri;
    while (true) {
        if (archMatri.eof()) break;
        tipo = archMatri.get();
        archMatri.get();
        if (tipo == 'A') {
           // archMatri.getline(buffer,200,'\n');
         llenarArreglos(archMatri, nombre, codigo, distrito, especialiadad, facultad, escala, valorCred, credMatri);
            nombreAlum[cantAlum]=nombre;
            codAlum[cantAlum] = codigo;
            distritoArr[cantAlum] = distrito;
            especialiadadArr[cantAlum] = especialiadad;
            facultadArr[cantAlum] = facultad;
            escalaArr[cantAlum] = escala;
            valorCredArr[cantAlum] = valorCred;
            credMatriArr[cantAlum] = credMatri;
            cantAlum++;
            free(distrito);
        } else if (tipo == 'D') {
            archMatri.getline(buffer,200,'\n');
            //llenarStruct(archMatri, docentes, cantDocent);
        }
    }
}

void llenarArreglos(ifstream &archMatri, char *&nombre, int &codigo, char *&distrito, char *&especialiadad, char *&facultad, int &escala, double &valorCred, double &credMatri) {
    char buffer[200];
    quitarBarra(archMatri, nombre);
        cout<<nombre<<endl;
        
    archMatri >> codigo;
    cout<<codigo<<endl;
    
       
        
    archMatri.get();
    archMatri.getline(buffer, 200, ',');
    distrito = new char(strlen(buffer) + 1);
    strcpy(distrito, buffer);
    cout<<distrito<<endl;
    archMatri.getline(buffer,200,'\n');
     
          return;
    archMatri.getline(buffer, 200, ',');
    especialiadad = new char(strlen(buffer) + 1);
    strcpy(especialiadad, buffer);
    archMatri.getline(buffer, 200, ',');
    facultad = new char(strlen(buffer) + 1);
    strcpy(facultad, buffer);
    archMatri >> escala;
    archMatri.get();
    archMatri >> valorCred;
    archMatri.get();
    archMatri >> credMatri;
    archMatri>>ws;
    
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