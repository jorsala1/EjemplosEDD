package main

import (
	"./pila"
)

func main() {

	lis := pila.NewPila()

	lis.Push(2)
	lis.Push(5)
	lis.Push(7)
	lis.Peek()
	lis.Pop()
	lis.Peek()
	lis.Size()
}
