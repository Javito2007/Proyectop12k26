//Creado por Fernando Castillo - 9959 - 25 - 288
#include "Alumnos.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <thread>
#include <chrono>
using namespace std;

//Constructor
Alumnos::Alumnos()
{
    //inicializar varibles
    this -> nombreAlumno = "";
    this -> apellidoAlumno = "";
    this -> diaNacimiento = 0;
    this -> mesNacimiento = 0;
    this -> anioNacimiento = 0;
    this -> numeroDpi = "";
    this -> correoPersonal = "";
    this -> fechaNacimientoAlumno = "";
    this -> carnetPersonal = "";
    this -> sexoAlumno = "";
}


//Constructor sobrecargado
Alumnos::Alumnos(string nombreAlumno,string apellidoAlumno, string sexoAlumno, string numeroDpi, string correoPersonal, string carnetPersonal)
{
    this -> nombreAlumno = nombreAlumno;
    this -> apellidoAlumno = apellidoAlumno;
    this -> sexoAlumno = sexoAlumno;
    //this -> diaNacimiento = diaNacimiento;
    //this -> mesNacimiento = mesNacimiento;
    //this -> anioNacimiento = anioNacimiento;
    this -> numeroDpi = numeroDpi;
    this -> correoPersonal = correoPersonal;
    this -> carnetPersonal = carnetPersonal;
}

//Menu registro
void Alumnos::menuRegistro()
{
    int opcionCarrera;
    do{
        system("cls");
        cout << "--- Seleccione la Carrera ---" << endl;
        cout << "1. Ingenieria en Sistemas" << endl;
        cout << "2. Ingenieria Industrial" << endl;
        cout << "3. Derecho" << endl;
        cout << "4. Administracion de Empresa" << endl;
        cout << "5. Ingenieria Civil" << endl;
        cout << "¿Que carrera desea escoger?:" << endl;
        cin >> opcionCarrera;
        cin.ignore(1000, '\n');
        if (opcionCarrera < 1 || opcionCarrera > 5){
            cout << "Error. escoga una carrera (1-5)" << endl;
            this_thread::sleep_for(chrono::seconds(2));
        }
    }while (!(opcionCarrera >= 1 && opcionCarrera <= 5));

    switch (opcionCarrera){
        case 1:
            registroDatos();
            creaCorreoPersonal();
            crearCarnetPersonal();
            system("cls");
            cout << "--- Universidad UMG - Registro Exitoso ---" << endl;
            cout << "Alumno: " << this -> getnombreAlumno() << " " << this -> getapellidoAlumno() << endl;
            cout << "Carnet: " << this -> getcarnetPersonal() << endl;
            cout << "Correo: " << this -> getcorreoPersonal() << endl;
            break;
}


}

//Obtner los datos ingresados por el usuario
void Alumnos::registroDatos()
{
    bool validarInformacion;
    char confirmarDatos;
    do{
        do{
            system("cls");
            cout << "Ingrese sus nombres: " << endl;
            //cout << "Codigo: " << Alumnos::CODIGO_ING_SISTEMA << endl;
            getline(cin, this -> nombreAlumno);
            if (this -> nombreAlumno == ""){
                cout << "Error, el nombre no puede ir vacio" << endl;
                this_thread::sleep_for(chrono::seconds(2));
            }
        }while (this -> nombreAlumno == "");

        do{
            system("cls");
            cout << "Ingrese sus apellidos: " << endl;
            getline(cin, this -> apellidoAlumno);
            if (this -> apellidoAlumno == ""){
                cout << "Error, el apellido no puede ir vacio" << endl;
                this_thread::sleep_for(chrono::seconds(2));
            }
        }while (this -> apellidoAlumno == "");

        do{
            system("cls");
            cout << "Ingrese su sexo (Hombre/Mujer): " << endl;
            getline(cin, this -> sexoAlumno);
            if (this -> sexoAlumno == ""){
                cout << "Error, el apellido no puede ir vacio" << endl;
                this_thread::sleep_for(chrono::seconds(2));
            }
        }while (this -> sexoAlumno == "");


        do{
            system("cls");
            cout << "Ingrese su numero de DPI: " << endl;
            getline(cin, this -> numeroDpi);
            if (this -> numeroDpi.size() != 13){
                cout << "Error, su numero de DPI tiene que tener 13 digitos" << endl;
                validarInformacion = false;
            }else{
                validarInformacion = true;
            }

            if (!validarInformacion){
                this_thread::sleep_for(chrono::seconds(2));
            }
        }while (validarInformacion != true);

         do{
            system("cls");
            cout << "Ingrese su dia de nacimiento: " << endl;
            cin >> this -> diaNacimiento;
            if (this -> diaNacimiento < 1 || this -> diaNacimiento > 31){
                cout << "Error, dia no valido" << endl;
                this_thread::sleep_for(chrono::seconds(2));
            }
        }while (!(this -> diaNacimiento >= 1 && this -> diaNacimiento <= 31));

        do{
            system("cls");
            cout << "Ingrese su mes de nacimiento (1-12): " << endl;
            cin >> this -> mesNacimiento;
            if (this -> mesNacimiento < 1 || this -> mesNacimiento > 12){
                cout << "Error, mes no valido" << endl;
                this_thread::sleep_for(chrono::seconds(2));
            }
        }while (!(this -> mesNacimiento >= 1 && this -> mesNacimiento <= 12));

        do{
            system("cls");
            cout << "Ingrese su año de nacimiento (1940-2009): " << endl;
            cin >> this -> anioNacimiento;
            if (this -> anioNacimiento < 1940 || this -> anioNacimiento > 2009){
                cout << "Error, año no valido" << endl;
                this_thread::sleep_for(chrono::seconds(2));
            }
        }while (!(this -> anioNacimiento >= 1940 && this -> anioNacimiento <= 2009));

        obtenerFechaNacimiento();

        system("cls");
        cout << "--- Datos Personales ---" << endl;
        cout << "Nombres: " << this -> getnombreAlumno() << endl;
        cout << "Apellidos: " << this -> getapellidoAlumno() << endl;
        cout << "DPI: " << this -> getnumeroDpi() << endl;
        cout << "Fecha Nacimiento: " << this -> getfechaNacimientoAlumno() << endl;
        cout << "¿Los datos son correctos (S/N)?: " << endl;
        cin >> confirmarDatos;
        cin.ignore(1000, '\n');

    }while (confirmarDatos == 'n' || confirmarDatos == 'N');

    cout << "Verificando datos... por favor espere." << endl;
	this_thread::sleep_for(chrono::seconds(2));
	cout << "Generando carnet..." << endl;
	this_thread::sleep_for(chrono::seconds(2));
	cout << "Generando correo..." << endl;
	this_thread::sleep_for(chrono::seconds(2));
}

