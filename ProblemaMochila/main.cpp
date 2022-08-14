/*
	*Universidad de las Fuerzas Armadas "ESPE"
   
     *Autores:
            De Veintemilla Luca
	         Iza Christopher 
	         Rea Denise
	         Vargas Kevin
	*Fecha de creacion: 
        * 14-08-2022
	*Fecha de modificacion:
        * 14-08-2022
   *GitHub del grupo:	
        https://github.com/ChristopherIza/GrupoParcial3.git
*/
#include <iostream>
#include "Mochila.cpp"
#include "IngresoDatos.cpp"
using namespace std;

int main() {
    Mochila* m = new Mochila();
    IngresoDatos In;
   cout << "Inserte el numero de objetos"<<endl;
   int n, W;
   n=In.IngresarDatosEntero();
   int v[n], w[n];
   for (int i = 0; i < n; i++) {
   cout <<"\nIngrese el valor del objeto N " << i << ":"<<endl;
      v[i]=In.IngresarDatosEntero();
    cout <<"\nIngrese el peso del objeto N " << i << ":"<<endl;
      w[i]=In.IngresarDatosEntero();
   }
   cout << "\nDigite el peso maximo de la mochila"<<endl;
   W=In.IngresarDatosEntero();
   cout <<"\n El resultado es:"<< m->solucion(W, w, v, n);
   return 0;
}