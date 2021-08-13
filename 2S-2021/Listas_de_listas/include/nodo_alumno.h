#ifndef NODO_ALUMNO_H
#define NODO_ALUMNO_H
#include <iostream>
#include"lista_cursos.h"
using namespace std;

class nodo_alumno
{
    public:
        nodo_alumno(int carnet,string nombre);
        virtual ~nodo_alumno();

    //atributos
    int carnet;
    string nombre;

    nodo_alumno * siguiente;
    nodo_alumno * anterior;
    lista_cursos * cursos;


};

#endif // NODO_ALUMNO_H
