#ifndef RESPALDO_H
#define RESPALDO_H

#include <string>

// Estructura de datos para los registros
struct RegistroBitacora {
    std::string carnet;
    std::string curso;
    std::string accion;
};

// Declaración de funciones del módulo
void menuRespaldo();
bool respaldarAsignaciones();
bool respaldarCobroTarjeta();
void mostrarRespaldo();
void crearRegistroManual();
void eliminarRegistroPorCarnet();
void registrarEnBitacora(const RegistroBitacora &reg);
std::string obtenerFechaHora();

#endif
