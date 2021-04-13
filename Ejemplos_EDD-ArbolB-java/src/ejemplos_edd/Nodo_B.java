/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package ejemplos_edd;

/**
 *
 * @author Josue
 */
public class Nodo_B {
    int valor;
    Nodo_B siguiente;
    Nodo_B anterior;
    Pagina izq;
    Pagina der;
    
    int posx;
    int posy;
    
    
    Nodo_B(int val){
        this.valor = val;
        this.anterior = null;
        this.siguiente = null;
        this.izq = null;
        this.der= null;
    }
    //metodos del nodo 
    int getValor(){
        return this.valor;
    }

    
    void setValor(int nuevo_valor){
        this.valor = nuevo_valor;
    }

}
