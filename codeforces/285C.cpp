#include <bits/stdc++.h>
using namespace std;
#define ll long long int

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
    sort(a.begin(), a.end());
    ll res = 0;
    for (ll i = 1; i <= n; ++i)
    {
        res += abs(a[i - 1] - i);
    }
    cout << res << "\n";
    return 0;
}