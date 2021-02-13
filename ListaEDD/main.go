package main

import (
	"./pila"
)

func main() {

	lis := pila.NewPila()

	lis.Push(2)
	lis.Push(5)
	lis.Push(7)
	lis.Push(1)
	lis.Push(52)
	lis.Push(4)
	lis.Push(73)
	lis.Graph()
}
