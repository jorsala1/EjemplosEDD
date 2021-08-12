#include "nodo.h"

nodo::nodo()
{
    this->id = 0;
    this->sig = NULL;
    this->ant = NULL;
}

int nodo::get_id(){
    return this->id;
}


void nodo::set_id(int dato){
    this->id = dato;
}

