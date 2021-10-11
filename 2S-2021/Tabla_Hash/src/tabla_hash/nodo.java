/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package tabla_hash;

/**
 *
 * @author Josue
 */
public class nodo {
    int hash;
    int carnet;
    String nombre;
    
    nodo(int carnet, String nombre){
        this.carnet = carnet;
        this.nombre = nombre;
    }
    
}
