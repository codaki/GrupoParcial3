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
#include <iostream>
#include <stdlib.h>
#include <iomanip>
#include <cmath>
//#include <vector>
#include <algorithm>
#include "Moneda.h"
#include "Vector.cpp"
//#include "IngresoDatos.cpp"

void Moneda::proceso(){

	cout << "Digite la cantidad que quiere cambiar: " << endl;
	cin>>total;
   
   

 
    sort(values.begin(), values.end()); 

    vector<vector<vector<int>>> empty(total+1); 
    vector<vector<vector<int>>> lastRow(total+1);
    vector<vector<vector<int>>> curRow(total+1);


    for(int i=0; i<values.size(); i++) {


        for(int curSum=0; curSum<=total; curSum++){
            if(curSum==0) {
                               
                curRow[curSum].push_back(vector<int> {}); 

            }else if(i==0) {
                

            }else if(values[i]>curSum){
                
                curRow[curSum] = lastRow[curSum];

            }else{
                
                curRow[curSum] = lastRow[curSum];
                vector<vector<int>> useCurCoin = curRow[curSum-values[i]];

               
                for(int k=0; k<useCurCoin.size(); k++){

                    useCurCoin[k].push_back(values[i]);
                    curRow[curSum].push_back(useCurCoin[k]);
                }               
            }    
        }        

        lastRow = curRow;
        curRow = empty;
    } 

    cout<<"Combinaciones totales: "<<lastRow.back().size()<<endl;
    for (int i=0; i<lastRow.back().size(); i++) {
        for (int j=0; j<lastRow.back()[i].size(); j++) {
            if(j!=0)
                cout<<" ";
            cout<<lastRow.back()[i][j];
        }
        cout<<endl;
    }

}     