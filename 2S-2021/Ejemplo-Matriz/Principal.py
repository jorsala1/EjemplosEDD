# -*- coding: utf-8 -*-
"""
@author: Jorge Salazar
### Matriz Ortogonal ######
"""
from Matriz import Matriz_ortogonal
import os


nueva_matriz = Matriz_ortogonal()

nueva_matriz.insertar(2,5,"nuevo nodo")
nueva_matriz.insertar(2,3,"nuevo nodo")
nueva_matriz.insertar(2,4,"nuevo nodo")
nueva_matriz.insertar(2,9,"nuevo nodo")
nueva_matriz.insertar(3,7,"nuevo nodo")
nueva_matriz.insertar(3,1,"nuevo nodo")
nueva_matriz.insertar(3,8,"nuevo nodo")
nueva_matriz.insertar(3,9,"nuevo nodo")
nueva_matriz.insertar(6,6,"nuevo nodo")
nueva_matriz.insertar(6,1,"nuevo nodo")
nueva_matriz.insertar(6,5,"nuevo nodo")
nueva_matriz.insertar(6,9,"nuevo nodo")
nueva_matriz.insertar(8,3,"nuevo nodo")
nueva_matriz.insertar(8,4,"nuevo nodo")
nueva_matriz.insertar(9,8,"nuevo nodo")
nueva_matriz.insertar(9,9,"nuevo nodo")
nueva_matriz.insertar(8,1,"nuevo nodo")
nueva_matriz.insertar(10,10,"nuevo nodo")
nueva_matriz.insertar(10,1,"nuevo nodo")
nodo = nueva_matriz.NodoRaiz.NodoColumnas


nodo = nueva_matriz.NodoRaiz.NodoFilas
while(nodo is not None):
    nodo_temp = nodo.derecha
    while(nodo_temp is not None):
        print("x:  "+str(nodo_temp.x)+ ", y:  "+str(nodo_temp.y))
        nodo_temp=nodo_temp.derecha
    nodo=nodo.siguiente
    
print("FIN Recorrido 1")
nodo = nueva_matriz.NodoRaiz.NodoColumnas
while(nodo is not None):
    nodo_temp = nodo.abajo
    while(nodo_temp is not None):
        print("x:  "+str(nodo_temp.x)+ ", y:  "+str(nodo_temp.y))
        nodo_temp=nodo_temp.abajo
    nodo=nodo.siguiente
    
print("FIN Recorrido 2")


def graficar_matriz():
    grafo = "digraph"
    grafo+=str("{\nnode[shape=record];\n")
    grafo+=str("graph[pencolor=transparent];\n")
    #grafo+=str("rankdir=LR;\n")
    grafo+=str("node [style=filled];\n")
    nodo = nueva_matriz.NodoRaiz.NodoFilas

    for y in range(1, 11):
        nodo_temp = nodo.derecha
        for x in range(1, 11):
            if(nueva_matriz.buscar(x,y)):
                grafo+=str("p"+str(x)+str(y)+"[label=\"{<data>"+str(x)+","+str(y)+"|<next>}\" pos=\""+str(x)+","+str(10-y)+"!\"];\n")
                if(nodo_temp.derecha!=None): 
                    nodo_2=nodo_temp
                    nodo_temp=nodo_temp.derecha
                    grafo+=str("p"+str(nodo_2.x)+str(nodo_2.y)+"->"+"p"+str(nodo_temp.x)+str(nodo_temp.y)+"[dir=both];\n")
            else:
                pass
            if nodo.siguiente!=None:
                if nodo.siguiente.indice==y+1:
                    nodo=nodo.siguiente    
    nodo = nueva_matriz.NodoRaiz.NodoColumnas
    for x in range(1, 11):
        nodo_temp = nodo.abajo
        for y in range(1, 11):
            if(nueva_matriz.buscar(x,y)):
                if(nodo_temp.abajo!=None):
                    nodo_2=nodo_temp
                    nodo_temp=nodo_temp.abajo
                    grafo+=str("p"+str(nodo_2.x)+str(nodo_2.y)+"->"+"p"+str(nodo_temp.x)+str(nodo_temp.y)+"[dir=both];\n")
            else:
                pass
            if nodo.siguiente!=None:
                if nodo.siguiente.indice==x+1:
                    nodo=nodo.siguiente         
    grafo+=str("}\n")
    f= open("ejemplo.dot","w+")
    f.write(grafo)
    f.close() 
    print("********* Se realizo Grafica *********  ")  
   # os.system("fdp -Tpng -o graph-g.png ejemplo.dot")


graficar_matriz()
