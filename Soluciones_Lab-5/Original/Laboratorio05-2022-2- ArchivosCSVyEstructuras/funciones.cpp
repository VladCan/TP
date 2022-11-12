/*
 * Nombre : Vladymir Canchari
 * Codigo : 20195808
 */
#include "funciones.hpp"

void llenarDatos(char **nombreAlum, int *codAlum, char **distritoAlum, char **especialidad, char **facultad, int *escala, double *valorCred, double *credMatri, int &cantAlum,
        struct Docente *docentes, int &cantDoncent) {
    ifstream achrMiembro("MiembrosDeTP.csv", ios::in);
    if (not achrMiembro.is_open()) {
        cout << "Error al abrir el archivo";
        exit(1);
    }
    char tipo;
    while (true) {
        if (achrMiembro.eof()) break;
        tipo = achrMiembro.get();
        achrMiembro.get();
        if (tipo == 'A')
            llenarArregloAlum(achrMiembro, nombreAlum, codAlum, distritoAlum, especialidad, facultad, escala, valorCred, credMatri, cantAlum);
        else if (tipo == 'D')
            llenarArrStructDocent(achrMiembro, docentes, cantDoncent);

    }


}

void llenarArregloAlum(ifstream &achrMiembro, char **nombreAlum, int *codAlum, char **distritoAlum, char **especialidad, char **facultad, int *escala, double *valorCred, double *credMatri, int &cantAlum) {
    char buffer[200];
    char *nombre;
    char *distrito;
    quitarBarra(nombre, achrMiembro);
    nombreAlum[cantAlum] = nombre;
    achrMiembro >> codAlum[cantAlum];
    achrMiembro.get();
    achrMiembro.getline(buffer, 200, ',');
    distritoAlum[cantAlum] = new char[strlen(buffer) + 1];
    strcpy(distritoAlum[cantAlum], buffer);
    achrMiembro.getline(buffer, 200, ',');
    especialidad[cantAlum] = new char[strlen(buffer) + 1];
    strcpy(especialidad[cantAlum], buffer);
    achrMiembro.getline(buffer, 200, ',');
    facultad[cantAlum] = new char[strlen(buffer) + 1];
    strcpy(facultad[cantAlum], buffer);
    achrMiembro >> escala[cantAlum];
    achrMiembro.get();
    achrMiembro >> valorCred[cantAlum];
    achrMiembro.get();
    achrMiembro >> credMatri[cantAlum];
    achrMiembro>>ws;
    cantAlum++;
}

void llenarArrStructDocent(ifstream &achrMiembro, struct Docente *docentes, int &cantDoncent) {
    char buffer[200];
    char *nombre;
    quitarBarra(nombre, achrMiembro);
    docentes[cantDoncent].nombre = nombre;
    achrMiembro >> docentes[cantDoncent].codigo;
    achrMiembro.get();
    achrMiembro.getline(buffer, 200, ',');
    docentes[cantDoncent].distrito = new char[strlen(buffer) + 1];
    strcpy(docentes[cantDoncent].distrito, buffer);
    achrMiembro.getline(buffer, 200, ',');
    docentes[cantDoncent].categoria = new char[strlen(buffer) + 1];
    strcpy(docentes[cantDoncent].categoria, buffer);
    achrMiembro.getline(buffer, 200, ',');
    docentes[cantDoncent].dedicacion = new char[strlen(buffer) + 1];
    strcpy(docentes[cantDoncent].dedicacion, buffer);
    achrMiembro.getline(buffer, 200, ',');
    docentes[cantDoncent].seccion = new char[strlen(buffer) + 1];
    strcpy(docentes[cantDoncent].seccion, buffer);
    achrMiembro.getline(buffer, 200, ',');
    docentes[cantDoncent].grado = new char[strlen(buffer) + 1];
    strcpy(docentes[cantDoncent].grado, buffer);
    achrMiembro >> docentes[cantDoncent].sueldo;
    achrMiembro>>ws;
    cantDoncent++;
}

void quitarBarra(char *&nombre, ifstream &achrMiembro) {
    char apellido1[50];
    char apellido2[50];
    char nombres[100];
    achrMiembro.getline(apellido1, 50, '/');
    achrMiembro.getline(apellido2, 50, '/');
    achrMiembro.getline(nombres, 50, ',');
    nombre = new char[strlen(apellido1) + strlen(apellido2) + strlen(nombres) + 4];
    strcpy(nombre, nombres);
    strcat(nombre, " ");
    strcat(nombre, apellido1);
    strcat(nombre, " ");
    strcat(nombre, apellido2);
}

