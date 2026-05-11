#pragma once   //Juan Jolon 9959-25-6194 y Jose Javier 9959-25-7728
#include <vector>
#include <string>
#include "usuarios.h"
#include "Alumnos.h"
#include "ConfiguracionEvaluacion.h"
#include "RegistrarNotas.h"
#include "reportes.h"
using namespace std;

class SistemaNotas {
private:
    usuarios              sesion;
    vector<Alumnos>       listaAlumnos;
    ConfiguracionEvaluacion config;
    RegistrarNotas          registro;
    reportes                reporte;
    string                  usuarioActivo;

public:
    bool iniciar();          // cargar alumnos
    void ejecutarMenu();
};
