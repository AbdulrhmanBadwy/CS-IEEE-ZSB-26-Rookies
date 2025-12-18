#include <iostream>

using namespace std;

int main()
{
    int k, r;
    cin >> k >> r;

    int n = 1;
    while (true)
    {
        if ((n * k) % 10 == 0 || (n * k) % 10 == r)
        {
            cout << n;
            return 0;
        }

        n++;
    }

    return 0;
}