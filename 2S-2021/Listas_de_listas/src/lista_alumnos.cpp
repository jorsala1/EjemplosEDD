#include "lista_alumnos.h"

lista_alumnos::lista_alumnos()
{
    this->primero = NULL;
    this->ultimo = NULL;
}

void lista_alumnos::insertar(int carnet, string nombre){ //insertar ordenado
    nodo_alumno * nuevo = new nodo_alumno(carnet,nombre);

    //codigo ejemplo lista doble - el mismo codigo del lab 3
    if(this->primero==NULL){ //validamos que la lista este vacia
        this->primero = nuevo;
        this->ultimo = nuevo;
    }else{
        if(nuevo->carnet < this->primero->carnet){ //validamos si el nuevo es menor al primero, va antes
            nuevo->siguiente = this->primero;
            this->primero->anterior = nuevo;
            this->primero= nuevo;
        }else if(nuevo->carnet >this->ultimo->carnet){ //validamos si el nuevo es mayor al ultimo, va despues
            nuevo->anterior = this->ultimo;
            this->ultimo->siguiente = nuevo;
            this->ultimo = nuevo;
        }else{ //el valor del nuevo esta entre el ultimo y el primero
            nodo_alumno * pivote = this->primero;
            while(pivote != NULL){
                if(pivote->carnet>nuevo->carnet){
                    nuevo->anterior = pivote->anterior;
                    nuevo->siguiente = pivote;
                    pivote->anterior->siguiente=nuevo;
                    pivote->anterior = nuevo;
                    break;
                }else{
                    pivote=pivote->siguiente;
                }
            }
        }
    }
}


void lista_alumnos::mostrar_alumnos(){
    if(this->primero == NULL){
        cout<<"\n ***** No hay elementos en la lista de alumnos \n"<<endl;
    }else{
        nodo_alumno * pivote = this->primero;

        cout<<"\n**************"<<endl;
        while(pivote != NULL){
            cout<<"-> " << pivote->carnet<<"  Nombre: "<<pivote->nombre<<endl;
            pivote= pivote->siguiente;
        }
        cout<<"************** \n"<<endl;
    }
}

nodo_alumno * lista_alumnos::buscar(int dato){
    //validar si la lista esta vacia
    if(this->primero == NULL){
        cout<<"\n**********"<<endl;
        cout<<"->LA LISTA ESTA VACIA"<<endl;
        cout<<"**********\n"<<endl;
        return NULL;
    }else{
        nodo_alumno * pivote = this->primero;
        //recorrer la lista hasta encontrar el dato
        while(pivote!= NULL){
            if(pivote->carnet == dato){
                return pivote;
            }else{
                pivote= pivote->siguiente;
            }
        }
        //SI LLEGA AQUI ES QUE NO ENCONTRO EL DATO
        cout<<"\n**********"<<endl;
        cout<<"->NO SE ENCONTRO ESE VALOR EN LA LISTA"<<endl;
        cout<<"**********\n"<<endl;
        return NULL;
    }
}

void lista_alumnos::agregar_curso(int carnet, int codigo, string nombre_curso){
    nodo_alumno * aux = buscar(carnet);

    if(aux != NULL){
        aux->cursos->insertar(codigo, nombre_curso);
    }
}

void lista_alumnos::mostrar_cursos_alumno(int carnet){
    nodo_alumno * nodo_buscado = buscar(carnet);
    if(nodo_buscado != NULL){
        cout<<"-Cursos de : "<<nodo_buscado->carnet<<endl;
        nodo_buscado->cursos->mostrar_cursos();
    }else{
        cout<<"No se encontro el alumno con el carnet : "<<carnet<<endl;
    }
}

void lista_alumnos::mostrar_alumnos_cursos(){
    if(this->primero == NULL){
        cout<<"\n ***** No hay elementos en la lista de alumnos \n"<<endl;
    }else{
        nodo_alumno * pivote = this->primero;

        cout<<"\n**************"<<endl;
        while(pivote != NULL){
            cout<<"-> " << pivote->carnet<<"  Nombre: "<<pivote->nombre<<endl;
            pivote->cursos->mostrar_cursos();
            cout<<"\n";
            pivote= pivote->siguiente;
        }
        cout<<"************** \n"<<endl;
    }
}

lista_alumnos::~lista_alumnos()
{
    //dtor
}
