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
public class NodoLista {

    public String direccion;
    public int envio;
    public int facturacion;
    
    public NodoLista(String direccion, int envio, int facturacion){
        this.direccion = direccion;
        this.envio = envio;
        this.facturacion = facturacion;
    }
    
    public String getDireccion() {
        return direccion;
    }

    public int getEnvio() {
        return envio;
    }

    public int getFacturacion() {
        return facturacion;
    }

    public void setDireccion(String direccion) {
        this.direccion = direccion;
    }

    public void setEnvio(int envio) {
        this.envio = envio;
    }

    public void setFacturacion(int facturacion) {
        this.facturacion = facturacion;
    }
    
}
