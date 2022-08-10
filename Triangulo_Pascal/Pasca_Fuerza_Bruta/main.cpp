/*
	*Universidad de las Fuerzas Armadas "ESPE"
   
     *Autores:
        De Veintemilla Luca
	Iza Christopher
	Rea Denise
	Vargas Kevin

	*Fecha de creacion: 
        * 10-08-2022
	*Fecha de modificacion:
        * 10-08-2022
    *GitHub del grupo:	
        https://github.com/ChristopherIza/GrupoParcial3.git
*/
#include<iostream>
#include "IngresoDatos.cpp"
using namespace std;
 
int main()
{
    int dimension;
    IngresoDatos ing;
    cout << "\n Implementacion Fuerza Bruta: ";
    cout << "\n Ingrese el numero de filas que desea: ";
    dimension = ing.IngresarDimension();
    cout << endl;
    for (int i = 0; i < dimension; i++)
    {
        int valor = 1;
        for (int j = 0; j <= i; j++)
        {
            cout << "      " << valor;
            valor = valor * (i - j) / (j + 1);
        }
        cout << endl << endl;
    }
    cout << endl;
    return 0;
}