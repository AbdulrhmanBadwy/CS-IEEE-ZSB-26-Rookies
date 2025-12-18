#include<iostream>
#include<string>
#include<algorithm>

using namespace std ; 

int main()
{
    int t; 
    cin >> t; 

    string Word = "codeforces"; 

    while (t--)
    {
        char c ; 
        cin>> c; 

        if(Word.find(c) != string::npos){
            cout << "YES\n"; 
        }
        else{
            cout << "NO\n"; 
        }

    }
    
    return 0 ; 
    
}