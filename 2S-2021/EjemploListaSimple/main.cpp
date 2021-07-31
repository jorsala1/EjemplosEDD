#include <iostream>
#include <string>



using namespace std;

// definicion de donde almacenaremos la informacion
struct nodoSimple{
    string dato;
    nodoSimple * siguiente;

    nodoSimple(string dato){
        this->dato = dato;
        this->siguiente = nullptr;
    }
};

//definicion de estructura para almacenar informacion
struct listaSimple{
    nodoSimple * inicio;
    nodoSimple * ultimo;
    int tam;

    listaSimple(){
        this->inicio = nullptr;
        this->ultimo = nullptr;
        this->tam = 0;
    }

    // verificacion de si la lista tiene o no datos
    bool listaVacia(){
        return this->inicio == nullptr; // true o false '0 o 1'
    }

    //insercion de datos;
    void agregar(string valor){
        nodoSimple *nuevo = new nodoSimple(valor);
        if(this->listaVacia()){
            this->inicio = nuevo;
            this->ultimo = nuevo;
            printf("se inserto primer elemento \n");
        }else{
            this->ultimo->siguiente = nuevo;
            this->ultimo = nuevo;
            printf("se inserto nuevo elemento \n");
        }
        this->tam ++;
        return ;
    }

    //metodo para visualizar lista
    void visualizar(){
        nodoSimple *aux = this->inicio;
        while(aux != nullptr){
            printf("Dato: %s ->",aux->dato.c_str());
            aux = aux->siguiente;
        }
        printf("\n");
    }

    //metodo para buscar elemento dentro de lista
    bool buscar(string dato){
        nodoSimple *aux = this->inicio;
        while(aux != nullptr){
            if(aux->dato == dato){
                printf("se encontro valor \n");
                return true;
            }
           aux = aux->siguiente;
        }

        printf("NO se encontro valor \n");
        return false;
    }
};

int main(){
    listaSimple * lst = new listaSimple();
    lst->agregar("2");
    lst->agregar("4");
    lst->agregar("6");
    lst->agregar("7");
    lst->visualizar();
    lst->buscar("9");
    //printf(" %d \n", lst->listaVacia());

    return 0;
}
