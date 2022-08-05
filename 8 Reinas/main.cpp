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
#include <iostream>
#include "Reina.cpp"
#include "IngresoDatos.cpp"
using namespace std;
int main(int argc, char **argv){

    int n;
    IngresoDatos in;
	n= in.IngresarDatosEntero();
    cout<<'\n';
     //cin>>n;
	Reina *obj=new Reina(n);
	obj->solucionReinas();
    //obj->mostrarPantalla();
    obj->solucionVoraz(0,0);
	cout<<"Se creo el archivo txt"<<endl;
    return 0;
}
