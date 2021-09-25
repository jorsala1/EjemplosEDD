#lista interna 
class nodo_interno:
    def __init__(self, valor, x,y):
        self.valor = valor
        self.pos_x = x
        self.pos_y = y

        #apuntadores
        self.ant = None
        self.sig = None

        self.arriba = None
        self.abajo = None

class lista_interna:
    def __init__(self):
        self.primero = None

    def insertar_x(self, valor, x,y):
        nuevo = nodo_interno(valor,x,y)

        if self.primero:
            if nuevo.pos_y < self.primero.pos_y:
                nuevo.sig = self.primero
                self.primero.ant = nuevo
                self.primero = nuevo
            else:
                aux = self.primero
                while aux:
                    if nuevo.pos_y < aux.pos_y:
                        nuevo.sig = aux
                        nuevo.ant = aux.ant
                        aux.ant.sig = nuevo
                        aux.ant = nuevo
                        break
                    elif nuevo.pos_x == aux.pos_x and nuevo.pos_y == aux.pos_y:
                        print("ya esta ocupada esa posicion")
                        break
                    else: 
                        if aux.sig == None:
                            aux.sig = nuevo
                            nuevo.ant = aux
                            break
                        else:
                            aux = aux.sig
        else: #si esta vacia se asigna nuevo al primero
            self.primero = nuevo
    
    def insertar_y(self, valor, x,y):
        nuevo = nodo_interno(valor,x,y)

        if self.primero:
            if nuevo.pos_x < self.primero.pos_x:
                nuevo.abajo = self.primero
                self.primero.arriba = nuevo
                self.primero = nuevo
            else:
                aux = self.primero
                while aux:
                    if nuevo.pos_x < aux.pos_x:
                        nuevo.abajo = aux
                        nuevo.arriba = aux.arriba
                        aux.arriba.abajo = nuevo
                        aux.arriba = nuevo
                        break
                    elif nuevo.pos_x == aux.pos_x and nuevo.pos_y == aux.pos_y:
                        print("ya esta ocupada esa posicion")
                        break
                    else: 
                        if aux.abajo == None:
                            aux.abajo = nuevo
                            nuevo.arriba = aux
                            break
                        else:
                            aux = aux.abajo
        else: #si esta vacia se asigna nuevo al primero
            self.primero = nuevo

    def recorrer(self):
        aux = self.primero
        while aux:
            print("valor =",aux.valor," - x = ",aux.pos_x , " y = ",aux.pos_y)
            aux = aux.sig         

    def recorrer_y(self):
        aux = self.primero
        while aux:
            print("valor =",aux.valor," - x = ",aux.pos_x , " y = ",aux.pos_y)
            aux = aux.abajo      

    def eliminar_x(self,pos_y):
        if self.primero:
            aux = self.primero

            while(aux):
                if aux.pos_y == pos_y:
                    #validamos que posicion estamos eliminando
                    if(aux == self.primero):
                        if aux.sig:
                            aux.sig.ant = None
                        self.primero = aux.sig
                        break
                    else:
                        aux.ant.sig = aux.sig
                        if aux.sig:
                            aux.sig.ant = aux.ant
                        break
                else:
                    aux = aux.sig
        else:
            print("no hay datos en la lista")

    def eliminar_y(self,pos_x):
        if self.primero:
            aux = self.primero
            while(aux):
                if aux.pos_x == pos_x:
                    #validamos que posicion estamos eliminando
                    if(aux == self.primero):
                        if aux.abajo:
                            aux.abajo.arriba = None
                        self.primero = aux.abajo
                        break
                    else:
                        aux.arriba.abajo = aux.abajo
                        if aux.abajo:
                            aux.abajo.arriba = aux.arriba
                        break
                else:
                    aux = aux.abajo
        else:
            print("no hay datos en la lista")


#lista cabeceras
class nodo_cabecera:
    def __init__(self, pos):
        self.posicion = pos
        self.sig = None
        self.ant = None
        self.lista_interna = lista_interna()

