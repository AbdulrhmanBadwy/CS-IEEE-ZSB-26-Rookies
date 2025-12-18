#include<iostream>
#include<algorithm>
using namespace std ; 

int main()
{
    int t ; 
    cin >>t ; 

    while (t--)
    {
        int a , b , c ; 
        cin >> a >> b >> c; 

        int MaxNumber = max(a , max(b,c)); 

        if(MaxNumber == a ){
            if((b+c) == a ){
                cout << "YES\n"; 
            }else{
                cout <<"NO\n"; 
            }
        }else if(MaxNumber == b ){
            if((a+c) == b ){
                cout <<"YES\n"; 
            }else{
                cout <<"NO\n"; 
            }
        }else
        {
            if((a+b) == c) {
                cout <<"YES\n"; 
            }else{
                cout <<"NO\n"; 
            }
        }

    }
    
    return 0 ; 
    
}