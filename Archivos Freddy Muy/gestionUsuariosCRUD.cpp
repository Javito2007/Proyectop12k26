#include<iostream>
#include<fstream>
#include<cstdlib>
#include<conio.h>
#include<iomanip>
using namespace std;

class GestionUsuarios {
public:
    // CRUD para la gestion de los usuaios
    void insertarUsuario() {
        system("cls");
        fstream file;
        string username, password, rol;
        cout << "\n------------------------------------------------------------------------------------------------------------------------";
        cout << "\n-------------------------------------- AGREGAR NUEVO USUARIO ---------------------------------------------------------" << endl;
        cout << "\t\t\tIngrese nombre de usuario: ";
        cin >> username;
        cout << "\t\t\tIngrese clave: ";
        cin >> password;
        cout << "\t\t\tIngrese rol (admin/usuario): ";
        cin >> rol;
        file.open("UsuariosSistema.txt", ios::app | ios::out);
        file << left << setw(15) << username << left << setw(15) << password << left << setw(10) << rol << left << setw(10) << 1 << "\n"; // 1 = activo
        file.close();
        cout << "\n\t\t\tUsuario registrado en archivo exitosamente." << endl;
    }

    void listarUsuarios() {
        system("cls");
        fstream file;
        int total = 0;
        string username, password, rol;
        int activo;
        cout << "\n------------------------- LISTADO DE USUARIOS -------------------------" << endl;
        file.open("UsuariosSistema.txt", ios::in);
        if (!file) {
            cout << "\n\t\t\tNo hay informacion...";
        } else {
            file >> username >> password >> rol >> activo;
            while (!file.eof()) {
                total++;
                cout << "\n\n\t\t\t Usuario   : " << username << endl;
                cout << "\t\t\t Clave     : " << password << endl;
                cout << "\t\t\t Rol       : " << rol << endl;
                cout << "\t\t\t Estado    : " << (activo == 1 ? "Activo" : "Desactivado") << endl;
                file >> username >> password >> rol >> activo;
            }
            if (total == 0) cout << "\n\t\t\tNo hay informacion...";
        }
        file.close();
    }

    void modificarUsuario() {
        system("cls");
        fstream file, file1;
        string searchUser;
        int found = 0;
        cout << "\n------------------------- MODIFICACION DE USUARIO -------------------------" << endl;
        file.open("UsuariosSistema.txt", ios::in);
        if (!file) {
            cout << "\n\t\t\tNo hay informacion...";
            file.close();
            return;
        }
        cout << "\n Ingrese el nombre de usuario que desea modificar: ";
        cin >> searchUser;
        file1.open("RecordUsuarios.txt", ios::app | ios::out);
        string username, password, rol;
        int activo;
        file >> username >> password >> rol >> activo;
        while (!file.eof()) {
            if (searchUser != username) {
                file1 << left << setw(15) << username << left << setw(15) << password << left << setw(10) << rol << left << setw(10) << activo << "\n";
            } else {
                cout << "\t\t\tIngrese nuevo nombre de usuario: ";
                cin >> username;
                cout << "\t\t\tIngrese nueva clave: ";
                cin >> password;
                cout << "\t\t\tIngrese nuevo rol (admin/usuario): ";
                cin >> rol;
                cout << "\t\t\tIngrese estado (1=Activo, 0=Desactivado): ";
                cin >> activo;
                file1 << left << setw(15) << username << left << setw(15) << password << left << setw(10) << rol << left << setw(10) << activo << "\n";
                found++;
            }
            file >> username >> password >> rol >> activo;
        }
        file1.close();
        file.close();
        remove("UsuariosSistema.txt");
        rename("RecordUsuarios.txt", "UsuariosSistema.txt");
        if (found > 0)
            cout << "\n\t\t\tUsuario modificado exitosamente." << endl;
        else
            cout << "\n\t\t\tUsuario no encontrado." << endl;
    }

