
#include <iostream>
#define ll long long int
using namespace std;

ll findGcd(ll a, ll b)
{
    if (b == 0)
        return a;
    return findGcd(b, a % b);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll t;
    cin >> t;
    for (ll i = 1; i <= t; ++i)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        ll gcd = findGcd(a, b);
        if (c % gcd == 0)
        {
            cout << "Case " << i << ": Yes" << endl;
        }
        else
        {
            cout << "Case " << i << ": No" << endl;
        }
    }
}