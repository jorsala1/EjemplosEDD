/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package ejemplo_hash;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import javax.swing.JOptionPane;

/**
 *
 * @author Josue
 */
public class tabla_Hash {
    Nodo_Hash claves [];
    int claves_usadas;
    int size_tabla;
    int num_reservacion;
    
    tabla_Hash(){
        claves = new Nodo_Hash[7];
        size_tabla =7;
    }
    
    void insertar_hash(Nodo_Hash nuevo){
        int indice = clacular_clave(nuevo.Nombre_cliente);
        
        if(this.claves[indice] == null){
           //JOptionPane.showMessageDialog(null, nuevo.Nombre_cliente+" -- indice: "+indice);
            claves[indice] = nuevo;
            this.claves_usadas++;
        }else{
           // JOptionPane.showMessageDialog(null, "manejar coliciones");
            int new_indice = solucion_coliciones(indice);
            claves[new_indice] = nuevo;
            this.claves_usadas++;
            //JOptionPane.showMessageDialog(null, nuevo.Nombre_cliente+" -- indice: "+new_indice);
           // JOptionPane.showMessageDialog(null, "indice: "+new_indice);
        }
        
        double P_uso=0;
        P_uso=(double)((double)this.claves_usadas /(double)this.size_tabla);
        
        if(P_uso >= 0.5){
              rehash();
        }
        
        this.num_reservacion++;
    }
    
    int clacular_clave(String nombre){
        //JOptionPane.showMessageDialog(null, nombre);
        int result=0;
        int k = (int)nombre.charAt(0) + (int)nombre.charAt(1) + (int)nombre.charAt(2);
        result = k % this.size_tabla;
        return result;
    }
    
    int solucion_coliciones(int indice){
        int new_indice=0;
        int i=0;
        boolean disponible=false;
        
        while(disponible == false){
            new_indice = indice + (int)Math.pow((i+1), 2);
            if(new_indice >= this.size_tabla){
                new_indice = new_indice - this.size_tabla;
            }
            if(this.claves[new_indice] == null){
                disponible = true;
            }
            i++;
        }
        return new_indice;
    }
    
    void rehash(){
        // encontrando un numero primo para redimencionar la tabla
        boolean es_primo= false ;
        int new_tam = this.size_tabla;

        while(es_primo == false){
            new_tam++;
            int cont=0;
            for(int i = new_tam; i > 0; i--){
                if(new_tam % i == 0 ){
                    cont++;
                }
            }
            if(cont == 2){
                es_primo = true;
            }
        }
    //--------------------------------------------------     
        Nodo_Hash aux [] = new Nodo_Hash[this.size_tabla];
        aux = this.claves;
            this.size_tabla = new_tam;

        Nodo_Hash new_claves [] = new Nodo_Hash[new_tam];
        this.claves = new_claves;
        this.claves_usadas=0;

        for(int i=0; i< aux.length; i++){
            if(aux[i]!= null){
                this.insertar_hash(aux[i]);
            }
        }
    }
    
    void graficar_hash() throws IOException{
        String path = System.getProperty("user.home") + "\\Desktop\\Hash.dot";
        File archivo = new File(path);
        BufferedWriter bw = null;
        bw = new BufferedWriter(new FileWriter(archivo));
            bw.write("digraph Hash{\n"
                    + "rankdir=LR;\n"
                + " nodesep=0;\n"
                + "node [shape = box,fillcolor=\"azure2\" color=\"black\" style=\"filled\"];\n"
                +generar_nodosGrafo()
                +"}\n");
        bw.close();
         String do_path = "C:\\Program Files (x86)\\Graphviz2.38\\bin\\dot.exe";
        String file_input_path = System.getProperty("user.home") + "\\Desktop\\Hash.dot";
        String file_get_path = System.getProperty("user.home") + "\\Desktop\\Hash.jpg";
        try {
            ProcessBuilder pBuilder;
            pBuilder = new ProcessBuilder(do_path, "-Tjpg", "-o", file_get_path, file_input_path);
            pBuilder.redirectErrorStream(true);
            pBuilder.start();
        } catch (Exception ex) {
            ex.printStackTrace();
        }
    }
    
    String generar_nodosGrafo(){
        String nodos="";
        for(int i =this.claves.length -1 ; i>=0 ; i--){
           if(this.claves[i]!=null){
               
               nodos+="node[shape=record    label=\"{"+i+"| - nombre: "
                       +this.claves[i].Nombre_cliente+"- }\";]v"+i+"\n";
           }else{
               nodos+="node[shape=record    label=\"{"+i+"|-CLAVE VACIA-}\";]v"+i+"\n";
           }
        }
        return nodos;
    }
    
    
}
