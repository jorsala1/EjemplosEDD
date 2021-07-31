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
        Nodo_B nuevo = new Nodo_B(5);
        arbol_ejemplo.insertar_nodo(nuevo);
        nuevo = new Nodo_B(6);
        arbol_ejemplo.insertar_nodo(nuevo);
        nuevo = new Nodo_B(1);
        arbol_ejemplo.insertar_nodo(nuevo);
        nuevo = new Nodo_B(10);
        arbol_ejemplo.insertar_nodo(nuevo);
        nuevo = new Nodo_B(13);
        arbol_ejemplo.insertar_nodo(nuevo);
        nuevo = new Nodo_B(3);
        arbol_ejemplo.insertar_nodo(nuevo);
        nuevo = new Nodo_B(8);
        arbol_ejemplo.insertar_nodo(nuevo);
         nuevo = new Nodo_B(2);
        arbol_ejemplo.insertar_nodo(nuevo);
        nuevo = new Nodo_B(20);
        arbol_ejemplo.insertar_nodo(nuevo);
        nuevo = new Nodo_B(25);
        arbol_ejemplo.insertar_nodo(nuevo);
        nuevo = new Nodo_B(30);
        arbol_ejemplo.insertar_nodo(nuevo);
        nuevo = new Nodo_B(4);
        arbol_ejemplo.insertar_nodo(nuevo);
        nuevo = new Nodo_B(40);
        arbol_ejemplo.insertar_nodo(nuevo);
        nuevo = new Nodo_B(45);
        arbol_ejemplo.insertar_nodo(nuevo);
        nuevo = new Nodo_B(50);
        arbol_ejemplo.insertar_nodo(nuevo);
        nuevo = new Nodo_B(42);
        arbol_ejemplo.insertar_nodo(nuevo);
        nuevo = new Nodo_B(37);
        arbol_ejemplo.insertar_nodo(nuevo);
        arbol_ejemplo.Graficar_ArbolB();
    }
    
}
