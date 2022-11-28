#include "funciones.hpp"

void llenarStructAlumnos(struct Alumno *alumnos,int &cant){
    ifstream archAlu("Alumnos.csv",ios::in);
    if(not archAlu.is_open()){
        cout<<"Error al abrir el archivo"<<endl;
        exit(1);
    }
    char buffer[60];
    while(true){
        if(archAlu.eof()) break;
        archAlu>>alumnos[cant].codigo;
        archAlu.get();
        archAlu.getline(buffer,60,',');
        alumnos[cant].nombre=asignarMemoria(buffer);
        archAlu.getline(buffer,60,'\n');
        alumnos[cant].escala=asignarMemoria(buffer);
        archAlu>>ws;
        cant++;
    }
}
void llenarStructCursos(struct Curso *cursos,int &cant){
    ifstream archCur("Cursos.csv",ios::in);
    if(not archCur.is_open()){
        cout<<"Error al abrir el archivo"<<endl;
        exit(1);
    }
    char buffer[60];
    while(true){
        if(archCur.eof())break;
        archCur.getline(buffer,60,',');
        cursos[cant].codigo=asignarMemoria(buffer);
        archCur.getline(buffer,60,',');
        cursos[cant].nombre=asignarMemoria(buffer);
        archCur>>cursos[cant].cred;
        archCur>>ws;
        cant++;
    }
}
void llenarStructEscalas(struct Escala *escalas,int &cant){
    ifstream archEscala("Escalas.txt",ios::in);
    if(not archEscala.is_open()){
        cout<<"Error al abrir el archivo"<<endl;
        exit(1);
    }
    int a,s;
    char buffer[3];
    double cred;
    while(true){
        if(archEscala.eof()) break;
        archEscala.getline(buffer,3,' ');
        escalas[cant].codigo=asignarMemoria(buffer);
        archEscala>>escalas[cant].vCred;
        archEscala>>a;
        archEscala.get();
        archEscala>>s;
        escalas[cant].semestre=a*10+s;
        archEscala>>ws;
        cant++;
        
    }
}
char * asignarMemoria(char *buffer){
    char *str;
    str=new char[strlen(buffer)+1];
    strcpy(str,buffer);
    return str;
}
void completarDatosAlum(struct Alumno *alumnos,int cant){
    ifstream archNotas("Notas.csv",ios::in);
    if(not archNotas.is_open()){
        cout<<"Error al abrir el archivo"<<endl;
        exit(1);
    }
    char buffer[10],extra;
    int cod,posicion,d,m,a;
    while(true){
        if(archNotas.eof()) break;
        archNotas>>cod;
        archNotas.get();
        posicion=buscarAlumno(alumnos,cod,cant);
        archNotas.getline(buffer,10,',');
        alumnos[posicion].cursosM[alumnos[posicion].numCur].cod=asignarMemoria(buffer);
        archNotas>>alumnos[posicion].cursosM[alumnos[posicion].numCur].nota;
        archNotas.get();
        archNotas>>d>>extra>>m>>extra>>a;
        archNotas>>ws;
        alumnos[posicion].cursosM[alumnos[posicion].numCur].fecha=a*10000+m*100+d;
        alumnos[posicion].numCur++;   
    }
}
int buscarAlumno(struct Alumno *alumnos,int cod,int cant){
    for(int i=0;i<cant;i++){
        if(alumnos[i].codigo==cod)
            return i;  
    }
    return -1;
}
