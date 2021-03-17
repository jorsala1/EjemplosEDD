/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package avlprueba;

import java.awt.Desktop;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;

/**
 *
 * @author chris
 */
public class AVL {

    public NodoAVL getRaiz() {
        return raiz;
    }

    public void setRaiz(NodoAVL raiz) {
        this.raiz = raiz;
    }
    public NodoAVL raiz;
    public int nodoshoja;
    public int nodosrama;
    public int alturaAvl;
    String arbol="";
    
    public AVL(){
        this.raiz = null;
        this.nodoshoja = 0;
        this.nodosrama = 0;
        this.alturaAvl = 0;
    }
    public NodoAVL buscar(int dato, NodoAVL auxiliar){
        
        if(auxiliar !=null){
            if(dato<auxiliar.id){
                return (buscar(dato,auxiliar.izq));
            }else if(dato>auxiliar.id){
                return (buscar(dato,auxiliar.der));
            }else{
                return auxiliar;
            }
        }else{
            return null;
        }
        
    }
    public int obtFE(NodoAVL raiz){
        if(raiz ==null){
            return -1;
        }else{
            return raiz.FE;
        }
    }
    public NodoAVL RotacionIzq(NodoAVL raiz){
        NodoAVL aux = raiz.izq;
        raiz.izq = aux.der;
        aux.der = raiz;
        raiz.FE = Math.max(obtFE(raiz.izq), obtFE(raiz.der))+1;
        aux.FE = Math.max(obtFE(aux.izq),obtFE(aux.der))+1;
        return aux;
    }
    public NodoAVL RotacionDer(NodoAVL raiz){
        NodoAVL aux = raiz.der;
        raiz.der = aux.izq;
        aux.izq = raiz;
        raiz.FE = Math.max(obtFE(raiz.izq), obtFE(raiz.der))+1;
        aux.FE = Math.max(obtFE(aux.izq),obtFE(aux.der))+1;
        return aux;
    }
    public NodoAVL RotacionDobleIzq(NodoAVL raiz){
        NodoAVL temp;
        raiz.izq = RotacionDer(raiz.izq);
        temp = RotacionIzq(raiz);
        return temp;
    }
    public NodoAVL RotacionDobleDer(NodoAVL raiz){
        NodoAVL temp;
        raiz.der = RotacionIzq(raiz.der);
        temp = RotacionDer(raiz);
        return temp;
    }
    void addNFE(NodoAVL raiz){
        if(raiz!=null){
            int maxHD = Math.max(obtFE(raiz.izq), obtFE(raiz.der));
            int maxHI = Math.min(obtFE(raiz.izq), obtFE(raiz.der));
            raiz.NFE = maxHI-maxHD;
            addNFE(raiz.izq);
            addNFE(raiz.der);
        }
    }
    void insertar(int id,String nickname,String pass){
        NodoAVL nuevo = new NodoAVL(id,nickname,pass);
        if(getRaiz()==null){
            setRaiz(nuevo);
        }else{
            setRaiz(insertarAVL(nuevo, this.getRaiz()));
        }
    }
    public NodoAVL insertarAVL(NodoAVL nuevo,NodoAVL subArb){
        NodoAVL nuevoPadre = subArb;
        if(nuevo.id<subArb.id){
            if(subArb.izq==null){
                subArb.izq = nuevo;
            }else{
                subArb.izq = insertarAVL(nuevo,subArb.izq);
                if((obtFE(subArb.izq)-obtFE(subArb.der)==2)){
                    /*if(nuevo.id< subArb.izq.id){
                        nuevoPadre = RotacionIzq(subArb);
                    }else{
                        nuevoPadre = RotacionDobleIzq(subArb);
                    }*/
                }
            }
        }else if(nuevo.id>subArb.id){
            if(subArb.der==null){
                subArb.der = nuevo;
            }else{
                subArb.der = insertarAVL(nuevo,subArb.der);
                if((obtFE(subArb.der)-obtFE(subArb.izq)==2)){
                   /* if(nuevo.id>subArb.der.id){
                        nuevoPadre = RotacionDer(subArb);
                    }else{
                        nuevoPadre = RotacionDobleDer(subArb);
                    }*/
                }
            }
        }else{
            System.out.println("No se aceptan repetidos");
        }
        //actualizar altura
        if((subArb.izq==null)&&(subArb.der!= null)){
            subArb.FE = subArb.der.FE +1;
        }else if((subArb.der==null)&&(subArb.izq!=null)){
            subArb.FE = subArb.izq.FE +1;
        }else{
            subArb.FE = Math.max(obtFE(subArb.izq), obtFE(subArb.der))+1;
        }
        return nuevoPadre;
    }
   /* public void preOrden(NodoAVL raiz){
        if(raiz!=null){
            System.out.print(raiz.id+ " ");
            preOrden(raiz.izq);
            preOrden(raiz.der);
        }
    }*/
    public void enOrden(NodoAVL raiz){
        if(raiz!=null){           
            enOrden(raiz.izq);
            System.out.print(raiz.id+ " ");
            enOrden(raiz.der);
        }
    }
    
