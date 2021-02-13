package pila

import (
	"fmt"
	"log"
	"os"
	"os/exec"
	"strconv"
)

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

//getFile is...
func getFile(path string) *os.File {
	file, err := os.OpenFile(path, os.O_RDWR, 0755)
	if err != nil {
		log.Fatal(err)
	}
	return file
}

func (m *pila) Graph() {
	os.Create("pila/GraficaPila.dot")
	graphdot := getFile("pila/GraficaPila.dot")

	fmt.Fprintf(graphdot, "digraph G { \n")
	fmt.Fprintf(graphdot, "rankdir = UD;\n")
	fmt.Fprintf(graphdot, "\tnode [shape=record,color=black];\n")
	fmt.Fprintf(graphdot, "label = \"Pila\";\n")
	fmt.Fprintf(graphdot, "color=black;\n")

	aux := m.cima
	contador := 0
	var text_aux string = ""

	for aux != nil {
		text_aux = "\t\tn_" + strconv.Itoa(contador) + "[label = \"Valor: " + strconv.Itoa(aux.valor) + "\"];\n"
		fmt.Fprintf(graphdot, text_aux)
		aux = aux.anterior
		contador++
	}

	for i := 0; i < contador-1; i++ {
		text_aux = "n_" + strconv.Itoa(i) + "->n_" + strconv.Itoa(i+1) + ";\n"
		fmt.Fprintf(graphdot, text_aux)
	}

	fmt.Fprintf(graphdot, "\t}\n")

	graphdot.Close()
	exec.Command("dot -Tpng pila/GraficaPila.dot -o pila/GraficaPila.png ").Output()
}
