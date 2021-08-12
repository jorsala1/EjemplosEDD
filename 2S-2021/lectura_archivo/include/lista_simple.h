#ifndef LISTA_SIMPLE_H
#define LISTA_SIMPLE_H
#include "nodo.h"

class lista_simple
{
    public:
        lista_simple();
        virtual ~lista_simple();

    //ATRIBUTOS
    nodo * primero;
    nodo * ultimo;

    //METODOS
    void insertar(string id, string nombre);
    void mostrar();
    void buscar(string dato);
};

#endif // LISTA_SIMPLE_H
