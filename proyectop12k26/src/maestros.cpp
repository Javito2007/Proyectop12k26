#include "maestros.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

maestros::maestros()
{
    nombre = "";
    apellido = "";
    correo = "";
    horario = "";
    codigo = "";
    sede = "";
    diaSemana = "";
    horasClase = "";

}

void maestros::ingresarDatosPersonales()
{
    cout << "--- Ingreso de datos personales ---" << endl;
    cout << "Ingrese su nombre: ";
    cin >> nombre;
    cout << "Ingrese su apellido: "
    cin >> apellido;

    generarCorrero();
    gernerarCodigo();
}
void maestros::generarCorrero(){
    correo = nombre + apellido + "@miumg.edu.gt";
    cout << "Correo generado : " coorero << endl;
}

void maestros::generarCodigo(){
    srand(time(0))
    codigo = 1000 + rand() % 900;
    cout << "Codigo de seguridad: " << codigo << endl;
}

void maestros:asignarHorario(){
    cout <<"--- Asignación de Horario ---" << endl;
    cout << "Seleccione la sede" << endl;
    cout << "1- Sede Zona Portales" << endl;
    cout << "2- Central" << endl;
    cout << "3- Sede Antigua" << endl;
    cout << "4- Sede San Jose Pinula" << endl;
    cout << "Opcion: ";
    int opcionSede;
    cin >> opcionSede;

    dia = 3;
    cout << "Dias a la semana asignados por el sistema: "<< diaSemana << "días" << endl;

    horaClase = 2;
    cout << "Horas por clase asignadas: " << horasClase << "horas" << endl;

    switch (opcionSede){
    case 1: sede = "Sede Zona Portales";break;
    case 2: sede = "Central";break;
    case 3: sede = "Sede Antigua";break;
    case 4: sede = "Sede San Jose Pinula";break;
    }

    cout << "Sede asignada: " << sede << endl;

}

void Maestros::asignarCurso(){
    cout << "Asignacion Curso" << endl;

    int codigoIngresado;
    cout << "Ingrese su codigo: ";
    cin >> codigoIngresado;

    if(!verificarCodigo(codigoIngresado)){
        cout << "Codigo incorrecto" <<  endl;
        return;
    }

    curso.mostrarCursos();
    curso.seleccionarCursos();
    curso.mostrarInformacion();

    asignarHorario();

    cout << "\n Curso asignado: " << curso.getNombre() << endl;
    cout << "Salario base del curso Q: " << cursoSalarioBase() << endl;

}
double maestros::verificarCodigo(int codigoIngresado){
    return codigoIngresado == codigo;

}

void maestros::mostrarResultados(){
    cout << "Nombre: " << nombre << " " << apellido << endl;
    cout << "Correro: " << correo<< endl;
    cout << "Codigo: " << codigo << endl;
    cout << "Curso asignado: " << curso.getNombre() << endl;
    cout << "Sede: " << sede << endl;
    cout << "Horario: " << horario << endl;
    cout << "Dias por semana: " << diasSemana << endl;
    cout << "Horas por clase: " << horasClase << endl;
    cout << "Salario final Q: " << calcularSalario<< endl;

}

int maestros::getCodigo(){
    return
}

string maestros::getNombreCurso(){
    return curso.getNombre();
}