    void buscarUsuario() {
        system("cls");
        fstream file;
        int found = 0;
        file.open("UsuariosSistema.txt", ios::in);
        if (!file) {
            cout << "\n------------------------- DATOS DEL USUARIO BUSCADO ------------------------" << endl;
            cout << "\n\t\t\tNo hay informacion...";
        } else {
            string searchUser;
            cout << "\n------------------------- DATOS DEL USUARIO BUSCADO ------------------------" << endl;
            cout << "\n Ingrese el nombre de usuario que quiere buscar: ";
            cin >> searchUser;
            string username, password, rol;
            int activo;
            file >> username >> password >> rol >> activo;
            while (!file.eof()) {
                if (searchUser == username) {
                    cout << "\n\n\t\t\t Usuario   : " << username << endl;
                    cout << "\t\t\t Clave     : " << password << endl;
                    cout << "\t\t\t Rol       : " << rol << endl;
                    cout << "\t\t\t Estado    : " << (activo == 1 ? "Activo" : "Desactivado") << endl;
                    found++;
                }
                file >> username >> password >> rol >> activo;
            }
            if (found == 0) cout << "\n\t\t\t Usuario no encontrado...";
            file.close();
        }
    }

    void eliminarUsuario() {
        system("cls");
        fstream file, file1;
        string deleteUser;
        int found = 0;
        cout << "\n------------------------- ELIMINAR USUARIO -------------------------" << endl;
        file.open("UsuariosSistema.txt", ios::in);
        if (!file) {
            cout << "\n\t\t\tNo hay informacion...";
            file.close();
            return;
        }
        cout << "\n Ingrese el nombre de usuario que desea borrar: ";
        cin >> deleteUser;
        file1.open("RecordUsuarios.txt", ios::app | ios::out);
        string username, password, rol;
        int activo;
        file >> username >> password >> rol >> activo;
        while (!file.eof()) {
            if (deleteUser != username) {
                file1 << left << setw(15) << username << left << setw(15) << password << left << setw(10) << rol << left << setw(10) << activo << "\n";
            } else {
                found++;
                cout << "\n\t\t\tUsuario eliminado exitosamente.";
            }
            file >> username >> password >> rol >> activo;
        }
        if (found == 0) cout << "\n\t\t\t Usuario no encontrado...";
        file1.close();
        file.close();
        remove("UsuariosSistema.txt");
        rename("RecordUsuarios.txt", "UsuariosSistema.txt");
    }

    void menuUsuarios() {
        int choice;
        char x;
        do {
            system("cls");
            cout << "\t\t\t-------------------------------" << endl;
            cout << "\t\t\t |    GESTION DE USUARIOS     |" << endl;
            cout << "\t\t\t-------------------------------" << endl;
            cout << "\t\t\t 1. Agregar Usuario" << endl;
            cout << "\t\t\t 2. Listar Usuarios" << endl;
            cout << "\t\t\t 3. Modificar Usuario" << endl;
            cout << "\t\t\t 4. Buscar Usuario" << endl;
            cout << "\t\t\t 5. Eliminar Usuario" << endl;
            cout << "\t\t\t 6. Salir" << endl;
            cout << "\t\t\t-------------------------------" << endl;
            cout << "Ingresa tu Opcion: ";
            cin >> choice;

            switch (choice) {
                case 1:
                    do {
                        insertarUsuario();
                        cout << "\n\t\t\t Agregar otro usuario? (Y/N): ";
                        cin >> x;
                    } while (x == 'y' || x == 'Y');
                    break;
                case 2:
                    listarUsuarios();
                    break;
                case 3:
                    modificarUsuario();
                    break;
                case 4:
                    buscarUsuario();
                    break;
                case 5:
                    eliminarUsuario();
                    break;
                case 6:
                    cout << "\n\t\t\tSaliendo del sistema de usuarios..." << endl;
                    return;
                default:
                    cout << "\n\t\t\t Opcion invalida...";
            }
            getch();
        } while (choice != 6);
    }
};

int main() {
    GestionUsuarios usuarios;
    usuarios.menuUsuarios();
    return 0;
}
