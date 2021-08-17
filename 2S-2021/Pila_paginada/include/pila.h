#ifndef PILA_H
#define PILA_H
#include "stacknode.h"


class pila
{
    public:
        pila();
        int pilaVacia();
        int tamPila();
        void push_pila(int valor);
        void pop_pila();
        stacknode peek_pila();
        void vaciar_pila();
        void mostrarPila();
        void graficar_pila();
        virtual ~pila();

    protected:

    private:
        stacknode * cima;
        int tam;
};

#endif // PILA_H
