#include "nodo.h"

nodo::nodo()
{
    this->id = 25;
    this->sig = NULL;

}

int nodo::get_id(){
    return this->id;
}


void nodo::set_id(int dato){
    this->id = dato;
}

