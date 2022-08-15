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
#include "Vector.h"

/**
 * El destructor de la clase Vector.
 */
Vector::~Vector(){
    delete [] arrayInterno;
}

void Vector::push_back(const int &data) {

    if (elementos < capacidad) {
        arrayInterno[elementos] = data;
        elementos++;
    } else {
        auto tmp_arr = new int[capacidad * 2];
        capacidad *= 2;
        for (int i = 0; i < elementos; i++) {
            tmp_arr[i] = arrayInterno[i];
        }
        delete [] arrayInterno;
        arrayInterno = tmp_arr;

        arrayInterno[elementos] = data;
        elementos++;
    }
}

/**
 * Si la posición es válida, devuelva el elemento en esa posición. De lo contrario, lanzar una
 * excepción
 * 
 * @return Una referencia al elemento en la posición dada.
 */
int& Vector::operator[](int pos) {
    if (pos >= 0 &&  pos < elementos)
        return arrayInterno[pos];
    throw std::out_of_range("Elemento fuera de rango");
}

int Vector::size(){
    return elementos;
}

int Vector::capacity(){
    return capacidad;
}

void Vector::pop_back() {
    if (empty())
        return;
    elementos--;
}

void Vector::vaciar(){
    elementos = 0;
}


bool Vector::empty(){
    return elementos == 0;
}

int *Vector::get(int pos) {
    if (pos >= 0 && pos < elementos)
        return arrayInterno + pos;
    return 0;
}

int Vector::getElementos(){
    return this->elementos;
}

int *Vector::getArrayInterno(){
    return this->arrayInterno;
}

void Vector::imprimir(Vector &vect){
    for(int i = 0; i < vect.getElementos(); i++){
        cout << vect[i] << " ";
    }    
}

void Vector::unirVectores(Vector &vect){
    for(int i = 0; i < vect.size(); i++){
        push_back(vect[0]);
    }
}