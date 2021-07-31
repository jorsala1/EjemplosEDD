package lista_s

import (
	"fmt"
)

// Lugar donde almacenaremos la informacion
type nodo struct {
	siguiente *nodo
	dato      int
}

// Estructura para almacenar nodos de informacion
type Lista struct {
	inicio *nodo
	ultimo *nodo
	tam    int
}

// crear una nueva lista
func NewLista() *Lista {
	return &Lista{nil, nil, 0}
}

//insertar un nodo
func (m *Lista) Insertar(valor int) {
	nuevo := &nodo{nil, valor}

	if m.inicio == nil {
		m.inicio = nuevo
		m.ultimo = nuevo
	} else {
		m.ultimo.siguiente = nuevo
		m.ultimo = nuevo
	}
	m.tam++
}

// imprimir la lista
func (m *Lista) Imprimir() {
	aux := m.inicio
	for aux != nil {
		fmt.Print("<-[", aux.dato, "]->")
		aux = aux.siguiente
	}
	fmt.Println()
	fmt.Println("Tamaño lista = ", m.tam)
}

//Buscar Elemento dentro de lista
func (m *Lista) Buscar(valor int) *nodo {
	aux := m.inicio
	for aux != nil {
		if aux.dato == valor {
			fmt.Println("Si se encontro el nodo")
			return aux
		}
		aux = aux.siguiente
	}
	fmt.Println("NO se encontro el nodo")
	return aux
}

//Eliminar nodo de la lista
func (m *Lista) Eliminar(valor int) {
	aux := m.Buscar(valor)
	// Método no terminado
	if m.inicio != nil {
		if m.inicio == aux {
			m.inicio = aux.siguiente
			aux.siguiente = nil
		} else if m.ultimo == aux {

		} else {

			aux.siguiente = aux
			aux = nil
		}
		m.tam--
	} else {
		fmt.Println("la lista esta vacia")
	}

}
