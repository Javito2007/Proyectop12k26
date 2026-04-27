#include <iostream>
#include "Carrera.h"                  //Clase creada por David Alegria
using namespace std;

void Carreras::ingresarDatos()
{
    cout << "Ingrese codigo de la carrera: ";
    cin >> codigoCarrera;
    cin.ignore();

    cout << "Ingrese nombre de la carrera: ";
    getline(cin, nombreCarrera);

    cout << "Ingrese estado de la carrera: ";
    getline(cin, estadoCarrera);
}

void Carreras::mostrarDatos()
{
    cout << "\n--- DATOS DE LA CARRERA UNIVERSIDAD MARIANO GALVEZ ---" << endl;
    cout << "Codigo: " << codigoCarrera << endl;
    cout << "Nombre: " << nombreCarrera << endl;
    cout << "Estado: " << estadoCarrera << endl;
}
