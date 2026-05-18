//Creado el dia 4 de mayo por los alumnos
//9959-25-4900: Jhonny Flores
//9959-25-4992: Josue Muy
//9959-25-6194: Juan Jolon
//9959-25-7728: Jose Barrios

#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include "RegistrarNotas.h"
using namespace std;

// Constructor por defecto
RegistrarNotas::RegistrarNotas() : nAlumnos(0) {}

// Valida que un valor este dentro del rango permitido [0, maximo]
bool RegistrarNotas::validarRango(float valor, float maximo) {
    return (valor >= 0.0f && valor <= maximo);
}

// Calcula la zona (suma de parciales y tareas)
float RegistrarNotas::calcularZona(float p1, float p2, float tareas) {
    return p1 + p2 + tareas;
}

// Calcula la nota final (zona + examen final)
float RegistrarNotas::calcularNotaFinal(float zona, float examenFinal) {
    return zona + examenFinal;
}

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


// Lee Alumnos.txt y devuelve un vector con todos los alumnos


vector<Alumnos> RegistrarNotas::cargarAlumnosDesdeArchivo() {
    vector<Alumnos> lista;
    ifstream file("Alumnos.txt");

    if (!file.is_open()) {
        cout << "  [Aviso] No se pudo abrir Alumnos.txt" << endl;
        return lista;
    }

    string carnet, nombreCompleto, carrera, correo, contrasenia, lineaCompleta;

    while (getline(file, lineaCompleta)) {
        // Verificar que la linea tenga al menos 4 '|'
        int contadorPipes = 0;
        for (char c : lineaCompleta) if (c == '|') contadorPipes++;
        if (contadorPipes < 4) continue;

        // Parsear la linea usando istringstream
        istringstream ss(lineaCompleta);
        getline(ss, carnet,         '|');
        getline(ss, nombreCompleto, '|');
        getline(ss, carrera,        '|');
        getline(ss, correo,         '|');
        getline(ss, contrasenia);

        // Quitar espacios al inicio y al final
        auto trim = [](string& s) {
            size_t ini = s.find_first_not_of(" \t\r\n");
            size_t fin = s.find_last_not_of(" \t\r\n");
            s = (ini == string::npos) ? "" : s.substr(ini, fin - ini + 1);
        };
        trim(carnet);
        trim(nombreCompleto);
        trim(carrera);
        trim(correo);
        trim(contrasenia);

        if (carnet.empty()) continue;   // linea en blanco, la saltamos

        // Separar nombre y apellido: la clase Alumnos los guarda por separado.

        string nombre    = "";
        string apellido  = "";
        size_t espacio   = nombreCompleto.find(' ');
        if (espacio != string::npos) {
            nombre   = nombreCompleto.substr(0, espacio);
            apellido = nombreCompleto.substr(espacio + 1);
        } else {
            nombre = nombreCompleto;
        }

        Alumnos alumno;
        alumno.setnombreAlumno(nombre);
        alumno.setapellidoAlumno(apellido);
        alumno.setcarnetPersonal(carnet);
        alumno.setcarreraAsignada(carrera);
        alumno.setcorreoPersonal(correo);
        alumno.setcontraseniaUnica(contrasenia);

        lista.push_back(alumno);
    }

    file.close();
    return lista;
}


// Lee Asignaciones.txt y devuelve solo los carnets que tienen asignado el curso con el codigoCurso recibido.

vector<string> RegistrarNotas::cargarCarnetsPorCurso(const string& codigoCurso) {
    vector<string> carnets;
    ifstream file("Asignaciones.txt");

    if (!file.is_open()) {
        cout << "  [Aviso] No se pudo abrir Asignaciones.txt" << endl;
        return carnets;
    }

    string linea;
    string carnetActual = "";
    bool   cursoPresenteEnBloque = false;

    while (getline(file, linea)) {

        // Inicio de bloque
        if (linea.rfind("ID:", 0) == 0) {
            // Si el bloque anterior tenia el curso, guardamos su carnet
            if (cursoPresenteEnBloque && !carnetActual.empty()) {
                // Evitar duplicados
                bool dup = false;
                for (const string& c : carnets)
                    if (c == carnetActual) { dup = true; break; }
                if (!dup) carnets.push_back(carnetActual);
            }
            // Resetear para el nuevo bloque
            carnetActual          = linea.substr(3);   // quita "ID:"
            cursoPresenteEnBloque = false;

            // Quitar espacios
            size_t f = carnetActual.find_last_not_of(" \t\r\n");
            if (f != string::npos) carnetActual = carnetActual.substr(0, f + 1);
            continue;
        }

        // El codigo de curso es la parte antes del primer '|', sin espacios
        if (!carnetActual.empty() && linea.find('|') != string::npos) {
            // Ignorar la linea de encabezado "REGISTRO DE ASIGNACION..."
            if (linea.find("REGISTRO") != string::npos) continue;
            if (linea.find("---")      != string::npos) continue;
            if (linea.find("===")      != string::npos) continue;

            string codigo = linea.substr(0, linea.find('|'));
            // Quitar espacios
            size_t ini = codigo.find_first_not_of(" \t\r\n");
            size_t fin = codigo.find_last_not_of(" \t\r\n");
            if (ini != string::npos)
                codigo = codigo.substr(ini, fin - ini + 1);

            if (codigo == codigoCurso)
                cursoPresenteEnBloque = true;
        }
    }

    // Ultimo bloque del archivo
    if (cursoPresenteEnBloque && !carnetActual.empty()) {
        bool dup = false;
        for (const string& c : carnets)
            if (c == carnetActual) { dup = true; break; }
        if (!dup) carnets.push_back(carnetActual);
    }

    file.close();
    return carnets;
}


