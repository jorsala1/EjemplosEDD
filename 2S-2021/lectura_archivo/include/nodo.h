#ifndef NODO_H
#define NODO_H
#include <iostream>
#include <fstream>
#include <string>
#include <string>
using namespace std;
class nodo
{
    public:
        nodo(string id, string nombre);
        virtual ~nodo();

        //atributos
        nodo * sig;
        string id;
        string nombre;


};

#endif // NODO_H
