#include "Matriz.h"

Matriz::Matriz(int capa)
{
    this->filas = new Lista_Cabeceras();
    this->columnas = new Lista_Cabeceras();
    this->num_capa = capa;
}

void Matriz::insertar_matriz(int pos_x, int pos_y, nodo_internoMatriz * nuevo){
   // printf("entro al meto principal aqui **************************************\n");
    nodo_cabecera * nodo_X = this->filas->buscar(pos_x); // buscar si existen las cabeceras en la matriz
    nodo_cabecera * nodo_y = this->columnas->buscar(pos_y);

    if(nodo_X == NULL){ // NO EXISTE LA CABECERA, SE CREA
        nodo_X = new nodo_cabecera(pos_x);
        printf("entro aqui crea cabecera x\n");
        filas->insertar_nodoCabecera(nodo_X); 
    }
    if(nodo_y == NULL){
       printf("entro aqui crea cabecera y\n");
        nodo_y = new nodo_cabecera(pos_y);
        columnas->insertar_nodoCabecera(nodo_y);  
    }

    // ya se verifico que hayan cabeceras ahora se tiene que insertar el nodo

    //---- INSERTAR EL NUEVO NODO EN LA COLUMNA (columnas = x , filas = y)
    if(nodo_X->getInterno()==NULL){ //EL nodo interno de cada cabecera es el primero de la lista de nodos internos.
        nodo_X->setNodoInterno(nuevo);
    }else{
        if(nuevo->getY() < nodo_X->getInterno()->getY()){
            nuevo->setDerecho(nodo_X->getInterno());
            nodo_X->getInterno()->setIzquierdo(nuevo);
            nodo_X->nodoInterno=(nuevo);
        }else{
            nodo_internoMatriz * pivote = nodo_X->getInterno();
            while(pivote != NULL){
                if(nuevo->getY() < pivote->getY()){
                    nuevo->setDerecho(pivote);
                    nuevo->setIzquierdo(pivote->getIzquierdo());
                    pivote->getIzquierdo()->setDerecho(nuevo);
                    pivote->setIzquierdo(nuevo);
                    break;
                }else if(nuevo->getX() == pivote->getX() && nuevo->getY() == pivote->getY() ){
                    break;
                }else{
                    if(pivote->getDerecho() == NULL){
                        pivote->setDerecho(nuevo);
                        nuevo->setIzquierdo(pivote);
                        break;
                    }else{
                        pivote = pivote->getDerecho();
                    }
                }
            }
        }
    }
    
    //---- INSERTAR EL NUEVO NODO EN LA fila
    if(nodo_y->getInterno()==NULL){ //EL nodo interno de cada cabecera es el primero de la lista de nodos internos.
        nodo_y->setNodoInterno(nuevo);
    }else{
        if(nuevo->x < nodo_y->getInterno()->x){
            nuevo->setAbajo(nodo_y->getInterno());
            nodo_y->getInterno()->setArriba(nuevo);
            nodo_y->nodoInterno=(nuevo);
        }else{
            nodo_internoMatriz * pivote = nodo_y->getInterno();

            while(pivote != NULL){
                if(nuevo->getX() < pivote->getX()){
                    nuevo->setAbajo(pivote);
                    nuevo->setArriba(pivote->getArriba());
                    pivote->getArriba()->setAbajo(nuevo);
                    pivote->setArriba(nuevo);
                    break;
                }else if(nuevo->getX() == pivote->getX() && nuevo->getY() == pivote->getY() ){
                    break;
                }else{
                     if(pivote->getAbajo() == NULL){
                        pivote->setAbajo(nuevo);
                        nuevo->setArriba(pivote);
                        break;
                    }else{
                        pivote = pivote->getAbajo();
                    }    
                }
            }
        }
    }
    printf(" ********************************************\n");
}