//Obtiene la fecha completa del alumno
void Alumnos::obtenerFechaNacimiento()
{
    this -> fechaNacimientoAlumno = to_string(this -> diaNacimiento) + "/" + to_string(this -> mesNacimiento) + "/" + to_string(this -> anioNacimiento);
}

//Genera correo personal
void Alumnos::creaCorreoPersonal()
{
    size_t i = 0;
    string nombreInicial = "";
    int numAleatorioCorreo = numeroAleatorio(100, 2000);
    string primerApellido = "";
    nombreInicial = this -> nombreAlumno.substr(0, 1);
    while ( i < this -> apellidoAlumno.size() && this -> apellidoAlumno[i] != ' '){
        primerApellido += this -> apellidoAlumno[i];
        i++;
    }
    this -> correoPersonal = nombreInicial + primerApellido + to_string(numAleatorioCorreo) + "@miumg.edu.gt";

    //Un ciclo for para crear el correo en minusculas
    for (size_t j = 0 ; j < this -> correoPersonal.length(); j++){
        this -> correoPersonal[j] = tolower(this -> correoPersonal[j]);
    }
}

//Genera Carnet Personal
void Alumnos::crearCarnetPersonal()
{
    int numAleatorio =  numeroAleatorio(100, 2000);
    this -> carnetPersonal = to_string(this -> CODIGO_ING_SISTEMA) + "-" + to_string(obtenerAnioCorto()) + "-" + to_string(numAleatorio);
}

//Genera numeros Aleatorios
int Alumnos::numeroAleatorio(int minimo, int maximo)
{
    return minimo + rand() % (maximo - minimo + 1);
}

//Recorta el año 2026 a 26 para el carnet
int Alumnos::obtenerAnioCorto()
{
    return this -> ANIO_ACTUAL % 100;
}

//Getters
string Alumnos::getnombreAlumno()
{
    return this -> nombreAlumno;
}
string Alumnos::getapellidoAlumno()
{
    return this -> apellidoAlumno;
}
string Alumnos::getsexoAlumno()
{
    return this -> sexoAlumno;
}
int Alumnos::getdiaNacimiento()
{
    return this -> diaNacimiento;
}
string Alumnos::getnumeroDpi()
{
    return this -> numeroDpi;
}
int Alumnos::getmesNacimiento()
{
    return this -> mesNacimiento;
}
int Alumnos::getanioNacimiento()
{
    return this -> anioNacimiento;
}
string Alumnos::getcorreoPersonal()
{
    return this -> correoPersonal;
}

string Alumnos::getfechaNacimientoAlumno()
{
    return this -> fechaNacimientoAlumno;
}
string Alumnos::getcarnetPersonal()
{
    return this -> carnetPersonal;
}
//Setters
void Alumnos::setnombreAlumno(string nombreAlumno)
{
    this -> nombreAlumno = nombreAlumno;
}
void Alumnos::setapellidoAlumno(string apellidoAlumno)
{
    this -> apellidoAlumno = apellidoAlumno;
}
void Alumnos::setsexoAlumno(string sexoAlumno)
{
    this -> sexoAlumno = sexoAlumno;
}
void Alumnos::setdiaNacimiento(int diaNacimiento)
{
    this -> diaNacimiento = diaNacimiento;
}
void Alumnos::setmesNacimiento(int mesNacimiento)
{
    this -> mesNacimiento = mesNacimiento;
}
void Alumnos::setanioNacimiento(int anioNacimiento)
{
    this -> anioNacimiento = anioNacimiento;
}
void Alumnos::setnumeroDpi(string numeroDpi)
{
    this -> numeroDpi = numeroDpi;
}
void Alumnos::setcorreoPersonal(string correoPersonal)
{
    this -> correoPersonal = correoPersonal;
}
void Alumnos::setfechaNacimientoAlumno(string fechaNacimientoAlumno)
{
    this -> fechaNacimientoAlumno = fechaNacimientoAlumno;
}
void Alumnos::setcarnetPersonal(string carnetPersonal)
{
    this -> carnetPersonal = carnetPersonal;
}
