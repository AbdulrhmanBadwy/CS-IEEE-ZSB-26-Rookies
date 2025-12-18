#include<iostream>
using namespace std; 

int main(){
    int t ; 
    cin >> t ; 

    while (t--)
    {
         int Rating; 
        cin >> Rating; 

        if(Rating >= 1900 ){
            cout << "Division 1" << endl; 
        }
        else if(Rating>= 1600 && Rating <= 1899){
            cout << "Division 2" << endl; 
        }
        else if(Rating >= 1400 && Rating <= 1599){
            cout << "Division 3" << endl; 
        }
        else if(Rating <= 1399 ){
            cout << "Division 4" << endl  ; 
        }
    }
    
}