#include <iostream>
#include "RegistrarNotas.h"
using namespace std;
// Jose Javier Barrios Carrera 9959-25-7728
// 04/05/2026

RegistrarNotas::RegistrarNotas() : nAlumnos(0) {}

bool RegistrarNotas::validarRango(float valor, float maximo) {
    return (valor >= 0.0f && valor <= maximo);
}

float RegistrarNotas::calcularZona(float p1, float p2, float tareas) {
    return p1 + p2 + tareas;
}

float RegistrarNotas::calcularNotaFinal(float zona, float examenFinal) {
    return zona + examenFinal;
}

// No avanza hasta recibir un valor dentro del rango
float RegistrarNotas::pedirNota(const string& etiqueta, int maximo) {
    float valor;
    do {
        cout << "  " << etiqueta << " (0 - " << maximo << "): ";
        cin >> valor;
        if (!validarRango(valor, maximo))
            cout << "  Error: ingrese un valor entre 0 y " << maximo << "." << endl;
    } while (!validarRango(valor, maximo));
    return valor;
}

// 4.1 El docente elige que alumnos del sistema pertenecen a este curso
void RegistrarNotas::seleccionarAlumnos(vector<Alumnos>& listaAlumnos) {
    cout << "\n===== Alumnos en el sistema =====" << endl;
    for (int i = 0; i < (int)listaAlumnos.size(); i++)
        cout << "  [" << i + 1 << "] "
             << listaAlumnos[i].getcarnetPersonal() << " - "
             << listaAlumnos[i].getnombreAlumno()   << " "
             << listaAlumnos[i].getapellidoAlumno() << endl;

    cout << "\nSeleccione alumnos del curso. Escriba 0 para terminar." << endl;

    nAlumnos = 0;
    int opcion;

    while (nAlumnos < MAX_ALUMNOS) {
        cout << "  Alumno " << (nAlumnos + 1) << " (0 para terminar): ";
        cin >> opcion;

        if (opcion == 0) break;

        if (opcion < 1 || opcion > (int)listaAlumnos.size()) {
            cout << "  Opcion invalida." << endl;
            continue;
        }

        // Evitar duplicados
        string carnetSeleccionado = listaAlumnos[opcion - 1].getcarnetPersonal();
        bool duplicado = false;
        for (int j = 0; j < nAlumnos; j++) {
            if (notas[j].carnet == carnetSeleccionado) {
                cout << "  Este alumno ya fue seleccionado." << endl;
                duplicado = true;
                break;
            }
        }
        if (duplicado) continue;

        notas[nAlumnos].carnet       = carnetSeleccionado;
        notas[nAlumnos].nombreAlumno = listaAlumnos[opcion - 1].getnombreAlumno()
                                     + " "
                                     + listaAlumnos[opcion - 1].getapellidoAlumno();
        nAlumnos++;
    }

    cin.ignore();
    cout << "Alumnos seleccionados: " << nAlumnos << endl;
}

// 4.2 + 4.3 Ingresa y valida notas. Zona minima de 26 para habilitar examen final
void RegistrarNotas::ingresarNotas(const ConfiguracionEvaluacion& config) {
    for (int i = 0; i < nAlumnos; i++) {
        cout << "\n--- [" << notas[i].carnet << "] "
             << notas[i].nombreAlumno << " ---" << endl;

        notas[i].primerParcial  = pedirNota("Primer Parcial ", config.getMaxPrimerParcial());
        notas[i].segundoParcial = pedirNota("Segundo Parcial", config.getMaxSegundoParcial());
        notas[i].zonaTareas     = pedirNota("Zona Tareas    ", config.getMaxZonaTareas());
        notas[i].zona           = calcularZona(notas[i].primerParcial,
                                               notas[i].segundoParcial,
                                               notas[i].zonaTareas);

        cout << "  -----------------------------" << endl;
        cout << "  Zona acumulada: " << notas[i].zona << " pts" << endl;

        notas[i].habilitadoFinal = (notas[i].zona >= config.getMinZonaFinal());

        if (!notas[i].habilitadoFinal) {
            cout << "  Alumno NO habilitado para examen final." << endl;
            cout << "  (Minimo requerido: " << config.getMinZonaFinal() << " pts)" << endl;
            notas[i].examenFinal = 0;
            notas[i].notaFinal   = notas[i].zona;
            notas[i].aprobado    = false;
        } else {
            cout << "  Alumno HABILITADO para examen final." << endl;
            notas[i].examenFinal = pedirNota("Examen Final   ", config.getMaxExamenFinal());
            notas[i].notaFinal   = calcularNotaFinal(notas[i].zona, notas[i].examenFinal);
            notas[i].aprobado    = (notas[i].notaFinal >= config.getNotaAprobacion());
        }
    }
    cin.ignore();
}

