#include <iostream>
#include "pila.h"

using namespace std;

int main()
{
    pila *p = new pila();
    p->push_pila(2);
    p->push_pila(23);
    p->push_pila(25);
    p->push_pila(26);
    p->push_pila(2);
    p->push_pila(23);
    p->push_pila(25);
    p->push_pila(26);
    p->push_pila(2);
    p->push_pila(23);
    p->push_pila(25);
    p->push_pila(26);
    p->push_pila(2);
    p->push_pila(23);
    p->push_pila(25);
    p->push_pila(26);
    p->mostrarPila();
    p->pop_pila();
    p->mostrarPila();
    p->peek_pila();
    p->graficar_pila();
    return 0;
}
