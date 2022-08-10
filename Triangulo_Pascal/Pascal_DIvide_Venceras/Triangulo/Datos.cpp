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
#pragma once
#include "Datos.h"
int Datos::get_exp() {
	return grado;
}

void Datos::set_exp(int _grado) {
	grado = _grado;
}