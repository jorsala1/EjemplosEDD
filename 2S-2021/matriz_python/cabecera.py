
#clase nodo cabecera
class nodo_cabecera:
    def __init__(self,dato):
        self.dato = dato
        self.ant = None
        self.sig = None
        self.lista = None
        
#clase lista cabecera
class lista_cabecera:
    def __init__(self):
        self.primero = None

    def insertar(self, dato):
        nuevo = nodo_cabecera(dato)
        if self.primero == None:
            self.primero = nuevo
        else: