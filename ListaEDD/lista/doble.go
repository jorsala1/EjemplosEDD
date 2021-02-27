package lista

import (
	"fmt"
)

// Lugar donde almacenaremos la informacion
type nodo struct {
	anterior  *nodo
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
	nuevo := &nodo{nil, nil, valor}

	if m.inicio == nil {
		m.inicio = nuevo
		m.ultimo = nuevo
	} else {
		m.ultimo.siguiente = nuevo
		nuevo.anterior = m.ultimo
		m.ultimo = nuevo
	}
	m.tam++
}

// imprimir la lista
func (m *Lista) Imprimir() {
	aux := m.inicio
	if m.tam == 0 {
		fmt.Println("lista vacia")
	}else{
		for aux != nil {
			fmt.Print("<-[", aux.dato, "]->")
			aux = aux.siguiente
		}
		fmt.Println()
		fmt.Println("Tamaño lista = ", m.tam)
	}

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
	if m.tam == 0 {
		fmt.Println("lista vacia")
	}else{
		if m.tam == 1{
			m.inicio = nil
			m.ultimo = nil
			fmt.Println("el nodo es unico")
			m.tam--
		}else{
			if m.inicio == aux {

				m.inicio = aux.siguiente
				aux.siguiente.anterior = nil
				aux.siguiente = nil
				fmt.Println("el nodo es el inicio")
				m.tam--
		} else if m.ultimo == aux {
				m.ultimo = aux.anterior
				aux.anterior.siguiente = nil
				aux.anterior = nil
				fmt.Println("el nodo es el final")
				m.tam--
		} else {
				aux.anterior.siguiente = aux.siguiente
				aux.siguiente.anterior = aux.anterior
				aux.anterior = nil
				aux.siguiente = nil
				fmt.Println("el nodo es enmedio")
				m.tam--
		}

	}


}



}
