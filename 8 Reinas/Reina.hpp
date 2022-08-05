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
#include <fstream>
#define DIMENSION 8
class Reina{
	private:
		bool **validar;
		char **tablero;
		std::fstream archivo;
		int contador;
		int n;
    public:
        /*bool** getvalidar();
        void setvalidar(bool** validar);
        char** getTablero();
        void getTablero(char** tablero);
        std::fstream getArchivo();
        void setArchivo(std::fstream archivo);
        int getContador();
        void setContador(int contador);
        int getN();
        void setN(int n);*/
        Reina(int n1);
		void encerarTablero();
        void crearArchivo();
        void bloquear(int x, int y);
        void mostrar();
        void quitarRelleno(int x,int y);
        void mostrarPantalla();
        void solucion(int x, int y, int n1);
        void solucionReinas();
        
        void solucionVoraz(int x, int y);

        bool vDAI(char dato,int posX, int posY);
        bool vDAD(char dato,int posX, int posY);
        bool vDAbI(char dato,int posX, int posY);
        bool vDAbD(char dato,int posX, int posY);

        bool vI(char dato,int posX, int posY);
        bool vD(char dato,int posX, int posY);
        bool vA(char dato,int posX, int posY);
        bool vAb(char dato,int posX, int posY);
        void insertarReina(char dato);
        int vC(char dato,int x,int y);
        int cantidadReinas(char dato);

		bool validarExcepciones(char dato,int posX, int posY);
};
