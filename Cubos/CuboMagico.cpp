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
#include "CuboMagico.hpp"
#include <math.h>
//using namespace std;

CuboMagico::CuboMagico(){
    matriz = new int *[DIM];
}


CuboMagico::CuboMagico(int **_matriz){

    matriz=_matriz;
}
void CuboMagico::encerar(){
    for(int i = 0; i<DIM;i++){
        matriz[i]= new int[DIM];
        for(int j = 0; j<DIM;j++){
            *(*(matriz+i)+j)=0;
        }
    }
}

void CuboMagico::metodo1(int a, int b){ //F=FILA Y C=COLUMNAS
int x=0,k=0,p=1,j=0,t=0,s=0,d=0;
        x=(b-1)/2;
        t=((a+1)/2);
        s=(a-x-1)/2;
        d=x;

         for(int g=0; g<((a+1)/2);g++){
            j=g;
            k=g;
        for( int i=x;i>=j;i--){
            *(*(matriz+i)+k)=p;
             if( k<(d-s) ){
                *(*(matriz+i)+(k+t))=p;
			}
            if(k>(d+s)){
                *(*(matriz+i)+(k-t))=p;
            }
            if(i>(d+s)){
                *(*(matriz+(i-t))+k)=p;
            }
            if(i<(d-s)){
                *(*(matriz+(i+t))+k)=p;
            }

            k++;
            p++;
        }
        x++;
    }
}