//void ordenarArreglosAlum(char **nombreAlum, int *codAlum, char **distritoAlum, char **especialidad, char **facultad, int *escala, double *valorCred, double *credMatri, int cantAlum) {
//    for (int i = 0; i < cantAlum; i++)
//        for (int j = i + 1; j < cantAlum; j++) {
//
//            if ((strcmp(distritoAlum[i], distritoAlum[j]) > 0) or (strcmp(distritoAlum[i], distritoAlum[j]) == 0 and escala[i] < escala[j]){
//
//                }
//            }
//
//
//}
void escribirReporte(char **nombreAlum, int *codAlum, char **distritoAlum, char **especialidad, char **facultad, int *escala, double *valorCred, double *credMatri, int cantAlum,
        struct Docente *docentes, int cantDoncent) {
    ofstream archReporte("Balance_de_Ingresos.txt", ios::out);
    if (not archReporte.is_open()) {
        cout << "Error al abrir el archivo";
                exit(1);
    }
    double totalMatri = 0;
            double egresosTotal = 0;
            archReporte << setw(50) << "Universidad TP" << endl;
            escribirLinea(archReporte, 100, '=');
            escribirReporteAlumnos(archReporte, nombreAlum, codAlum, distritoAlum, especialidad, facultad, escala, valorCred, credMatri, cantAlum,totalMatri);
            
            archReporte << "PAGO A LOS DOCENTES:" << endl;
            archReporte << "CODIGO" << setw(20) << "NOMBRE" << setw(30) << "DISTRITO" << setw(20) << "CATEGORIA" << setw(20) << "DEDICACION" << setw(20) << "SECCION" << setw(20) << "GRADO" << setw(20) << "PAGOS" << endl;
    for (int i = 0; i < cantDoncent; i++) {
        archReporte << docentes[i].codigo << setw(5) << " " << docentes[i].nombre << setw(5) << " " << docentes[i].distrito << setw(5) << " " << docentes[i].categoria << setw(5) << " ";
                archReporte << docentes[i].dedicacion << setw(5) << " " << docentes[i].seccion << setw(5) << " " << docentes[i].grado << setw(5) << " " << docentes[i].sueldo * 8 << endl;
                egresosTotal += docentes[i].sueldo * 8;
    }
    escribirLinea(archReporte, 100, '-');
            archReporte << "Total de Egresos por Sueldos:" << setprecision(8) << egresosTotal << endl;
            escribirLinea(archReporte, 100, '=');
            archReporte << "Estado de las ganancias o perdidas: " << totalMatri - egresosTotal << endl;
            archReporte << "Recomndoacion: ";
    if (totalMatri - egresosTotal > 0)
            archReporte << "DEBE INVERTIR SUS GANANCIAS" << endl;

    else
        archReporte << "DEBE CERRAR LA INSTITUCION: " << endl;
    }
void escribirReporteAlumnos(ofstream &archReporte, char **nombreAlum, int *codAlum, char **distritoAlum, char **especialidad, char **facultad, int *escala, double *valorCred, double *credMatri, int cantAlum,double &totalMatri) {
    archReporte << "RECAUDACION POR MATRICULAS" << endl;
    escribirLinea(archReporte, 100, '-');
   
      archReporte << "CODIGO" << setw(20) << " " << "NOMBRE" << setw(30) << " " << "DISTRITO" << setw(35) << "ESPECIALIDAD" << setw(21) << "FACULTAD";
    archReporte << setw(11) << "ESCALA" << setw(10) << "VCRED" << setw(12) << "CREDMAT" << setw(12) << "PAGO" << endl;
    escribirLinea(archReporte, 200, '=');
    
      for (int i = 0; i < cantAlum; i++) {
        archReporte << codAlum[i] << setw(5) << " " << nombreAlum[i] << setw(45 - strlen(nombreAlum[i])) << " " << distritoAlum[i] << setw(35 - strlen(distritoAlum[i])) << " ";
        archReporte << especialidad[i] << setw(25 - strlen(especialidad[i])) << " " << facultad[i] << setw(15 - strlen(facultad[i])) << " " << escala[i] << setw(5) << " ";
        archReporte << fixed << setprecision(2) << valorCred[i] << setw(6) << " ";

        archReporte << fixed << setw(5) << credMatri[i] << setw(10 - (credMatri[i] / 100)) << " ";

        archReporte << setprecision(3) << credMatri[i] * valorCred[i] << endl;
        totalMatri += credMatri[i] * valorCred[i];
    }
    escribirLinea(archReporte, 100, '-');
    archReporte << "Total de ingresos por matriculas:" << setprecision(8) << totalMatri << endl;
    escribirLinea(archReporte, 100, '=');

}
void escribirLinea(ofstream &archReporte, int cant, char c) {
    for (int i = 0; i < cant; i++) {
        archReporte.put(c);
    }
    archReporte << endl;
}