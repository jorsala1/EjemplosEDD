#ifndef LISTA_H
#define LISTA_H
#include "nodo.h"

class lista
{
    public:
        lista();
        virtual ~lista();

        //atributos
        nodo * primero;
        nodo * ultimo;
        int cantidad;

        //metodos
        void insertar_Final(int dato);
        void insertar_inicio(int dato);
        void insertar_ordenado(int dato);

        void eliminar(int dato);
        nodo *  buscar(int dato);
        void mostrar_lista();

        void prueba();


};

#endif // LISTA_H
