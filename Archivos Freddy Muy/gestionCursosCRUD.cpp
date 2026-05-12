#include<iostream>
#include<fstream>
#include<cstdlib>
#include<conio.h>
#include<iomanip>
#include<sstream>
using namespace std;

class GestionCursos {
public:
    // CRUD para los cursos
    void insertarCurso() {
        system("cls");
        fstream file;
        string nombreCurso, catedratico;
        int cupo;
        cout << "\n------------------------------------------------------------------------------------------------------------------------";
        cout << "\n-------------------------------------- AGREGAR NUEVO CURSO ------------------------------------------------------------" << endl;
        cout << "\t\t\tIngrese nombre del curso: ";
        cin >> nombreCurso;
        cout << "\t\t\tIngrese cupo maximo: ";
        cin >> cupo;
        cout << "\t\t\tIngrese nombre del catedratico: ";
        cin >> catedratico;
        file.open("Cursos.txt", ios::app | ios::out);
        file << left << setw(20) << nombreCurso << left << setw(10) << cupo << left << setw(20) << catedratico << left << setw(10) << 1 << "\n"; // 1 = activo
        file.close();
        cout << "\n\t\t\tCurso registrado en archivo exitosamente." << endl;
    }

    void listarCursos() {
        system("cls");
        fstream file;
        int total = 0;
        string nombreCurso, catedratico;
        int cupo, activo;
        cout << "\n------------------------- LISTADO DE CURSOS -------------------------" << endl;
        file.open("Cursos.txt", ios::in);
        if (!file) {
            cout << "\n\t\t\tNo hay informacion...";
        } else {
            file >> nombreCurso >> cupo >> catedratico >> activo;
            while (!file.eof()) {
                total++;
                cout << "\n\n\t\t\t Nombre Curso  : " << nombreCurso << endl;
                cout << "\t\t\t Cupo maximo   : " << cupo << endl;
                cout << "\t\t\t Catedratico   : " << catedratico << endl;
                cout << "\t\t\t Estado        : " << (activo == 1 ? "Activo" : "Inactivo") << endl;
                file >> nombreCurso >> cupo >> catedratico >> activo;
            }
            if (total == 0) cout << "\n\t\t\tNo hay informacion...";
        }
        file.close();
    }

    void modificarCurso() {
        system("cls");
        fstream file, file1;
        string searchName;
        int found = 0;
        cout << "\n------------------------- MODIFICACION DE CURSO -------------------------" << endl;
        file.open("Cursos.txt", ios::in);
        if (!file) {
            cout << "\n\t\t\tNo hay informacion...";
            file.close();
            return;
        }
        cout << "\n Ingrese el nombre del curso que desea modificar: ";
        cin >> searchName;
        file1.open("RecordCursos.txt", ios::app | ios::out);
        string nombreCurso, catedratico;
        int cupo, activo;
        file >> nombreCurso >> cupo >> catedratico >> activo;
        while (!file.eof()) {
            if (searchName != nombreCurso) {
                file1 << left << setw(20) << nombreCurso << left << setw(10) << cupo << left << setw(20) << catedratico << left << setw(10) << activo << "\n";
            } else {
                cout << "\t\t\tIngrese nuevo nombre del curso: ";
                cin >> nombreCurso;
                cout << "\t\t\tIngrese nuevo cupo maximo: ";
                cin >> cupo;
                cout << "\t\t\tIngrese nuevo catedratico: ";
                cin >> catedratico;
                cout << "\t\t\tIngrese estado (1=Activo, 0=Inactivo): ";
                cin >> activo;
                file1 << left << setw(20) << nombreCurso << left << setw(10) << cupo << left << setw(20) << catedratico << left << setw(10) << activo << "\n";
                found++;
            }
            file >> nombreCurso >> cupo >> catedratico >> activo;
        }
        file1.close();
        file.close();
        remove("Cursos.txt");
        rename("RecordCursos.txt", "Cursos.txt");
        if (found > 0)
            cout << "\n\t\t\tCurso modificado exitosamente." << endl;
        else
            cout << "\n\t\t\tCurso no encontrado." << endl;
    }

    void buscarCurso() {
        system("cls");
        fstream file;
        int found = 0;
        file.open("Cursos.txt", ios::in);
        if (!file) {
            cout << "\n------------------------- DATOS DEL CURSO BUSCADO ------------------------" << endl;
            cout << "\n\t\t\tNo hay informacion...";
        } else {
            string searchName;
            cout << "\n------------------------- DATOS DEL CURSO BUSCADO ------------------------" << endl;
            cout << "\n Ingrese el nombre del curso que quiere buscar: ";
            cin >> searchName;
            string nombreCurso, catedratico;
            int cupo, activo;
            file >> nombreCurso >> cupo >> catedratico >> activo;
            while (!file.eof()) {
                if (searchName == nombreCurso) {
                    cout << "\n\n\t\t\t Nombre Curso  : " << nombreCurso << endl;
                    cout << "\t\t\t Cupo maximo   : " << cupo << endl;
                    cout << "\t\t\t Catedratico   : " << catedratico << endl;
                    cout << "\t\t\t Estado        : " << (activo == 1 ? "Activo" : "Inactivo") << endl;
                    found++;
                }
                file >> nombreCurso >> cupo >> catedratico >> activo;
            }
            if (found == 0) cout << "\n\t\t\t Curso no encontrado...";
            file.close();
        }
    }

