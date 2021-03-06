package arbol

import (
	"fmt"
)

// nodo del arbol
type NodoABB struct {
	valor int
	izq   *NodoABB
	der   *NodoABB
}

//arbol binario
type Arbol struct {
	raiz *NodoABB
	tam  int
}

//creando nuevo arbol
func NewArbol() *Arbol {
	return &Arbol{nil, 0}
}

//Variable estatica que ayuda a verificar si el nodo existe o no
var Yaesta bool

//metodo para insertar un nuevo nodo
func (ar *Arbol) InsertarNodoABB(valor int) bool {
	nuevo := &NodoABB{valor, nil, nil}
	Yaesta = false
	if ar.raiz == nil {
		fmt.Println("se inserto la raiz")
		ar.raiz = nuevo
		ar.tam++
	} else {
		// LLamar metodo de insercion recursiva
		insertarABB(ar.raiz, nuevo)

		return Yaesta
	}
	return Yaesta
}

func insertarABB(raiz *NodoABB, nuevo *NodoABB) {
	if nuevo.valor > raiz.valor {
		if raiz.der == nil {
			fmt.Println("se inserto a la derecha")
			raiz.der = nuevo
		} else {
			// verificar nueva insecion
			insertarABB(raiz.der, nuevo)
		}
	} else if nuevo.valor < raiz.valor {
		if raiz.izq == nil {
			fmt.Println("se inserto a la izquierda")
			raiz.izq = nuevo

		} else {
			// verificar nueva insercion
			insertarABB(raiz.izq, nuevo)
		}
	} else if nuevo.valor == raiz.valor {
		fmt.Println("el nodo ya existe")
		Yaesta = true
	}
}

// Metodo para obtener un arbol de manera recursiva
func ObtenerNodo(raiz *NodoABB, valor int) *NodoABB {
	if raiz == nil {
		return nil
	} else if raiz.valor == valor {
		fmt.Println("se encontro el nodo")
		return raiz
	} else {
		var valor1 *NodoABB
		if valor > raiz.valor {
			valor1 = ObtenerNodo(raiz.der, valor)
		} else if valor < raiz.valor {
			valor1 = ObtenerNodo(raiz.izq, valor)
		}
		return valor1
	}
}

// Metodo que obtiene el nodo como tal
func (ar *Arbol) Obtener(valor int) *NodoABB {
	var retornado = ObtenerNodo(ar.raiz, valor)
	fmt.Println(retornado)
	return retornado
}

//funcion para retornar la cantidad de nodos del arbol
func (ar *Arbol) CantidadNodos() int {
	return ar.tam
}

//Metodo recursivo de profundidad de un arbol
func profundidad(raiz *NodoABB) int {
	if raiz == nil {

		return 0
	} else {
		var profizq = profundidad(raiz.izq)
		var profder = profundidad(raiz.der)

		if profizq > profder {

			return profizq + 1
		} else {
			return profder + 1
		}
	}
}

// Metodo para retornar el valor de la profundidad
func (ar *Arbol) RetornarProf() int {
	profundidad := profundidad(ar.raiz)
	fmt.Println("La profundidad es: ", profundidad)
	return profundidad
}

/*****************************RECORRIDOS**********************/
//Metodo recursivo para recorrer Inorden
// IZQ - RAIZ - DERECHA
func inorden(raia *NodoABB) {
	if raia.izq != nil {
		inorden(raia.izq)
	}

	fmt.Print("nodo: ", raia.valor, "    ")

	if raia.der != nil {
		inorden(raia.der)
	}
}

//metodo que retorna el recorrido
func (ar *Arbol) RecorridoInorden() {
	inorden(ar.raiz)
	fmt.Println("Termino el recorrido")
}

//Metodo recursivo para recorre Preorder
func Preorder(raiz *NodoABB) {
	fmt.Print("nodo: ", raiz.valor, "    ")

	if raiz.izq != nil {
		Preorder(raiz.izq)
	}

	if raiz.der != nil {
		Preorder(raiz.der)
	}
}

//metodo que retorna el recorrido
func (ar *Arbol) RecorridoPreorden() {
	Preorder(ar.raiz)
	fmt.Println("Termino el recorrido")
}

//Metodo recursivo para recorre Postorden
func postorden(raiz *NodoABB) {

	if raiz.izq != nil {
		postorden(raiz.izq)
	}

	if raiz.der != nil {
		postorden(raiz.der)
	}

	fmt.Print("nodo: ", raiz.valor, "    ")
}

//metodo que retorna el recorrido
func (ar *Arbol) RecorridoPostorden() {
	postorden(ar.raiz)
	fmt.Println("Termino el recorrido")
}
