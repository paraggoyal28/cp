#include <bits/stdc++.h>
#define ll long long int
using namespace std;

ll cntLucky(ll start, ll end, ll minStars, vector<vector<ll>> &dp)
{
    if (end - start + 1 < minStars)
        return 0;

    if (end == start)
        return dp[start][end] = end;

    if (dp[start][end] != -1)
    {
        return dp[start][end];
    }
    ll length = end - start + 1;
    ll mid = (end + start) / 2;
    if (length % 2)
    {
        return dp[start][end] = mid + cntLucky(start, mid - 1, minStars, dp) + cntLucky(mid + 1, end, minStars, dp);
    }
    else
    {
        return dp[start][end] = cntLucky(start, mid, minStars, dp) + cntLucky(mid + 1, end, minStars, dp);
    }
}

void solve()
{
    ll n, k;
    cin >> n >> k;
    vector<vector<ll>> dp(n + 1, vector<ll>(n + 1, -1));
    cout << cntLucky(1LL, n, k, dp) << "\n";
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