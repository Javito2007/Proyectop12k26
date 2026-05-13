#include "respaldo.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <ctime>

using namespace std;

// Configuración de nombres de archivos
const string TXT_ASIGNACIONES = "Asignaciones.txt";
const string TXT_CREDITO      = "tarjetacredito.txt";
const string TXT_DEBITO       = "tarjetadebito.txt";
const string ARCHIVO_FINAL    = "Respaldo.txt";

// Función para obtener estampa de tiempo
string obtenerFechaHora() {
    time_t t = time(nullptr);
    tm tm = *localtime(&t);
    ostringstream oss;
    oss << put_time(&tm, "%d/%m/%Y %H:%M:%S");
    return oss.str();
}

// Guarda la información en el archivo final (lo crea si no existe)
void registrarEnBitacora(const RegistroBitacora &reg) {
    ofstream archivo(ARCHIVO_FINAL, ios::app);
    if (archivo.is_open()) {
        archivo << "[" << obtenerFechaHora() << "] "
                << "Carnet: " << reg.carnet << " | "
                << "Carrera/Curso: " << reg.curso << " | "
                << "Accion: " << reg.accion << "\n";
        archivo.close();
    }
}

// Función especial para procesar el formato visual de Asignaciones
bool leerYProcesarAsignaciones(string nombreArchivo) {
    ifstream archivoIn(nombreArchivo);
    if (!archivoIn.is_open()) return false;

    string linea;
    string carnetFijo = "9959-26-1159"; // Extraído del formato de tu compañero

    while (getline(archivoIn, linea)) {
        // Ignorar líneas vacías, decoraciones o encabezados
        if (linea.empty() ||
            linea.find("==") != string::npos ||
            linea.find("--") != string::npos ||
            linea.find("REGISTRO") != string::npos ||
            linea.find("CODIGO") != string::npos ||
            linea.find("Cursos:") != string::npos) {
            continue;
        }

        // Si la línea tiene el separador '|', es un curso real
        if (linea.find("|") != string::npos) {
            stringstream ss(linea);
            string codigo, nombreCurso;

            getline(ss, codigo, '|'); // Todo antes del |
            getline(ss, nombreCurso); // Todo después del |

            // Limpieza de espacios en blanco (Trim)
            codigo.erase(0, codigo.find_first_not_of(" \t"));
            codigo.erase(codigo.find_last_not_of(" \t") + 1);
            nombreCurso.erase(0, nombreCurso.find_first_not_of(" \t"));
            nombreCurso.erase(nombreCurso.find_last_not_of(" \t") + 1);

            RegistroBitacora aux;
            aux.carnet = carnetFijo;
            aux.curso = nombreCurso;
            aux.accion = "Asignado (Cod: " + codigo + ")";

            registrarEnBitacora(aux);
        }
    }
    archivoIn.close();
    return true;
}

// Para los cobros seguimos usando el formato CSV (Carnet,Curso,Accion)
bool leerYProcesarCobros(string nombreArchivo) {
    ifstream archivoIn(nombreArchivo);
    if (!archivoIn.is_open()) return false;
    string linea;
    while (getline(archivoIn, linea)) {
        if (linea.empty()) continue;
        stringstream ss(linea);
        RegistroBitacora aux;
        getline(ss, aux.carnet, ',');
        getline(ss, aux.curso, ',');
        getline(ss, aux.accion, ',');
        registrarEnBitacora(aux);
    }
    archivoIn.close();
    return true;
}

bool respaldarAsignaciones() { return leerYProcesarAsignaciones(TXT_ASIGNACIONES); }
bool respaldarCobroTarjeta() {
    bool c1 = leerYProcesarCobros(TXT_CREDITO);
    bool c2 = leerYProcesarCobros(TXT_DEBITO);
    return (c1 || c2);
}

void mostrarRespaldo() {
    ifstream archivo(ARCHIVO_FINAL);
    string linea;
    cout << "\n--- CONTENIDO DE BITACORA ACTUAL ---" << endl;
    if (!archivo.is_open()) { cout << "Archivo vacio o inexistente." << endl; return; }
    while (getline(archivo, linea)) cout << linea << endl;
    archivo.close();
}

void crearRegistroManual() {
    RegistroBitacora n;
    cout << "\n--- REGISTRO PASO A PASO ---" << endl;
    cout << "Carnet: "; cin >> n.carnet;
    cin.ignore();
    cout << "Nombre de Carrera/Curso: "; getline(cin, n.curso);
    cout << "Tipo de Accion: "; getline(cin, n.accion);
    registrarEnBitacora(n);
    cout << "Guardado con exito." << endl;
}

void eliminarRegistroPorCarnet() {
    string id;
    cout << "\nCarnet para eliminar: "; cin >> id;
    ifstream in(ARCHIVO_FINAL);
    ofstream out("Temp.txt");
    string linea;
    bool found = false;
    while (getline(in, linea)) {
        if (linea.find(id) == string::npos) out << linea << "\n";
        else found = true;
    }
    in.close(); out.close();
    remove(ARCHIVO_FINAL.c_str());
    rename("Temp.txt", ARCHIVO_FINAL.c_str());
    if (found) cout << "Eliminacion completada." << endl;
    else cout << "No se encontro el carnet." << endl;
}

void menuRespaldo() {
    int op;
    do {
        cout << "\n--- MENU DE RESPALDO Y AUDITORIA ---" << endl;
        cout << "1. Importar Asignaciones" << endl;
        cout << "2. Importar Cobros (TC/TD)" << endl;
        cout << "3. Ver Respaldo.txt" << endl;
        cout << "4. Registro Manual" << endl;
        cout << "5. Borrar por Carnet" << endl;
        cout << "0. Salir" << endl;
        cout << "Seleccion: ";
        cin >> op;

        if(op == 1) respaldarAsignaciones();
        else if(op == 2) respaldarCobroTarjeta();
        else if(op == 3) mostrarRespaldo();
        else if(op == 4) crearRegistroManual();
        else if(op == 5) eliminarRegistroPorCarnet();
    } while (op != 0);
}

// Main para ejecución directa
int main() {
    menuRespaldo();
    return 0;
}
