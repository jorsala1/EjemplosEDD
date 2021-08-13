#include "nodo_alumno.h"

nodo_alumno::nodo_alumno(int carnet,string nombre)
{
    this->carnet = carnet;
    this->nombre = nombre;

    this->siguiente = NULL;
    this->anterior = NULL;
    this->cursos = new lista_cursos();
}


nodo_alumno::~nodo_alumno()
{
    //dtor
}
