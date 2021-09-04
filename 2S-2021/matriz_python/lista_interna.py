#clase nodo interno
from cabecera import nodo_cabecera


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

    def insertar(self,valor,x,y):
        nuevo = nodo_interno(valor,x,y)
        if(self.primero == None):
            self.primero = nu

