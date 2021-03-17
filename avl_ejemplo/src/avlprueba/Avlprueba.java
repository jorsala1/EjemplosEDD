/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package avlprueba;

import java.io.IOException;

/**
 *
 * @author chris
 */
public class Avlprueba {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws IOException {
        AVL avl = new AVL();
        avl.insertar(10, "ad", "ad");
        avl.insertar(5, "ad", "ad");
        avl.insertar(3, "ad", "ad");
        avl.insertar(6, "ad", "ad");
        avl.insertar(12, "ad", "ad");

        
        avl.preOrden(avl.raiz);
        
        avl.crear_grafo(1);
    }
    
}
