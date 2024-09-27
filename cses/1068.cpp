/** Ram Ram */
#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main()
{
    ll n;
    cin >> n;
    while (true)
    {
        cout << n << " ";
        if (n == 1)
            return 0;
        if (n & 1)
        {
            n = n * 3 + 1;
        }
        else
        {
            n = n / 2;
        }
    }
}