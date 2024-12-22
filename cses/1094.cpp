#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (ll i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    ll operations = 0;
    for (ll i = 1; i < n; ++i)
    {
        if (a[i] < a[i - 1])
        {
            operations += a[i - 1] - a[i];
            a[i] = a[i - 1];
        }
    }
    cout << operations << "\n";
    return 0;
}