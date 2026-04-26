#include <iostream>
#include "inscipcion.h"
using namespace std;


void Inscripcion::ingresarDatos()
{
    cout << "\n--- INSCRIPCION UNIVERSIDAD MARIANO GALVEZ ---" << endl;

    cout << "Ingrese codigo de inscripcion: ";
    cin >> codigoInscripcion;
    cin.ignore();

    cout << "Ingrese tipo (Primer ingreso / Reingreso): ";
    getline(cin, tipoInscripcion);

    cout << "Ingrese fecha de inscripcion: ";
    getline(cin, fechaInscripcion);

    cout << "Ingrese estado de inscripcion: ";
    getline(cin, estadoInscripcion);
}

void Inscripcion::mostrarDatos()
{
    cout << "\n--- DATOS INSCRIPCION ---" << endl;
    cout << "Codigo: " << codigoInscripcion << endl;
    cout << "Tipo: " << tipoInscripcion << endl;
    cout << "Fecha: " << fechaInscripcion << endl;
    cout << "Estado: " << estadoInscripcion << endl;
}
