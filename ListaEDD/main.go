package main

import (
	"fmt"

	"./lista"
)

func main() {

	lis := lista.NewLista()
	lis.Insertar(2)
	lis.Insertar(4)
	lis.Insertar(8)
	lis.Insertar(16)
	lis.Imprimir()
	fmt.Println("Se termino de imprimir lista")
	fmt.Println("__________________________________________")
	lis.Eliminar(16)
	lis.Imprimir()

}
