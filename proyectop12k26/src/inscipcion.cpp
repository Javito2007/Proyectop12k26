#include <iostream>
#include "inscipcion.h"
using namespace std;


void Inscripcion::ingresarDatos()
{
    cout << "\n==================================" << endl;
    cout << " SISTEMA DE INSCRIPCION UNIVERSIDAD MARIANO GALVEZ " << endl;
    cout << "==================================" << endl;

    cout << "Codigo de inscripcion: ";
    cin >> codigoInscripcion;

    cout << "Carnet estudiante: ";
    cin >> carnetEstudiante;
    cin.ignore();

    cout << "Nombre del estudiante: ";
    getline(cin, nombreEstudiante);

    cout << "Carrera: ";
    getline(cin, carrera);

    cout << "Tipo de inscripcion (Primer ingreso / Reingreso): ";
    getline(cin, tipoInscripcion);

    cout << "Ciclo academico: ";
    getline(cin, ciclo);

    cout << "Jornada (Matutina / Vespertina / Nocturna): ";
    getline(cin, jornada);

    cout << "Fecha de inscripcion: ";
    getline(cin, fechaInscripcion);

    cout << "Estado (Activa / Pendiente / Finalizada): ";
    getline(cin, estadoInscripcion);
}

void Inscripcion::mostrarDatos()
{
    cout << "\n==================================" << endl;
    cout << " COMPROBANTE DE INSCRIPCION " << endl;
    cout << "==================================" << endl;

    cout << "Codigo: " << codigoInscripcion << endl;
    cout << "Carnet: " << carnetEstudiante << endl;
    cout << "Estudiante: " << nombreEstudiante << endl;
    cout << "Carrera: " << carrera << endl;
    cout << "Tipo: " << tipoInscripcion << endl;
    cout << "Ciclo: " << ciclo << endl;
    cout << "Jornada: " << jornada << endl;
    cout << "Fecha: " << fechaInscripcion << endl;
    cout << "Estado: " << estadoInscripcion << endl;
}
