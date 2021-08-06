#ifndef NODO_H
#define NODO_H
#include <iostream>

using namespace std;

class nodo
{
    public:
        nodo();

        int id;
        nodo * sig;
        nodo * ant;

        //Funciones
        int get_id();

        //metodo
        void set_id(int dato);

};

#endif // NODO_H
