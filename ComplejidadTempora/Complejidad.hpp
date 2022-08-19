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
#include <iostream> 
#include "ManejoArchivos.cpp"


class Complejidad{
    
    public:

    void insertionSort(int arr[], int n);
    void bubbleSort(int arr[], int n);
    int lsearch(int arr[], int n, int x);
    int medianValue(int arr[],int n);
    int binarySearch(int arr[], int l, int r, int x);
    int triangulo(int dimension);
    void quickSort(int arr[], int start, int end);
    int partition(int arr[], int start, int end);


    void complejidadContinua();
    void complejidadLogaritmica();
    void complejidadLineal();
    void complejidadLinealLogaritmica();
    void complejidadCuadratica();
    void complejidadExponencial();
};