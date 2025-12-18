#include<iostream>
#include<string>


using namespace std ; 

bool CharacterIsFound(char c , string s ){
    for(int i = 0 ; i < s.length() ; i++){
        if (s[i] == c )
        {
            return true ; 
        }
    
    }
    return false; 
}
int main()
{
    int t ; 
    cin >> t; 

    while (t--)
    {
        int n ; 
        cin >> n; 
        
    string s ; 
        cin >> s; 

        int TotalBallons = 0 ; 
        for(int i = 0 ; i < n ; i++){
            if(CharacterIsFound(s[i] , s.substr(0,i))){
                TotalBallons+=1; 
            }
            else 
            {
                TotalBallons+=2; 
            }
        }

        cout<<TotalBallons << endl ; 
    }
    
    return 0 ; 
    
}