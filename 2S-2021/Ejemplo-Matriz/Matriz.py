from Nodo import NodoMatriz
from Nodo import NodoCabecera
from Nodo import NodoRaiz


class Matriz_ortogonal:
    def __init__(self):
        self.NodoRaiz=None
        
    def insertar_nodo_fila(self,nodo):
        temporalfila = self.NodoRaiz.NodoFilas 
        while(temporalfila.indice!=nodo.y): 
            temporalfila = temporalfila.siguiente
        #temporalfila=temporalfila.derecha
        if temporalfila.derecha is None:
            nodo.derecha=temporalfila.derecha 
            temporalfila.derecha = nodo 
        elif temporalfila.derecha.x >= nodo.x: 
            nodo.derecha = temporalfila.derecha
            temporalfila.derecha = nodo 
        else : 
            current = temporalfila.derecha 
            while(current.derecha is not None and current.derecha.x < nodo.x): 
                current = current.derecha
            nodo.derecha = current.derecha
            current.derecha = nodo
    def insertar_nodo_col(self,nodo):
        temporalcol = self.NodoRaiz.NodoColumnas 
        while(temporalcol.indice!=nodo.x): 
            temporalcol= temporalcol.siguiente
        #temporalcol=temporalcol.abajo
        if temporalcol.abajo is None: 
            nodo.abajo = temporalcol.abajo
            temporalcol.abajo = nodo
        elif temporalcol.abajo.y >= nodo.y: 
            nodo.abajo = temporalcol.abajo
            temporalcol.abajo = nodo
        else : 
            current = temporalcol.abajo
            while(current.abajo is not None and current.abajo.y < nodo.y): 
                current = current.abajo
            nodo.abajo = current.abajo
            current.abajo = nodo    
    def insertar_cabercera(self,nodo,indice,tipo):
        temporalfila=nodo
        if temporalfila.indice > indice: 
            nuevaCabecera=NodoCabecera(tipo=tipo,indice=indice)
            nuevaCabecera.siguiente = self.NodoRaiz.NodoFilas 
            self.NodoRaiz.NodoFilas = nuevaCabecera 
        else : 
            current = temporalfila 
            while(current.siguiente is not None and current.siguiente.indice <= indice): 
                current = current.siguiente
            if current.indice != indice:
                nuevaCabecera=NodoCabecera(tipo=tipo,indice=indice)
                nuevaCabecera.siguiente = current.siguiente
                current.siguiente = nuevaCabecera
                
    def insertar(self,x,y,informacion):
        nodoN = NodoMatriz(x=x,y=y,dato=informacion)
        if  self.NodoRaiz is None:
            self.NodoRaiz= NodoRaiz()
            self.NodoRaiz.NodoColumnas=NodoCabecera(tipo="Columna",indice=x) 
            self.NodoRaiz.NodoFilas=NodoCabecera(tipo="Fila",indice=y)
            self.NodoRaiz.NodoColumnas.siguiente =None   
            self.NodoRaiz.NodoFilas.siguiente =None
            self.NodoRaiz.NodoColumnas.abajo=nodoN
            self.NodoRaiz.NodoFilas.derecha=nodoN
        else:
            Nodotemporal=self.NodoRaiz
            self.insertar_cabercera(Nodotemporal.NodoFilas,y,"Fila")
            Nodotemporal=self.NodoRaiz
            self.insertar_cabercera(Nodotemporal.NodoColumnas,x,"Columna")
            self.insertar_nodo_fila(nodo=nodoN)
            self.insertar_nodo_col(nodo=nodoN)
    def buscar(self,x,y):
        nodo = self.NodoRaiz.NodoFilas
        while(nodo is not None):
            nodo_temp = nodo.derecha
            while(nodo_temp is not None):
                if nodo_temp.x ==x and nodo_temp.y==y:
                    return True
                nodo_temp=nodo_temp.derecha
            nodo=nodo.siguiente
        return False




