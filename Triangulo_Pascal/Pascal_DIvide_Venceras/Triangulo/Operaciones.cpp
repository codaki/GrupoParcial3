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
#include <iostream>
#include "Operaciones.h"
using namespace std;


int Operaciones::factorial(int n){

    if (n < 1) {
        return 1;
    }
    else {
        return n * factorial(n - 1);
    }
}

int Operaciones::combinacion(int n, int m) {
    int combinacion;
    combinacion = factorial(n) / (factorial(m) * factorial(n - m));
    return combinacion;
}

void Operaciones::mostrar(Datos _dato) {
    
    for (int i = 0; i <= _dato.get_exp(); i++)
    {
        cout << "Grado: " << i<<" ";
        for (int j = _dato.get_exp()-i ; j >0 ; j--)
        {
            cout << " ";
        }
        for (int k = 0; k <= i; k++)
        {
            cout << combinacion(i, k) << " ";
        }
        cout << endl;
    }
}