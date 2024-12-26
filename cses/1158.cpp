#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll n, x;
    cin >> n >> x;
    vector<ll> price(n), pages(n);
    for (ll i = 0; i < n; ++i)
    {
        cin >> price[i];
    }
    for (ll i = 0; i < n; ++i)
    {
        cin >> pages[i];
    }

    vector<ll> dp(x + 1, 0LL);

    for (ll idx = 1; idx <= n; ++idx)
    {
        vector<ll> next(x + 1, 0LL);

        for (ll prc = 1; prc <= x; ++prc)
        {
            if (price[idx - 1] <= prc)
            {
                next[prc] = max(dp[prc], pages[idx - 1] + dp[prc - price[idx - 1]]);
            }
            else
            {
                next[prc] = dp[prc];
            }
        }
        dp = next;
    }

    cout << dp[x] << "\n";
    return 0;
}