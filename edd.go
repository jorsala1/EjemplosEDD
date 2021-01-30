package main

import (
	"fmt"
)

// Pequeño objeto
type persona struct {
	iden   int
	nombre string
}

func main() {
	juanito := persona{
		iden:   132,
		nombre: "Juanito",
	}

	fmt.Printf("%+v", juanito)
}