class lista_cabeceras:
    def __init__(self):
        self.primero = None
    
    def insertar(self, nuevo):
        if self.primero:
            if nuevo.posicion < self.primero.posicion:
                nuevo.sig = self.primero
                self.primero.ant = nuevo
                self.primero = nuevo
            else:
                aux = self.primero
                while aux:
                    if nuevo.posicion < aux.posicion:
                        nuevo.sig = aux
                        nuevo.ant = aux.ant
                        aux.ant.sig = nuevo
                        aux.ant = nuevo
                        break
                    else: 
                        if aux.sig == None:
                            aux.sig = nuevo
                            nuevo.ant = aux
                            break
                        else:
                            aux = aux.sig
        else: #si esta vacia se asigna nuevo al primero
            self.primero = nuevo

    def buscar_cabecera(self,dato):
        aux = self.primero
        while aux:
            if aux.posicion == dato:
                return aux
            else:
                aux = aux.sig
        return None

    def recorrer(self):
        aux = self.primero
        while aux:
            print(aux.posicion)
            aux = aux.sig
    
    def eliminar_cabecera(self,dato):
        if self.primero:
            aux = self.primero
            if self.primero.posicion == dato: #eliminar el primero
                if aux.sig:
                    aux.sig.ant = None
                self.primero = aux.sig
            else:
                while(aux):
                    if(aux.posicion == dato):
                        aux.ant.sig = aux.sig
                        if(aux.sig):
                            aux.sig.ant = aux.ant
                        break
                    else:
                        aux = aux.sig
                    
                

class matriz:
    def __init__(self, mes):
        self.mes = mes
        self.cabeceras_X= lista_cabeceras()
        self.cabeceras_y = lista_cabeceras()

    def insertar(self, valor,posx,posy):
        nodo_cabecera_x=None 
        nodo_cabecera_y=None

        if self.cabeceras_X and self.cabeceras_y:
            nodo_cabecera_x = self.cabeceras_X.buscar_cabecera(posx)
            nodo_cabecera_y = self.cabeceras_y.buscar_cabecera(posy)

        if nodo_cabecera_x == None:
            nodo_cabecera_x = nodo_cabecera(posx)
            self.cabeceras_X.insertar(nodo_cabecera_x)
        
        if nodo_cabecera_y == None:
            nodo_cabecera_y = nodo_cabecera(posy)
            self.cabeceras_y.insertar(nodo_cabecera_y)

        #ya que nos aseguramos que tengamos las cabeceras necesarias, procedemos a insertar el nodo interno
        #insertamos en X
        nodo_cabecera_x.lista_interna.insertar_x(valor,posx,posy)
        #insertar en Y
        nodo_cabecera_y.lista_interna.insertar_y(valor,posx,posy)

    def recorrer_matriz(self):
        print("#cabeceras en x")
        aux = self.cabeceras_X.primero
        while aux:
            print("     pos-> ",aux.posicion) 
            aux2 = aux.lista_interna.primero
            while aux2:
                print("         -", aux2.valor)
                aux2 = aux2.sig

            aux = aux.sig

        print("#cabeceras en Y")
        aux = self.cabeceras_y.primero
        while aux:
            print("     pos-> ",aux.posicion) 
            aux2 = aux.lista_interna.primero
            while aux2:
                print("         -", aux2.valor)
                aux2 = aux2.abajo
                
            aux = aux.sig
        
    def eliminar(self,posx,posy):
        cabecera_x = self.cabeceras_X.buscar_cabecera(posx)
        cabecera_y = self.cabeceras_y.buscar_cabecera(posy)

        if(cabecera_x != None and cabecera_y != None):
            #eliminar en la lista x
            cabecera_x.lista_interna.eliminar_x(posy)
            if(cabecera_x.lista_interna.primero == None):
                self.cabeceras_X.eliminar_cabecera(cabecera_x.posicion)
                
            cabecera_y.lista_interna.eliminar_y(posx)
            if(cabecera_y.lista_interna.primero == None):
                    self.cabeceras_y.eliminar_cabecera(cabecera_y.posicion)
        else:
            print("no existe esa posicion")




''' print("######################")
lista_int = lista_interna()
lista_int.insertar_x(1,5,6)
lista_int.insertar_x(2,5,1)
lista_int.insertar_x(2,5,2)
lista_int.recorrer() 

#prueba listas internas
lista = lista_interna()
lista.insertar_y(5,1,1)
lista.insertar_y(6,2,1)
lista.insertar_y(7,3,1)

lista.recorrer_y()

lista.eliminar_y(3)
print("con valores eliminados ****************")
lista.recorrer_y()

#cabeceras 
lista = lista_cabeceras()
lista.insertar(nodo_cabecera(6))
lista.insertar(nodo_cabecera(1))
lista.insertar(nodo_cabecera(2))
lista.recorrer()

print("con valores eliminados ****************")
lista.eliminar_cabecera(6)
lista.recorrer()
'''

#insertar en matriz
matriz1 = matriz("junio")
               #(v,x,y)
matriz1.insertar(1,5,2)
matriz1.insertar(2,1,1)
matriz1.insertar(3,4,1)
matriz1.insertar(4,4,2)
matriz1.recorrer_matriz()

print("con valores eliminados ****************")
matriz1.eliminar(5,2)
matriz1.recorrer_matriz()
