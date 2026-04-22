#include "Cursos.h"

Cursos::Cursos(string nombreCurso, int codigoCurso, string preRequisitoDeCursos, char estadoCurso)
{
    this -> nombreCurso = nombreCurso;
    this -> codigoCurso = codigoCurso;
    this -> preRequisitoDeCursos = preRequisitoDeCursos;
    this -> estadoCurso = estadoCurso;
}

string Cursos::getnombreCurso()
{
    return this -> nombreCurso;
}
string Cursos::setnombreCurso(string nombreCurso)
{
    this -> nombreCurso = nombreCurso;
}
string Cursos::getpreRequisitoDeCurso()
{
    return this -> preRequisitoDeCursos;
}
string Cursos::setpreRequisitoDeCurso(string preRequisitoDeCurso)
{
    this -> preRequisitoDeCursos = preRequisitoDeCurso;
}
int Cursos::getcodigoCurso()
{
    return this -> codigoCurso;
}
int Cursos::setcodigoCurso(int codigoCurso)
{
    this -> codigoCurso = codigoCurso;
}
char Cursos::getestadoCurso()
{
    return this -> estadoCurso;
}
char Cursos::setestadoCurso(char estadoCurso)
{
    this -> estadoCurso = estadoCurso;
}