// 4.4 Muestra resumen, guarda en archivo y registra en bitacora
void RegistrarNotas::almacenarNotas(const string& usuarioActivo) {
    mostrarResumen();

    reportes reporte;
    cout << "\n===== Guardando en archivo =====" << endl;
    for (int i = 0; i < nAlumnos; i++) {
        reporte.generarDesdeNota(
            notas[i].carnet,
            notas[i].nombreAlumno,
            notas[i].primerParcial,
            notas[i].segundoParcial,
            notas[i].zonaTareas,
            notas[i].zona,
            notas[i].examenFinal,
            notas[i].notaFinal,
            notas[i].aprobado ? "APROBADO" : "REPROBADO"
        );
    }

    bitacora auditoria;
    auditoria.insertar(usuarioActivo, "RegistrarNotas", "NOTAS_ALMACENADAS");
}

// Estadisticas solo consideran alumnos que llegaron al examen final
void RegistrarNotas::mostrarResumen() {
    cout << "\n=================================================" << endl;
    cout << " REPORTE FINAL DE NOTAS"                            << endl;
    cout << "================================================="  << endl;

    int   aprobados     = 0;
    int   reprobados    = 0;
    int   noHabilitados = 0;
    int   conFinal      = 0;
    float sumaNotas     = 0;
    float notaMasAlta   = -1;
    float notaMasBaja   = 101;

    for (int i = 0; i < nAlumnos; i++) {
        cout << "\n  Alumno : " << notas[i].nombreAlumno         << endl;
        cout << "  Carnet : " << notas[i].carnet                 << endl;
        cout << "  P1     : " << notas[i].primerParcial          << " / 20" << endl;
        cout << "  P2     : " << notas[i].segundoParcial         << " / 25" << endl;
        cout << "  Tareas : " << notas[i].zonaTareas             << " / 20" << endl;
        cout << "  Zona   : " << notas[i].zona                   << " / 65" << endl;

        if (!notas[i].habilitadoFinal) {
            cout << "  Final  : No habilitado"                   << endl;
            cout << "  Estado : REPROBADO (sin derecho a final)" << endl;
            noHabilitados++;
        } else {
            cout << "  Final  : " << notas[i].examenFinal        << " / 35" << endl;
            cout << "  Total  : " << notas[i].notaFinal          << " / 100" << endl;
            cout << "  Estado : "
                 << (notas[i].aprobado ? "APROBADO" : "REPROBADO") << endl;

            sumaNotas += notas[i].notaFinal;
            conFinal++;
            if (notas[i].notaFinal > notaMasAlta) notaMasAlta = notas[i].notaFinal;
            if (notas[i].notaFinal < notaMasBaja) notaMasBaja = notas[i].notaFinal;
            if (notas[i].aprobado) aprobados++;
            else                   reprobados++;
        }
        cout << "  -----------------------------------------" << endl;
    }

    cout << "\n  Aprobados      : " << aprobados     << endl;
    cout << "  Reprobados     : " << reprobados    << endl;
    cout << "  Sin der. final : " << noHabilitados << endl;

    if (conFinal > 0) {
        float promedio             = sumaNotas / conFinal;
        float porcentajeAprobacion = ((float)aprobados / conFinal) * 100;

        cout << "\n--- Estadisticas del curso ---"                     << endl;
        cout << "  Promedio general     : " << promedio               << " pts" << endl;
        cout << "  Nota mas alta        : " << notaMasAlta            << " pts" << endl;
        cout << "  Nota mas baja        : " << notaMasBaja            << " pts" << endl;
        cout << "  Porcentaje aprobacion: " << porcentajeAprobacion   << "%"    << endl;
    } else {
        cout << "\n  Sin estadisticas: ningun alumno llego al examen final." << endl;
    }

    cout << "=================================================" << endl;
}
