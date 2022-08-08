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
#include <ctime>
#include <cstdlib>
#include <iomanip>
#include "ManejoArchivos.cpp"
using namespace std;

#define N 5
 
bool resolverLab(int lab[N][N], int x, int y,int sol[N][N]);
 

void imprimirSol(int sol[N][N])
{
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cout<<" "<<sol[i][j]<<" ";
        cout<<endl;
    }
}

bool esSeguro(int lab[N][N], int x, int y)
{
  
    if (x >= 0 && x < N && y >= 0 && y < N && lab[x][y] == 1)
        return true;
    return false;
}
 
bool resolverLaberinto(int lab[N][N])
{
    int sol[N][N] = { { 0, 0, 0, 0, 0 },
                      { 0, 0, 0, 0, 0 },
                      { 0, 0, 0, 0, 0 },
                      { 0, 0, 0, 0, 0 },
                      { 0, 0, 0, 0, 0 } };
    if (resolverLab(lab, 0, 0, sol) == false) {
        cout<<"!Solucion no existe!";
        return false;
    }
    imprimirSol(sol);
    return true;
}
 

bool resolverLab(int lab[N][N], int x, int y, int sol[N][N])
{

    if (x == N - 1 && y == N - 1 && lab[x][y] == 1) {
        sol[x][y] = 1;
        return true;
    }

    if (esSeguro(lab, x, y) == true) {

        if (sol[x][y] == 1)
            return false;

        sol[x][y] = 1;

        if (resolverLab(lab, x + 1, y, sol) == true)
            return true;

        if (resolverLab(lab, x, y + 1, sol) == true)
            return true;

        sol[x][y] = 0;
        return false;
    }
    return false;
}

void llenarMatriz()
{
    ManejoArchivos man;
    int cont=-1;
    int val=0;
    std::vector <int> valores;
    valores= man.leerArchivo();
    int lab [N] [N];

    for (int i = 0; i < N; i++)
    {
        cont++;
        for (int j = 0; j < N; j++)
        {
            if (valores[cont]==48)
            {
                val=0;
            }
            else if(valores[cont]==49)
            {
                val=1;
            }
            lab[i][j]=val;
            cont++;
        }
    }

    cout<<"******L  A   B   E   R   I   N   T   O******"<<endl;                   
     for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cout<<" "<<lab[i][j]<<" ";
        cout<<endl;
    }

    resolverLaberinto(lab);
}



int main()
{
	llenarMatriz();
    return 0;
}
