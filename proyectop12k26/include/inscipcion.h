#ifndef INSCIPCION_H
#define INSCIPCION_H

#include <string>
using namespace std;

class Inscripcion
{
private:
    int codigoInscripcion;
    int carnetEstudiante;
    string nombreEstudiante;
    string carrera;
    string tipoInscripcion;
    string ciclo;
    string jornada;
    string fechaInscripcion;
    string estadoInscripcion;

public:
    void ingresarDatos();
    void mostrarDatos();
};

#endif
