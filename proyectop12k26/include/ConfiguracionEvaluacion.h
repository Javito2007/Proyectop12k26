// clase creada por Freddy Muy el dia lunes 4/05/2026

#ifndef CONFIGURACION_EVALUACION_H
#define CONFIGURACION_EVALUACION_H

#include <string>
#include <vector>
#include <fstream>
#include "Cursos.h"
using namespace std;

class ConfiguracionEvaluacion {
private:
    string periodo;
    string codigoCurso;
    string nombreCurso;

    // Constantes para las notas
    static const int MAX_PRIMER_PARCIAL  = 20;
    static const int MAX_SEGUNDO_PARCIAL = 25;
    static const int MAX_ZONA_TAREAS     = 20;
    static const int MAX_EXAMEN_FINAL    = 35;
    static const int MIN_ZONA_FINAL      = 26;
    static const int NOTA_APROBACION     = 61;

    // Consulta Asignaciones.txt para saber si un curso tiene alumnos asignados
    bool cursoTieneAlumnos(const string& codigoCurso);

public:
    ConfiguracionEvaluacion();

    void seleccionarCurso();
    void configurarPeriodo();
    bool almacenarConfiguracion();

    string getCodigoCurso()       const;
    string getNombreCurso()       const;
    string getPeriodo()           const;
    int    getMaxPrimerParcial()  const;
    int    getMaxSegundoParcial() const;
    int    getMaxZonaTareas()     const;
    int    getMaxExamenFinal()    const;
    int    getMinZonaFinal()      const;
    int    getNotaAprobacion()    const;
};

#endif