// seleccionarAlumnos: ahora lee el archivo, filtra por curso si se pasa un codigoCurso, y deja al usuario elegir de esa lista.

void RegistrarNotas::seleccionarAlumnos(vector<Alumnos>& listaAlumnos) {

    // Si el vector viene vacio, lo llenamos nosotros
    if (listaAlumnos.empty()) {
        cout << "\n  Cargando alumnos desde Alumnos.txt..." << endl;
        listaAlumnos = cargarAlumnosDesdeArchivo();
    }

    if (listaAlumnos.empty()) {
        cout << "\n  No hay alumnos registrados en el sistema." << endl;
        return;
    }

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


// el codigoCurso de ConfiguracionEvaluacion.

void RegistrarNotas::seleccionarAlumnosPorCurso(const string& codigoCurso) {

    // Cargar todos los alumnos del archivo
    vector<Alumnos> todosAlumnos = cargarAlumnosDesdeArchivo();
    if (todosAlumnos.empty()) {
        cout << "\n  No hay alumnos registrados en el sistema." << endl;
        return;
    }

    // Obtener carnets asignados a este curso
    vector<string> carnetsDelCurso = cargarCarnetsPorCurso(codigoCurso);

    // quedarse solo con alumnos que esten en ese curso
    // Se hace trim de ambos carnets antes de comparar por si quedaron espacios
    auto trimStr = [](const string& s) -> string {
        size_t ini = s.find_first_not_of(" \t\r\n");
        size_t fin = s.find_last_not_of(" \t\r\n");
        return (ini == string::npos) ? "" : s.substr(ini, fin - ini + 1);
    };

    vector<Alumnos> alumnosFiltrados;
    for (Alumnos& a : todosAlumnos) {
        string carnetAlumno = trimStr(a.getcarnetPersonal());
        for (const string& c : carnetsDelCurso) {
            if (carnetAlumno == trimStr(c)) {
                alumnosFiltrados.push_back(a);
                break;
            }
        }
    }

    if (alumnosFiltrados.empty()) {
        cout << "\n  No hay alumnos asignados al curso [" << codigoCurso << "]." << endl;
        cout << "  Verifique Asignaciones.txt o use la seleccion manual." << endl;

        // Ofrecer seleccion manual como respaldo
        cout << "\n  Desea seleccionar alumnos manualmente? (1=Si / 0=No): ";
        int resp; cin >> resp;
        if (resp == 1)
            seleccionarAlumnos(todosAlumnos);
        return;
    }

    cout << "\n===== Alumnos asignados al curso [" << codigoCurso << "] =====" << endl;
    for (int i = 0; i < (int)alumnosFiltrados.size(); i++)
        cout << "  [" << i + 1 << "] "
             << alumnosFiltrados[i].getcarnetPersonal() << " - "
             << alumnosFiltrados[i].getnombreAlumno()   << " "
             << alumnosFiltrados[i].getapellidoAlumno() << endl;

    cout << "\nSeleccione alumnos a los que ingresara notas. Escriba 0 para terminar." << endl;

    nAlumnos = 0;
    int opcion;

    while (nAlumnos < MAX_ALUMNOS) {
        cout << "  Alumno " << (nAlumnos + 1) << " (0 para terminar): ";
        cin >> opcion;

        if (opcion == 0) break;

        if (opcion < 1 || opcion > (int)alumnosFiltrados.size()) {
            cout << "  Opcion invalida." << endl;
            continue;
        }

        string carnetSeleccionado = alumnosFiltrados[opcion - 1].getcarnetPersonal();

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
        notas[nAlumnos].nombreAlumno = alumnosFiltrados[opcion - 1].getnombreAlumno()
                                     + " "
                                     + alumnosFiltrados[opcion - 1].getapellidoAlumno();
        nAlumnos++;
    }

    cin.ignore();
    cout << "Alumnos seleccionados: " << nAlumnos << endl;
}

void RegistrarNotas::ingresarNotas(const ConfiguracionEvaluacion& config) {
    for (int i = 0; i < nAlumnos; i++) {
        cout << "\n--- [" << notas[i].carnet << "] "
             << notas[i].nombreAlumno << " ---" << endl;

        notas[i].primerParcial  = pedirNota("Primer Parcial ", config.getMaxPrimerParcial());
        notas[i].segundoParcial = pedirNota("Segundo Parcial", config.getMaxSegundoParcial());
        notas[i].zonaTareas     = pedirNota("Zona Tareas    ", config.getMaxZonaTareas());

        notas[i].zona = calcularZona(notas[i].primerParcial,
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
