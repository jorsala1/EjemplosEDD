package main

import ( 
	"./grafo"
)

func  main()  {
	grafo := grafo.NewGrafo()
	grafo.InsertarNuevo(5)
	grafo.InsertarNuevo(2)
	grafo.InsertarNuevo(7)
	grafo.InsertarNuevo(4)
	grafo.AgregarAdyasente(5,2)
	grafo.AgregarAdyasente(5,7)
	grafo.AgregarAdyasente(7,4)
	grafo.AgregarAdyasente(4,5)

grafo.Graficar()
}