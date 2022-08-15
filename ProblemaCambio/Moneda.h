/*
	*Universidad de las Fuerzas Armadas "ESPE"
   
     *Autores:
            De Veintemilla Luca
	        Iza Christopher 
	        Rea Denise
	        Vargas Kevin
	*Fecha de creacion: 
        * 15-08-2022
	*Fecha de modificacion:
        * 15-08-2022
    *GitHub del grupo:	
        https://github.com/ChristopherIza/GrupoParcial3.git
*/
#include <iostream>
#include <stdlib.h>
#include <iomanip>
#include <cmath>
#include <vector>
#include <algorithm>
//#include "IngresoDatos.hpp"
#include "IngresoDatos.cpp"

using namespace std;

class Moneda{
	public:
		   int total;
		   int moneda();
		   vector<int> values = {0, 1, 5, 10, 20}; 
			void proceso();	
	
	
};