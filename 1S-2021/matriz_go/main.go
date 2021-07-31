package main

import (
	"fmt"
	"./matriz"
)

func main() {
	fmt.Println("Matriz ortogonal")
	matriz := matriz.NewMatriz(1)

	matriz.Insertar(3,2,5)
	matriz.Insertar(3,1,6)
	matriz.Insertar(4,1,1)
	matriz.Insertar(1,1,0)

	matriz.MostarCabecerasX()
	matriz.MostarCabecerasY()

	matriz.Comprobar()//reorre las cabeceras X y muesta sus valores
	
}