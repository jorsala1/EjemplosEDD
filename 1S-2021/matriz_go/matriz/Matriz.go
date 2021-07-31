package matriz

import (
	"fmt"
)

type nodoInterno struct{ //nodo para guardar la informacion
	Valor int
	X int
	Y int
	SiguienteX *nodoInterno
	AnteriorX *nodoInterno

	SiguienteY *nodoInterno
	AnteriorY *nodoInterno
}

type listainterna struct{ //lista que tendra cada cabecera de la matriz
	Primero * nodoInterno
}

type  nodoCabecera struct{ //nodo de la cabecesa de la condenada x o y
	Valor int
	Siguiente *nodoCabecera
	Anterior *nodoCabecera
	Lista *listainterna
}

type listaCabecera struct{ //lista para las cabeceras, se usa la misma para Y y X
	Primero *nodoCabecera
	Ultimo *nodoCabecera
}

type Matriz struct{ //nodo central de la matriz 
	Capa int
	CabecerasX *listaCabecera
	CabecerasY *listaCabecera
}

//Funciones para creacion de los elementos de la matriz

//Nueva Matriz
func NewMatriz(Valor int) * Matriz{
	cabeceraX := NewCabecera()
	cabeceraY := NewCabecera()
	fmt.Println("se creo una nueva matriz")
	return &Matriz{Valor, cabeceraX, cabeceraY}
}

//Nueva lista cabecera
func NewCabecera() * listaCabecera{
	return &listaCabecera{nil,nil}
}

//Nueva lista interna
func NewLista() * listainterna{
	return &listainterna{nil}
}

//Funciones para el manejo de la matriz

//Buscar cabecera en matriz
func (m *listaCabecera) buscar(pos int) *nodoCabecera {
	aux := m.Primero

	for aux != nil {
		if aux.Valor == pos {
			return aux
		}
		aux = aux.Siguiente
	}

	return nil
}

//Insertar en matriz
func (m *Matriz) Insertar(posx int, posy int, id int) {
	//crear nuevo nodo
	nuevo := &nodoInterno{id,posx,posy,nil,nil,nil,nil} //los 4 apuntadores se inician como nulos

	//buscar cabeceras de X en la matriz
	cabecerax := m.CabecerasX.buscar(posx) 
	//si las cabeceras no existen se deben crear
	if cabecerax == nil {
		//se crea la lista interna de las cabeceras
		lista := &listainterna{nil}
		cabecerax = &nodoCabecera{posx,nil,nil,lista}
		m.CabecerasX.Insertarcabecera(cabecerax)
	}

	//buscar cabeceras de Y en la matriz
	cabeceray := m.CabecerasY.buscar(posy)
	if (cabeceray == nil){
		listay := &listainterna{nil}
		cabeceray =  &nodoCabecera{posy,nil,nil,listay}
		m.CabecerasY.Insertarcabecera(cabeceray)
	}


	//Insertar el nodo a las cabeceras
	//Insertar en X
	listaX := cabecerax.Lista
	
	
	//**** SE DEBE INSERTAR ORDENADO en X comparando los valores en y
	if (listaX.Primero == nil){ //si es nulo solo se agrega
		listaX.Primero = nuevo
	}else{
		if (nuevo.Y < listaX.Primero.Y){ //el nodo debe ir al inicio de la lista
			nuevo.SiguienteX = listaX.Primero
			listaX.Primero.AnteriorX = nuevo
			listaX.Primero = nuevo
			//return
		}else { //se recorre la lista para insertar ordenado
			pivote := listaX.Primero

			for pivote != nil {
				if (nuevo.Y < pivote.Y){
					nuevo.SiguienteX = pivote
					nuevo.AnteriorX = pivote.AnteriorX
					pivote.AnteriorX.SiguienteX = nuevo
				}else if (nuevo.Y == pivote.Y && nuevo.X == pivote.X ){//comparacion para saber si no se ha insertado una mis posicion
					fmt.Println("Ya existe un nodo es estas coordenadas")
					//return
					break
				} else{ //else el y del nuevo es mayor al del pivote 
					if (pivote.SiguienteX == nil){ //se valida si se llego al ultimo 
						pivote.SiguienteX = nuevo //si el siginete es nil 
						nuevo.AnteriorX = pivote
						//return
						break
					}else{
						pivote = pivote.SiguienteX //si no es el ultimo nos pasamos al siguiente y vuelve a iterar el ciclo
					}
				}
			}
		}
	}

	//Insertar el nodo a las cabeceras
	//Insertar en Y
	listaY := cabeceray.Lista

	//**** SE DEBE INSERTAR ORDENADO en Y comparando los valores en X
	if (listaY.Primero == nil){ //si es nulo solo se agrega
		listaY.Primero = nuevo
	}else{
		fmt.Println("entro aqui ****")
		if (nuevo.X < listaY.Primero.X){ //el nodo debe ir al inicio de la lista
			fmt.Println("entro aqui *")
			nuevo.SiguienteY = listaY.Primero
			listaY.Primero.AnteriorY = nuevo
			listaY.Primero = nuevo
			//return
		}else { //se recorre la lista para insertar ordenado
			pivote := listaY.Primero

			for pivote != nil {
				fmt.Println("entro aqui")
				if (nuevo.X < pivote.X){
					nuevo.SiguienteY = pivote
					nuevo.AnteriorY = pivote.AnteriorY
					pivote.AnteriorY.SiguienteY = nuevo
				}else if (nuevo.Y == pivote.Y && nuevo.X == pivote.X ){//comparacion para saber si no se ha insertado una mis posicion
					fmt.Println("Ya existe un nodo es estas coordenadas")
					//return
					break
				} else{ //else el y del nuevo es mayor al del pivote 
					if (pivote.SiguienteY == nil){ //se valida si se llego al ultimo 
						pivote.SiguienteY = nuevo //si el siginete es nil 
						nuevo.AnteriorY = pivote
						//return
						break
					}else{
						pivote = pivote.SiguienteY //si no es el ultimo nos pasamos al siguiente y vuelve a iterar el ciclo
					}
				}
			}
		}
	}
	
}


