#include <iostream>
#include <thread>
#include <dos.h>
#include <conio.h>
#include <stdio.h>
#include "Complejidad.cpp"

void continua(){
    Complejidad complejidad;
    complejidad.complejidadContinua(); 
}
void lineal(){
    Complejidad complejidad;
    complejidad.complejidadLineal();
}
void LinealLogaritmico(){
    Complejidad complejidad;
    complejidad.complejidadLinealLogaritmica();
}
void Cuadratica(){
    Complejidad complejidad;
    complejidad.complejidadCuadratica();
}
void Exponencial(){
    Complejidad complejidad;
    complejidad.complejidadExponencial();
}
void conjunto(){
    continua();
    lineal();
    LinealLogaritmico();
}
int main(int argc, char **argv){

    //Complejidad complejidad;
    std::thread fist(conjunto);
    std::thread second(Cuadratica);
    Exponencial();
    system("start leertxt.R");
    std::cout<<"Programa en R ejecutado"<<std::endl;
    system("start ScriptEstruc.m");
   std::cout<<"Programa en matlab ejecutado"<<std::endl;
    
    
    
    return 0;
}