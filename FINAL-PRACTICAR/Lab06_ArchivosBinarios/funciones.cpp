/*
 * Author: Vladymir Canchari 20195908
 */

#include "funciones.hpp"

void crearPacientesBin(const char *nameArchBinP) {
    ifstream archPacientes("Pacientes.csv", ios::in);
    if (not archPacientes.is_open()) {
        cout << "Error al abrir el archivo" << endl;
        exit(1);
    }
    ofstream archPacientesBin(nameArchBinP, ios::out | ios::binary);
    if (not archPacientesBin.is_open()) {
        cout << "Error al abrir el archivo" << endl;
        exit(1);
    }
    struct Paciente paciente;
    int cantPacientes = 0;
    char buffer[60];
    while (true) {
        if (archPacientes.eof()) break;
        archPacientes >> paciente.dni;
        archPacientes.get();
        archPacientes.getline(buffer, 60, '\n');
        strcpy(paciente.nombre, buffer);
        archPacientes>>ws;
        paciente.fecha = 0;
        strcpy(paciente.codMedico, "000000");
        paciente.gasto = 0.0;
        archPacientesBin.write((const char *) (&paciente), sizeof (struct Paciente));
        cantPacientes++;
    }
    archPacientesBin.close();
}

void verificarPacientesBin(const char *nameArchBinP) {
    ofstream archVerificarPac("ReporteVerificarPacientesBin.txt", ios::out);
    if (not archVerificarPac.is_open()) {
        cout << "Error al abrir el archivo" << endl;
        exit(1);
    }
    ifstream archPacientesBin(nameArchBinP, ios::in | ios::binary);
    if (not archPacientesBin.is_open()) {
        cout << "Error al abrir el archivo" << endl;
        exit(1);
    }
    struct Paciente paciente;
    int tamStructP = sizeof (struct Paciente);
    int tamArchPBin;
    archPacientesBin.seekg(0, ios::end);
    tamArchPBin = archPacientesBin.tellg();
    int cantPacientes = tamArchPBin / tamStructP;
    archVerificarPac << "DNI" << setw(15) << "NOMBRE" << setw(28) << "COD MEDICO" << setw(10) << "GASTO" << endl;
    for (int i = 0; i < cantPacientes; i++) {
        archPacientesBin.seekg(sizeof (struct Paciente)*i, ios::beg);
        archPacientesBin.read((char *) (&paciente), sizeof (struct Paciente));
        archVerificarPac << paciente.dni << setw(strlen(paciente.nombre) + 5) << paciente.nombre << setw(30 - strlen(paciente.nombre)) << paciente.codMedico;
        archVerificarPac << setw(10) << " " << paciente.gasto << endl;
        archPacientesBin.seekg(0, ios::beg);
    }

}

void crearMedicinasBin(const char *nameArchBinM) {
    ifstream archMedicinas("Medicinas.csv", ios::in);
    if (not archMedicinas.is_open()) {
        cout << "Error al abrir el archivo" << endl;
        exit(1);
    }
    ofstream archMedicinasBin(nameArchBinM, ios::out | ios::binary);
    if (not archMedicinasBin.is_open()) {
        cout << "Error al abrir el archivo" << endl;
        exit(1);
    }
    struct Medicina medicina;
    int cantMedicinas = 0;
    char buffer[60];
    while (true) {
        if (archMedicinas.eof()) break;
        archMedicinas >> medicina.codigo;
        archMedicinas.get();
        archMedicinas.getline(buffer, 60, ',');
        strcpy(medicina.descripcion, buffer);
        archMedicinas >> medicina.precio;
        archMedicinas>>ws;
        archMedicinasBin.write((const char *) (&medicina), sizeof (struct Medicina));
        cantMedicinas++;
    }
    archMedicinasBin.close();

}

