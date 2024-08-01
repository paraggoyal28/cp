#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

void solve()
{
    ll n;
    cin >> n;
    vector<ll> h(n);
    for (ll i = 0; i < n; ++i)
    {
        cin >> h[i];
    }
    vector<ll> dp(n, 0);
    dp[n - 1] = h[n - 1];
    for (ll i = n - 2; i >= 0; --i)
    {
        dp[i] = max(dp[i + 1] + 1, h[i]);
    }
    cout << dp[0] << "\n";
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