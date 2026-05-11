<<<<<<< HEAD
// Este trabajo fue realizado por 9959-25-4900: Jhonny Flores el día 4 de mayo de 2026
=======
//Creado por el alumno 9959-25-4900: Jhonny Flores el día 4 de mayo de 2026
>>>>>>> 681a2b0eeace5d3189fbaadd9e890b00214e2ed0

#ifndef REPORTES_H
#define REPORTES_H

#include <string>
#include <fstream>
using namespace std;

class reportes {
private:
    // Archivo donde se guardan los reportes
    const string ARCHIVO = "Reportes.txt";
    const char   SEP     = '|';

    // Convierte float a string
    string floatAString(float v);

public:
    // Llamado desde RegistrarNotas — no pide datos por teclado
    void generarDesdeNota(const string& carnet, const string& nombre,
                          float p1,    float p2,  float tareas,
                          float zona,  float examenFinal,
                          float notaFinal, const string& estado);

    void acceder();         // Read   — ver todos los registros
    void buscarPorCarnet(); // Read   — buscar uno especifico
    void actualizar();      // Update — modificar un registro
    void borrar();          // Delete — eliminar un registro
};

#endif
