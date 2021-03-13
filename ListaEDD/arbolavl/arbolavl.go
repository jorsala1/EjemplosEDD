package arbolavl

import (
	"fmt"
)

// nodo del arbol
type NodoAVL struct {
	valor int
	izq   *NodoAVL
	der   *NodoAVL
	feq   int
}

//arbol binario
type Arbol struct {
	raiz *NodoAVL
	tam  int
}

//creando nuevo arbol
func NewArbol() *Arbol {
	return &Arbol{nil, 0}
}

//Variable estatica que ayuda a verificar si el nodo existe o no
var Yaesta bool

//metodo para insertar un nuevo nodo
func (ar *Arbol) InsertarNodoAVL(valor int) bool {
	nuevo := &NodoAVL{valor, nil, nil,0}
	Yaesta = false
	if ar.raiz == nil {
		fmt.Println("se inserto la raiz")
		ar.raiz = nuevo
		ar.tam++
	} else {
		// LLamar metodo de insercion recursiva
		insertarAVL(ar, ar.raiz, nuevo)

		return Yaesta
	}
	return Yaesta
}

func insertarAVL(ar *Arbol, raiz *NodoAVL, nuevo *NodoAVL) {
	if nuevo.valor > raiz.valor {
		if raiz.der == nil {
			fmt.Println("se inserto a la derecha")
			raiz.der = nuevo
		} else {
			// verificar nueva insecion
			insertarAVL(ar, raiz.der, nuevo)
		}
	} else if nuevo.valor < raiz.valor {
		if raiz.izq == nil {
			fmt.Println("se inserto a la izquierda")
			raiz.izq = nuevo

		} else {
			// verificar nueva insercion
			insertarAVL(ar, raiz.izq, nuevo)
		}
	} else if nuevo.valor == raiz.valor {
		fmt.Println("el nodo ya existe")
		Yaesta = true
	}
	Equilibrar(ar, raiz)
}

// Metodo para obtener un arbol de manera recursiva
func ObtenerNodo(raiz *NodoAVL, valor int) *NodoAVL {
	if raiz == nil {
		return nil
	} else if raiz.valor == valor {
		fmt.Println("se encontro el nodo")
		return raiz
	} else {
		var valor1 *NodoAVL
		if valor > raiz.valor {
			valor1 = ObtenerNodo(raiz.der, valor)
		} else if valor < raiz.valor {
			valor1 = ObtenerNodo(raiz.izq, valor)
		}
		return valor1
	}
}

// Metodo que obtiene el nodo como tal
func (ar *Arbol) Obtener(valor int) *NodoAVL {
	var retornado = ObtenerNodo(ar.raiz, valor)
	fmt.Println(retornado)
	return retornado
}

//funcion para retornar la cantidad de nodos del arbol
func (ar *Arbol) CantidadNodos() int {
	return ar.tam
}

//Metodo recursivo de profundidad de un arbol
func profundidad(raiz *NodoAVL) int {
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
func inorden(raia *NodoAVL) {
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
func Preorder(raiz *NodoAVL) {
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
func postorden(raiz *NodoAVL) {

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


//Metodo para obtener el padre
func obtenerPadreAVL(raiz *NodoAVL, valor int) *NodoAVL{
	if valor > raiz.valor{
		if valor == raiz.der.valor{
			return raiz
		}else{
		 return	obtenerPadreAVL(raiz.der, valor)
		}
	}else if valor < raiz.valor {
		if valor == raiz.izq.valor {
			return raiz
		}else{
		 return	obtenerPadreAVL(raiz.izq, valor)
		}
	}else{
		return nil
	}
}

//Rotaciones
func  rotII(ar *Arbol, n *NodoAVL, n1 *NodoAVL){
	n.izq = n1.der
	n1.der = n

	if n1.feq == -1{
		n.feq =0
		n1.feq = 0
	}else{
		n.feq = -1
		n1.feq = 0
	}
	if ar.raiz == n{
		n = n1
		ar.raiz = n1
	}else{
		temp := obtenerPadreAVL(ar.raiz, n.valor)
		if temp.izq == n{
			temp.izq = n1
		}else{
			temp.der = n1
		}
	}
	fmt.Println("Se realizo rotacion II ")
}

func  rotDD( ar *Arbol, n *NodoAVL, n1 *NodoAVL){
	n.der = n1.izq
	n.izq = n

	if n1.feq == 1 {
		n.feq =0
		n1.feq = 0
	}else{
		n.feq = 1
		n1.feq = 0
	}

	if ar.raiz == n {
		n = n1
		ar.raiz = n1
	}else{
		temp := obtenerPadreAVL(ar.raiz, n.valor)
		if temp.izq == n{
			temp.izq = n1
		}else{
			temp.der = n1
		}
	}
	fmt.Println("Se realizo rotacion DD ")
}

func rotID( ar *Arbol, n *NodoAVL, n1 *NodoAVL, n2 *NodoAVL){
	n.izq = n2.der
	n2.der = n
	n1.der = n2.izq
	n2.izq = n1

	if n2.feq == 1 {
		n1.feq = -1
	}else{
		n1.feq = 0
	}

	if n2.feq == -1{
		n.feq = 1
	}else{
		n.feq = 0
	}
	n2.feq = 0

	if ar.raiz == n {
		n = n2
		ar.raiz = n2
	}else{
		temp := obtenerPadreAVL(ar.raiz, n.valor)
		if temp.izq == n{
			temp.izq = n2
		}else{
			temp.der = n2
		}
	}

	fmt.Println("Se realizo rotacion ID ")
}

func  rotDI(ar *Arbol, n *NodoAVL, n1 *NodoAVL, n2 *NodoAVL){
	n.der = n2.izq
	n2.izq = n
	n1.izq = n2.der
	n2.der = n1

	if n2.feq == 1{
		n.feq = -1
	}else{
		n.feq = 0
	}

	if n2.feq == -1 {
		n1.feq = 1
	}else{
		n1.feq = 0
	}
	n2.feq = 0

	if ar.raiz == n{
		n = n2
		ar.raiz = n2
	}else{
		temp := obtenerPadreAVL(ar.raiz, n.valor)
		if temp.izq == n {
			temp.izq = n2
		}else{
			temp.der = n2
		}
	}

	fmt.Println("Se realizo rotacion DI ")
}

// Metodo que sirve para equilibrar el arbol
func  Equilibrar( ar * Arbol, raiz *NodoAVL){
	izq := profundidad(raiz.izq)
	der := profundidad(raiz.der)

	raiz.feq = der - izq

	if raiz.feq == -2{
		if raiz.izq.feq > 0{
			rotID(ar, raiz, raiz.izq, raiz.izq.der)
		}else{
			rotII(ar, raiz, raiz.izq)
		}
	}else if raiz.feq == 2{
		if raiz.der.feq < 0{
			rotDI(ar, raiz, raiz.der, raiz.der.izq)
		}else{
			rotDD(ar, raiz, raiz.der)
		}
	}
}