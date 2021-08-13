#include "nodo_curso.h"

nodo_curso::nodo_curso(int codigo, string nombre)
{
    this->codigo_curso = codigo;
    this->nombre = nombre;
    this->siguiente = NULL;
}

nodo_curso::~nodo_curso()
{
    //dtor
}
