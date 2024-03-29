/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package ejemplos_edd;

import javax.swing.JOptionPane;

/**
 *
 * @author Josue
 */
public class lista_nodoB { // lista de nodos que tendra una pagina
    Nodo_B primero;
    Nodo_B ultimo;
    int size;
    
    lista_nodoB(){
        this.primero = null;
        this.ultimo = null;
        this.size =0;
    }
    
    //metodos de la lista
    Nodo_B getPrimero(){
        return this.primero;
    }
    int getSize(){
        return this.size;
    }
    
    Nodo_B getUltimo(){
        return this.ultimo;
    }
    
    void setPrimero(Nodo_B prim){
        this.primero= prim;
    }
    
    boolean insertar(Nodo_B nuevo){//---------------------------insertar un nodo a la lista de una pagina 
        if(this.primero == null){
            this.primero = nuevo;
            this.ultimo = nuevo;
            size ++;
            return true;
        }else{
            if(this.primero == this.ultimo){ // -------------------------solo hay un nodo 
                if(nuevo.valor < this.primero.valor){
                    nuevo.siguiente = this.primero;
                    this.primero.anterior = nuevo;
                    this.primero.izq = nuevo.der; // -----cambia los punteros a las paginas
                    this.primero = nuevo;
                    size++; 
                    return true;
                }else if(nuevo.valor > this.ultimo.valor){
                    this.ultimo.siguiente = nuevo;
                    nuevo.anterior = this.ultimo;
                    this.ultimo.der = nuevo.izq; //------ cambia los punteros a las paginas 
                    this.ultimo = nuevo;
                    size++; 
                    return true;
                }else{
                     System.out.println ("ya hay un destino con ese codigo registrado");
                    return false;
                }
            }else{ // ---------------------------------------------------hay mas de un nodo
                if(nuevo.valor < this.primero.valor){
                    nuevo.siguiente = this.primero;
                    this.primero.anterior = nuevo;
                    this.primero.izq = nuevo.der; // -----cambia los punteros a las paginas
                    this.primero = nuevo;
                    size++; 
                    return true;
                }else if(nuevo.valor > this.ultimo.valor){
                    this.ultimo.siguiente = nuevo;
                    nuevo.anterior = this.ultimo;
                    this.ultimo.der = nuevo.izq; //------ cambia los punteros a las paginas 
                    this.ultimo = nuevo;
                    size++; 
                    return true;
                }else{
                    Nodo_B pivote = this.primero;
                    while(pivote != null){
                        if(nuevo.valor < pivote.valor){
                            nuevo.siguiente = pivote;
                            nuevo.anterior = pivote.anterior;
                            //--------------------------- cambia los punteros a las paginas
                            pivote.izq = nuevo.der;
                            pivote.anterior.der = nuevo.izq;
                            //-----------------------------------------------------------
                            pivote.anterior.siguiente = nuevo;
                            pivote.anterior = nuevo;
                            size++;
                            return true;
                        }else if(nuevo.valor == pivote.valor){
                            System.out.println ("ya hay un destino con ese codigo registrado");
                            return false;
                        }else{
                            pivote = pivote.siguiente;
                        }
                    }
                }
            }
        }
        return false;
    }
}
