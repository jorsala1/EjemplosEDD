/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package ejemplos_edd;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import javax.swing.JOptionPane;

/**
 *
 * @author Josue
 */
public class Arbol_B {
    
    Pagina raiz;
    int orden;
    int altura;
    
    Arbol_B(){
        this.raiz = null;
        this.orden = 5;
        this.altura = 0;
    }
    // metodos del arbol b
    
    int getAltura(){
        return this.altura;
    }
    
    void insertar_nodo(Nodo_B nuevo){ // recorrer el arbol para ver en que pagina tiene que insertar
        if(this.raiz == null){
            this.raiz = new Pagina();
            this.raiz.raiz = true;
            this.raiz = (Pagina)this.raiz.insertar_pagina(nuevo);
            System.out.print("se inserto el valor "+nuevo.valor +"\n");
        }else{
            if(this.altura == 0){ // no se a dividido la raiz
                Object respuesta_insertar = this.raiz.insertar_pagina(nuevo);
                if(respuesta_insertar instanceof Pagina){ // --------------------la raiz no se dividio 
                    this.raiz = (Pagina)respuesta_insertar; 
                    System.out.print("se inserto el getValor "+nuevo.valor +"\n");
                    
                }else if(respuesta_insertar instanceof Nodo_B){ // -----------------la raiz se dividio
                    this.altura++;
                    this.raiz = new Pagina();
                    Nodo_B nuevo_raiz = (Nodo_B)respuesta_insertar;
                    this.raiz = (Pagina)this.raiz.insertar_pagina(nuevo_raiz);
                }
            }else{//-------ya hay mas de una pagina, recorrer el arbol y ubicarse en la rama donde deveria de ir el nodo
                Object respuesta_insertar = insertar_recorrer(nuevo,this.raiz); // verificar que responde y si cambia la raiz
                
                if(respuesta_insertar instanceof Nodo_B){ //---- la raiz se dividio
                   // JOptionPane.showMessageDialog(null, "retorno un nodo a la raiz");
                    this.altura++;
                    this.raiz = new Pagina();
                    this.raiz.insertar_pagina((Nodo_B) respuesta_insertar);
                }else{
                    //JOptionPane.showMessageDialog(null, "retorno una pagina a la raiz");
                    this.raiz= (Pagina)respuesta_insertar;
                }
            }
        }
    }
    
    Object insertar_recorrer(Nodo_B nuevo, Pagina raiz_actual){
        //JOptionPane.showMessageDialog(null,"entro al metodo insertar_recorer");
        if(raiz_actual.Es_hoja(raiz_actual)){
            //JOptionPane.showMessageDialog(null,"entro a es hoja");
            Object respuesta_insertar = raiz_actual.insertar_pagina(nuevo);
            return respuesta_insertar;
        }else{ // recorrer la lista para insertar en donde se debe
            //JOptionPane.showMessageDialog(null,"entro al metodo si no es hoja");
            Object respuesta_insertar;
            if( nuevo.getValor() < raiz_actual.claves.getPrimero().getValor()){ //*------- si tiene que ir antes
                //JOptionPane.showMessageDialog(null,"entro a la izquierda");
                respuesta_insertar = insertar_recorrer(nuevo,raiz_actual.claves.getPrimero().izq);
                if(respuesta_insertar instanceof Nodo_B){ // la pagina hija se dividio y se tiene que insertar el nodo en est pagina
                    System.out.print("entro aqui, retorno un nodo \n");
                    return raiz_actual.insertar_pagina((Nodo_B)respuesta_insertar);
                }else{
                    System.out.print("entro aqui, retorno una pagina \n");
                    raiz_actual.claves.getPrimero().izq = (Pagina)respuesta_insertar;
                    return raiz_actual;
                }
            }else if(nuevo.getValor() > raiz_actual.claves.getUltimo().getValor()){ //*---- si es mayor al ultimo 
                //.showMessageDialog(null,"entro al ultimo");
                respuesta_insertar = insertar_recorrer(nuevo,raiz_actual.claves.getUltimo().der);
                if(respuesta_insertar instanceof Nodo_B){ // la pagina hija se dividio y se tiene que insertar el nodo en est pagina
                    System.out.print("entro aqui, retorno un nodo \n");
                    return raiz_actual.insertar_pagina((Nodo_B)respuesta_insertar);
                }else{
                    System.out.print("entro aqui, retorno una pagina \n");
                    raiz_actual.claves.getUltimo().der = (Pagina)respuesta_insertar;
                    return raiz_actual;
                }
            }else{
              //  JOptionPane.showMessageDialog(null,"entro aqui");
                Nodo_B pivote = raiz_actual.claves.getPrimero();
                
                while(pivote != null){
                    if(nuevo.valor < pivote.valor){
                        respuesta_insertar = insertar_recorrer(nuevo,pivote.izq);
                        if(respuesta_insertar instanceof Nodo_B){
                            return raiz_actual.insertar_pagina((Nodo_B)respuesta_insertar);
                        }else{
                            pivote.izq = (Pagina)respuesta_insertar;
                            pivote.anterior.der = (Pagina) respuesta_insertar;
                            return raiz_actual;
                        }
                    }else if(nuevo.valor == pivote.valor){
                        return raiz_actual;
                    }else{
                        pivote = pivote.siguiente;
                    }
                }
            }
        }
        
       return this;
    }
    