//Insertar cabeceras
func (m * listaCabecera) Insertarcabecera(nuevo * nodoCabecera) {
	
	if m.Primero == nil {
		m.Primero = nuevo
		m.Ultimo = nuevo
	}else{
		if m.Primero == m.Ultimo { //solo hay un dato
			if nuevo.Valor > m.Primero.Valor {
				m.Primero.Siguiente = nuevo
				nuevo.Anterior = m.Primero
				m.Ultimo = nuevo
			}else if nuevo.Valor < m.Primero.Valor{
				nuevo.Siguiente = m.Primero
				m.Primero.Anterior = nuevo
				m.Primero = nuevo
			}
		}else { //hay mas de un dato
			if nuevo.Valor < m.Primero.Valor { //es menor al Primero 
				nuevo.Siguiente = m.Primero
				m.Primero.Anterior = nuevo
				m.Primero = nuevo
			}else if nuevo.Valor > m.Ultimo.Valor { // es mayor al Ultimo
				m.Ultimo.Siguiente = nuevo
				nuevo.Anterior = m.Ultimo
				m.Ultimo = nuevo
			}else {
				aux := m.Primero

				for aux != nil {
					if nuevo.Valor < aux.Valor {
						nuevo.Siguiente = aux
						nuevo.Anterior = aux.Anterior
						aux.Anterior.Siguiente = nuevo
						aux.Anterior = nuevo
						return
					}
				}
			}
		}
	}
}

func (m *Matriz) Comprobar(){
	listaAux := m.CabecerasX
	pivote := listaAux.Primero
	fmt.Println("**** recorrer cabeceras x ****")
	for pivote != nil {
		fmt.Println("cabecera: ",pivote.Valor)
		listaInterna := pivote.Lista
		pivoteInterno := listaInterna.Primero
		if pivoteInterno != nil {
			for pivoteInterno != nil {
				fmt.Println(pivoteInterno.Valor)
				pivoteInterno = pivoteInterno.SiguienteX
			}
			
		}
		pivote = pivote.Siguiente
	}
	
}

func (m *Matriz) MostarCabecerasX(){
	listaAux := m.CabecerasX
	aux := listaAux.Primero
	fmt.Println("**** Cabeceras en  X ****")
	if (aux == nil){
		fmt.Println("No existen cabeceras creadas X")
		return
	}

	for aux != nil {
		fmt.Println(aux.Valor)
		aux = aux.Siguiente
	}
}

func (m *Matriz) MostarCabecerasY(){
	listaAux := m.CabecerasY
	auxy := listaAux.Primero
	fmt.Println("**** Cabeceras en  Y ****")
	if (auxy == nil){
		fmt.Println("No existen cabeceras creadas Y")
		return
	}

	for auxy != nil {
		fmt.Println(auxy.Valor)
		auxy = auxy.Siguiente
	}
}