void verificarMedicinasBin(const char *nameArchBinM) {
    ofstream archVerificarMed("ReporteVerificarMedicinasBin.txt", ios::out);
    if (not archVerificarMed.is_open()) {
        cout << "Error al abrir el archivo" << endl;
        exit(1);
    }
    ifstream archMedicinasBin(nameArchBinM, ios::in | ios::binary);
    if (not archMedicinasBin.is_open()) {
        cout << "Error al abrir el archivo" << endl;
        exit(1);
    }
    struct Medicina medicina;
    int tamStructM = sizeof (struct Medicina);
    int tamArchMBin;
    archMedicinasBin.seekg(0, ios::end);
    tamArchMBin = archMedicinasBin.tellg();
    int cantMedicinas = tamArchMBin / tamStructM;
    archVerificarMed << "CODIGO" << setw(15) << "DESCRUIPCION" << setw(28) << "PRECIO" << endl;
    for (int i = 0; i < cantMedicinas; i++) {
        archMedicinasBin.seekg(sizeof (struct Medicina)*i, ios::beg);
        archMedicinasBin.read((char *) (&medicina), sizeof (struct Medicina));
        archVerificarMed << medicina.codigo << setw(strlen(medicina.descripcion) + 5) << medicina.descripcion << setw(40 - strlen(medicina.descripcion)) << medicina.precio << endl;
        archMedicinasBin.seekg(0, ios::beg);
    }
}

void completarInformacion(const char *nameArchBinP, const char *nameArchBinM) {
    ifstream archConsultas("Consultas.csv", ios::in);
    //verificarOpenArchivo(archConsultas);
    if (not archConsultas.is_open()) {
        cout << "Error al abrir el archivo" << endl;
        exit(1);
    }
    fstream archBinP(nameArchBinP, ios::out | ios::in | ios::binary);
    if (not archBinP.is_open()) {
        cout << "Error al abrir el archivo" << endl;
        exit(1);
    }
    struct Paciente paciente;
    int fecha, d, m, a, posicion, dni;
    char extra, buffer[10];
    while (true) {
        archConsultas >> d;
        if (archConsultas.eof()) break;
        archConsultas >> extra >> m >> extra>>a;
        fecha = d + m * 100 + a * 10000;
        archConsultas >> extra >> dni>>extra;
        archConsultas.getline(buffer, 10, ',');
        posicion = buscarPaciente(dni, nameArchBinP);
        archBinP.seekg((sizeof (struct Paciente)*posicion), ios::beg);
        archBinP.read((char *) (&paciente), sizeof (struct Paciente));
        actualizarPaciente(archConsultas, paciente, fecha, buffer, nameArchBinM);
        archBinP.seekg((sizeof (struct Paciente)*posicion), ios::beg);
        archBinP.write((const char *) (&paciente), sizeof (struct Paciente));
        archBinP.flush();
    }
}

double buscarPrecio(int codMed, const char *nameArchBinM) {
    ifstream archBinM(nameArchBinM, ios::in | ios::binary);
    if (not archBinM.is_open()) {
        cout << "Error al abrir el archivo" << endl;
        exit(1);
    }
    struct Medicina medicina;
    int tamStructM = sizeof (struct Medicina);
    int tamArchMBin;
    archBinM.seekg(0, ios::end);
    tamArchMBin = archBinM.tellg();
    int cantMedicinas = tamArchMBin / tamStructM;
    for (int i = 0; i < cantMedicinas; i++) {
        archBinM.seekg(tamStructM*i, ios::beg);
        archBinM.read((char *) (&medicina), tamStructM);
        if (medicina.codigo == codMed)
            return medicina.precio;
    }
}

int buscarPaciente(int dni, const char *nameArchBinP) {
    ifstream archBinP(nameArchBinP, ios::in | ios::binary);
    if (not archBinP.is_open()) {
        cout << "Error al abrir el archivo" << endl;
        exit(1);
    }
    struct Paciente paciente;
    int tamStructP = sizeof (struct Paciente);
    int tamArchPBin;
    archBinP.seekg(0, ios::end);
    tamArchPBin = archBinP.tellg();
    int cantPacientes = tamArchPBin / tamStructP;
    for (int i = 0; i < cantPacientes; i++) {
        archBinP.seekg(tamStructP*i, ios::beg);
        archBinP.read((char *) (&paciente), tamStructP);
        if (paciente.dni == dni)
            return i;
    }
}

