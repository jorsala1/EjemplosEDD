#ifndef LISTA_ALUMNOS_H
#define LISTA_ALUMNOS_H
#include"nodo_alumno.h"

class lista_alumnos
{
    public:
        lista_alumnos();
        virtual ~lista_alumnos();

    //Atributos
    nodo_alumno * primero;
    nodo_alumno * ultimo;

    //metodos
    void insertar(int carnet, string nombre);
    void agregar_curso(int carnet, int codigo, string nombre_curso);

    nodo_alumno * buscar(int carnet);
    void mostrar_alumnos();
    void mostrar_cursos_alumno(int carnet);
    void mostrar_alumnos_cursos();

};

#endif // LISTA_ALUMNOS_H
