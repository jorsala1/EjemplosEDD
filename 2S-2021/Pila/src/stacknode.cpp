#include "stacknode.h"

stacknode::stacknode()
{
    //ctor
    this->valor = 0;
    this->prev = nullptr;
}

stacknode::stacknode(int valor_, stacknode *prev_)
{
    //ctor
    this->valor = valor_;
    this->prev = prev_;
}

stacknode::~stacknode()
{
    //dtor
}