void ordenarPacientes(const char *nameArchBinP) {
    fstream archBinP(nameArchBinP, ios::in | ios::out | ios::binary);
    if (not archBinP.is_open()) {
        cout << "Error al abrir el archivo" << endl;
        exit(1);
    }
    struct Paciente pI, pJ;
    int tamStructP = sizeof (struct Paciente);
    archBinP.seekg(0, ios::end);
    int cantP = archBinP.tellg() / tamStructP;
    for (int i = 0; i < cantP; i++)
        for (int j = i + 1; j < cantP - 1; j++) {
            archBinP.seekg(tamStructP*i, ios::beg);
            archBinP.read((char *) (&pI), tamStructP);
            archBinP.seekg(tamStructP*j, ios::beg);
            archBinP.read((char *) (&pJ), tamStructP);
            if ((pI.fecha > pJ.fecha) or (pI.fecha == pJ.fecha and (strcmp(pI.codMedico, pJ.codMedico) < 1))) {
                archBinP.seekg(tamStructP*i, ios::beg);
                archBinP.write((const char *) (&pJ), tamStructP);
                archBinP.seekg(tamStructP*j, ios::beg);
                archBinP.write((const char *) (&pI), tamStructP);
                archBinP.flush();
            }
        }
}

void escribirResumen(const char *nameArchBinP) {
    ifstream archBinP(nameArchBinP, ios::in | ios::binary);
    if (not archBinP.is_open()) {
        cout << "Error al abrir el archivo" << endl;
        exit(1);
    }
    ofstream archR("ResumenDeGastosPorPaciente.txt", ios::out);
    if (not archR.is_open()) {
        cout << "Error al abrir el archivo" << endl;
        exit(1);
    }
    archR << setw(50) << "RESUMEN DE GASTOS POR PACIENTE" << endl;
    escibirLinea(archR, 100, '=');
    archR <<setw(10)<<"DNI"<<setw(18)<<"NOMBRE"<<setw(38)<<"ULTIMA CONSULTA"<<setw(22)<<"TOTAL GASTADO"<< endl;
    struct Paciente paciente;
    int tamStructP = sizeof (struct Paciente), tamArchPBin;
    archBinP.seekg(0, ios::end);
    tamArchPBin = archBinP.tellg();
    int cantPacientes = tamArchPBin / tamStructP;
    double totalGatado=0;
    for (int i = 0; i < cantPacientes; i++) {
        archBinP.seekg(sizeof (struct Paciente)*i, ios::beg);
        archBinP.read((char *) (&paciente), sizeof (struct Paciente));
        archR <<setw(2)<<i+1<<')'<<setw(10)<<paciente.dni << setw(strlen(paciente.nombre) + 5) << paciente.nombre << setw(30 - strlen(paciente.nombre))<<" ";
        escribirFecha(archR,paciente.fecha);
        archR << setw(10) << paciente.codMedico<< setw(10) << " " << paciente.gasto << endl;
        totalGatado+=paciente.gasto;
        archBinP.seekg(0, ios::beg);
    }
    escibirLinea(archR,100,'=');
    archR<<"Promedio total gastado por paciente: "<<totalGatado/cantPacientes<<endl;
}
void escribirFecha(ofstream &archR,int fecha){
    int d,m,a;
    a=fecha/10000;
    fecha=fecha-a*10000;
    m=(fecha)/100;
    d=fecha%100;
    archR.fill('0');
    archR<<setw(2)<<d<<'/'<<setw(2)<<m<<'/'<<setw(4)<<a;
    archR.fill(' ');
}
void escibirLinea(ofstream &arch, int cant, char c) {
    for (int i = 0; i < cant; i++) {
        arch.put(c);
    }
    arch << endl;
}

void actualizarPaciente(ifstream &archConsultas, struct Paciente &paciente, int fecha,
        char *buffer, const char *nameArchBinM) {
    int codMed, cantMed;
    char fin;
    double precioMedicina;
    if (paciente.fecha < fecha) {
        paciente.fecha = fecha;
        strcpy(paciente.codMedico, buffer);
    }
    while (true) {
        archConsultas>>codMed;
        archConsultas.get();
        archConsultas>>cantMed;
        fin = archConsultas.get();
        precioMedicina = buscarPrecio(codMed, nameArchBinM);
        paciente.gasto += precioMedicina*cantMed;
        if (fin == '\n') break;
    }
}

//void verificarOpenArchivo(ifstream &arch){
//      if (not arch.is_open()) {
//        cout << "Error al abrir el archivo 5" << endl;
//        exit(1);
//    }
//}