#ifndef REGISTRAR_NOTAS_H
#define REGISTRAR_NOTAS_H

#include <string>
#include <vector>
#include "ConfiguracionEvaluacion.h"
#include "Alumnos.h"
#include "bitacora.h"
#include "reportes.h"
using namespace std;

const int MAX_ALUMNOS = 10;

struct Nota {
    string carnet;
    string nombreAlumno;
    float  primerParcial;
    float  segundoParcial;
    float  zonaTareas;
    float  zona;
    float  examenFinal;
    float  notaFinal;
    bool   habilitadoFinal;
    bool   aprobado;
};

class RegistrarNotas {
private:
    Nota notas[MAX_ALUMNOS];
    int  nAlumnos;

    bool  validarRango(float valor, float maximo);
    float calcularZona(float p1, float p2, float tareas);
    float calcularNotaFinal(float zona, float examenFinal);
    float pedirNota(const string& etiqueta, int maximo);

public:
    RegistrarNotas();

    void seleccionarAlumnos(vector<Alumnos>& listaAlumnos);
    void ingresarNotas(const ConfiguracionEvaluacion& config);
    void almacenarNotas(const string& usuarioActivo);
    void mostrarResumen();
};

#endif
