#include "Cursos.h"
#include <string>
using namespace std;

Cursos::Cursos()
{

}

Cursos::Cursos(string nombreCurso, int codigoCurso, string preRequisitoDeCurso, bool estadoCurso)
{
    this -> nombreCurso = nombreCurso;
    this -> codigoCurso = codigoCurso;
    this -> preRequisitoDeCurso = preRequisitoDeCurso;
    this -> estadoCurso = estadoCurso;
}

//Getters
string Cursos::getnombreCurso()
{
    return this -> nombreCurso;
}
string Cursos::getpreRequisitoDeCurso()
{
    return this -> preRequisitoDeCurso;
}
int Cursos::getcodigoCurso()
{
    return this -> codigoCurso;
}
bool Cursos::getestadoCurso()
{
    return this -> estadoCurso;
}

//Setters
void Cursos::setnombreCurso(string nombreCurso)
{
    this -> nombreCurso = nombreCurso;
}
void Cursos::setpreRequisitoDeCurso(string preRequisitoDeCurso)
{
    this -> preRequisitoDeCurso = preRequisitoDeCurso;
}
void Cursos::setcodigoCurso(int codigoCurso)
{
    this -> codigoCurso = codigoCurso;
}
void Cursos::setestadoCurso(bool estadoCurso)
{
    this -> estadoCurso = estadoCurso;
}