void Matriz::graficar_logico(){
    FILE * doc = fopen("matriz_logico.dot","w");
    fprintf(doc,"digraph G{ rankdir = TB\n");
    fprintf(doc,"node[shape = box,width=0.7,height=0.7,fillcolor=\"azure2\" color=\"white\" style=\"filled\"];\n");
    fprintf(doc, "edge[style = \"bold\"]; \n");

 
    fprintf(doc,"\n\ node[label = \"capa: %d\" fillcolor=\" darkolivegreen1\" pos = \"-1,1!\"]principal;",this->num_capa);
    
    //graficar nodos cabecera
    //graficar nodos x
        nodo_cabecera * pivote = this->filas->getPrimero_lisctaCabeceras();
        int posx=0;
        while(pivote != NULL){
            fprintf(doc,"\n\tnode[label = \"X: %d\" fillcolor=\" azure3\" pos = \"%d,1!\" shape = box]x%d;",pivote->getId(),posx,pivote->getId());
            pivote = pivote->getSiguiente();
            posx++;
        }
        pivote = this->filas->getPrimero_lisctaCabeceras();
        while(pivote->getSiguiente() != NULL){
            fprintf(doc,"x%d -> x%d;\n",pivote->getId(),pivote->getSiguiente()->getId());
            fprintf(doc,"x%d -> x%d;\n",pivote->getSiguiente()->getId(),pivote->getId());
            
            pivote = pivote->getSiguiente();
        }
        fprintf(doc,"principal -> x%d;\n",filas->getPrimero_lisctaCabeceras()->getId());
    //graficar nodos y 
        nodo_cabecera * pivotey = this->columnas->getPrimero_lisctaCabeceras();
        int posy=0;
        while(pivotey != NULL){
            fprintf(doc,"\n\tnode[label = \"Y: %d\" fillcolor=\" azure3\" pos = \"-1,-%d!\" shape = box]y%d;",pivotey->getId(),posy,pivotey->getId());
            pivotey = pivotey->getSiguiente();
            posy++;
        }
        pivotey = this->columnas->getPrimero_lisctaCabeceras();
        while(pivotey->getSiguiente() != NULL){
            fprintf(doc,"y%d -> y%d;\n",pivotey->getId(),pivotey->getSiguiente()->getId());
            fprintf(doc,"y%d -> y%d;\n",pivotey->getSiguiente()->getId(),pivotey->getId());
            
            pivotey = pivotey->getSiguiente();
        }
        fprintf(doc,"principal -> y%d;\n",columnas->getPrimero_lisctaCabeceras()->getId());

    //graficar nodos internos 
    pivote = this->filas->getPrimero_lisctaCabeceras();
    posx=0;
    while(pivote != NULL){
        nodo_internoMatriz * pivote_interno = pivote->nodoInterno;
        
        while(pivote_interno!= NULL){
            //****** encontrar pos y ****
                pivotey= this->columnas->getPrimero_lisctaCabeceras();
                int posy_interno =0;
                while(pivotey!=NULL){
                    if(pivotey->getId() == pivote_interno->getY()){
                        break;
                    }
                    posy_interno++;
                    pivotey = pivotey->getSiguiente();
                }
            //***************************
            fprintf(doc,"\n\tnode[label = \" %d , %d \n  %s \" fillcolor=\" azure2\" pos = \"%d,-%d!\" shape = box]\"i%d-%d\";",pivote_interno->getX(),pivote_interno->getY(),pivote_interno->getColor().c_str(),posx,posy_interno,pivote_interno->getX(),pivote_interno->getY());
            pivote_interno = pivote_interno->getDerecho();
        }

        pivote_interno = pivote->nodoInterno;
        while(pivote_interno != NULL){
            if(pivote_interno->getDerecho()!= NULL){
                fprintf(doc,"\n \"i%d-%d\" -> \"i%d-%d\";\n",pivote_interno->getX(),pivote_interno->getY(),pivote_interno->getDerecho()->getX(),pivote_interno->getDerecho()->getY());
                fprintf(doc,"\"i%d-%d\" -> \"i%d-%d\";\n",pivote_interno->getDerecho()->getX(),pivote_interno->getDerecho()->getY(),pivote_interno->getX(),pivote_interno->getY());
            }
            pivote_interno = pivote_interno->getDerecho();   
        }

        fprintf(doc,"\n x%d -> \"i%d-%d\" \n",pivote->getId(),pivote->getInterno()->getX(),pivote->getInterno()->getY());
        fprintf(doc,"\n \"i%d-%d\"-> x%d  \n",pivote->getInterno()->getX(),pivote->getInterno()->getY(),pivote->getId());
        //printf("cabecera: %d  -> %d,%d\n",pivote->getId(),pivote->getInterno()->getX(),pivote->getInterno()->getY());
        pivote = pivote->getSiguiente();
        posx++;
    }

    pivote = this->columnas->getPrimero_lisctaCabeceras();
    while(pivote != NULL){
        nodo_internoMatriz * pivote_interno = pivote->getInterno();
        while(pivote_interno != NULL){
            if(pivote_interno->getAbajo()!= NULL){
                fprintf(doc,"\n \"i%d-%d\" -> \"i%d-%d\";\n",pivote_interno->getX(),pivote_interno->getY(),pivote_interno->getAbajo()->getX(),pivote_interno->getAbajo()->getY());
                fprintf(doc,"\"i%d-%d\" -> \"i%d-%d\";\n",pivote_interno->getAbajo()->getX(),pivote_interno->getAbajo()->getY(),pivote_interno->getX(),pivote_interno->getY());
            }
            pivote_interno = pivote_interno->getAbajo();   
        }
        fprintf(doc,"\n y%d -> \"i%d-%d\" \n",pivote->getId(),pivote->getInterno()->getX(),pivote->getInterno()->getY());
        fprintf(doc,"\n \"i%d-%d\" -> y%d \n",pivote->getInterno()->getX(),pivote->getInterno()->getY(),pivote->getId());
           
        pivote = pivote->getSiguiente();
    }


    fprintf(doc,"}\n");
    fclose(doc);
    system("cd src/" );
    system( "neato -Tpng matriz_logico.dot -o matriz_logico.png");
    system("cd src/" );
    system("xdg-open matriz_logico.png");
}



