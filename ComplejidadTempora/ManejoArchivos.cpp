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