#ifndef NODO_CURSO_H
#define NODO_CURSO_H
#include <iostream>

using namespace std;

class nodo_curso
{
    public:
        nodo_curso(int codigo, string nombre);
        virtual ~nodo_curso();

    //atributos
    int codigo_curso;
    string nombre;

    nodo_curso * siguiente;
};

#endif // NODO_CURSO_H
