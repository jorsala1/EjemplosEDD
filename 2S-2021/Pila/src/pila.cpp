#include "pila.h"
#include <iostream>
#include <fstream>

using namespace std;

//Constructor de pila
pila::pila()
{
    //ctor
    this->cima = nullptr;
    this->tam  = 0;
}

//metodo que verifica si la pila tiene algun elemento
int pila::pilaVacia(){
    return this->cima == nullptr;
}

//Insertar un valor en la pila
void pila::push_pila(int valor){
    stacknode *nuevo = new stacknode(valor, nullptr);
    if(this->pilaVacia()){
        this->cima = nuevo;
        cout << "se inserto primer elemento \n" << endl;
    }else{
        nuevo->prev = this->cima;
        this->cima = nuevo;
        cout << "se inserto nuevo elemento en pila \n" << endl;
    }

    this->tam ++;
}

//Eliminar un elemento de la pila
void pila::pop_pila(){
    stacknode *aux;
    if(this->pilaVacia()){
      cout << "La pila esta vacia" << endl;
    }else{
        aux = this->cima;
        this->cima = aux->prev;
        cout << "se  elimino un elemento de la pila" << endl;
        delete(aux); //para vaciar el espacio de memoria
        this->tam --;
    }
}

//Devuelve el la cantidad de elementos almacenada en la pila
int pila::tamPila(){
    return this->tam;
}

//Retorna el ultimo elemento ingresado a la pila
stacknode pila::peek_pila(){
    cout<<"la cima es: "<< this->cima->valor<<endl;
    return *this->cima;
}


//Recorre la pila para mostrar en consola
void pila::mostrarPila(){
    if(this->pilaVacia()){
       cout << "La pila esta vacia" << endl;
    }else{
        stacknode *aux = this->cima;
        while(aux != nullptr){
            cout << "[" << aux->valor <<"]->" ;
            aux = aux->prev;
        }
        cout << "" << endl;
    }
}

//Elimina todos los elementos que se encuentran en la pila
void pila::vaciar_pila(){
    if(this->pilaVacia()){
        cout << "La pila esta vacia" << endl;
    }else{
        while(!(this->pilaVacia())){
            this->pop_pila();
        }
        cout << "se ha vaciado la pila" << endl;
    }
}

//Grafica la pila (creando un archivo de texto)
void pila::graficar_pila(){
    ofstream fs("pila.dot");
        fs<<"digraph G {"<<"\n"<<endl;
        fs << "rankdir = UD;\n" <<endl;
        fs << "\tnode [shape=record,color=black];" <<endl;
        fs << "label = \"Pila\"; \n"<<endl;
        fs << "color= black \n"<<endl;
        stacknode * temp = this->cima;

        int contador = 0;

        while(temp != nullptr){
            fs <<"\t\tn_"<<contador<< "[label = \"Valor: "<< temp->valor<<"\"];\n" <<endl;
            temp=temp->prev;
            contador++;
        }

        for(int i = 0; i<contador-1;i++){
                fs <<"n_"<<i<< " ->"<<"n_"<<i+1<< ";" <<endl;
            }

        fs << "\t}\n" << endl;
        fs << " }" << endl;
        fs.close();
        //system( "dot -Tpng pila.dot -o pila.png");

}

//destructor de la pila
pila::~pila()
{
    //dtor
}
