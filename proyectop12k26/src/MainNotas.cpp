#include "SistemaNotas.h"    //Juan Jolon 9959-25-6194 y Jose Javier 9959-25-7728
#include <iostream>
using namespace std;

bool SistemaNotas::iniciar() {
    if (!sesion.loginUsuarios()) { //verifica si el usuario puede iniciar sesion
        cout << "Acceso denegado. Cerrando sistema." << endl;
        return false;
    }
    //Guarda nombre de usuario activo
    usuarioActivo = sesion.getNombre();

    //Almacena cantidad de alumnos
    int cantAlumnos;
    cout << "\n¿Cuantos alumnos desea registrar en el sistema? ";
    cin >> cantAlumnos;
    cin.ignore();

    for (int i = 0; i < cantAlumnos; i++) {
        Alumnos a;
        a.menuRegistro();
        cin.clear();
        cin.ignore(1000, '\n');
        listaAlumnos.push_back(a);
    }
    return true;
}

void SistemaNotas::ejecutarMenu() {
    int opcion;
    do {
        cout << "   SISTEMA DE GESTION DE NOTAS"         << endl;
        cout << "   Usuario: " << usuarioActivo           << endl;
        cout << "-------------------------------------"   << endl;
        cout << "  1. Configurar curso"                   << endl;
        cout << "  2. Seleccionar alumnos del curso"      << endl;
        cout << "  3. Ingresar notas"                     << endl;
        cout << "  4. Guardar y ver reporte"              << endl;
        cout << "  5. Consultar todos los reportes"       << endl;
        cout << "  6. Buscar nota por carnet"             << endl;
        cout << "  7. Modificar nota"                     << endl;
        cout << "  8. Eliminar nota"                      << endl;
        cout << "  9. Salir"                              << endl;
        cout << "--------------------------------------"   << endl;
        cout << "  Opcion: ";
        cin >> opcion;
        cin.ignore();

        switch (opcion) {
            case 1:
                config = ConfiguracionEvaluacion();
                config.seleccionarCurso();
                config.configurarPeriodo();
                config.almacenarConfiguracion();
                break;
            case 2:
                registro = RegistrarNotas();
                registro.seleccionarAlumnos(listaAlumnos);
                break;
            case 3:  registro.ingresarNotas(config);            break;
            case 4:  registro.almacenarNotas(usuarioActivo);    break;
            case 5:  reporte.acceder();                         break;
            case 6:  reporte.buscarPorCarnet();                 break;
            case 7:  reporte.actualizar();                      break;
            case 8:  reporte.borrar();                          break;
            case 9:  cout << "\nCerrando sistema. Hasta luego." << endl; break;
            default: cout << "\nOpcion invalida." << endl;
        }
    } while (opcion != 9);
}


#include "SistemaNotas.h"

int main() {
    SistemaNotas sistema;
    if (!sistema.iniciar()) return 1;
    sistema.ejecutarMenu();
    return 0;
}
