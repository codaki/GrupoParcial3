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
#include "Validacion.h"

using namespace std;

class Ingreso {

public:
	string leer(string,int);
};

string Ingreso::leer(string mensage,int tipo) {
	Validacion validacion;
	string entrada;
	cout << mensage << endl;
	cin >> entrada;
	while (validacion.validar(entrada, tipo)) {
		cout << "Valor no valido reingrese" << endl;
		cin >> entrada;
	}
	return entrada;

}
