#include "lista_simple.h"

lista_simple::lista_simple()
{
    this->primero = NULL;
    this->ultimo = NULL;
}

void lista_simple::insertar(string id, string nombre){
    nodo * nuevo = new nodo(id,nombre);

    if(this->primero == NULL){
        this->primero = nuevo;
        this->ultimo = nuevo;
    }else{ //se inserta al final
        this->ultimo->sig = nuevo;
        this->ultimo = nuevo;
    }
}

void lista_simple::mostrar(){
    nodo * pivote = this->primero;
    if(this->primero == NULL){
        cout<<"******* LA LISTA ESTA VACIA"<<endl;
    }
    while(pivote != NULL){
        cout<<"-> id: "<<pivote->id<<" Nombre: "<<pivote->nombre<<endl;
        pivote= pivote->sig;
    }

}

void lista_simple::buscar(string dato){
    nodo * pivote = this->primero;

    while(pivote!= NULL){
        if(dato==pivote->id){
            cout<<"se encontro el dato"<<endl;
            break;
        }else{
            pivote=pivote->sig;
        }

        cout<<"NO SE ENCONTRO EL DATO"<<endl;
    }
}

lista_simple::~lista_simple()
{
    //dtor
}
