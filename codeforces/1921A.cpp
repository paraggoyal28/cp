#include <bits/stdc++.h>
using namespace std;
#define ll long long int

ll solve()
{
    unordered_set<ll> x, y;
    ll xc, yc;
    for (ll i = 0; i < 4; ++i)
    {
        cin >> xc >> yc;
        x.insert(xc);
        y.insert(yc);
    }
    vector<ll> xCoord, yCoord;
    for (ll it : x)
    {
        xCoord.push_back(it);
    }
    for (ll it : y)
    {
        yCoord.push_back(it);
    }
    return (abs(xCoord[1] - xCoord[0]) * abs(yCoord[1] - yCoord[0]));
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
        cout << solve() << "\n";
    }
    return 0;
}