#include <iostream>
#include <chrono>
#include "Complejidad.hpp"
using namespace std;
void Complejidad::insertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}


 void Complejidad::bubbleSort(int arr[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
        for (j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1])
                std::swap(arr[j], arr[j + 1]);
}

int Complejidad::lsearch(int arr[], int n, int x)
{
    int i;
    for (i = 0; i < n; i++)
        if (arr[i] == x)
            return i;
    return -1;
}

int  Complejidad::medianValue(int arr[],int n){
    int medianV = 0;
        medianV = n/2;
    return medianV;
}


int Complejidad::binarySearch(int arr[], int l, int r, int x){
    if (r >= l) {
        int mid = l + (r - l) / 2;
 
        if (arr[mid] == x)
            return mid;

        if (arr[mid] > x)
            return binarySearch(arr, l, mid - 1, x);
 
        return binarySearch(arr, mid + 1, r, x);
    }
 

    return -1;
    }

    int Complejidad::triangulo(int dimension){

         for (int i = 0; i < dimension; i++)
            {
                int valor = 1;
                for (int j = 0; j <= i; j++)
                {
                    valor = valor * (i - j) / (j + 1);
                }
                
            }
            return 1;
    }

    int Complejidad::partition(int arr[], int start, int end){
 
    int pivot = arr[start];
 
    int count = 0;
    for (int i = start + 1; i <= end; i++) {
        if (arr[i] <= pivot)
            count++;
    }

    int pivotIndex = start + count;
    std::swap(arr[pivotIndex], arr[start]);

    int i = start, j = end;
 
    while (i < pivotIndex && j > pivotIndex) {
 
        while (arr[i] <= pivot) {
            i++;
        }
 
        while (arr[j] > pivot) {
            j--;
        }
 
        if (i < pivotIndex && j > pivotIndex) {
            std::swap(arr[i++], arr[j--]);
        }
    }
 
    return pivotIndex;
}
 
void Complejidad::quickSort(int arr[], int start, int end)
{
 
    if (start >= end)
        return;

    int p = partition(arr, start, end);
 
    quickSort(arr, start, p - 1);
 
    quickSort(arr, p + 1, end);
}




void Complejidad::complejidadContinua(){
    //int arraysize;
    //std::cout<<"Enter the size of array: ";
    //std::cin>>arraysize;
    ManejoArchivos archivo;
    for(int j=0;j<=50000; j=j+2500){
        int arraysize= j;
    int randArray[arraysize];
    for(int i=0; i<arraysize; i++)
      randArray[i]=i;
    auto start = std::chrono::steady_clock::now();
    medianValue(randArray,arraysize);
    auto end = std::chrono::steady_clock::now();
    //std::cout<< std::chrono::duration_cast<std::chrono::nanoseconds>(end-start).count()<<std::endl;
    archivo.crearArchivo("CContinua.txt",j,std::chrono::duration_cast<std::chrono::nanoseconds>(end-start).count());
    
    }
}

void Complejidad::complejidadCuadratica(){
    //int arraysize;
    //std::cout<<"Enter the size of array: ";
    //std::cin>>arraysize;
    ManejoArchivos archivo;
    for(int j=0;j<=50000; j=j+2500){
        int arraysize= j;
    int randArray[arraysize];
    for(int i=0; i<arraysize; i++)
        randArray[i]=rand()%1000; 
    auto start = std::chrono::steady_clock::now();
    bubbleSort(randArray,arraysize);
    auto end = std::chrono::steady_clock::now();
    //std::cout<< std::chrono::duration_cast<std::chrono::nanoseconds>(end-start).count()<<std::endl;
    archivo.crearArchivo("CCuadratica.txt",j,std::chrono::duration_cast<std::chrono::nanoseconds>(end-start).count());}
}

void Complejidad::complejidadExponencial(){
    //int arraysize;
    
    //std::cout<<"Enter the size of array: ";
    //std::cin>>arraysize;
    ManejoArchivos archivo;
    for(int j=0;j<=50000; j=j+2500){
        int arraysize= j;
    int randArray[arraysize];
    auto start = std::chrono::steady_clock::now();
    triangulo(arraysize);
    auto end = std::chrono::steady_clock::now();
    //std::cout<< std::chrono::duration_cast<std::chrono::nanoseconds>(end-start).count()<<std::endl;
    archivo.crearArchivo("CExponencial.txt",j,std::chrono::duration_cast<std::chrono::nanoseconds>(end-start).count());
    }
}

void Complejidad::complejidadLineal(){
    //int arraysize;
    //std::cout<<"Enter the size of array: ";
    //std::cin>>arraysize;
    ManejoArchivos archivo;
    for(int j=0;j<=50000; j=j+2500){
        int arraysize= j;
    int randArray[arraysize];
    for(int i=0; i<arraysize; i++)
        randArray[i]=i; 
    auto start = std::chrono::steady_clock::now();
    lsearch(randArray,arraysize,arraysize/2);
    auto end = std::chrono::steady_clock::now();
    //std::cout<< std::chrono::duration_cast<std::chrono::nanoseconds>(end-start).count()<<std::endl;
    archivo.crearArchivo("CLineal.txt",j,std::chrono::duration_cast<std::chrono::nanoseconds>(end-start).count());}
}

void Complejidad::complejidadLinealLogaritmica(){
    //int arraysize;
    //cout<<"Enter the size of array: ";
    //cin>>arraysize;
    ManejoArchivos archivo;
    for(int j=0;j<=50000; j=j+2500){
        int arraysize= j;
    int randArray[arraysize];
    for(int i=0; i<arraysize; i++)
        randArray[i]=rand()%1000; 
    auto start = chrono::steady_clock::now();
    quickSort(randArray,0,arraysize-1);
    auto end = chrono::steady_clock::now();
    //std::cout<<std::chrono::duration_cast<std::chrono::nanoseconds>(end-start).count()<<std::endl;
    archivo.crearArchivo("CLinealLogaritmica.txt",j,std::chrono::duration_cast<std::chrono::nanoseconds>(end-start).count());
    }
}

void Complejidad::complejidadLogaritmica(){
    int arraysize;
    std::cout<<"Enter the size of array: ";
    std::cin>>arraysize;
    int randArray[arraysize];
    for(int i=0; i<arraysize; i++)
      randArray[i]=i;
    auto start = std::chrono::steady_clock::now();
    binarySearch(randArray, 0,arraysize-1,(arraysize/2)-1);
    auto end = std::chrono::steady_clock::now();
    std::cout<<"Tiempo busqueda binaria: "<< std::chrono::duration_cast<std::chrono::nanoseconds>(end-start).count()<<" nanoseconds"<<std::endl;
}