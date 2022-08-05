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