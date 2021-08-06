#include "lista.h"

lista::lista()
{
    this->primero = NULL;
    this->ultimo = NULL;
    this->cantidad =0;
    cout<<"se inicio la lista"<<endl;
}

void lista::insertar_Final(int dato){
    //crear nodo
    nodo * nuevo = new nodo();
    nuevo->id = dato;
    nuevo->sig= NULL;
    nuevo->ant = NULL;

    //insertar nodo en la lista

    if(this->primero == NULL){ //validamos que la lista este vacia
        this->primero = nuevo;
        this-> ultimo = nuevo;
    }else{ //si no esta vacia lo insertamos de ultimo
        if(this->primero == this->ultimo){ //solo hay un valor en la lista
            this->primero->sig = nuevo;
            nuevo->ant = this->primero;
            this->ultimo = nuevo;
        }else{
            nuevo->ant = this->ultimo;
            this->ultimo->sig = nuevo;
            this->ultimo = nuevo;
        }
    }
}

void lista::insertar_inicio(int dato){
    nodo * nuevo = new nodo();
    nuevo->id = dato;
    nuevo->sig= NULL;
    nuevo->ant = NULL;

    if(this->primero == NULL){ //validamos que la lista esta vacia
        this->primero = nuevo;
        this->ultimo = nuevo;
    }else{
        nuevo->sig = this->primero;
        this->primero->ant = nuevo;
        this->primero = nuevo;
    }
}

void lista::insertar_ordenado(int dato){
    nodo * nuevo = new nodo();
    nuevo->id = dato;
    nuevo->sig= NULL;
    nuevo->ant = NULL;

    if(this->primero==NULL){ //validamos que la lista este vacia
        this->primero = nuevo;
        this->ultimo = nuevo;
    }else{
        if(nuevo->id < this->primero->id){ //validamos si el nuevo es menor al primero, va antes
            nuevo->sig = this->primero;
            this->primero->ant = nuevo;
            this->primero= nuevo;
        }else if(nuevo->id >this->ultimo->id){ //validamos si el nuevo es mayo al ultimo, va despues
            nuevo->ant = this->ultimo;
            this->ultimo->sig = nuevo;
            this->ultimo = nuevo;
        }else{ //el valor del nuevo esta entre el ultimo y el primero
            nodo * pivote = this->primero;
            while(pivote != NULL){
                if(pivote->id>nuevo->id){
                    nuevo->ant = pivote->ant;
                    nuevo->sig = pivote;
                    pivote->ant->sig=nuevo;
                    pivote->ant = nuevo;
                    break;
                }else{
                    pivote=pivote->sig;
                }
            }
        }
    }

}

void lista::mostrar_lista(){
    if(this->primero == NULL){
        cout<<"\n ***** No hay elementos en la lista \n"<<endl;
    }else{
        nodo * pivote = this->primero;

        cout<<"\n**************"<<endl;
        while(pivote != NULL){
            cout<<"-> " << pivote->id<<endl;
            pivote= pivote->sig;
        }
        cout<<"************** \n"<<endl;
    }
}

nodo * lista::buscar(int dato){
    //validar si la lista esta vacia
    if(this->primero == NULL){
        cout<<"\n**********"<<endl;
        cout<<"->LA LISTA ESTA VACIA"<<endl;
        cout<<"**********\n"<<endl;
        return NULL;
    }else{
        nodo * pivote = this->primero;
        //recorrer la lista hasta encontrar el dato
        while(pivote!= NULL){
            if(pivote->id == dato){
                return pivote;
            }else{
                pivote= pivote->sig;
            }
        }
        //SI LLEGA AQUI ES QUE NO ENCONTRO EL DATO
        cout<<"\n**********"<<endl;
        cout<<"->NO SE ENCONTRO ESE VALOR EN LA LISTA"<<endl;
        cout<<"**********\n"<<endl;
        return NULL;
    }


}

void lista::eliminar(int dato){
    //usamos el metodo buscar para encontrar el dato a eliminar
    nodo * pivote = this->buscar(dato);

    //vemos si no devuelve nulo
    if(pivote != NULL){
        //validaciones
        //si la lista solo tiene un dato
        if(this->primero==this->ultimo){
            this->primero=NULL;
            this->ultimo=NULL;
        }else if(pivote == this->primero){ //si el dato a eliminar es el primero de la lista
            this->primero=pivote->sig;
            //eliminamos el pivote
            pivote->sig->ant=NULL;

        }else if(pivote == this->ultimo){ //si el dato a elminar es el ultimo de la lista
            this->ultimo= pivote->ant;
            //eliminamos el enlce del pivote
            pivote->ant->sig= NULL;
        }else{ // es un nodo intermedio
            pivote->ant->sig= pivote->sig;
            pivote->sig->ant = pivote->ant;
        }

        pivote->sig=NULL;
        pivote->ant=NULL;
        delete(pivote);

        cout<<"***\nSe elimino el dato: "<<dato<<"***\n"<<endl;
    }
}

lista::~lista()
{
    //dtor
}