    Nodo_B buscar(Pagina raiz_actual, int codigo_buscar){
       Nodo_B pivote = raiz_actual.claves.primero;
        while(pivote != null){
            if(pivote.valor == codigo_buscar){
                return pivote;
            }else{
                pivote = pivote.siguiente;
            }
        }
        
        //si no lo encuentra en la pagina actual tiene que buscarlo en sus paginas hijos
        if(raiz_actual.Es_hoja(raiz_actual) == false){
            if(codigo_buscar < raiz_actual.claves.primero.valor){
                return buscar(raiz_actual.claves.primero.izq, codigo_buscar);
            }else if(codigo_buscar > raiz_actual.claves.ultimo.valor){
                return buscar(raiz_actual.claves.ultimo.der , codigo_buscar);
            }else{
                pivote = raiz_actual.claves.primero;
                while(pivote != null){
                    if(codigo_buscar < pivote.valor){
                        return buscar(pivote.izq, codigo_buscar);
                    }else{
                        pivote = pivote.siguiente;
                    }
                }
            }
        }
        return null;
    }
    
    void Graficar_ArbolB() throws IOException{
       String path = System.getProperty("user.home") + "\\Desktop\\ArbolB.dot";
        File archivo = new File(path);
        BufferedWriter bw = null;
        bw = new BufferedWriter(new FileWriter(archivo));
            bw.write("digraph arbolB{\n"
                    + "rankdir=TB;\n"
                + "node [shape = box,fillcolor=\"azure2\" color=\"black\" style=\"filled\"];\n"
                +recorer_GraficarNodos(this.raiz)
                +recorer_GraficarEnlaces(this.raiz)
                +"}\n");
        bw.close();
         String do_path = "C:\\Program Files (x86)\\Graphviz2.38\\bin\\dot.exe";
        String file_input_path = System.getProperty("user.home") + "\\Desktop\\ArbolB.dot";
        String file_get_path = System.getProperty("user.home") + "\\Desktop\\ArbolB.jpg";
        try {
            ProcessBuilder pBuilder;
            pBuilder = new ProcessBuilder(do_path, "-Tjpg", "-o", file_get_path, file_input_path);
            pBuilder.redirectErrorStream(true);
            pBuilder.start();
        } catch (Exception ex) {
            ex.printStackTrace();
        }
    }
    String recorer_GraficarEnlaces(Pagina raiz_actual){
        String grafo="";
        if(raiz_actual.Es_hoja(raiz_actual)){
            return ""+raiz_actual.claves.getPrimero().getValor()+";";
        }else{
            grafo+= ""+raiz_actual.claves.getPrimero().getValor()+";";
            
            Nodo_B pivote = raiz_actual.claves.getPrimero();
            int cont =0;
            String r_actual = ""+raiz_actual.claves.getPrimero().valor;
            while(pivote != null){
                grafo+="\n"+r_actual+":p"+cont+"->"+recorer_GraficarEnlaces(pivote.izq);
                cont++;
                pivote = pivote.siguiente;
            }
            grafo+="\n"+r_actual+":p"+cont+"->"+recorer_GraficarEnlaces(raiz_actual.claves.getUltimo().der);
            return grafo;
        }
    }
    
    String recorer_GraficarNodos(Pagina raiz_actual){
        String grafo="";
        if(raiz_actual.Es_hoja(raiz_actual)){//si es hoja solo se escribe su nodo 
            grafo+="node[shape=record label= \"<p0>";
            int cont=0;
            Nodo_B pivote = raiz_actual.claves.getPrimero();
            while(pivote != null){
                cont++;
                grafo+="|{"+pivote.getValor()+" }|<p"+cont+"> ";
                pivote= pivote.siguiente;
            }
            grafo+="\"]"+raiz_actual.claves.getPrimero().getValor()+"; \n";
            return grafo;
        }else{ // se escribe su nodo y se manda a llamar a cada uno de sus hijos 
           grafo+="node[shape=record label= \"<p0>";
            int cont=0;
            Nodo_B pivote = raiz_actual.claves.getPrimero();
            while(pivote != null){
                cont++;
                grafo+="|{"+pivote.getValor()+" }|<p"+cont+"> ";
                pivote= pivote.siguiente;
            }
            grafo+="\"]"+raiz_actual.claves.getPrimero().getValor()+"; \n";
            
            
            pivote= raiz_actual.claves.getPrimero();
            cont =0;
            while(pivote != null){
                String aux="";
                aux+= recorer_GraficarNodos(pivote.izq);
                grafo+= aux;
                cont++;
                pivote = pivote.siguiente;
            }
            grafo+= recorer_GraficarNodos(raiz_actual.claves.getUltimo().der);
            
            return grafo;
        }
    }
}
