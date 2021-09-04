class NodoMatriz:
    def __init__(self, x = None, y = None, dato = None,arriba=None,abajo=None,izquierda=None,derecha=None):
        self.x=x
        self.y=y
        self.dato=dato
        self.arriba=arriba
        self.abajo=abajo
        self.izquierda= izquierda
        self.derecha = derecha

class NodoCabecera:
    def __init__(self,tipo=None,indice=None,siguiente=None,derecha=None,abajo=None):
        self.tipo=tipo
        self.indice=indice
        self.siguiente=siguiente
        self.derecha=derecha
        self.abajo=abajo
class NodoRaiz:
    def __init__(self):
        self.NodoFilas=None
        self.NodoColumnas=None
