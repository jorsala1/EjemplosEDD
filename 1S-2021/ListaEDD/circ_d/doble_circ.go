package circ_d

import "fmt"

type nodocd struct {
	anterior  *nodocd
	siguiente *nodocd
	valor     int
}

type listacd struct {
	inicio *nodocd
	fin    *nodocd
	tam    int
}

func NewListacd() *listacd {
	return &listacd{nil, nil, 0}
}

//verificar si la lista esta vacia
func (m *listacd) ListaVacia() bool {
	return m.inicio == nil
}

//Metodo para insertar al final
func (m *listacd) Insertar(valor int) {
	aux := &nodocd{nil, nil, valor}

	if m.ListaVacia() {
		m.inicio = aux
		m.fin = aux
		m.fin.siguiente = m.inicio
		m.inicio.anterior = m.fin
		fmt.Println("se inserto primer nodo")
	} else {
		aux.anterior = m.fin
		m.fin.siguiente = aux
		m.fin = aux
		m.fin.siguiente = m.inicio
		m.inicio.anterior = m.fin
		fmt.Println("se inserto otro nodo")
	}
	m.tam++
}

// Mostrar lista circular
func (m *listacd) Listar() {
	aux := m.inicio
	aux2 := m.inicio
	fmt.Print("  [", aux.valor, "]   ")
	aux = aux.siguiente
	if !m.ListaVacia() {
		for aux != aux2 {
			fmt.Print("  [", aux.valor, "]   ")
			aux = aux.siguiente
		}
	} else {
		fmt.Println("  LISTA VACIA  ")
	}

}

//Buscar un nodo en lista circular
func (m *listacd) Buscar(valor int) *nodocd {
	var aux *nodocd
	if !m.ListaVacia() {
		aux := m.fin
		for aux != nil {
			if aux.valor == valor {
				return aux
			}
			aux = aux.anterior
		}
	}
	fmt.Println("no se encontro")
	return aux
}
