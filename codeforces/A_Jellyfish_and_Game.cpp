#include <bits/stdc++.h>
#define ll long long int
using namespace std;

void solve()
{
    ll n, m, k;
    cin >> n >> m >> k;
    k--;
    vector<ll> jA(n);
    vector<ll> gA(m);
    for (ll i = 0; i < n; ++i)
    {
        cin >> jA[i];
    }
    for (ll i = 0; i < m; ++i)
    {
        cin >> gA[i];
    }

    ll x = 0, y = 0;
    for (ll i = 1; i < n; ++i)
        if (jA[i] < jA[x])
            x = i;
    for (ll i = 1; i < m; ++i)
        if (gA[i] > gA[y])
            y = i;

    if (gA[y] > jA[x])
        swap(gA[y], jA[x]);

    if (k & 1)
    {
        x = 0, y = 0;
        for (ll i = 1; i < n; ++i)
            if (jA[i] > jA[x])
                x = i;
        for (ll i = 1; i < m; ++i)
            if (gA[i] < gA[y])
                y = i;

        swap(jA[x], gA[y]);
    }

    ll sum = accumulate(jA.begin(), jA.end(), 0LL);
    cout << sum << endl;
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