/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package ejemplos_edd;

import java.io.IOException;

/**
 *
 * @author Josue
 */
public class Ejemplos_EDD {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws IOException {
        // TODO code application logic here
        Arbol_B arbol_ejemplo = new Arbol_B();
        arbol_ejemplo.insertar_nodo(360);
        arbol_ejemplo.insertar_nodo(100);
        arbol_ejemplo.insertar_nodo(268);
        arbol_ejemplo.insertar_nodo(700);
        arbol_ejemplo.insertar_nodo(750);
        arbol_ejemplo.insertar_nodo(50);
        arbol_ejemplo.insertar_nodo(10);
        arbol_ejemplo.insertar_nodo(5);
        arbol_ejemplo.insertar_nodo(55);
        arbol_ejemplo.insertar_nodo(12);
        arbol_ejemplo.insertar_nodo(25);
        
        arbol_ejemplo.insertar_nodo(361);
        arbol_ejemplo.insertar_nodo(101);
        arbol_ejemplo.insertar_nodo(261);
        arbol_ejemplo.insertar_nodo(701);
        arbol_ejemplo.insertar_nodo(751);
        arbol_ejemplo.insertar_nodo(51);
        arbol_ejemplo.insertar_nodo(35);
        arbol_ejemplo.insertar_nodo(56);
        arbol_ejemplo.insertar_nodo(58);
        arbol_ejemplo.insertar_nodo(1);
        arbol_ejemplo.insertar_nodo(255);
        
        arbol_ejemplo.Graficar_ArbolB();
    }
    
}
