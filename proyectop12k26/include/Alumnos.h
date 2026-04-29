#ifndef ALUMNOS_H
#define ALUMNOS_H
#include <string>


class Alumnos
{
    public:
        //Contructor
        Alumnos();
        Alumnos(std::string nombreAlumno, std::string apellidoAlumno, std::string sexoAlumno, std::string numeroDpi, std::string correoPersonal, std::string carnetPersonal);
        //Getters
        std::string getnombreAlumno();
        std::string getapellidoAlumno();
        std::string getsexoAlumno();
        int getdiaNacimiento();
        int getmesNacimiento();
        int getanioNacimiento();
        std::string getnumeroDpi();
        std::string getcorreoPersonal();
        std::string getfechaNacimientoAlumno();
        std::string getcarnetPersonal();
        //Setters
        void setnombreAlumno(std::string nombreAlumno);
        void setapellidoAlumno(std::string apellidoAlumno);
        void setsexoAlumno(std::string sexoAlumno);
        void setdiaNacimiento(int diaNacimiento);
        void setmesNacimiento(int mesNacimiento);
        void setanioNacimiento(int anioNacimiento);
        void setnumeroDpi(std::string numeroDpi);
        void setcorreoPersonal(std::string correoPersonal);
        void setfechaNacimientoAlumno(std::string fechaNacimientoAlumno);
        void setcarnetPersonal(std::string carnetPersonal);
        //Metodos
        void registroDatos();
        void menuRegistro();
        void obtenerFechaNacimiento();
        int obtenerAnioCorto();
        void creaCorreoPersonal();
        void crearCarnetPersonal();

    protected:

    private:
         //Datos personales del alumno
        std::string nombreAlumno;
        std::string apellidoAlumno;
        std::string sexoAlumno;
        int diaNacimiento;
        int mesNacimiento;
        int anioNacimiento;
        std::string numeroDpi;
        std::string correoPersonal;
        std::string fechaNacimientoAlumno;
        std::string carnetPersonal;
        int anioCorto;
        //Constantes
        static const int CODIGO_ING_SISTEMA = 9959;
        static const int ANIO_ACTUAL = 26;
        //numeroAleatorio
        int numeroAleatorio(int minimo, int maximo);


};

#endif // ALUMNOS_H
