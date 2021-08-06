#include <stdio.h>
#include <stdlib.h>

struct nodo{
    int id;
    struct nodo * sig;
};
typedef struct nodo nodo;

void insertar(nodo ** primero, int dato){
    nodo * nuevo = (nodo*)malloc(sizeof(nodo));
    nuevo->id = dato;
    nuevo->sig =NULL;

    if(*primero == NULL){
        *primero= nuevo;
    }else{
        nodo * pivote = (*primero);
        do{
            if(pivote->sig == NULL){
                pivote->sig = nuevo;
                break;
            }else{
                pivote=pivote->sig;
            }
        }while(pivote!= NULL);
    }
}

void mostrar_lista(nodo * primero){ //en este caso, no se va a modificar este puntero por eso se envia simple
    nodo * pivote = primero;

    while(pivote != NULL){
        printf("-> %d \n",pivote->id);
        pivote = pivote->sig;
    }

}
int main()
{
    //crear un nodo
    nodo * primero = (nodo*)malloc(sizeof(nodo));
    primero=NULL;

    insertar(&primero,10);
    insertar(&primero,20);
    insertar(&primero,30);
    insertar(&primero,35);

    //printf("primero = %d \n",primero->id);
    //printf("siguiente = %d \n",primero->sig->id);
    //printf("tercer = %d",primero->sig->sig->id);

    mostrar_lista(primero);
    return 0;
}
