//Creado el dia 4 de mayo por los alumnos
//9959-25-4900: Jhonny Flores
//9959-25-4992: Josue Muy
//9959-25-6194: Juan Jolon
//9959-25-7728: Jose Barrios

#ifndef REGISTRAR_NOTAS_H
#define REGISTRAR_NOTAS_H

#include <string>
#include <vector>
#include "ConfiguracionEvaluacion.h"
#include "Alumnos.h"
#include "bitacora.h"
#include "reportes.h"
using namespace std;

// Constante que define el maximo de alumnos que se pueden registrar por curso
const int MAX_ALUMNOS = 10;

// Estructura que almacena toda la informacion de notas de un alumno
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

    // Metodos privados utilitarios
    bool  validarRango(float valor, float maximo);
    float calcularZona(float p1, float p2, float tareas);
    float calcularNotaFinal(float zona, float examenFinal);
    float pedirNota(const string& etiqueta, int maximo);

    // Lee Alumnos.txt y retorna vector con todos los alumnos
    vector<Alumnos> cargarAlumnosDesdeArchivo();

    // Lee Asignaciones.txt y retorna los carnets asignados a un curso
    vector<string> cargarCarnetsPorCurso(const string& codigoCurso);

public:
    RegistrarNotas();

    // Seleccion manual
    void seleccionarAlumnos(vector<Alumnos>& listaAlumnos);

    // lee Alumnos.txt y Asignaciones.txt automaticamente
    // Usar esta cuando ya se tiene el codigoCurso de ConfiguracionEvaluacion
    void seleccionarAlumnosPorCurso(const string& codigoCurso);

    void ingresarNotas(const ConfiguracionEvaluacion& config);
    void almacenarNotas(const string& usuarioActivo);
    void mostrarResumen();
};

#endif
