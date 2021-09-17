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
public class Pagina {
    lista_nodoB claves;
    boolean raiz;
    int claves_max;
    int claves_min;
    int tam;
    
   Pagina(){
       claves = new lista_nodoB();
       raiz = false;
       claves_max = 4; // valores establecidos por el orden del arbol
       claves_min = 2;
       tam =0;
   }
    
    //metodos de la pagina
    
   Object insertar_pagina(Nodo_B nuevo){
       if(this.claves.insertar(nuevo)){
           //JOptionPane.showMessageDialog(null,"se inserto el nuevo destino");
           this.tam = this.claves.getSize();
           
            if(this.tam <5){
                return this;
            }else if(this.tam == 5){
                return dividir_pag(this);
            } 
       }
       
       return null;
   }
   
   Nodo_B dividir_pag(Pagina pag){
       System.out.print("entro aqui \n");
       Nodo_B temp = pag.claves.getPrimero();
       for(int i =0; i<2; i++){
           temp = temp.siguiente;
       }
       Nodo_B primero = pag.claves.getPrimero();
       Nodo_B segundo = pag.claves.getPrimero().siguiente;
       Nodo_B tercero = temp.siguiente;
       Nodo_B cuarto = pag.claves.ultimo;
       
       primero.siguiente=null;
       primero.anterior = null;
       
       segundo.siguiente = null;
       segundo.anterior = null;
       
       tercero.siguiente = null;
       tercero.anterior = null;
       
       cuarto.siguiente = null;
       cuarto.anterior = null;

       temp.anterior = null;
       temp.siguiente = null;
       
       Pagina izquierda = new Pagina();
       izquierda.insertar_pagina(primero);
       izquierda.insertar_pagina(segundo);
       
       Pagina derecha = new Pagina();
       derecha.insertar_pagina(tercero);
       derecha.insertar_pagina(cuarto);
       
       temp.izq = izquierda;
       temp.der = derecha;
       
       System.out.print("nodo central-> "+temp.getValor()+"\n");
       return temp;
   }
   
   boolean Es_hoja(Pagina pag){
       if(pag.claves.getPrimero().izq == null){
           return true;
       }
      return false;
   }
}
