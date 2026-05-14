#include "ModuloPagos.h"
#include "validacionpagos0.h"
//#include "validacionpagos0.cpp"
#include <iostream>
#include <iomanip>
using namespace std;

void ModuloPagos::ejecutar()
{
    double resultado = 1020.00;
    int opcion;
    int opcion2;
    int numeroT;
    string nombrealumno;
    string date;
    int codseguro;

    validacionpagos0 asignaciones; //primer objeto de la clase
    // se usan las funciones en los objetos

    asignaciones.cargarCursosDesdeArchivo("Asignaciones.txt");
do {
    system("cls");
   cout <<"---ASIGNACION DE CURSOS---" << endl;
   cout <<"1.Cursos asignados y tu carnet" << endl;
   cout <<"2.Pagar colegiatura" << endl;
   cout <<"3.Volver al Menu Principal"<<endl;
   cout <<"Seleccione una opcion: ";
   cin >> opcion;

    system("cls");
     if(opcion == 1) {
        asignaciones.informaciondecursos();
     } else if(opcion ==2){
        cout << endl << "Total a pagar es de: Q" << resultado << endl;
        cout << "Puedes pagar de la manera que prefieras,escoge debito o credito: " << endl;
        cout << "1. Debito" << endl;
        cout <<"2. Credito" << endl;
        cin >> opcion2;
        system("cls");
        asignaciones.tipodePago(opcion2,numeroT,nombrealumno,date,codseguro);
        cout <<"\nAbriendo el panel de gestion de pagos..."<<endl;
        asignaciones.menuGestionPagos(numeroT, opcion2);
     }
     else if(opcion == 3){
        cout<<"Regresando al menu principal..."<<endl;

     }
     else{
        cout <<"Opcion invalida. Intente de nuevo." <<endl;
        system("pause");
     }
} while(opcion !=3);
     // return 0;
}
