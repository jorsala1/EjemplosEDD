package grafo

import (
	"fmt"
	"log"
	"os"
	"os/exec"
	"strconv"
)

// Nodo grafo
type nodo struct {
	dato int
	siguiente * nodo
	lista * ListaAdyasentes
}

//Lista nodos del grafo
type Grafo struct {
	inicio * nodo
	ultimo * nodo
}

//lista de nodos adyasentes 
//los nodos en la lista de adyasentes solo guardaran la informacion no la lista de adyasentes propia
type ListaAdyasentes struct {
	inicio * nodo
	ultimo * nodo
}

func NewGrafo() * Grafo {
	fmt.Println("se creo un nuevo grafo")
	return &Grafo{nil,nil}
}

//Funcion que agrega un nuevo nodo al grafo
func (g * Grafo) InsertarNuevo(dato int){
	//inicializo la lista
	listaAd := &ListaAdyasentes{nil,nil}
	nuevo := &nodo{dato,nil, listaAd} //se le envia la lista inicializada 

	//validaciones para insertar
	//se insertara siempre de ultimo
	if g.inicio == nil {
		g.inicio = nuevo
		g.ultimo = nuevo
	}else{
		g.ultimo.siguiente = nuevo
		g.ultimo = nuevo
	}
}

//funcion para agregar nodos adyasenes a los nodos
func (g * Grafo) AgregarAdyasente(dato int, ad int){
	//dato es el nodo al cual se le agregara un adyasente
	//ad sera el adyasente que se agrege
	// la lista de adyasentes de add siempre tiene que estar vacia
	
	//*** ambos nodos deben existir en el grafo antes de agregarse como adyasentes**
	nodografo := g.Buscar(dato)

	if nodografo == nil {
		fmt.Println("no se encontro el nodo dato en el grafo")
	}else{
		//buscar el nodo ad
		nosoAd := g.Buscar(ad)
		if nosoAd == nil{
			fmt.Println("no se encontro el nodo ad en el grafo")
		}else{
			//se crea un nodo nuevo con la info del nodo ad para que no modifique el siguiente del nodo original
			nodoad := &nodo{ad, nil,nil}
			//insertamos el nuevo nodo en la lista de adyasentes
			nodografo.lista.InsertarNuevoAd(nodoad)

			//** al no se dirigido se agregega el nodo grafo como adyadente del nodo ad
			//nodog := &nodo{dato,nil,nil}
			//nosoAd.lista.InsertarNuevoAd(nodog)
		}
	}

}

//Buscar nodo
func (g * Grafo) Buscar(dato int) * nodo {
	//verificar si el grafo esta vacio
	if g.inicio != nil {
		pivote := g.inicio
		for pivote != nil {
			if pivote.dato == dato {
				return pivote
			}else{
				pivote = pivote.siguiente
			}
		}
	}
	return nil
}

//Funcion que agrega un nuevo nodo adyasente a un nodo
func (l * ListaAdyasentes) InsertarNuevoAd(nuevo * nodo){

	//validaciones para insertar
	//se insertara siempre de ultimo
	if l.inicio == nil {
		l.inicio = nuevo
		l.ultimo = nuevo
	}else{
		l.ultimo.siguiente = nuevo
		l.ultimo = nuevo
	}
}

//graficar 
func (g * Grafo) Graficar(){
	os.Create("GraficaPila.dot")

	graphdot := getFile("GraficaPila.dot")

	fmt.Fprintf(graphdot, "graph G {\n")
	fmt.Fprintf(graphdot, "rankdir = LR; \n")
	fmt.Fprintf(graphdot, "subgraph cluster_1 { \n")
	fmt.Fprintf(graphdot, "node [color=lightblue2, style=filled, shape=circle]; \n")
	
	

	//recorrer el grafo 
	//crear nodos
	pivote := g.inicio
	var text_aux string = ""
	for pivote != nil {
		text_aux = "n"+ strconv.Itoa(pivote.dato) +"[label=\"dato"+strconv.Itoa(pivote.dato)+" \"] \n"
		fmt.Fprintf(graphdot,text_aux)
		pivote = pivote.siguiente
	}
	//enlazar adyasentes
	pivote = g.inicio
	for pivote != nil {
		pivoteAd := pivote.lista.inicio
		for pivoteAd != nil {
			text_aux = "n"+ strconv.Itoa(pivote.dato) +" -- n"+strconv.Itoa(pivoteAd.dato)+" \n"
			fmt.Fprintf(graphdot,text_aux)
			pivoteAd = pivoteAd.siguiente
		}
		pivote = pivote.siguiente
	}

	fmt.Fprintf(graphdot, "label = \"grafo\";\n")
	fmt.Fprintf(graphdot, "}\n")
	fmt.Fprintf(graphdot, "}\n")
	exec.Command("dot", "-Tpng", "GraficaPila.dot", "-o", "GraficaPila.png ").Output()

	graphdot.Close()
}

//obtener el archivo
func getFile(path string) *os.File {
	file, err := os.OpenFile(path, os.O_RDWR, 0775)

	if err != nil {
		log.Fatal(err)
	}
	return file
}