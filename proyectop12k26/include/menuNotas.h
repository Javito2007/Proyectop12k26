#pragma once
#include <vector>
#include <string>
#include "usuarios.h"
#include "Alumnos.h"
#include "ConfiguracionEvaluacion.h"
#include "RegistrarNotas.h"
#include "reportes.h"
using namespace std;

<<<<<<< HEAD
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
=======
// Clase principal que gestiona todo el sistema de notas
class SistemaNotas {
private:
    usuarios              sesion;           // Manejo de login y usuarios
    vector<Alumnos>       listaAlumnos;     // Lista de todos los alumnos registrados en el sistema
    ConfiguracionEvaluacion config;         // Configuración de evaluación del curso
    RegistrarNotas          registro;       // Objeto para registrar y gestionar notas
    reportes                reporte;        // Manejo de reportes y consultas
    string                  usuarioActivo;  // Nombre del usuario actualmente logueado

public:
    bool iniciar();          // Inicializa sesión y carga/registra alumnos
    void ejecutarMenu();     // Muestra y procesa el menú principal del sistema
>>>>>>> 3f9edb6a5ec3ebf7f23ae2a9a2aec885b62bae95
};
