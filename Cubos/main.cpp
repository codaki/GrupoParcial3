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
#include "CuboMagico.cpp"
#include "IngresoDatos.cpp"
#include "CuboLatino.cpp"
#define DIM 3
int main(int argc, char **argv){
    int **matriz;
    IngresoDatos ing;
    int num=3;
    num=2*num-1;
    matriz=(int**)calloc(num,sizeof(int*));
    for(int i=0;i<num;i++){
        *(matriz+i)=(int*)calloc(num,sizeof(int));
    }
    CuboMagico* cubo = new CuboMagico();
    CuboMagico cubo1  =  CuboMagico(matriz);
    int op = 0;
    do{ 
        system("cls");
        std::cout<<" 1)Metodo 1\n 2)Metodo 2\n 3)Metodo 3\n 4)Cuadrado Latino\n 5)Salir"<<std::endl;
        op = ing.IngresarDatosEntero();
        if(op == 1){
            system("cls");
            std::cout <<"Metodo 1"<<std::endl;
            cubo1.metodo1(num,num);
            cubo1.mostrar(num,num); 
            system("pause");    
        }
        if(op == 2){
            system("cls");
            std::cout <<"Metodo 2"<<std::endl;
            cubo->encerar();
            cubo->metodo2();
            cubo->imprimirCubo();
            system("pause"); 
        }
        if(op == 3){
            system("cls");
            std::cout <<"Metodo 3"<<std::endl;
            cubo->encerar();
            cubo->metodo3();
            system("pause"); 
        }
        if(op == 4){
            system("cls");
            int dim = ing.IngresarDimension();
            system("cls");
            std::cout <<"Cuadrado latino"<<std::endl;   
            CuboLatino* cuboL = new CuboLatino(dim);
            cuboL->imprimirCuadrado();
            system("pause"); 
        }
    }while(op != 5);

    
    
    
    
    return 0;
}