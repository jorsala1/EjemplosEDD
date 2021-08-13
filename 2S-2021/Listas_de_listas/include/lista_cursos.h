#ifndef LISTA_CURSOS_H
#define LISTA_CURSOS_H
#include"nodo_curso.h"

class lista_cursos
{
    public:
        lista_cursos();
        virtual ~lista_cursos();

    //atributos
    nodo_curso * primero;
    nodo_curso * ultimo;

    //metodos
    void insertar(int codigo, string nombre);
    void mostrar_cursos();
};

#endif // LISTA_CURSOS_H
