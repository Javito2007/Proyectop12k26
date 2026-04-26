#ifndef carrera.h
#define carrera.h
#include <string>
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
