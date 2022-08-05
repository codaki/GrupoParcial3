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
#include "Reina.hpp"
#include "time.h"
void Reina:: encerarTablero(){
			for(int i=0;i<DIMENSION;i++){
				validar[i]=new bool[DIMENSION];
				tablero[i]=new char[DIMENSION];
				for(int j=0;j<DIMENSION;j++){
					*(*(validar+i)+j)=false;
					*(*(tablero+i)+j)='*';
				}
			}
		}

void Reina:: crearArchivo(){
		archivo.open("exaustivo.txt",std::fstream::out);
		archivo<<"solucion"<<DIMENSION<<"*"<<DIMENSION<<std::endl<<std::endl;
		contador=0;
	}

 Reina::Reina(int n1){
		n=n1;
		validar=new bool *[DIMENSION];
		tablero=new char *[DIMENSION];
		encerarTablero();
		crearArchivo();
	}
void Reina::bloquear(int x, int y){
		int aux1,aux2;
		aux2=y;
		aux1=0;
		while(aux1<DIMENSION){//vertical
			*(*(validar+aux1)+aux2)=true;
			aux1++;
		}
		aux2=0;
		aux1=x;
		while(aux2<DIMENSION){
			*(*(validar+aux1)+aux2)=true;
			aux2++;
		}
		aux2=y;//diagonal
		aux1=x;
		while(aux1>0&&aux2>0){
			aux1--;
			aux2--;
		}
		aux2=y;
		aux1=x;
		while(aux1<DIMENSION && aux2>0){
			aux1++;
			aux2--;
		}
		aux1--;
		aux2++;
		while(aux1>=0 && aux2<DIMENSION){
			*(*(validar+aux1)+aux2)=true;
			aux1--;
			aux2++;
		}
	}

void Reina:: mostrar(){
		contador++;
		archivo<<"solucion N "<<contador <<std::endl;
		for(int i=0;i<DIMENSION;i++){
			for(int j=0;j<DIMENSION;j++){
				archivo<<*(*(tablero+i)+j)<<" ";
			}
			archivo<<std::endl;
		}
		archivo<<std::endl;
	}

void Reina:: quitarRelleno(int x, int y){
		*(*(tablero +x)+y)='*';
		for(int i=0;i<DIMENSION;i++){
			for(int j=0;j<DIMENSION;j++){
				*(*(validar +i)+j)=false;
			}
		}
		for(int i=0;i<DIMENSION;i++){
			for(int j=0;j<DIMENSION;j++){
				if(*(*(tablero +i)+j)=='R')
				bloquear(i,j);
			}	
		}
	}

void Reina::mostrarPantalla(){
		for(int i=0;i<DIMENSION;i++){
			for(int j=0;j<DIMENSION;j++){
				std::cout<<(*(*(tablero +i)+j))<<" ";
			}
			std::cout<<"\n";
		}
	}

void Reina::solucion(int x, int y, int n1){
		*(*(tablero +x)+y)='R';
		bloquear(x,y);
		if(n1==n){
			mostrar();
		}else{
			for(int i=0;i<n;i++){
				if(*(*(validar +i )+ y+1)==false){
					solucion(i,y+1,n1+1);
				}
			}
		}
		quitarRelleno(x,y);
	}

void Reina::solucionReinas(){
		for(int i=0;i<DIMENSION;i++){
			solucion(i,0,1);	
		}
		archivo.close();	
	}

//x vertical ,y horizontal
void Reina::solucionVoraz(int x, int y){
    insertarReina('R');
    std::cout<<"Solucion"<<std::endl;
    mostrarPantalla();
}

int Reina::cantidadReinas(char dato){
    int cantidad = 0;
    for(int i=0;i<DIMENSION;i++){
        for(int j=0;j<DIMENSION;j++){
            if( *(*(tablero+i)+j) == dato){ 
                cantidad++;
            }
        }
    }
    return cantidad;
}

void Reina::insertarReina(char dato){
    srand(time(NULL));
    int count = 0;
    int nR =0;
    do{
        nR =0;
    encerarTablero();
    int posX = 0+rand()%DIMENSION;
    int posY = 0+rand()%DIMENSION;

    for(int i = posX;i>=0;i--){
        int inicioY = 0;
        if(posX==i){
            inicioY = posY;
        }else{
            inicioY = n-1;
        }
        for(int j = inicioY;j>=0;j--){
            if(!vDAI(dato,i,j)&&!vDAD(dato,i,j)&&!vDAbD(dato,i,j)&&!vDAbI(dato,i,j)
            &&!vD(dato,i,j)&&!vI(dato,i,j)&&!vA(dato,i,j)&&!vAb(dato,i,j)){
                *(*(tablero+i)+j) = dato;
                nR++; 
            }
        }
    }

    for(int i = posX;i<n;i++){
        int inicioY = 0;
        if(posX==i){
            inicioY = posY;
        }else{
            inicioY = 0;
        }
        for(int j = inicioY;j<n;j++){
            if(!vDAI(dato,i,j)&&!vDAD(dato,i,j)&&!vDAbD(dato,i,j)&&!vDAbI(dato,i,j)
            &&!vD(dato,i,j)&&!vI(dato,i,j)&&!vA(dato,i,j)&&!vAb(dato,i,j)){
                *(*(tablero+i)+j) = dato ;
                nR++; 
            }
        }
    }
    count++;
    }while(cantidadReinas(dato)<n|| nR > n);
    std::cout<<"Cantidad de combinaciones realizadas:"<<count<<std::endl;
}

