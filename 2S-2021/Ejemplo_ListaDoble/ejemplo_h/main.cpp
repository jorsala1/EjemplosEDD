#include <iostream>
#include "lista.h"

using namespace std;
void prueba(long long int dpi){
    cout<<dpi<<endl;
}
int main()
{
    int op=0;

    long long int dpi = 3000347170101;
    prueba(dpi);


    lista * nueva_lista= nueva_lista = new lista();

    while(op!=5){
        cout<<"***** Menu *****"<<endl;
        cout<<"1- insertar"<<endl;
        cout<<"2- Buscar"<<endl;
        cout<<"3- eliminar"<<endl;
        cout<<"4- Mostrar lista"<<endl;
        cout<<"5- salir"<<endl;
        cout<<"Ingrese el numero de opcion  ";
        cin>>op;

        if(op==1){
            int dato=0;
            int op2=0;
            cout<<"Ingrese el valor a insertar:     ";

            cin>>dato;
            cout<<"\n Donde quiere insertar el valor?"<<endl;
            cout<<"     1- Inicio"<<endl;
            cout<<"     2- Final"<<endl;
            cout<<"     3- Ordenado"<<endl;
            cout<<"     Ingrese el numero de opcion  ";
            cin>>op2;

            if(op2==1){
                nueva_lista->insertar_inicio(dato);
            }else if(op2==2){
                nueva_lista->insertar_Final(dato);
            }else if(op2==3){
                nueva_lista->insertar_ordenado(dato);
            }

        }else if(op==2){
            int dato=0;
            cout<<"Ingrese el valor a Buscar:       ";
            cin>>dato ;
            nodo * resultado_busquedad = nueva_lista->buscar(dato);
            if(resultado_busquedad != NULL){
                cout<<"\n***************"<<endl;
                cout<<"resultado busqueda: -> "<<resultado_busquedad->id<<endl;
                cout<<"***************\n"<<endl;
            }
        }else if(op==3){
            int dato=0;
            cout<<"Ingrese el valor a Eliminar:       ";
            cin>>dato ;
            nueva_lista->eliminar(dato);
        }else if(op==4){
             nueva_lista->mostrar_lista();
        }else if(op==5){

        }
    }

    return 0;
}
