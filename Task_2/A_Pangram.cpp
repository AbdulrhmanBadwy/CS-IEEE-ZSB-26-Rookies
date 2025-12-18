#include<iostream>
#include<string>
#include<algorithm>

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

bool isCapital(char c ){
    if( c >='A' && c<='Z'){
        return true ; 
    }
    else 
    {
        return false ; 
    }
}

char ConvertCapitalToSmall(char c ){
    c = char(int(c)+32); 

    return c ; 
}
int main()
{
    int n ; 
    cin >>n; 

    string s ; 
    cin >> s; 

    // Convert all To Small 

    for(int i = 0 ; i < n ; i++){
        if(isCapital(s[i])){
            s[i] = ConvertCapitalToSmall(s[i]); 
        }
    }



    int sumOfAscii = 0 ; 
    if(n < 26 )
    {
        cout << "NO"; 
    }
    else 
    {
        for(int i = 0 ; i < n ; i++){
            if(CharacterIsFound(s[i] , s.substr(0,i))){
                continue;
            }
            else {
                sumOfAscii+=int(s[i]); 
                
            }
        }

        if(sumOfAscii== 2847){
            cout << "YES"; 
        }
        else 
        {
            cout << "NO"; 
        }
    }

    return 0 ; 
    
}