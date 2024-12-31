#include <bits/stdc++.h>
#define ll long long int
#define mod 1000000007
using namespace std;

int power(int base, int exponent)
{
    int res = 1;
    while (exponent > 0)
    {
        if (exponent & 1)
        {
            res = (res * 1LL * base) % mod;
        }
        base = (base * 1LL * base) % mod;
        exponent /= 2;
    }
    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;

    cout << power(2, n) << "\n";

    return 0;
}
