#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double

bool solve()
{
    ll n;
    ld f, a, b;
    cin >> n >> f >> a >> b;
    vector<ld> mom(n);
    for (ll i = 0; i < n; ++i)
    {
        cin >> mom[i];
    }
    ld start = 0;
    for (ll i = 0; i < n && f > 0; ++i)
    {
        if ((mom[i] - start) * a <= b)
        {
            f -= (mom[i] - start) * a;
        }
        else
        {
            f -= b;
        }
        if (f <= 0)
        {
            return false;
        }
        start = mom[i];
    }
    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll t;
    cin >> t;
    while (t--)
    {
        if (solve())
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }
    return 0;
}