
#clase nodo interno
class nodo_interno:
    def __init__(self,valor,coordenada_x,coordenada_y):
        self.valor = valor
        self.x = coordenada_x
        self.y = coordenada_y
        self.sig = None
        self.ant = None

#clase lista interna
class lista_interna:
    def __init__(self):
        self.primero = None

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

#clase matriz
class matriz:
    def __init__(self, mes):
        self.mes = mes
        self.cabeceraX = None
        self.cabeceraY = None

    def buscar_cabecera(self, dato):
        aux = self.primero

        while aux:
            if aux.dato == dato:
                return aux
            aux = aux.sig
        
        return None

    
