package main

import (
	"./arbol"
)

func main() {

	arbol := arbol.NewArbol()
	arbol.RetornarProf()
	arbol.InsertarNodoABB(5)
	arbol.InsertarNodoABB(10)
	arbol.InsertarNodoABB(1)
	arbol.InsertarNodoABB(23)
	arbol.InsertarNodoABB(18)
	arbol.InsertarNodoABB(18)
	arbol.InsertarNodoABB(5)
	arbol.RetornarProf()
	arbol.Obtener(23)
	arbol.RecorridoInorden()
	arbol.RecorridoPostorden()
	arbol.RecorridoPreorden()

}
