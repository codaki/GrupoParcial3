/*
	*Universidad de las Fuerzas Armadas "ESPE"
   
     *Autores:
        De Veintemilla Luca
	Iza Christopher 
	Rea Denise
	Vargas Kevin

	*Fecha de creacion: 
        * 04-08-2022
	*Fecha de modificacion:
        * 05-08-2022
    *GitHub del grupo:	
        https://github.com/ChristopherIza/GrupoParcial3.git
*/
#include "IngresoDatos.hpp"
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <string>


int IngresoDatos::IngresarDatosEntero()
{
	std::cout<<"Ingrese el numero de Reinas por favor"<<std::endl;
	char *dato=new char[10],c;
	int i=0,n= 0;
	//do{
		while((c=_getch())!=13){
		if(c>='1'&& c<='8'&& n<=1){
			printf("%c",c);
			dato[i++]=c;
			n++;
				}
		else if(c==8||c==127){
			printf("\b \b");
			dato[i--]=0;
			n--;
		}
			}
			dato[i]='\0';
	//}while((c=_getch())==13 || n==0);
		return atoi(dato);
}



