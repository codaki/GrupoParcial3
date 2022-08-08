/*
	*Universidad de las Fuerzas Armadas "ESPE"
   
     *Autores:
    De Veintemilla Luca
	Iza Christopher 
	Rea Denise
	Vargas Kevin
	*Fecha de creacion: 
        * 06-08-2022
	*Fecha de modificacion:
        * 07-08-2022
    *GitHub del grupo:	
        https://github.com/ChristopherIza/GrupoParcial3.git
*/
#include <iostream>
#define MARCA 219
int main(int argc, char **argv){
for(int j = 0; j <8;j++){
    if(j%2 == 0){
        for(int m = 0;m<3;m++){
            for(int i = 0; i <4;i++){
                for(int u = 0; u<3;u++){
                    printf("%c",MARCA);
                    printf("%c",MARCA);
                    printf("%c",MARCA);
                }
                for(int k=0;k<3;k++){        
                    printf(" ",MARCA);
                    printf(" ",MARCA);
                    printf(" ",MARCA);
                }
            }
        printf("\n");
        }
    }else{ 
        for(int m = 0;m<3;m++){
            for(int i = 0; i <4;i++){
                for(int k=0;k<3;k++){        
                    printf(" ",MARCA);
                    printf(" ",MARCA);
                    printf(" ",MARCA);
                }
                for(int u = 0; u<3;u++){
                    printf("%c",MARCA);
                    printf("%c",MARCA);
                    printf("%c",MARCA);
                }
            }
        printf("\n");
        }
    }
}
    return 0; 
}