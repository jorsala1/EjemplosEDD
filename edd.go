package main

import (
	"fmt"
	"net/http"

	"github.com/gorilla/mux"
)

func rutaInicial(w http.ResponseWriter, r *http.Request) {
	fmt.Fprintf(w, "Si funciono el servidor")
}

func main() {
	router := mux.NewRouter().StrictSlash(true)

	router.HandleFunc("/", rutaInicial)

	http.ListenAndServe(":3000", router)

}
