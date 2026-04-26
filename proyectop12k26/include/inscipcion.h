
#define inscipcion.h

#include <string>
using namespace std;

class Inscripcion
{
private:
    int codigoInscripcion;
    string tipoInscripcion;
    string fechaInscripcion;
    string estadoInscripcion;

public:
    void ingresarDatos();
    void mostrarDatos();
};