    void eliminarCurso() {
        system("cls");
        fstream file, file1;
        string deleteName;
        int found = 0;
        cout << "\n------------------------- ELIMINAR CURSO -------------------------" << endl;
        file.open("Cursos.txt", ios::in);
        if (!file) {
            cout << "\n\t\t\tNo hay informacion...";
            file.close();
            return;
        }
        cout << "\n Ingrese el nombre del curso que desea borrar: ";
        cin >> deleteName;
        file1.open("RecordCursos.txt", ios::app | ios::out);
        string nombreCurso, catedratico;
        int cupo, activo;
        file >> nombreCurso >> cupo >> catedratico >> activo;
        while (!file.eof()) {
            if (deleteName != nombreCurso) {
                file1 << left << setw(20) << nombreCurso << left << setw(10) << cupo << left << setw(20) << catedratico << left << setw(10) << activo << "\n";
            } else {
                found++;
                cout << "\n\t\t\tCurso eliminado exitosamente.";
            }
            file >> nombreCurso >> cupo >> catedratico >> activo;
        }
        if (found == 0) cout << "\n\t\t\t Curso no encontrado...";
        file1.close();
        file.close();
        remove("Cursos.txt");
        rename("RecordCursos.txt", "Cursos.txt");
    }

// inscribir a los estudiantes
    void inscribirEstudiante() {
        system("cls");
        string nombreEstudiante, nombreCurso;
        cout << "\n------------------------- INSCRIPCION A CURSO -------------------------" << endl;
        cout << "Ingrese nombre del estudiante: ";
        cin >> nombreEstudiante;
        cout << "Ingrese nombre del curso: ";
        cin >> nombreCurso;

        // Verificacion del curso, actividad, cupos etc
        fstream fileCurso("Cursos.txt", ios::in);
        if (!fileCurso) {
            cout << "\n\t\t\tError: No se pudo abrir el archivo de cursos." << endl;
            return;
        }

        bool cursoEncontrado = false;
        bool cupoDisponible = false;
        string nombre, catedratico;
        int cupoActual, activo;
        fstream tempCurso("TempCursos.txt", ios::out);
        if (!tempCurso) {
            cout << "\n\t\t\tError al crear archivo temporal." << endl;
            fileCurso.close();
            return;
        }

        while (fileCurso >> nombre >> cupoActual >> catedratico >> activo) {
            if (nombre == nombreCurso) {
                cursoEncontrado = true;
                if (activo == 1 && cupoActual > 0) {
                    cupoDisponible = true;
                    cupoActual--;  // ocupamos un cupo
                    cout << "\n\t\t\tInscripcion exitosa." << endl;
                } else if (activo != 1) {
                    cout << "\n\t\t\tEl curso no esta activo." << endl;
                } else if (cupoActual <= 0) {
                    cout << "\n\t\t\tNo hay cupo disponible en este curso." << endl;
                }
            }
            tempCurso << left << setw(20) << nombre << left << setw(10) << cupoActual << left << setw(20) << catedratico << left << setw(10) << activo << "\n";
        }
        fileCurso.close();
        tempCurso.close();

        if (!cursoEncontrado) {
            cout << "\n\t\t\tCurso no encontrado." << endl;
            remove("TempCursos.txt");
            return;
        }
        if (!cupoDisponible) {
            remove("TempCursos.txt");
            return;
        }

        // este es el archivo que se reemplaza
        remove("Cursos.txt");
        rename("TempCursos.txt", "Cursos.txt");

        // mandar el registro de las inscripciones a un archivo
        fstream fileIns("Inscripciones.txt", ios::app | ios::out);
        fileIns << left << setw(15) << nombreEstudiante << left << setw(20) << nombreCurso << "\n";
        fileIns.close();
    }

