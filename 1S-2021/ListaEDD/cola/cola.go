package cola

import "fmt"

type nodocola struct {
	siguiente *nodocola
	valor     int
}

type cola struct {
	frente *nodocola
	fondo  *nodocola
	tam    int
}

// crear cola
func NewCola() *cola {
	return &cola{nil, nil, 0}
}

//Metodo para verificar si la cola esta vacía
func (m *cola) ColaVacia() bool {
	return m.frente == nil
}

//Metodo para agregar datos a la cola
func (m *cola) Encolar(valor int) {
	aux := &nodocola{nil, valor}
	if m.ColaVacia() {
		m.frente = aux
		m.fondo = aux
	} else {
		m.fondo.siguiente = aux
		m.fondo = aux
	}
	m.tam++
}

//funcion para eliminar un dato de la cola
func (m *cola) Desencolar() {
	if !m.ColaVacia() {
		aux := m.frente
		m.frente = aux.siguiente
		aux = nil
		m.tam--
	} else {
		fmt.Println("la cola esta vacia")
	}
}

//mostrar cola de datos
func (m *cola) Mostrar() {
	if !m.ColaVacia() {
		aux := m.frente
		for aux != nil {
			fmt.Print("[", aux.valor, "]->")
			aux = aux.siguiente
		}
		fmt.Println()
	} else {
		fmt.Println("la cola esta vacia")
	}
}

//Metodo para ver el frente de la cola
func (m *cola) Front() *nodocola {
	fmt.Println("el frente es: ", m.frente)
	return m.frente
}

//Metodo para mostrar el fondo
func (m *cola) Rear() *nodocola {
	fmt.Println("el ultimo nodo es: ", m.fondo.valor)
	return m.fondo
}

//Metodo para vaciar la cola
func (m *cola) Vaciar() {
	if !m.ColaVacia() {
		for !m.ColaVacia() {
			m.Desencolar()
		}
	} else {
		fmt.Println("la cola esta vacia")
	}

}

//Metodo para retornar el tamaño de la cola
func (m *cola) Size() int {
	fmt.Println("el tamaño de la cola es: ", m.tam)
	return m.tam
}
