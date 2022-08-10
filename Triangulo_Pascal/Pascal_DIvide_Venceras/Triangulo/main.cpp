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
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <sstream>
#include <iostream>
#include "Datos.cpp"
#include "Operaciones.cpp"
#include "Ingreso.h"
using namespace std;

int main()
{
	int opc;
	Ingreso ingreso;
		    int num;
		    
		    string dim1;
	do {
		Datos dato;
		int numero;
		Operaciones op;
		do {
		    	dim1=ingreso.leer("pasos inicial",2);
		    	istringstream (dim1) >> numero;

		} while (numero <= 0);
		dato.set_exp(numero);
		op.mostrar(dato);
		cout << "\n";
		cout << "1 continuar - 0 cerrar";
		cin >> opc;
	} while (opc != 0);
	
	
}
