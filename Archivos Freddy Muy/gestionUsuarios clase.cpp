#include<iostream>
using namespace std;

using SIN_TIPO = string;

class GestionUsuarios {
private:
    SIN_TIPO usuarios[100];
    SIN_TIPO claves[100];
    string roles[100];
    float activo[100];
    int totalusuarios;

public:
    GestionUsuarios() {
        totalusuarios = 0;
    }

    void registrarusuario() {
        totalusuarios = totalusuarios + 1;
        cout << "Ingrese nombre de usuario:" << endl;
        cin >> usuarios[totalusuarios-1];
        cout << "Ingrese clave:" << endl;
        cin >> claves[totalusuarios-1];
        roles[totalusuarios-1] = "usuario";
        activo[totalusuarios-1] = 1;
        cout << "Usuario registrado exitosamente." << endl;
    }

    void autenticarusuario() {
        string clave;
        bool encontrado;
        int i;
        string nombre;
        encontrado = false;
        cout << "Ingrese nombre de usuario:" << endl;
        cin >> nombre;
        cout << "Ingrese clave:" << endl;
        cin >> clave;
        for (i = 1; i <= totalusuarios; ++i) {
            if (usuarios[i-1] == nombre && claves[i-1] == clave && activo[i-1] == 1) {
                cout << "Autenticacion exitosa." << endl;
                encontrado = true;
            }
        }
        if (!encontrado) {
            cout << "Usuario/clave incorrectos o usuario desactivado." << endl;
        }
    }

    void asignarrol() {
        bool encontrado;
        int i;
        string nombre;
        string nuevorol;
        encontrado = false;
        cout << "Ingrese nombre de usuario:" << endl;
        cin >> nombre;
        cout << "Ingrese nuevo rol (admin/usuario):" << endl;
        cin >> nuevorol;
        for (i = 1; i <= totalusuarios; ++i) {
            if (usuarios[i-1] == nombre) {
                roles[i-1] = nuevorol;
                cout << "Rol asignado correctamente." << endl;
                encontrado = true;
            }
        }
        if (!encontrado) {
            cout << "Usuario no encontrado." << endl;
        }
    }

    void modificarusuario() {
        bool encontrado;
        int i;
        string nombre;
        string nuevaclave;
        int opcion;
        encontrado = false;
        cout << "Ingrese nombre de usuario a modificar:" << endl;
        cin >> nombre;
        for (i = 1; i <= totalusuarios; ++i) {
            if (usuarios[i-1] == nombre) {
                encontrado = true;
                cout << "1. Cambiar clave" << endl;
                cout << "2. Desactivar usuario" << endl;
                cout << "3. Reactivar usuario" << endl;
                cin >> opcion;
                if (opcion == 1) {
                    cout << "Ingrese nueva clave:" << endl;
                    cin >> nuevaclave;
                    claves[i-1] = nuevaclave;
                    cout << "Clave actualizada." << endl;
                } else if (opcion == 2) {
                    activo[i-1] = 0;
                    cout << "Usuario desactivado." << endl;
                } else if (opcion == 3) {
                    activo[i-1] = 1;
                    cout << "Usuario reactivado." << endl;
                } else {
                    cout << "Opcion no valida." << endl;
                }
            }
        }
        if (!encontrado) {
            cout << "Usuario no encontrado." << endl;
        }
    }

    void mostrarusuarios() {
        string estado;
        int i;
        cout << "----- LISTA DE USUARIOS -----" << endl;
        for (i = 1; i <= totalusuarios; ++i) {
            if (activo[i-1] == 1) {
                estado = "Activo";
            } else {
                estado = "Desactivado";
            }
            cout << "Usuario: " << usuarios[i-1] << " | Rol: " << roles[i-1] << " | Estado: " << estado << endl;
        }
    }
};

int main() {
    GestionUsuarios gestion;
    string opcion;
    do {
        cout << "1. Registrar usuario" << endl;
        cout << "2. Autenticar usuario" << endl;
        cout << "3. Asignar rol" << endl;
        cout << "4. Modificar/Desactivar/Reactivar usuario" << endl;
        cout << "5. Mostrar usuarios" << endl;
        cout << "6. Salir" << endl;
        cin >> opcion;
        if (opcion == "1") {
            gestion.registrarusuario();
        } else if (opcion == "2") {
            gestion.autenticarusuario();
        } else if (opcion == "3") {
            gestion.asignarrol();
        } else if (opcion == "4") {
            gestion.modificarusuario();
        } else if (opcion == "5") {
            gestion.mostrarusuarios();
        } else if (opcion == "6") {
            cout << "Haz salido del sistema" << endl;
        } else {
            cout << "Opcion no valida." << endl;
        }
    } while (opcion != "6");
    return 0;
}
