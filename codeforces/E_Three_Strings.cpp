/*
Author: Parag K. Goyal
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define all(v) v.begin(), v.end()

void solve()
{
    string a, b, c;
    cin >> a >> b >> c;
    ll n = a.size(), m = b.size();
    if (n + m != c.size())
    {
        cout << "-1\n";
        return;
    }
    vector<vector<ll>> dp(n + 1, vector<ll>(m + 1, 1e9));

    dp[0][0] = 0;
    for (ll i = 0; i <= n; ++i)
    {
        for (ll j = 0; j <= m; ++j)
        {
            ll k = i + j;

            if (i == 0 && j == 0)
                continue;
            else if (i == 0)
            {
                ll cost = (b[j - 1] != c[k - 1]) ? 1 : 0;
                dp[i][j] = min(dp[i][j], dp[i][j - 1] + cost);
            }
            else if (j == 0)
            {
                ll cost = (a[i - 1] != c[k - 1]) ? 1 : 0;
                dp[i][j] = min(dp[i][j], dp[i - 1][j] + cost);
            }
            else
            {
                ll cost1 = (b[j - 1] != c[k - 1]) ? 1 : 0;
                ll cost2 = (a[i - 1] != c[k - 1]) ? 1 : 0;
                dp[i][j] = min({dp[i][j], dp[i - 1][j] + cost2, dp[i][j - 1] + cost1});
            }
        }
    }
    cout << dp[n][m] << "\n";
}

signed main()
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
