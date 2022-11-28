#include <memory>

#include "funciones.hpp"

void llenarStructCursos(struct Curso *cursos, int &cant) {
    ifstream archCursos("Cursos.csv", ios::in);
    if (not archCursos.is_open()) {
        cout << "Error al abrir el archivo" << endl;
        exit(1);
    }
    char buffer[50];
    while (true) {
        if (archCursos.eof()) break;
        archCursos >> cursos[cant].codigo;
        archCursos.get();
        archCursos.getline(buffer, 50, ',');
        cursos[cant].nombreCrur = asignarMemoria(buffer);
        archCursos >> cursos[cant].numCred;
        archCursos.get();
        archCursos.getline(buffer, 50, '\n');
        cursos[cant].especialidad = asignarMemoria(buffer);
        archCursos>>ws;
        cant++;
    }
}

void llenarStructProfesores(struct Profesor *profesores, int &cant) {
    ifstream archProf("Profesores.csv", ios::in);
    if (not archProf.is_open()) {
        cout << "Error al abrir el archivo" << endl;
        exit(1);
    }
    char buffer[60], nombres[50], apellido1[30], apellido2[30], *nombreFormato;
    while (true) {
        if (archProf.eof()) break;
        archProf >> profesores[cant].codigo;
        archProf.get();
        archProf.getline(apellido1, 30, '/');
        archProf.getline(apellido2, 30, '/');
        archProf.getline(nombres, 30, ',');
        nombreFormato = cambiarFormatoNombe(nombres, apellido1, apellido2);
        profesores[cant].nombre = nombreFormato;
        archProf.getline(buffer, 60, ',');
        profesores[cant].categoria = asignarMemoria(buffer);
        archProf.getline(buffer, 60, '\n');
        profesores[cant].dedicacion = asignarMemoria(buffer);
        archProf>>ws;
        profesores[cant].cursos = new struct Curso[10];
        cant++;
    }

}

void completarStructProfesres(struct Curso *cursos, struct Profesor *profesores, int cantCursos, int cantProf) {
    ifstream archSesiones("Sesiones.csv", ios::in);
    if (not archSesiones.is_open()) {
        cout << "Error al abrir el archivo" << endl;
        exit(1);
    }
    int codCur, horario, numAlu, codProf;
    int posocionProf, posicionCurso;
    while (true) {
        if (archSesiones.eof()) break;
        almacenarDatosDeSecion(archSesiones, codCur, horario, numAlu, codProf);
        posocionProf = buscarProfesor(profesores, codProf, cantProf);
        posicionCurso = buscarCurso(cursos, codCur, cantCursos);
        actualisarProfesor(profesores, cursos, posocionProf, posicionCurso, codCur, horario, numAlu, archSesiones);

    }


}

void actualisarProfesor(struct Profesor *profesores, struct Curso *cursos, int posocionProf, int posicionCurso, int codCur, int horario, int numAlu, ifstream &archSesiones) {
    char buffer[50];
    char aula[5], fin;
    int horaI, horaF;
    profesores[posocionProf].cursos[profesores[posocionProf].numCur] = cursos[posicionCurso];
    profesores[posocionProf].cursos[profesores[posocionProf].numCur].horario = horario;
    profesores[posocionProf].cursos[profesores[posocionProf].numCur].numMatriculados = numAlu;
    profesores[posocionProf].cursos[profesores[posocionProf].numCur].sesiones = new struct Sesion[5];
    while (true) {
        archSesiones.getline(buffer, 50, ',');
        profesores[posocionProf].cursos[profesores[posocionProf].numCur].sesiones[ profesores[posocionProf].cursos[profesores[posocionProf].numCur].numSesions].dia = asignarMemoria(buffer);
        archSesiones >> profesores[posocionProf].cursos[profesores[posocionProf].numCur].sesiones[ profesores[posocionProf].cursos[profesores[posocionProf].numCur].numSesions].horaI;
        archSesiones.get();
        archSesiones >> profesores[posocionProf].cursos[profesores[posocionProf].numCur].sesiones[ profesores[posocionProf].cursos[profesores[posocionProf].numCur].numSesions].horaF;
        archSesiones.get();
        archSesiones.get(aula, 5);
        fin = archSesiones.get();
        profesores[posocionProf].cursos[profesores[posocionProf].numCur].sesiones[ profesores[posocionProf].cursos[profesores[posocionProf].numCur].numSesions].Aula = asignarMemoria(aula);
        profesores[posocionProf].cursos[profesores[posocionProf].numCur].numSesions++;
        if (fin == '\n') {
            archSesiones>>ws;
            break;
        }


    }
    profesores[posocionProf].numCur++;
}

