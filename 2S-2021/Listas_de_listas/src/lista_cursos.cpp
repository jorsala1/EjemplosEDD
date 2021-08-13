#include "lista_cursos.h"

lista_cursos::lista_cursos()
{
    this->primero = NULL;
    this->ultimo = NULL;
}

void lista_cursos::insertar(int codigo, string nombre){
    nodo_curso * nuevo = new nodo_curso(codigo,nombre);

    cout<<"\n** se creo el curso "<<nuevo->nombre<<endl;
    if(this->primero == NULL){
        this->primero = nuevo;
        this->ultimo = nuevo;
    }else{
        this->ultimo->siguiente = nuevo;
        this->ultimo = nuevo;
    }
}

void lista_cursos::mostrar_cursos(){
    if(this->primero == NULL){
        cout<<"\n ***** No hay elementos en la lista de cursos \n"<<endl;
    }else{
        nodo_curso * pivote = this->primero;

        while(pivote != NULL){
            cout<<"     -> coodigo" << pivote->codigo_curso<<"  Nombre: "<<pivote->nombre<<endl;
            pivote= pivote->siguiente;
        }
    }
}

lista_cursos::~lista_cursos()
{
    //dtor
}
