/*
	*Universidad de las Fuerzas Armadas "ESPE"
   
     *Autores:
            De Veintemilla Luca
	         Iza Christopher 
	         Rea Denise
	         Vargas Kevin
	*Fecha de creacion: 
        * 14-08-2022
	*Fecha de modificacion:
        * 14-08-2022
    *GitHub del grupo:	
        https://github.com/ChristopherIza/GrupoParcial3.git
*/

#include "Mochila.hpp"

Mochila::Mochila(){
   
}

int Mochila::max(int x, int y) {
   return (x > y) ? x : y;
}

int Mochila::solucion(int W, int w[], int v[], int n) {
   int i, wt;
   int K[n + 1][W + 1];
   for (i = 0; i <= n; i++) {
      for (wt = 0; wt <= W; wt++) {
         if (i == 0 || wt == 0)
         K[i][wt] = 0;
         else if (w[i - 1] <= wt)
            K[i][wt] = max(v[i - 1] + K[i - 1][wt - w[i - 1]], K[i - 1][wt]);
         else
        K[i][wt] = K[i - 1][wt];
      }
   }
   return K[n][W];
}