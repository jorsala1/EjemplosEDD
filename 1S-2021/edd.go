package main

import (
	"encoding/json"
	"fmt"
	"io/ioutil"
	"log"
	"net/http"

	"github.com/gorilla/mux"
)

type Tienda struct {
	Nombre       string
	Descripcion  string
	Contacto     string
	Calificacion int
}

type Departamento struct {
	Nombre  string
	Tiendas []Tienda
}

type Dato struct {
	Indice        string
	Departamentos []Departamento
}

type Sobre struct {
	Datos []Dato
}

func main() {
	fmt.Println("se levanto el server")
	request()
}

func homePage(w http.ResponseWriter, r *http.Request) {
	fmt.Fprintf(w, "Servidor en Go")
}

func getArreglo(w http.ResponseWriter, r *http.Request) {
	fmt.Fprintf(w, "[1,2,3,4]")
}

func metodopost(w http.ResponseWriter, r *http.Request) {
	body, _ := ioutil.ReadAll(r.Body)
	var re Sobre
	json.Unmarshal(body, &re)
	fmt.Println("Se cargaron los datos")
	w.Header().Set("Content-Type", "application/json")
	json.NewEncoder(w).Encode(re.Datos[0].Departamentos[0].Tiendas[0])
	//fmt.Fprintln(w, re.Datos[0].Departamentos[0].Tiendas[0])
}

func request() {
	myrouter := mux.NewRouter().StrictSlash(true)
	myrouter.HandleFunc("/", homePage)
	myrouter.HandleFunc("/getArreglo", getArreglo).Methods("GET")
	myrouter.HandleFunc("/cargadatos", metodopost).Methods("POST")
	log.Fatal(http.ListenAndServe(":3000", myrouter))
}
