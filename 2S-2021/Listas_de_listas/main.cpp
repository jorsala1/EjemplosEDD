#include <iostream>
#include"lista_alumnos.h"
using namespace std;

int main()
{
    //ejemplo de lista de alumnos
    //cada alumno tendra asociado cursos en una lista de cursos

    string op="";
    lista_alumnos * lista_nueva = new lista_alumnos();


    int carnet=0;
    string nombre ="";
    string apellido="";

    cout << "Ejemplo Listas dentro de listas" << endl;

    while(op!="6"){
        cout << "   Menu" << endl;
        cout << "1-> Insertar alumno" << endl;
        cout << "2-> Insertar curso a alumno" << endl;
        cout << "3-> Mostrar lista alumno" << endl;
        cout << "4-> Mostrar lista cursos de un alumno" << endl;
        cout << "5-> Mostrar lista de alumnos con sus cursos" << endl;
        cout << "6-> Salir"<<endl;

        cout << "\n Ingrese el # de opcion:       ";
        getline(cin, op);

        if(op =="1"){
            string c="0";
            cout << "Ingrese el carnet del alumno -> ";
            //cin>>carnet;
            getline(cin, c);
            cout << "\nIngrese el nombre del alumno -> ";
            getline(cin, nombre);
            //cin>>nombre>>apellido;


            try {
                carnet = stoi(c); //castear string a int
                cout<<"carnet-> "<<carnet<<" Nombre-> "<<nombre<<" "<<apellido<<endl;
                lista_nueva->insertar(carnet,nombre);

            } catch (const invalid_argument& ia) { // se pone el tipo de error que puede dar
                cout << "Tipo de dato invalido: " << ia.what() << '\n';
                cout<<"\n**************** ERROR AL INGRESAR DATOS **************** "<<endl;
            }

            cout<<"\n "<<endl;
        }else if(op=="2"){
            string c="";
            string cod="";
            string nombre_curso="";

            cout << "Ingrese el carnet del alumno -> ";
            getline(cin, c);

            cout << "\nIngrese el codigo del curso -> ";
            getline(cin, cod);

            cout << "\nIngrese el nombre del curso -> ";
            getline(cin, nombre_curso);

            try {
                carnet = stoi(c);
                int codigo_curso = stoi(cod);

                lista_nueva->agregar_curso(carnet,codigo_curso,nombre_curso);

            } catch (const invalid_argument& ia) { // se pone el tipo de error que puede dar
                cout << "Tipo de dato invalido: " << ia.what() << '\n';
                cout<<"\n**************** ERROR AL INGRESAR DATOS  **************** "<<endl;
            }
        }else if(op=="3"){
            lista_nueva->mostrar_alumnos();
        }else if(op=="4"){
            string c="0";
            cout << "Ingrese el carnet del alumno -> ";
            getline(cin, c);

            try {
                carnet = stoi(c);
                cout<<"************************************"<<endl;
                lista_nueva->mostrar_cursos_alumno(carnet);
                cout<<"************************************\n"<<endl;

            } catch (const invalid_argument& ia) { // se pone el tipo de error que puede dar
                cout << "Tipo de dato invalido: " << ia.what() << '\n';
                cout<<"\n**************** ERROR AL INGRESAR DATOS **************** "<<endl;
            }
        }


    }
    return 0;
}
