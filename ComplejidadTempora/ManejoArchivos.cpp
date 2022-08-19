/*
	*Universidad de las Fuerzas Armadas "ESPE"
   
     *Autores:
        De Veintemilla Luca
	Iza Christopher
	Rea Denise
	Vargas Kevin
	*Fecha de creacion: 
        * 18-08-2022
	*Fecha de modificacion:
        * 19-08-2022
    *GitHub del grupo:	
        https://github.com/ChristopherIza/GrupoParcial3.git
*/
#include "ManejoArchivos.hpp"
//#include <filesystem>
ManejoArchivos::ManejoArchivos()
{

}

void ManejoArchivos:: crearArchivo(std::string nombre , int x ,double y)
{
    std::string x_=std::to_string(x)+" "+std::to_string(y)+"\n";
    std::ofstream lectura;
    //int tam= int(std::filesystem::file_size(nombre));

    lectura.open(nombre,std::ios::app);
    if (vacio(nombre))
        {
            lectura<<"x y \n";
        }
    
    if (lectura.is_open())
    {
        lectura<<x_;
    }
    else{
        std::cout<<"Archivo incompatible";
    }
    lectura.close();
}

bool ManejoArchivos:: vacio(std::string nombre)
{
    std::ifstream lectura;
    lectura.open(nombre, std::ios::in);
    std::string texto;
    std::getline(lectura,texto);
    lectura.close();
    return texto.empty();
}