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

    //usaremos 2 contadores
    int contador_imagenes = 0; //contador para generar imagenes y que no se elimine la anterior
    int contador_datos=0;      //contador para limitar el numero de datos en una grafica

    //********************
        stacknode * pivote = this->cima; // el temporal no se reiniciara cada vez que se haga una grafica

        while(pivote != NULL){ //vamos a recorrer la estructura hasta llegar al final
            ofstream fs("pila.dot");
            fs<<"digraph G {"<<"\n"<<endl;
            fs << "rankdir = UD;\n" <<endl;
            fs << "\tnode [shape=record,color=black];" <<endl;
            fs << "label = \"Pila\"; \n"<<endl;
            fs << "color= black \n"<<endl;

            int contador = 0;

            while(contador_datos<5){ // ponemos este ciclo ya que queremos que se genere una imagen cuando esta tenga 5 datos
                if(pivote!=NULL){ // revisamos si ya llegamos al final, si no continuamos graficando
                    fs <<"\t\tn_"<<contador<< "[label = \"Valor: "<< pivote->valor<<"\"];\n" <<endl;
                    pivote=pivote->prev;
                    contador_datos++;
                    contador++;
                }else{
                    break; // si llagamos al final nos salimos del while aunque no se haya llegado a los 5 datos
                    //al salir hara la grafica de las flechas y luego verificara el while principal
                    //como pivote es null nos saca de todo el ciclo
                }
            }

            contador_datos=0;
            contador_imagenes++;
            for(int i = 0; i<contador-1;i++){
                    fs <<"n_"<<i<< " ->"<<"n_"<<i+1<< ";" <<endl;
            }

            fs << "\t}\n" << endl;
            fs.close();

            //utilizamos to_string para pasar el dato numero a un string
            string tmp = to_string(contador_imagenes);
            string ej= "dot -Tpng pila.dot -o pila"+tmp+".png"; // guadamos el string que ejecutaremos con system
            //solo cambiamos el nombre de la imagen porque es lo unico que necesitamos que no se reemplace
            //system esun comando de c, por lo que no nos permite utilizar string
            //casteamos el estring ej a un arreglo de caracteres con .c_str()
            char const *ejecutar = ej.c_str();
            system(ejecutar);

        }
}

//destructor de la pila
pila::~pila()
{
    //dtor
}
