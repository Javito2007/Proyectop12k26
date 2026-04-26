#include <iostream>
#include "Carrera.h"
#include "Inscipcion.h"

using namespace std;

int main()
{
    int opcion;

    do
    {
        cout << "\n===== MENU PRINCIPAL UNIVERSIDAD MARIANO GALVEZ =====" << endl;
        cout << "1. Carreras" << endl;
        cout << "2. Inscripcion" << endl;
        cout << "3. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch(opcion)
        {
            case 1:
            {
                Carreras c1;
                c1.ingresarDatos();
                c1.mostrarDatos();
                break;
            }

            case 2:
            {
                Inscripcion i1;
                i1.ingresarDatos();
                i1.mostrarDatos();
                break;
            }

            case 3:
                cout << "Saliendo del sistema..." << endl;
                break;

            default:
                cout << "Opcion invalida." << endl;
        }

    } while(opcion != 3);

    return 0;
}
