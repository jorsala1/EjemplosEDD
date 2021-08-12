#include <iostream>
#include <fstream>
#include <string>
#include <bits/stdc++.h>
#include "lista_simple.h"

using namespace std;
//C:\Users\joshu\Desktop\prueba.txt

void insertar_data(string info, lista_simple * lista){
    string del =",";
    int start = 0; //posicion inicial en el string
    int end_pos = info.find(del); //posicion donde encuentra el caracter por el que haremos el split
    //variables para guardar la info
    string id="0";
    string nombre="";

    cout<<"*****************"<<endl;
    cout<<info<<endl;
    while (end_pos != -1) {
        id =info.substr(start, end_pos - start);
        //cout << id << endl; //substr nos ayuda a operar un string quitando los caracteres indicados
        start = end_pos + del.size(); //la posicion de inicio la cambiamos para el caracter siguiente de la coma
        end_pos = info.find(del, start); // busca otra coma, al no encontrarla end_pos sera -1 y
    }
    //cout<<end_pos - start<<endl;
    nombre= info.substr(start, end_pos - start);
    //cout << nombre <<endl; // ahora la substraccion es desde el caracter siguiente a la coma hasta el final
    // substr si se le indica un numero negativo empieza a obtener los caracteres de derecha a izquierda
    cout<<"*****************\n"<<endl;

    lista->insertar(id,nombre);
}

int main()
{
    lista_simple * lista = new lista_simple();
    string ruta="";
    cout << "ingrese el path del archivo:  " ;
    cin>>ruta;

    string info;
    string info2;
    fstream my_file;
	my_file.open(ruta, ios::in);
	if (!my_file) {
		cout << "No such file";
	}
	else {

		while (1) {
			my_file >> info; //lectura por filas
			info2= info2+"\n" + info; // concatenar en una variable

			if (my_file.eof()){ //si el puntero llega al final del archivo, End Of File, nos salimos del ciclo
                break;
			}

            insertar_data(info,lista);

			//cout << info<<"-"<<endl;

		}
        my_file.close();
	}
    lista->mostrar();
	cout<<"*************************"<<endl;
	lista->buscar("4");
	//cout<<info2<<endl;

    return 0;
}
