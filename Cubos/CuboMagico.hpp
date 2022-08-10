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
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <vector>

#define DIM 3

class CuboMagico{
    private:
        int  **matriz;
    public:
        
        CuboMagico(int **);
        CuboMagico();
        void metodo1(int ,int);
        void encerar();
        void metodov1();
        void metodo2();
        void metodo3();
        void imprimirCubo();
        void mostrar(int, int);
        std::vector<int> pos_1();
        std::vector<int> pos_n(std::vector<int>);
        bool ocupado(std::vector<int>);
};




