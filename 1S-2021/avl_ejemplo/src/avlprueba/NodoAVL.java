/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package avlprueba;

/**
 *
 * @author chris
 */
public class NodoAVL {
    public int id;
    public String nickname;
    public String contrasena;
    public NodoAVL padre;
    public NodoAVL der;
    public NodoAVL izq;
    public NodoLista list;
    public NodoCola PPC;
    public NodoCola CDC;
    public int altura;
    public int FE;
    public int NFE;
    
    public NodoAVL(int id, String nickname, String contrasena){
        
        this.id = id;
        this.nickname = nickname;
        this.contrasena = contrasena;
        this.FE = 0;
        this.padre = null;
        this.der = null;
        this.izq = null;
        this.CDC = null;
        this.PPC = null;
        this.list = null;
    }
    public int getAltura() {
        return altura;
    }

    public NodoCola getCDC() {
        return CDC;
    }

    public NodoAVL getDer() {
        return der;
    }

    public int getFE() {
        return FE;
    }

    public int getId() {
        return id;
    }

    public NodoAVL getIzq() {
        return izq;
    }

    public NodoLista getList() {
        return list;
    }

    public int getNFE() {
        return NFE;
    }

    public NodoAVL getPadre() {
        return padre;
    }

    public NodoCola getPPC() {
        return PPC;
    }

    public void setAltura(int altura) {
        this.altura = altura;
    }

    public void setCDC(NodoCola CDC) {
        this.CDC = CDC;
    }

    public void setDere(NodoAVL der) {
        this.der = der;
    }

    public void setFE(int FE) {
        this.FE = FE;
    }

    public void setId(int id) {
        this.id = id;
    }

    public void setIzq(NodoAVL izq) {
        this.izq = izq;
    }

    public void setList(NodoLista list) {
        this.list = list;
    }

    public void setNFE(int NFE) {
        this.NFE = NFE;
    }

    public void setPadre(NodoAVL padre) {
        this.padre = padre;
    }

    public void setPPC(NodoCola PPC) {
        this.PPC = PPC;
    }
   
    
    public String getContrasena() {
        return contrasena;
    }

    public String getNickname() {
        return nickname;
    }

    public void setContrasena(String contrasena) {
        this.contrasena = contrasena;
    }

    public void setNickname(String nickname) {
        this.nickname = nickname;
    }
    
}
