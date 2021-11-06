import os
#ejemplo implementacion con lista de adyacencia de un grafo dirigido
class nodo:
    def __init__(self, dato):
        self.dato = dato
        self.sig = None
        self.lista_adyasentes = lista()

class lista: #lista adyacentes
    def __init__(self):
        self.inicio = None
        self.ultimo = None

    def insertar(self, dato):
        #crear nuevo nodo
        nuevo = nodo(dato)

        if self.inicio == None:
            self.inicio = nuevo
            self.ultimo = nuevo
        else:
            self.ultimo.sig = nuevo
            self.ultimo = nuevo
            

class grafo: 
    def __init__(self):
        self.inicio = None
        self.ultimo = None

    def insertar(self, dato):
        #crear nuevo nodo
        nuevo = nodo(dato)

        if self.inicio == None:
            self.inicio = nuevo
            self.ultimo = nuevo
        else:
            self.ultimo.sig = nuevo
            self.ultimo = nuevo

    def buscar(self, dato):
        aux = self.inicio
        while aux:
            if aux.dato == dato:
                return aux
            else:
                aux = aux.sig
        return None

    def agregar_adyasente(self,dato_nodo, adyasente):
        nodo_principal = self.buscar(dato_nodo)
        #se buscara si el dato del adyacente ya existe, si no se agrega
        nodo_ad = self.buscar(adyasente)
        if nodo_ad == None:
            self.insertar(adyasente)
        ######
        if nodo_principal:
            lista_ad = nodo_principal.lista_adyasentes
            lista_ad.insertar(adyasente)
            print("se agrego el adyasente")
        else:
            print("no se encontro el nodo origen")

    def mostrar_grafo(self):
        aux = self.inicio
        while aux:
           
            lista_ad = aux.lista_adyasentes
            info=""
            if lista_ad.inicio:
                aux2 = lista_ad.inicio
                while aux2!= None:
                    info+="-> "+str(aux2.dato)
                    aux2=aux2.sig
                    
            print("-" , aux.dato,info)
            aux = aux.sig

    def graficar(self):
        cadena = "digraph arbol {\n rankdir=\"LR\""
        #recorer los nodos para imprimirlos
        aux = self.inicio
        while aux:
            cadena+= "n"+str(aux.dato)+"[label= \""+str(aux.dato)+"\"];\n"
            aux = aux.sig

        #gaficar enlaces
        aux = self.inicio
        while aux:
            aux2= aux.lista_adyasentes.inicio
            while aux2:
                cadena+= "n"+str(aux.dato)+" -> n"+str(aux2.dato)+"\n"
                aux2 = aux2.sig
            aux = aux.sig
        cadena += "}"
        Archivo = open("ejemplo.dot","w+")
        Archivo.write(cadena)
        Archivo.close()
        os.system("fdp -Tpng -o graph-g.png ejemplo.dot")

    def cargar(self,data):
        aux = None
        for estudiante in data:
            print(estudiante['carnet'])
            self.insertar(estudiante['carnet'])
            if aux != None:
                self.agregar_adyasente(aux,estudiante['carnet'])
            aux=estudiante['carnet']
            


'''prueba = grafo()
prueba.insertar(5)
prueba.insertar(6)

prueba.agregar_adyasente(5,6)
prueba.agregar_adyasente(5,7)
prueba.agregar_adyasente(6,7)
prueba.agregar_adyasente(7,8)
prueba.agregar_adyasente(7,9)
prueba.agregar_adyasente(9,5)
prueba.mostrar_grafo()
prueba.graficar()'''