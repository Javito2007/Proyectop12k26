#ifndef CURSOS_H
#define CURSOS_H


class Cursos
{
    public:
        Cursos();
        string obtenerNombreCurso(string pNombreCurso);
        string obtenerRequesitoDeCursos(string pPreRequisitoDeCursos);
        bool obtenerEstadoDeCursos(string pEstadoCurso);


    protected:

    private:
        nombreCurso;
        preRequisitoDeCursos;
        codigoCurso;
        estadoCurso;

};

#endif // CURSOS_H