void CuboMagico::metodov1(){ 
    int f=DIM; 
    int c=DIM;
    	int numero1[100];
    	int numero2[100];
		int m = 0;
	    int n = 0;
        int z=0;
        int arreglo[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
		int tamanioElemento = sizeof arreglo[0];
		int longitud = sizeof arreglo / tamanioElemento;
		
		int mitad = longitud / 2;
		int mediana;
		// Después vemos si la longitud es par
		if (longitud % 2 == 0) {
		    // Debemos promediar los valores del centro
		    mediana = (arreglo[mitad - 1] + arreglo[mitad]) / 2;
		} else {
		    mediana = arreglo[mitad];
		}
		
		 while(z < longitud){
	        if(arreglo[z] % 2 == 0){
	            numero1[m] = arreglo[z];
	            
	            m++;
	        }else{
	            numero2[n] = arreglo[z]; 
	            
	            n++; 
	        }
	        z++; 
    	}
    	
    	
    	int tamanioElemento2 = sizeof numero1[0];
		int longitud2 = sizeof numero1 / tamanioElemento2;
		
	int aa=numero1[0];
	int ab=numero1[1];
	int bb=numero1[2];
	int ba=numero1[3];	

         for(int l=0; l<f; l++){              
            for(int h=0;h<c;h++){				
                    *(*(matriz+1)+1)=mediana;
                	*(*(matriz+0)+0)=aa;          	
					*(*(matriz+(f-1))+0)=ab; 
					*(*(matriz+0)+(c-1))=bb; 
					*(*(matriz+(f-1))+(c-1))=ba; 
			}
		}
		
	for(int l=0;l<f;l++){
                std::cout<<"\n";
            for(int h=0;h<c;h++){
                
                    std::cout<<*(*(matriz+l)+h);
                
        	}
		}
		
		
		int ac=15-aa-bb;
		int ad=15-aa-ab;
		int ae=15-ab-ba;
		int af=15-ba-bb;
	 for(int l=0;l<f;l++){              
            for(int h=0;h<c;h++){				
                    
                	*(*(matriz+0)+1)=ac;          	
					*(*(matriz+1)+0)=ad; 
					*(*(matriz+2)+1)=ae; 
					*(*(matriz+1)+2)=af; 
			}
		}


}



void CuboMagico::metodo2(){
    int **matrizAux;
    matrizAux= new int *[DIM+2];

    for(int i = 0; i<5;i++){
        matrizAux[i]= new int[DIM];
        for(int j = 0; j<5;j++){
            *(*(matrizAux+i)+j)=0;
        }
    }
    for(int j = 0,k=2; j<3 ;j++,k++){
            *(*(matrizAux+j)+k)=j+1;
    }

    for(int j = 1,k=1; j<=3 ;j++,k++){
            *(*(matrizAux+j)+k)=j+3;
    }

    for(int j = 2,k=0; k<3 ;j++,k++){
            *(*(matrizAux+j)+k)=j+5;
    }
    if(*(*(matrizAux)+2)!=0){
        *(*(matrizAux+3)+2)=*(*(matrizAux)+2);
    }
    if(*(*(matrizAux+2))!=0){
        *(*(matrizAux+2)+3)=*(*(matrizAux+2));
    }
    if(*(*(matrizAux+2)+4)!=0){
        *(*(matrizAux+2)+1)=*(*(matrizAux+2)+4);
    }
    if(*(*(matrizAux+4)+2)!=0){
        *(*(matrizAux+1)+2)=*(*(matrizAux+4)+2);
    }   
    for(int i=0;i<DIM;i++){
        for(int j=0;j<DIM;j++){
            *(*(matriz+i)+j)=*(*(matrizAux+i+1)+j+1);
        }
    }
}

void CuboMagico::metodo3(){
    int limite = pow(DIM, 2);
    int aux1, aux2;
    std::vector<int> anterior;
    for (int i = 1; i <= limite; i++)
    {
        if (i == 1)
        {
            matriz[pos_1()[0]][pos_1()[1]] = i;
            anterior = pos_1();
        }
        else
        {
            if (ocupado(pos_n(anterior)))
            {

                aux1 = pos_n(anterior)[0] + 1;
                aux2 = pos_n(anterior)[1] - 2;
                matriz[aux1][aux2] = i;
                anterior.clear();
                anterior.push_back(aux1);
                anterior.push_back(aux2);
            }
            else
            {
                matriz[pos_n(anterior)[0]][pos_n(anterior)[1]] = i;
                aux1 = pos_n(anterior)[0];
                aux2 = pos_n(anterior)[1];
                anterior.clear();
                anterior.push_back(aux1);
                anterior.push_back(aux2);
            }
        }
    }
    imprimirCubo();
}

void CuboMagico::imprimirCubo(){
    for(int i=0;i<DIM;i++){
        for(int j=0;j<DIM;j++){
            std::cout<<"\t"<<(*(*(matriz +i)+j));
        }
        std::cout<<"\n";
    }
}

std::vector<int> CuboMagico::pos_1()
{
    std::vector<int> pos;
    int i = round(DIM / 2);
    int j = DIM - 1;
    pos.push_back(i);
    pos.push_back(j);
    return pos;
}

std::vector<int> CuboMagico::pos_n(std::vector<int> posi)
{
    std::vector<int> pos;
    int i = posi[0] - 1;
    int j = posi[1] + 1;
    pos.push_back(i);
    pos.push_back(j);
    if (i < 0)
    {
        pos[0] = DIM - 1;
    }
    if (j > (DIM - 1))
    {
        pos[1] = 0;
    }
    if (i < 0 && j > (DIM - 1))
    {
        pos[0] = 0;
        pos[1] = DIM - 2;
    }
    return pos;
}

bool CuboMagico::ocupado(std::vector<int> pos)
{
    if (matriz[pos[0]][pos[1]] == 0)
    {
        return false;
    }
    else
        return true;
}



void CuboMagico::mostrar(int a,int b){
   //system("cls");
    int x=0,t=0,s=0;
        t=((a+1)/2);
        x=(b-1)/2;
        s=(a-x-1)/2;

        for(int l=0;l<a;l++){
                std::cout<<"\n";
            for(int h=0;h<b;h++){
                if(h>=(x-s) && h<=(x+s) && l<=(x+s) && l>=(x-s)){
                    std::cout<<"\t"<<*(*(matriz+l)+h);
                }
        	}
		}
}