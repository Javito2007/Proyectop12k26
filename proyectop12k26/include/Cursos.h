#ifndef CURSOS_H
#define CURSOS_H


class Cursos
{
    public:
        Cursos(string nombreCurso, int codigoCurso, string preRequisitoDeCursos, char estadoCurso);
        string getnombreCurso();
        string setnombreCurso(string nombreCurso);
        string getpreRequisitoDeCurso();
        string setpreRequisitoDeCurso(string preRequisitoDeCursos);
        int getcodigoCurso();
        int setcodigoCurso(int codigoCurso);
        char getestadoCurso();
        char setestadoCurso(char estadoCurso);
        void prueba();

    protected:

    private:
        string nombreCurso;
        string preRequisitoDeCursos;
        int codigoCurso;
        char estadoCurso;

};

#endif // CURSOS_H
