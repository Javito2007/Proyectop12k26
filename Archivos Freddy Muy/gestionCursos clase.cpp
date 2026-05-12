#include<iostream>
using namespace std;

using SIN_TIPO = string;

class GestionCursos {
private:
    SIN_TIPO cursos[100];
    float cupos[100];
    float activo[100];
    SIN_TIPO catedraticos[100];
    SIN_TIPO inscripciones[100];
    SIN_TIPO cursosinscritos[100];
    int totalcursos;
    int totalinscripciones;

public:
    GestionCursos() {
        totalcursos = 0;
        totalinscripciones = 0;
    }

    void registrarcurso() {
        bool existe;
        int i;
        string nombre;
        existe = false;
        cout << "Ingrese nombre del curso:" << endl;
        cin >> nombre;
        if (totalcursos > 0) {
            for (i = 1; i <= totalcursos; ++i) {
                if (cursos[i-1] == nombre) {
                    existe = true;
                }
            }
        }
        if (existe) {
            cout << "El curso ya existe." << endl;
        } else {
            totalcursos = totalcursos + 1;
            cursos[totalcursos-1] = nombre;
            cout << "Ingrese cupo maximo del curso:" << endl;
            cin >> cupos[totalcursos-1];
            activo[totalcursos-1] = 1;
            cout << "Curso registrado exitosamente." << endl;
        }
    }

    void asignarcatedratico() {
        string docente;
        bool encontrado;
        int i;
        string nombre;
        encontrado = false;
        cout << "Ingrese nombre del curso:" << endl;
        cin >> nombre;
        cout << "Ingrese nombre del catedratico:" << endl;
        cin >> docente;
        if (totalcursos > 0) {
            for (i = 1; i <= totalcursos; ++i) {
                if (cursos[i-1] == nombre && activo[i-1] == 1) {
                    catedraticos[i-1] = docente;
                    cout << "Catedratico asignado correctamente." << endl;
                    encontrado = true;
                }
            }
        }
        if (!encontrado) {
            cout << "Curso no encontrado o inactivo." << endl;
        }
    }

    void inscribirseacurso() {
        bool encontrado;
        int i;
        string nombrecurso;
        string nombreestudiante;
        encontrado = false;
        cout << "Ingrese nombre del estudiante:" << endl;
        cin >> nombreestudiante;
        cout << "Ingrese nombre del curso:" << endl;
        cin >> nombrecurso;
        if (totalcursos > 0) {
            for (i = 1; i <= totalcursos; ++i) {
                if (cursos[i-1] == nombrecurso && activo[i-1] == 1) {
                    if (cupos[i-1] > 0) {
                        cupos[i-1] = cupos[i-1] - 1;
                        totalinscripciones = totalinscripciones + 1;
                        inscripciones[totalinscripciones-1] = nombreestudiante;
                        cursosinscritos[totalinscripciones-1] = nombrecurso;
                        cout << "Inscripcion completada exitosamente." << endl;
                        encontrado = true;
                    } else {
                        cout << "No hay cupo disponible en este curso." << endl;
                        encontrado = true;
                    }
                }
            }
        }
        if (!encontrado) {
            cout << "Curso no encontrado o inactivo." << endl;
        }
    }

    void consultarcursosactivos() {
        bool hayactivos;
        int i;
        hayactivos = false;
        cout << "===== CURSOS ACTIVOS =====" << endl;
        if (totalcursos > 0) {
            for (i = 1; i <= totalcursos; ++i) {
                if (activo[i-1] == 1) {
                    cout << "Curso: " << cursos[i-1] << " | Catedratico: " << catedraticos[i-1] << " | Cupos disponibles: " << cupos[i-1] << endl;
                    hayactivos = true;
                }
            }
        }
        if (!hayactivos) {
            cout << "No hay cursos activos." << endl;
        }
    }

    void dardebajauncurso() {
        bool encontrado;
        int i;
        int j;
        string nombre;
        encontrado = false;
        cout << "Ingrese nombre del curso a dar de baja:" << endl;
        cin >> nombre;
        if (totalcursos > 0) {
            for (i = 1; i <= totalcursos; ++i) {
                if (cursos[i-1] == nombre && activo[i-1] == 1) {
                    activo[i-1] = 0;
                    encontrado = true;
                    cout << "Curso dado de baja." << endl;
                    if (totalinscripciones > 0) {
                        for (j = 1; j <= totalinscripciones; ++j) {
                            if (cursosinscritos[j-1] == nombre) {
                                inscripciones[j-1] = "";
                                cursosinscritos[j-1] = "";
                            }
                        }
                    }
                    cout << "Curso dado de baja exitosamente." << endl;
                }
            }
        }
        if (!encontrado) {
            cout << "Curso no encontrado o inactivo." << endl;
        }
    }
};

int main() {
    GestionCursos gestion;
    string opcion;
    do {
        cout << "1. Registrar curso" << endl;
        cout << "2. Asignar catedratico a curso" << endl;
        cout << "3. Inscribirse a curso" << endl;
        cout << "4. Consultar cursos activos" << endl;
        cout << "5. Dar de baja un curso" << endl;
        cout << "6. Salir" << endl;
        cin >> opcion;
        if (opcion == "1") {
            gestion.registrarcurso();
        } else if (opcion == "2") {
            gestion.asignarcatedratico();
        } else if (opcion == "3") {
            gestion.inscribirseacurso();
        } else if (opcion == "4") {
            gestion.consultarcursosactivos();
        } else if (opcion == "5") {
            gestion.dardebajauncurso();
        } else if (opcion == "6") {
            cout << "Haz salido del sistema" << endl;
        } else {
            cout << "Opcion no valida." << endl;
        }
    } while (opcion != "6");
    return 0;
}
