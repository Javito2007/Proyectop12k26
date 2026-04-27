#ifndef carrera_h
#define carrera_h
#include <string>                     //Clase creada por David Alegria
using namespace std;

class Carreras
{
private:
    int codigoCarrera;
    string nombreCarrera;
    string estadoCarrera;

public:
    void ingresarDatos();
    void mostrarDatos();
};

#endif
