//archivo creado por Freddy Muy el dia lunes 4/05/2026

#include <iostream>
#include <fstream>
#include "ConfiguracionEvaluacion.h"
using namespace std;

ConfiguracionEvaluacion::ConfiguracionEvaluacion()
    : periodo(""), codigoCurso(""), nombreCurso("") {}


// Verifica en Asignaciones.txt si existe al menos un alumno asignado
// al curso con el codigo dado. Retorna true si hay al menos uno.

bool ConfiguracionEvaluacion::cursoTieneAlumnos(const string& codigo) {
    ifstream file("Asignaciones.txt");
    if (!file.is_open()) return false;

    string linea;
    while (getline(file, linea)) {
        // Ignorar lineas que no sean de cursos (encabezados, separadores, ID)
        if (linea.find('|') == string::npos)  continue;
        if (linea.find("REGISTRO") != string::npos) continue;
        if (linea.find("---")      != string::npos) continue;
        if (linea.find("===")      != string::npos) continue;


        string codLinea = linea.substr(0, linea.find('|'));
        size_t ini = codLinea.find_first_not_of(" \t\r\n");
        size_t fin = codLinea.find_last_not_of(" \t\r\n");
        if (ini == string::npos) continue;
        codLinea = codLinea.substr(ini, fin - ini + 1);

        if (codLinea == codigo) {
            file.close();
            return true;
        }
    }
    file.close();
    return false;
}

void ConfiguracionEvaluacion::seleccionarCurso() {
    Cursos temp;
    vector<Cursos> catalogo = temp.catalagoCursosIngSistemas();

    cout << "\n===== Catalogo de Cursos =====" << endl;
    for (int i = 0; i < (int)catalogo.size(); i++) {
        string cod = catalogo[i].getcodigoCurso();
        cout << "  [" << i + 1 << "] "
             << cod << " - "
             << catalogo[i].getnombreCurso();

        // Indicar si hay alumnos asignados para orientar al usuario
        if (cursoTieneAlumnos(cod))
            cout << "  (*alumnos asignados*)";

        cout << endl;
    }

    int opcion;
    cout << "\nSeleccione un curso: ";
    cin >> opcion;
    cin.ignore();

    if (opcion < 1 || opcion > (int)catalogo.size()) {
        cout << "Opcion invalida. Se usara el primero por defecto." << endl;
        opcion = 1;
    }

    codigoCurso = catalogo[opcion - 1].getcodigoCurso();
    nombreCurso = catalogo[opcion - 1].getnombreCurso();
    cout << "Curso seleccionado: [" << codigoCurso << "] " << nombreCurso << endl;

    // Avisar si el curso no tiene alumnos en Asignaciones.txt
    if (!cursoTieneAlumnos(codigoCurso)) {
        cout << "[Aviso] Este curso no tiene alumnos asignados en Asignaciones.txt." << endl;
        cout << "        Podra seleccionarlos manualmente al registrar notas." << endl;
    }
}

void ConfiguracionEvaluacion::configurarPeriodo() {
    cout << "Periodo de evaluacion (Ej: Primer Semestre 2026): ";
    getline(cin, periodo);
}

bool ConfiguracionEvaluacion::almacenarConfiguracion() {
    if (codigoCurso == "" || periodo == "") {
        cout << "Error: faltan datos de curso o periodo." << endl;
        return false;
    }

    cout << "\n===== Configuracion del Curso =====" << endl;
    cout << "Curso  : [" << codigoCurso << "] " << nombreCurso << endl;
    cout << "Periodo: " << periodo                              << endl;
    cout << "\n--- Distribucion de notas ---"                   << endl;
    cout << "  Primer Parcial  : " << MAX_PRIMER_PARCIAL        << " pts" << endl;
    cout << "  Segundo Parcial : " << MAX_SEGUNDO_PARCIAL       << " pts" << endl;
    cout << "  Zona Tareas     : " << MAX_ZONA_TAREAS           << " pts" << endl;
    cout << "  Zona max        : "
         << (MAX_PRIMER_PARCIAL + MAX_SEGUNDO_PARCIAL + MAX_ZONA_TAREAS)
         << " pts (min " << MIN_ZONA_FINAL << " para habilitar final)"    << endl;
    cout << "  Examen Final    : " << MAX_EXAMEN_FINAL          << " pts" << endl;
    cout << "  Nota aprobacion : " << NOTA_APROBACION           << " pts" << endl;
    return true;
}

// Getters
string ConfiguracionEvaluacion::getCodigoCurso()       const { return codigoCurso; }
string ConfiguracionEvaluacion::getNombreCurso()       const { return nombreCurso; }
string ConfiguracionEvaluacion::getPeriodo()           const { return periodo; }
int    ConfiguracionEvaluacion::getMaxPrimerParcial()  const { return MAX_PRIMER_PARCIAL; }
int    ConfiguracionEvaluacion::getMaxSegundoParcial() const { return MAX_SEGUNDO_PARCIAL; }
int    ConfiguracionEvaluacion::getMaxZonaTareas()     const { return MAX_ZONA_TAREAS; }
int    ConfiguracionEvaluacion::getMaxExamenFinal()    const { return MAX_EXAMEN_FINAL; }
int    ConfiguracionEvaluacion::getMinZonaFinal()      const { return MIN_ZONA_FINAL; }
int    ConfiguracionEvaluacion::getNotaAprobacion()    const { return NOTA_APROBACION; }