//*********************metodos de la lista de cabeceras ****

Lista_Cabeceras::Lista_Cabeceras(){
    this->primero = NULL;
    this->ultimo = NULL;
    this->tam_lista=0;
}

//metodos get de las listas de cabecera
nodo_cabecera * Lista_Cabeceras::getPrimero_lisctaCabeceras(){
    return this->primero;
}
    nodo_cabecera * Lista_Cabeceras::getUltimo_listaCabeceras(){
        return this->ultimo;
    }
    int Lista_Cabeceras::getSize(){
        return this->tam_lista;
    }
    //metodos set de la lista de cabeceras
    void Lista_Cabeceras::setPrimero(nodo_cabecera * nuevo){
        this->primero = nuevo;
    }
    void Lista_Cabeceras::setUltimo(nodo_cabecera * nuevo){
        this->ultimo = nuevo;
    }
    void setSize(int size);


void Lista_Cabeceras::insertar_nodoCabecera(nodo_cabecera * nuevo){
    if(this->getPrimero_lisctaCabeceras() == NULL){
        this->setPrimero(nuevo);
        this->setUltimo(nuevo);
        nuevo->setSiguiente(NULL);
        nuevo->setAnterior(NULL);
    }else{
        if(this->getPrimero_lisctaCabeceras() == this->getUltimo_listaCabeceras()){ // solo hay un nodo en el sistema
            if(nuevo->getId() < this->getPrimero_lisctaCabeceras()->getId()){
                nuevo->setSiguiente(this->getPrimero_lisctaCabeceras());
                this->getPrimero_lisctaCabeceras()->setAnterior(nuevo);
                this->setPrimero(nuevo);
            }else if(nuevo->getId() > this->getUltimo_listaCabeceras()->getId()){
                this->getPrimero_lisctaCabeceras()->setSiguiente(nuevo);
                nuevo->setAnterior(this->getPrimero_lisctaCabeceras());
                this->setUltimo(nuevo);
            }
        }else{
            if(nuevo->getId() < this->getPrimero_lisctaCabeceras()->getId()){
                nuevo->setSiguiente(this->getPrimero_lisctaCabeceras());
                this->getPrimero_lisctaCabeceras()->setAnterior(nuevo);
                this->setPrimero(nuevo);
            }else if(nuevo->getId() > this->getUltimo_listaCabeceras()->getId()){
                this->getUltimo_listaCabeceras()->setSiguiente(nuevo);
                nuevo->setAnterior(this->getUltimo_listaCabeceras());
                this->setUltimo(nuevo);
            }else{
                nodo_cabecera * pivote = this->getPrimero_lisctaCabeceras();

                while(pivote != NULL){
                    if(nuevo->getId() < pivote->getId()){
                        nuevo->setSiguiente(pivote);
                        nuevo->setAnterior(pivote->getAnterior());
                        pivote->getAnterior()->setSiguiente(nuevo);
                        pivote->setAnterior(nuevo);
                        printf("pivote %d ->anterior = %d \n",pivote->getId(),pivote->getAnterior()->getId());
                        printf("entra a la comparacion %d \n",nuevo->getId());
                        break;
                        break;
                    }else if(nuevo->getId() > pivote->getId()){
                        pivote = pivote->getSiguiente();
                    }else{
                        break;
                    }
                }
            }
        }

    }
    
}

void Lista_Cabeceras::imprimir_cabeceras(){
    nodo_cabecera * pivote = this->getPrimero_lisctaCabeceras();
    while (pivote != NULL){
            printf(" cabecera: %d \n", pivote->getId());
            pivote = pivote->getSiguiente();
    }
}
nodo_cabecera * Lista_Cabeceras::buscar(int dato_buscar){
    nodo_cabecera * pivote = this->getPrimero_lisctaCabeceras();
    printf("entro aqui buscar  %d \n",dato_buscar);
    while (pivote != NULL){
        if(pivote->getId() == dato_buscar){
            return pivote;
        }else{
            pivote = pivote->siguiente;
        }
    }
    return NULL;
}