int buscarProfesor(struct Profesor *profesores, int codProf, int cantProf) {
    for (int i = 0; i < cantProf; i++) {
        if (profesores[i].codigo == codProf)
            return i;
    }
    return -1;
}

int buscarCurso(struct Curso *cursos, int codCur, int cantCursos) {
    for (int i = 0; i < cantCursos; i++) {
        if (cursos[i].codigo == codCur)
            return i;
    }
    return -1;
}

void almacenarDatosDeSecion(ifstream &archSesiones, int &codCur, int &horario, int &numAlu, int &codProf) {
    archSesiones>>codCur;
    archSesiones.get();
    archSesiones>>horario;
    archSesiones.get();
    archSesiones>>numAlu;
    archSesiones.get();
    archSesiones>>codProf;
    archSesiones.get();
}

char * cambiarFormatoNombe(char *nombres, char *apellido1, char *apellido2) {
    char *nombreF;
    nombreF = new char[strlen(apellido1) + strlen(apellido2) + strlen(nombres) + 3];
    for (int i = 0; i < strlen(nombres); i++) {
        if (nombres[i] == '-')
            nombres[i] = ' ';
    }
    strcpy(nombreF, nombres);
    strcat(nombreF, " ");
    strcat(nombreF, apellido1);
    strcat(nombreF, " ");
    strcat(nombreF, apellido2);
    return nombreF;
}

char *asignarMemoria(char *buffer) {
    char *str;
    str = new char[strlen(buffer) + 1];
    strcpy(str, buffer);
    return str;
}

void escribirReporte(struct Curso *cursos, struct Profesor *profesores, int cantCursos, int cantProf) {
    ofstream archR("Reporte.txt", ios::out);
    if (not archR.is_open()) {
        cout << "Error al abrir el archivo" << endl;
        exit(1);
    }
    archR << setw(60) << "CARGA HORARIA DE PROFESORES " << endl;
    escribirLinea(archR, 120, '=');
    for (int i = 0; i < cantProf; i++) {
        archR << "Codigo: " << profesores[i].codigo << setw(3) << " " << "Nombre: " << profesores[i].nombre << setw(50 - strlen(profesores[i].nombre)) << "Categoria: " << profesores[i].categoria << setw(25 - strlen(profesores[i].categoria)) << "Dedicacion" << setw(3) << " " << profesores[i].dedicacion << endl;
        archR << "Horarios asignados: " << endl;
        for (int j = 0; j < profesores[i].numCur; j++) {
            archR << "N°. Curso" << setw(47) << "Codigo" << setw(15) << "Especialidad" << setw(15) << "Horario" << setw(15) << "Matriculados" << endl;
            archR << setw(3) << j + 1 << ')' << setw(2) << " " << profesores[i].cursos[j].nombreCrur << setw(50 - strlen(profesores[i].cursos[j].nombreCrur)) << profesores[i].cursos[j].codigo << setw(3) << " " << profesores[i].cursos[j].especialidad << setw(22 - strlen(profesores[i].cursos[j].especialidad)) << " " << profesores[i].cursos[j].horario << setw(12) << profesores[i].cursos[j].numMatriculados << endl;
            archR << setw(6) << "" << "Sesiones" << setw(13) << "Hora" << setw(12) << "Aula" << endl;
            for (int k = 0; k < profesores[i].cursos[j].numSesions; k++) {
                archR << setw(6) << "" << k + 1 << ") " << profesores[i].cursos[j].sesiones[k].dia << setw(15 - strlen(profesores[i].cursos[j].sesiones[k].dia)) << profesores[i].cursos[j].sesiones[k].horaI << "-" << profesores[i].cursos[j].sesiones[k].horaF << setw(10) << profesores[i].cursos[j].sesiones[k].Aula << endl;
            }
        }
        escribirLinea(archR, 120, '-');
        archR << "Total de horas asignadas por semana:" << endl;
        escribirLinea(archR, 120, '=');
    }


}

void escribirLinea(ofstream &archR, int cant, char c) {
    for (int i = 0; i < cant; i++)
        archR.put(c);
    archR << endl;
}