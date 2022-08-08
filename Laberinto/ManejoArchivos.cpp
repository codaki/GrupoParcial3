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

#include "ManejoArchivos.h"
#include <fstream>
#include <string.h>

std::vector <int> ManejoArchivos::leerArchivo()
{
    std::vector <int> valores;
    std::ifstream lectura;
    std::string num;
    char a;
    lectura.open("datos.txt", std::ios::in);
    
    if (!lectura.fail())
    {
        lectura.get(a);
        while (!lectura.eof())
        {
            valores.push_back((int)(a));
            lectura.get(a);
        }
        
        
    }
    else{
        std::cout<<"No se pudo abrir el archivo"<<std::endl;
    }
    lectura.close();
    return valores;
}

ManejoArchivos::ManejoArchivos()
{

}