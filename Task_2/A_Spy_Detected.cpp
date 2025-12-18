#include<iostream>
#include<string>
#include<algorithm>

using namespace std ; 

int main()
{
    int t ; 
    cin >> t; 

    while(t--)
    {
        int n ; 
        cin >> n ; 

        int* arr = new int[n];
        for(int i = 0 ; i < n ; i++){
            cin >> arr[i] ; 
        }
        
        int common = 0 ; 
        if(arr[0] == arr[1] || arr[0] == arr[2])
            common = arr[0]; 
        else 
            common = arr[1]; 

    int Position = 0 ; 
    for(int i = 0 ; i < n ; i++){
        if(arr[i] != common){
            Position = i+1;
            break;  
        }
    }
    cout << Position << endl ; 
    }
    return 0 ; 
    
}