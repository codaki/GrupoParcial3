#include <iostream>
#include <stdlib.h>
#include <iomanip>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

int main(int argc, const char * argv[]) {       
int total=0;

	cout << "BILLETES EN EL BANCO " << endl;
	cout << "$1 $5 $10 $20 " << endl;
	cout << "Ingrese cantidad a cambiar " << endl;
	cin>>total;

    vector<int> values = {0, 1, 5, 10, 20}; 
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
    return 0;
}