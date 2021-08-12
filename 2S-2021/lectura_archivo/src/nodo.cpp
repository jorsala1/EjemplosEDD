#include "nodo.h"

nodo::nodo(string id, string nombre)
{
    this->id = id;
    this->nombre = nombre;
    this->sig = NULL;
}

nodo::~nodo()
{
    //dtor
}