int Reina::vC(char dato,int x, int y){
    bool resul = false;
    int count = 0;
    //diagonales
    if(vDAI(dato,x,y)) count++;
    if(vDAD(dato,x,y)) count++;
    if(vDAbD(dato,x,y)) count++;
    if(vDAbI(dato,x,y)) count++;
    //laterales
    if(vD(dato,x,y)) count++;
    if(vI(dato,x,y)) count++;
    if(vA(dato,x,y)) count++;
    if(vAb(dato,x,y)) count++;
   
    return count;
}

bool Reina::vDAI(char dato,int x, int y){
    bool resultado = false;
    if(x>=0 && y<DIMENSION && x<DIMENSION && y>=0){
        if(dato == *(*(tablero +x)+y)){
            return true;
        }
        else{
            resultado = vDAI(dato,x-1,y-1);
        }
    }
    return resultado;
}
bool Reina::vDAD(char dato,int x, int y){
    bool resultado = false;
    if(x>=0 && y<DIMENSION && x<DIMENSION && y>=0){
        if(dato == *(*(tablero +x)+y)){
            return true;
        }
        else{
            resultado = vDAD(dato,x-1,y+1);
        }
    }
    return resultado;
}

bool Reina::vDAbI(char dato,int x, int y){
    bool resultado = false;
    if(x>=0 && y<DIMENSION && x<DIMENSION && y>=0){
        if(dato == *(*(tablero +x)+y)){
            return true;
        }
        else{
            resultado = vDAbI(dato,x+1,y-1);
        }
    }
    return resultado;
}

bool Reina::vDAbD(char dato,int x, int y){
    bool resultado = false;
    if(x>=0 && y<DIMENSION && x<DIMENSION && y>=0){
        if(dato == *(*(tablero +x)+y)){
            return true;
        }
        else{
            resultado = vDAbD(dato,x+1,y+1);
        }
    }
    return resultado;
}

bool Reina::vA(char dato,int x, int y){
    bool resultado = false;
    if(x>=0 && y<DIMENSION && x<DIMENSION && y>=0){
        if(dato == *(*(tablero +x)+y)){
            return true;
        }
        else{
            resultado = vA(dato,x+1,y);
        }
    }
    return resultado;
}

bool Reina::vAb(char dato,int x, int y){
    bool resultado = false;
    if(x>=0 && y<DIMENSION && x<DIMENSION && y>=0){
        if(dato == *(*(tablero +x)+y)){
            return true;
        }
        else{
            resultado = vAb(dato,x-1,y);
        }
    }
    return resultado;
}

bool Reina::vD(char dato,int x, int y){
    bool resultado = false;
    if(x>=0 && y<DIMENSION && x<DIMENSION && y>=0){
        if(dato == *(*(tablero +x)+y)){
            return true;
        }
        else{
            resultado = vD(dato,x,y+1);
        }
    }
    return resultado;
}

bool Reina::vI(char dato,int x, int y){
    bool resultado = false;
    if(x>=0 && y<DIMENSION && x<DIMENSION && y>=0){
        if(dato == *(*(tablero +x)+y)){
            return true;
        }
        else{
            resultado = vI(dato,x,y-1);
        }
    }
    return resultado;
}


bool Reina:: validarExcepciones(char dato,int posX, int posY){
    bool valid=false;
    if (!vI(dato,posX,posY))
    {
        if (!vD(dato,posX,posY))
        {
            if(!vA(dato,posX,posY))
            {
                if(!vAb(dato,posX,posY))
                {
                    if (!vDAI(dato,posX,posY))
                    {
                        if(!vDAD(dato,posX,posY))
                        {
                            if (!vDAbI(dato,posX,posY))
                            {
                                if(!vDAbD(dato,posX,posY))
                                {
                                    if(!vC(dato,posX,posY))
                                    {
                                        valid=true;
                                    }
                                }
                            }
                            
                        }
                    }
                    
                }
            }
        }
        
    }
    return valid;
}   
