package main

import ("./arbol")

func main() {

	arbol := arbol.NewArbol()
	arbol.InsertarNodoABB(5)
	arbol.InsertarNodoABB(10)
	arbol.InsertarNodoABB(1)
	arbol.InsertarNodoABB(23)
	arbol.InsertarNodoABB(18)
	arbol.Obtener(23)


/*	lis := pila.NewPila()
	listaaa := lista.NewLista()

	lis.Push(2)
	lis.Push(5)
	lis.Push(7)
	lis.Push(1)
	lis.Push(52)
	lis.Push(4)
	lis.Push(73)
	lis.Mostrar()
	lis.Graph()

	listaaa.Insertar(12)
	listaaa.Insertar(14)
	listaaa.Insertar(15)
	//listaaa.Imprimir()
	listaaa.Eliminar(12)
	//listaaa.Imprimir()
	listaaa.Eliminar(15)
	listaaa.Eliminar(14)
	listaaa.Eliminar(14)
	//listaaa.Imprimir()*/



}