    void retirarEstudiante() {
        system("cls");
        string nombreEstudiante, nombreCurso;
        cout << "\n------------------------- RETIRAR ESTUDIANTE DE CURSO -------------------------" << endl;
        cout << "Ingrese nombre del estudiante: ";
        cin >> nombreEstudiante;
        cout << "Ingrese nombre del curso: ";
        cin >> nombreCurso;

        fstream fileIns("Inscripciones.txt", ios::in);
        if (!fileIns) {
            cout << "\n\t\t\tNo hay inscripciones registradas." << endl;
            return;
        }

        fstream tempIns("TempIns.txt", ios::out);
        bool inscripcionEncontrada = false;
        string est, cur;
        while (fileIns >> est >> cur) {
            if (est == nombreEstudiante && cur == nombreCurso) {
                inscripcionEncontrada = true;
                continue;
            }
            tempIns << left << setw(15) << est << left << setw(20) << cur << "\n";
        }
        fileIns.close();
        tempIns.close();

        if (!inscripcionEncontrada) {
            cout << "\n\t\t\tNo se encontro inscripcion del estudiante en ese curso." << endl;
            remove("TempIns.txt");
            return;
        }

        remove("Inscripciones.txt");
        rename("TempIns.txt", "Inscripciones.txt");

        // Aumenta el cupo de los cursos
        fstream fileCurso("Cursos.txt", ios::in);
        if (!fileCurso) {
            cout << "\n\t\t\tError al actualizar cupo del curso." << endl;
            return;
        }

        fstream tempCurso("TempCursos.txt", ios::out);
        string nombre, catedratico;
        int cupo, activo;
        bool cursoActualizado = false;
        while (fileCurso >> nombre >> cupo >> catedratico >> activo) {
            if (nombre == nombreCurso) {
                cupo++;
                cursoActualizado = true;
            }
            tempCurso << left << setw(20) << nombre << left << setw(10) << cupo << left << setw(20) << catedratico << left << setw(10) << activo << "\n";
        }
        fileCurso.close();
        tempCurso.close();

        if (cursoActualizado) {
            remove("Cursos.txt");
            rename("TempCursos.txt", "Cursos.txt");
            cout << "\n\t\t\tEstudiante retirado del curso exitosamente. Cupo liberado." << endl;
        } else {
            cout << "\n\t\t\tCurso no encontrado para actualizar cupo." << endl;
            remove("TempCursos.txt");
        }
    }

    void verInscripciones() {
        system("cls");
        string nombreCurso;
        cout << "\n------------------------- VER INSCRIPCIONES POR CURSO -------------------------" << endl;
        cout << "Ingrese el nombre del curso: ";
        cin >> nombreCurso;

        fstream fileIns("Inscripciones.txt", ios::in);
        if (!fileIns) {
            cout << "\n\t\t\tNo hay inscripciones registradas." << endl;
            return;
        }

        string estudiante, curso;
        int total = 0;
        cout << "\n\t\t Estudiantes inscritos en el curso '" << nombreCurso << "':" << endl;
        cout << "\t\t ------------------------------------" << endl;
        while (fileIns >> estudiante >> curso) {
            if (curso == nombreCurso) {
                total++;
                cout << "\t\t\t" << total << ". " << estudiante << endl;
            }
        }
        fileIns.close();

        if (total == 0) {
            cout << "\n\t\t\tNo hay estudiantes inscritos en este curso." << endl;
        } else {
            cout << "\n\t\t\tTotal de inscritos: " << total << endl;
        }
    }

    void menuCursos() {
        int choice;
        char x;
        do {
            system("cls");
            cout << "\t\t\t-------------------------------" << endl;
            cout << "\t\t\t |     GESTION DE CURSOS      |" << endl;
            cout << "\t\t\t-------------------------------" << endl;
            cout << "\t\t\t 1. Agregar Curso" << endl;
            cout << "\t\t\t 2. Listar Cursos" << endl;
            cout << "\t\t\t 3. Modificar Curso" << endl;
            cout << "\t\t\t 4. Buscar Curso" << endl;
            cout << "\t\t\t 5. Eliminar Curso" << endl;
            cout << "\t\t\t 6. Inscribirse a Curso" << endl;
            cout << "\t\t\t 7. Retirarse de Curso (darse de baja)" << endl;
            cout << "\t\t\t 8. Ver inscripciones por curso" << endl;
            cout << "\t\t\t 9. Salir" << endl;
            cout << "\t\t\t-------------------------------" << endl;
            cout << "Ingresa tu Opcion: ";
            cin >> choice;

            switch (choice) {
                case 1:
                    do {
                        insertarCurso();
                        cout << "\n\t\t\t Agregar otro curso? (Y/N): ";
                        cin >> x;
                    } while (x == 'y' || x == 'Y');
                    break;
                case 2:
                    listarCursos();
                    break;
                case 3:
                    modificarCurso();
                    break;
                case 4:
                    buscarCurso();
                    break;
                case 5:
                    eliminarCurso();
                    break;
                case 6:
                    inscribirEstudiante();
                    break;
                case 7:
                    retirarEstudiante();
                    break;
                case 8:
                    verInscripciones();
                    break;
                case 9:
                    cout << "\n\t\t\tSaliendo del sistema de cursos..." << endl;
                    return;
                default:
                    cout << "\n\t\t\t Opcion invalida...";
            }
            getch();
        } while (choice != 9);
    }
};

int main() {
    GestionCursos cursos;
    cursos.menuCursos();
    return 0;
}
