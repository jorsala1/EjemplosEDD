/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package ejemplo_hash;

import java.io.IOException;

/**
 *
 * @author Josue
 */
public class Ejemplo_hash {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws IOException {
        // TODO code application logic here
        tabla_Hash tabla = new tabla_Hash();
        Nodo_Hash nuevo = new Nodo_Hash("josue");
        tabla.insertar_hash(nuevo);
        tabla.graficar_hash();
    }
    
}
