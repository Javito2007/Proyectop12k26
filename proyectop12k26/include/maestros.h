#ifndef MAESTROS_H
#define MAESTROS_H

#include <string>
using namespace std;

class Maestros {
private:
    string nombre;
    string apellido;
    string correo;
    int codigo;
    string horario;
    string sede;
    int diasSemana;
    int horasClase;


public:
    Maestros();

    void ingresarDatosPersonales();
    void generarCorreo();
    void generarCodigo();
    void asignarCurso();
    void asignarHorario();
    double calcularSalario();
    bool verificarCodigo(int codigoIngresado);
    void mostrarResultados();

    int getCodigo();
    string getNombreCurso();
};

#endif
