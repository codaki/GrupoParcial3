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
#include <ctype.h>
#include <string.h>

using namespace std;

class Validacion {
public:
	bool validar(string, int);
};

bool Validacion::validar(string entrada, int tipo) {
	int contador = 0;
	try {
		for (int i = 0; i < entrada.length(); i++) {
			if (isalpha(entrada[i])) {
				throw 1;
			}
			if (!isdigit(entrada[i]) && tipo == 1) {
				throw 1;
			}
			if (entrada[i] == '.') {
				contador++;
			}
			if ((isdigit(entrada[i]) == 0 && entrada[i] != '.') || (contador>1)) {				
				throw 1;
			}			
		}	
	}
	catch (int e) {
		return true;
	}	
	return false;
}
