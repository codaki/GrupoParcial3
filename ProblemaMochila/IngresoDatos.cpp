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

#include "IngresoDatos.hpp"
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <string>

int IngresoDatos::IngresarDatosEntero()
{
	char *dato=new char[10],c;
	int i=0,n= 0;
	
		while((c=_getch())!=13){
		if(c>='0'&& c<='9'){
			printf("%c",c);
			dato[i++]=c;
			n++;
				}
		else if(c==8||c==127){
			printf("\b \b");
			dato[i--]=0;
		}
			}
		dato[i]='\0';
	return atoi(dato);
}

std::string IngresoDatos::IngresoDatosnumericos_String()
{
    char *dato=new char[10],c;
	int i=0,n=0;
		while((c=_getch())!=13){
			//gotoXY(x+i,y);
		if(c>='0'&& c<='9' && n!=10){
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
	return dato;
}