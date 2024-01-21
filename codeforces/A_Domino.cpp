#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
void solve()
{
    ll n;
    cin >> n;
    vector<pair<ll, ll>> v(n);
    for (ll i = 0; i < n; ++i)
    {
        cin >> v[i].first >> v[i].second;
    }
    ll oddFirst = 0, oddSecond = 0;
    bool canSwap = false;
    for (ll i = 0; i < n; ++i)
    {
        if (v[i].first % 2)
        {
            oddFirst += 1;
        }
        if (v[i].second % 2)
        {
            oddSecond += 1;
        }
        if (v[i].first % 2 != v[i].second % 2)
        {
            canSwap = true;
        }
    }
    if (oddFirst % 2 != oddSecond % 2)
    {
        cout << "-1\n";
    }
    else if (oddFirst % 2 == 0)
    {
        cout << "0\n";
    }
    else
    {
        if (canSwap)
        {
            cout << "1\n";
        }
        else
        {
            cout << "-1\n";
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ll test = 1;
    // cin>>test;
    while (test--)
    {
        solve();
    }
    return 0;
}
