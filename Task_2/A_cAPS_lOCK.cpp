#include<iostream>
#include<string>
#include<algorithm>

using namespace std ; 

bool ifAllExceptFirstCapital(string s  ){
    bool allCaps = true ; 
    
    if(s[0] >='A' && s[0]<='Z') {allCaps = false;};  
    for(int i = 1 ;i < s.length() ; i++){
        if(s[i] <'A' || s[i] >'Z'){
            allCaps = false ; 
        }
    }
    return allCaps; 
}
bool ifAlltCapital(string s  ){
    bool allCaps = true ; 
    for(int i = 0 ;i < s.length() ; i++){
        if(s[i] <'A' || s[i] >'Z'){
            allCaps = false ; 
        }
    }
    return allCaps; 
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

char ConvertSmallToCapital(char c){
    c = char(int(c) - 32); 

    return c ; 
}
int main()
{
    string s ; 
    cin >> s ; 

    if(ifAllExceptFirstCapital(s) || ifAlltCapital(s)){
        for(int i= 0; i < s.length() ; i++){
            if(isCapital(s[i])){
                s[i] = ConvertCapitalToSmall(s[i]); 
            }
            else 
            {
                s[i] = ConvertSmallToCapital(s[i]); 
            }
        }
    }

    cout << s; 
    return 0 ; 
    
}