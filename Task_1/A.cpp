#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    
    short TotalProblemsImplemented = 0 ; 

    while (n--)
    {
        bool person1, person2, person3;
        cin >> person1 >> person2 >> person3;

        short NumberOfSure = 0 ; 

        if(person1 == 1 ) NumberOfSure++; 
        if(person2 == 1 ) NumberOfSure++; 
        if(person3 == 1 ) NumberOfSure++; 

        if(NumberOfSure>= 2 ) TotalProblemsImplemented++; 
    }

    cout << TotalProblemsImplemented ; 
}