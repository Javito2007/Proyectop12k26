#ifndef CURSOS_H
#define CURSOS_H
#include <string>

class Cursos
{
    public:
        Cursos();
        Cursos(std::string nombreCurso, int codigoCurso, std::string preRequisitoDeCurso, bool estadoCurso);
        //Getters
        std::string getnombreCurso();
        std::string getpreRequisitoDeCurso();
        int getcodigoCurso();
        bool getestadoCurso();
        //Setters
        void setestadoCurso(bool estadoCurso);
        void setcodigoCurso(int codigoCurso);
        void  setnombreCurso(std::string nombreCurso);
        void setpreRequisitoDeCurso(std::string preRequisitoDeCursos);

    protected:

    private:
        std::string nombreCurso;
        std::string preRequisitoDeCurso;
        int codigoCurso;
        bool estadoCurso;

};

#endif // CURSOS_H
