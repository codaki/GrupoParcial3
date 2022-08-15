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

#pragma once
#include <iostream>
#include <string>

using std::cout; 
using std::cin;
using std::endl; 
using std::string;

class Vector {

    //int es un tipo definido entero long long sin signo
    private:
        int *arrayInterno = new int[10];
        int capacidad{10};
        int elementos{0};

    public:
        Vector(){};
        ~Vector();

        void push_back(const int &data);
        void pop_back();
        void vaciar();
        bool empty();
        int size();
        int capacity();
        int& operator[](int pos);
        int *get(int);
        int getElementos();
        int *getArrayInterno();

        void imprimir(Vector &vector);

        void unirVectores(Vector &vect);

};