    // METODOS PARA GENERAR GRAFO
    // SE UTILIZAN LOS RECORRIDOS PARA CREAR EL GRAFO DEL ARBOL
    //PREORDEN GRAFICA NODOS DEL ARBOL
    //IN ORDEN LAS FLECHAS QUE ENLAZAN LOS NODOS DEL ARBOL
    public void preOrden(NodoAVL R){
            if(R != null){
            
            arbol += "node" + " [label = \"username: " + R.getNickname() + "\n id: "+R.getId()+"\"]"+R.getId()+";\n";
            
            preOrden(R.izq);
            preOrden(R.der);
            
        }
    }
    public void inOrden(NodoAVL R){
        if(R != null){
            if(R.izq != null){
                arbol += R.getId()+ "->" + R.izq.getId()+ ";\n";
            }
            if(R.der != null){
                arbol += R.getId() + "->" + R.der.getId() + ";\n";
            }
         inOrden(R.izq);
         inOrden(R.der);
            
        }
    }
    
    public String concatenar_grafo(){
        String codigo = "";
        preOrden(raiz);
        inOrden(raiz);
        codigo = arbol;
        return codigo;
    }
        
    public String generar_reporte(int jugador) {
        String reporte;
        reporte = "digraph Hash{\n"
                + "node [color =\"turquoise\" ];\n"
                +"subgraph clusterMarco {\nlabel=\"Arbol Jugador"+jugador+" \";\ncolor=black;\n"
                + concatenar_grafo()
                // +ArbolB.graph
                + "}\n}";
        return reporte;
    }
    
    public void crear_grafo(int jugador) throws IOException{
        arbol="";
        String completo="";
         completo = this.generar_reporte(jugador);
        //System.out.println("Grafo:: \n" + grafo);
        String graf_path = System.getProperty("user.home") + "\\Desktop\\arbol.dot";
        File archivo = new File(graf_path);
        BufferedWriter bw;

        if (archivo.exists()) {
            bw = new BufferedWriter(new FileWriter(archivo));
            bw.write(completo);
        } else {
            bw = new BufferedWriter(new FileWriter(archivo));
            bw.write(completo);
        }

        bw.close();
        
        String do_path = "C:\\Program Files (x86)\\Graphviz2.38\\bin\\dot.exe";
        String file_input_path = System.getProperty("user.home") + "\\Desktop\\arbol.dot";
        String file_get_path = System.getProperty("user.home") + "\\Desktop\\arbol.jpg";
        
        try {
                
            ProcessBuilder pBuilder;

            pBuilder = new ProcessBuilder(do_path, "-Tjpg", "-o", file_get_path, file_input_path);
            pBuilder.redirectErrorStream(true);

            pBuilder.start();
            
            //Desktop.getDesktop().open(new File(file_get_path));

        } catch (Exception ex) {
            ex.printStackTrace();
        }
    }
}
