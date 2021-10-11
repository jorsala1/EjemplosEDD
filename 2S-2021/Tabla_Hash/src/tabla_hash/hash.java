/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package tabla_hash;

/**
 *
 * @author Josue
 * 
 * ejemplo tabla hash iniciando con 7 claves y creciondo al numero primo proximo
 */
public class hash {
    nodo claves [];
    int claves_usadas;
    int size;
    
    hash(){ //
        claves = new nodo[7];
        size =7;
    }
    
    //METODOS
    int calcular_hash(int carnet){
        //metodo de division
        int resultado;
        resultado = carnet % this.size;
        
        //multipiclacion
        /*int k = carnet;
        double A = 0.5497605;
        double mod = (k*A)- (int)(k*A);
        resultado = (int)(this.size * mod);*/
        //System.out.println(resultado);
        return resultado;
    }
    
    int solucion_coliciones(int indice){ //exploracion cuadratica
        int nuevo_indice =0;
        int i=0;
        boolean disponible=false;
        
        while(disponible == false){
            nuevo_indice = indice + (int)Math.pow(i,2);
            //validar indice menor a tamaño de la tabla
            if(nuevo_indice >= this.size){
                nuevo_indice = nuevo_indice - this.size;
            }
            //validar que el nuevo indice este disponible
            if(this.claves[nuevo_indice] == null){
                disponible = true;
            }
            i++;
        }
        
        return nuevo_indice;
    }
    
    void insertar(int carnet, String nombre){
        nodo nuevo = new nodo(carnet, nombre);
        
        int indice_hash = calcular_hash(carnet);
        
        //condiciones
        if(this.claves[indice_hash]==null){
            this.claves[indice_hash] = nuevo;
            this.claves_usadas++;
        }else{ //existe una colicion
            indice_hash = solucion_coliciones(indice_hash);
            this.claves[indice_hash] = nuevo;
            this.claves_usadas++;
        }
        
        //validar el tamaño
        double P_uso=0;
        P_uso=(double)((double)this.claves_usadas /(double)this.size);
        
        if(P_uso >= 0.5){
              rehash();
        }
    }
    
    void recorrer(){
        for(int i =0; i<this.size; i++){
            if (this.claves[i]!= null){
                System.out.println("["+this.claves[i].carnet+" - "+this.claves[i].nombre+"]");
            }else{
                 System.out.println("----------[]----------");
            }
        }
    }
    
    void rehash(){
        // encontrando un numero primo para redimencionar la tabla
        boolean es_primo= false ;
        int new_tam = this.size;

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
        nodo aux [] = new nodo[this.size];
        aux = this.claves;
            this.size = new_tam;

        nodo new_claves [] = new nodo[new_tam];
        this.claves = new_claves;
        this.claves_usadas=0;

        for(int i=0; i< aux.length; i++){
            if(aux[i]!= null){
                this.insertar(aux[i].carnet, aux[i].nombre);
            }
        }
    }
}
