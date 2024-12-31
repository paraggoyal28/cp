#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n, m;
    cin >> n >> m;
    vector<ll> a(n);
    for (ll i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    ll dp[n][m + 2];
    memset(dp, 0, sizeof(dp));
    ll MOD = 1e9 + 7;
    for (int i = 0; i < n; ++i)
    {
        if (i == 0)
        {
            if (a[i] == 0)
            {
                for (ll j = 1; j <= m; ++j)
                {
                    dp[0][j] = 1;
                }
            }
            else
            {
                dp[0][a[i]] = 1;
            }
        }
        else
        {
            if (a[i] == 0)
            {
                for (ll j = 1; j <= m; ++j)
                {
                    dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j] + dp[i - 1][j + 1]) % MOD;
                }
            }
            else
            {
                dp[i][a[i]] = (dp[i - 1][a[i] - 1] + dp[i - 1][a[i]] + dp[i - 1][a[i] + 1]) % MOD;
            }
        }
    }
    ll ans = 0;
    for (ll i = 1; i <= m; ++i)
    {
        ans = (ans + dp[n - 1][i]) % MOD;
    }
    cout << ans << "\n";
    return 0;
}