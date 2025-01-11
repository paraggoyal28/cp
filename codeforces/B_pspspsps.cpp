#include <bits/stdc++.h>
#define ll long long int
using namespace std;

void solve()
{
    ll n;
    cin >> n;
    string s;
    cin >> s;
    set<ll> pPos, sPos;
    for (ll i = 0; i < n; ++i)
    {
        if (s[i] == 's')
        {
            sPos.insert(i);
        }
        else if (s[i] == 'p')
        {
            pPos.insert(i);
        }
    }
    for (ll pPosition : pPos)
    {
        if (lower_bound(sPos.begin(), sPos.end(), pPosition) != sPos.end())
        {
            cout << "NO\n";
            return;
        }
        else if (pPosition != n - 1 && lower_bound(sPos.begin(), sPos.end(), 1) != sPos.end())
        {
            cout << "NO\n";
            return;
        }
    }

    cout << "YES\n";
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