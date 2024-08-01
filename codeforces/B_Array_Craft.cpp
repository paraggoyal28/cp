#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

void solve()
{
    ll n, x, y;
    cin >> n >> x >> y;
    vector<ll> a(n, 1);
    x--;
    y--;
    int e = -1;
    for (int i = x + 1; i < n; ++i)
    {
        a[i] = e;
        e *= -1;
    }

    e = -1;
    for (int i = y - 1; i >= 0; --i)
    {
        a[i] = e;
        e *= -1;
    }

    for (ll i = 0; i < n; ++i)
    {
        cout << a[i] << " ";
    }
    cout << "\n";
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
        solve();
    }
    return 0;
}