/*
	*Universidad de las Fuerzas Armadas "ESPE"
   
     *Autores:
        De Veintemilla Luca
	Iza Christopher
	Rea Denise
	Vargas Kevin

	*Fecha de creacion: 
        * 09-08-2022
	*Fecha de modificacion:
        * 09-08-2022
    *GitHub del grupo:	
        https://github.com/ChristopherIza/GrupoParcial3.git
*/
#include "CuboLatino.hpp"
#include "time.h"
 CuboLatino::CuboLatino(int DIMENSION){
		n=DIMENSION;
	}

void CuboLatino::imprimirCuadrado(){
	int op;
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				op=(i+j)%n;
				if(op == 0)
				op = n;
				std::cout<<op<<" ";
			}
			std::cout<<"\n";
		}
	}


