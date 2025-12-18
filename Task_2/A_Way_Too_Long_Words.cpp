#include<iostream>
#include<string>
#include<algorithm>

using namespace std ; 

int main()
{
    int n ; 
    cin >> n ;

    while(n--)
    {
        string s ;
        cin >>s ; 

        string result ; 
        int length = s.length() -2 ; 
        if(s.length() > 10 ){
            result= s[0] + to_string(length) + s[s.length()-1]; 
        }
        else 
        {
            result = s; 
        }

        cout << result << endl ; 
    }
    
}