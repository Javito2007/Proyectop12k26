// creado por Juan Jolon
#include "menuNotas.h"
#include <iostream>
using namespace std;

void SistemaNotas::ejecutarMenu() {
    int opcion;

    // Bucle principal del men� del sistema
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

        // Ejecuta la opci�n seleccionada por el usuario
        switch (opcion) {
            case 1:
                // Configuraci�n del curso y evaluaci�n
                config = ConfiguracionEvaluacion();
                config.seleccionarCurso();
                config.configurarPeriodo();
                config.almacenarConfiguracion();
                break;

            case 2:
                // Selecci�n de alumnos para el curso actual
                // Filtra automaticamente por curso usando Asignaciones.txt y Alumnos.txt
                registro = RegistrarNotas();
                registro.seleccionarAlumnosPorCurso(config.getCodigoCurso());
                break;

            case 3:
                registro.ingresarNotas(config);
                break;

            case 4:
                registro.almacenarNotas(usuarioActivo);
                break;

            case 5:
                reporte.acceder();
                break;

            case 6:
                reporte.buscarPorCarnet();
                break;

            case 7:
                reporte.actualizar();
                break;

            case 8:
                reporte.borrar();
                break;

            case 9:
                cout << "\nCerrando sistema. Hasta luego." << endl;
                break;

            default:
                cout << "\nOpcion invalida." << endl;
        }
    } while (opcion != 9);
}
