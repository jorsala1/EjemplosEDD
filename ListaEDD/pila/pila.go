package pila

import "fmt"

type nodopila struct {
	anterior *nodopila
	valor    int
}

type pila struct {
	cima *nodopila
	tam  int
}

func NewPila() *pila {
	return &pila{nil, 0}
}

func (m *pila) PilaVacia() bool {
	return m.cima == nil
}

func (m *pila) Push(val int) {
	nuevo := &nodopila{nil, val}
	if m.PilaVacia() {
		m.cima = nuevo
	} else {
		nuevo.anterior = m.cima
		m.cima = nuevo
	}
	m.tam++
}

func (m *pila) Pop() {
	if !m.PilaVacia() {
		aux := m.cima
		m.cima = aux.anterior
		fmt.Println("se saco un elemento de la pila")
		aux = nil
		m.tam--
	} else {
		fmt.Println("La pila esta vacia")
	}
}

func (m *pila) Peek() *nodopila {
	fmt.Println("La cima de la pila es: ", m.cima.valor)
	return m.cima
}

func (m *pila) Mostrar() {
	if !m.PilaVacia() {
		aux := m.cima
		for aux != nil {
			fmt.Print("[", aux.valor, "]->")
			aux = aux.anterior
		}
	} else {
		fmt.Println("La pila esta vacia")
	}

}

func (m *pila) Vaciar() {
	if !m.PilaVacia() {
		for !m.PilaVacia() {
			m.Pop()
		}
	} else {
		fmt.Println("La pila esta vacia")
	}
}

func (m *pila) Size() int {
	fmt.Println("el tamaño de la pila es: ", m.tam)
	return m.tam
}
