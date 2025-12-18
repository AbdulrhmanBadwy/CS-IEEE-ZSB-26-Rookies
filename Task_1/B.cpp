#include<iostream>
using namespace std ; 

int main()
{
    int Weight;
    cin >> Weight; 

    if(Weight%2 == 0 ){
        if(Weight == 2){
            cout << "NO"; 
        }
        else {
            cout << "YES"; 
        }
    }else{
        cout <<"NO"; 
    }

    return 0 ; 
    
}