#include<iostream>
#include<string>
#include<algorithm>
#include<vector>


using namespace std ; 

int main()
{
    const int n = 5; 

    int arr[n][n] ; 

    int RowPos = 0 , ColPos = 0 ; 

     for(int i = 0 ; i< n ; i++){
        for(int j = 0 ; j < n ; j++){
            cin >> arr[i][j]; 
        }
    }

    for(int i = 0 ; i < n ;i++){
        for(int j = 0 ; j < n ; j++){
            if(arr[i][j] == 1 ){
                RowPos = i ; 
                ColPos = j ; 
                break; 
            }
        }
    }

    int NumberofSteps  = 0 , RowStep = 0 , ColStep = 0 ; 

    RowStep = RowPos-2; 
    if(RowStep<0)
        RowStep*=-1; 
    
    ColStep = ColPos-2; 
    if(ColStep < 0 ) ColStep*=-1; 


    NumberofSteps = ColStep+RowStep; 
    

    cout << NumberofSteps ;

    return 0 ; 
    
}