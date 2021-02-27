package arbol

import (
	"fmt"
)

// nodo del arbol
type NodoABB struct {
	valor int
	izq *NodoABB
	der *NodoABB
}

//arbol binario
type Arbol struct {
	raiz *NodoABB
}

//creando nuevo arbol
func NewArbol() *Arbol{
	return &Arbol{nil}
}

//Variable estatica que ayuda a verificar si el nodo existe o no
var Yaesta bool

//metodo para insertar un nuevo nodo
func (ar *Arbol) InsertarNodoABB(valor int) bool{
	nuevo := &NodoABB{valor,nil,nil}
	Yaesta = false
	if ar.raiz == nil{
		fmt.Println("se inserto la raiz")
		ar.raiz = nuevo
	}else{
		// LLamar metodo de insercion recursiva
		insertarABB(ar.raiz,nuevo)
		return Yaesta
	}
	return Yaesta
}


func insertarABB(raiz *NodoABB,nuevo *NodoABB){
	if nuevo.valor > raiz.valor{
		if raiz.der == nil{
			fmt.Println("se inserto a la derecha")
			raiz.der = nuevo
		}else{
			// verificar nueva insecion
			insertarABB(raiz.der,nuevo)
		}
	}else if nuevo.valor < raiz.valor{
		if(raiz.izq == nil){
			fmt.Println("se inserto a la izquierda")
			raiz.izq = nuevo
		}else{
			// verificar nueva insercion
			insertarABB(raiz.izq,nuevo)
		}
	}else if nuevo.valor == raiz.valor {
		fmt.Println("el nodo ya existe")
		Yaesta = true
	}
}

// Metodo para obtener un arbol de manera recursiva
func  ObtenerNodo(raiz *NodoABB, valor int) *NodoABB{

	if raiz == nil  {
		return nil
	}else if raiz.valor == valor{
		fmt.Println("se encontro el nodo")

		return  raiz
	}else{
		if valor > raiz.valor{
			fmt.Println("se corrio a la derecha")
			ObtenerNodo(raiz.der,valor)
		}else if valor < raiz.valor{
			fmt.Println("se corrido a la izquierda")
			ObtenerNodo(raiz.izq,valor)
		}else{

			return  nil
		}
	}
	return nil
}

// Metodo que obtiene el nodo como tal
func (ar *Arbol) Obtener(valor int) *NodoABB {
	retornado := ObtenerNodo(ar.raiz,valor)

	return retornado
}

//Metodo recursivo de profundidad de un arbol
func profundidad()  {
	
}




